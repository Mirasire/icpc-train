# 网络流学习笔记-最大流

**最大流问题**是求在一张网络中从源点 **$s$** 出发到汇点 **$t$** 的最大流量。(不一定非要单路径)

> 模板题地址 | [**Here**](https://www.luogu.org/problem/P3376)

## FF算法 

我们先给出一张网络每个边上的数字表示**流量/容量**

![MF1](/GithubFile/Mirasire/icpc-train/pic/draw.io_pic/2019-10-19/MF1.png)

首先我们考虑一个**错误操作**，错误操作是**寻找增广路**,**存在**就**进行增广**。

假设我们在这张图上找到的**增广路**为 **$s->1->2->t$**，然后对**找到的增广路**并且进行**增广**，那么会变成下图

![MF1](/GithubFile/Mirasire/icpc-train/pic/draw.io_pic/2019-10-19/MF2.png)

之后我们发现再也找不到增广路，这样子我们得出**伪-最大流**为**1**,显然这是**不对**的，这张图的**最大流应该是2**。

于是我们将原来的图中的每一条边**添加一条反向边**，因为建立反向边以后，代表你的程序可以**反悔**，也就是新找到的增广路径**经过反向边**来达到**退流**的目的。


> **$s->1$** 添加反向边类似如下图
>
> ![MF1](/GithubFile/Mirasire/icpc-train/pic/draw.io_pic/2019-10-20/MF3_2.png)

这样一来我们原来**错误操作**就变成**正确的了**,这就是**Ford-Fulkerson 增广路算法**

## EK算法

**EK**算法的想法是用**BFS**寻找增光路，并进行增流。这边有两个关键的问题

- 如何寻找增广路 ?
- 如何进行增广 ?

解决办法就是用**BFS**一直寻找，假设有向边 $e_i = {\langle u,v \rangle}$ 可增广，就记录点 **$v$** 前面的节点为 **$u$** 并且记录**最大残量**，直到遇到 **$源点t$** 或者**最大可增广为0**，退出**BFS**,判断下 **$源点t$** 有没有前面的节点，为了方便姑且叫他 **$pre[t]$**。
> 这边我们可以用一个 **$pre[v] = u$**，来记录前面的节点
> 最大残量是 = min(最大残量，目前残量)

- **$pre[t]存在$**
  -  使用 **$per$数组**和得到的**最大残余流量**进行增广

- 不存在 
  - 代表已经完成得到最大流，**退出返回最大流**

EK算法的时间复杂度是$O(nm^2)$  (n是点数，m是边数) `TLE的罪魁祸首`

### EK模板

> 模板来自紫书和OI-WIKI，存图使用邻接表

```cpp
#define maxn 250
#define INF 0x3f3f3f3f

struct Edge {
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

struct EK {
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  int a[maxn];
  int p[maxn];

  void init(int n) {
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void AddEdge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }

  int Maxflow(int s, int t) {
    int flow = 0;
    for (;;) {
      memset(a, 0, sizeof(a));
      queue<int> Q;
      Q.push(s);
      a[s] = INF;
      while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (int i = 0; i < G[x].size(); i++) {
          Edge& e = edges[G[x][i]];
          if (!a[e.to] && e.cap > e.flow) {
            p[e.to] = G[x][i];
            a[e.to] = min(a[x], e.cap - e.flow);
            Q.push(e.to);
          }
        }
        if (a[t]) break;
      }
      if (!a[t]) break;
      for (int u = t; u != s; u = edges[p[u]].from) {
        edges[p[u]].flow += a[t];
        edges[p[u] ^ 1].flow -= a[t];
      }
      flow += a[t];
    }
    return flow;
  }
};
```
## Dinic

> 其实Dinic没有理解清楚，姑且先给个口胡解释吧。

`我们先设置图的点数为n，边数为m。`
**仔细观察EK算法**，我们可以发现EK算法**每次**都只是寻找**一条**增广路进行增广，所以每次需要$O(m)$的时间去寻找增广路，这样的话总时间复杂度就到了$O(nm^2)$。
但是如果提前像**BFS**求最短路一样
1. 先将用**BFS**网络变成一个层次图，然后之后每次寻找的边就在**相邻的层**中寻找
2. 再用DFS**在层次图上**进行**多路增广**，并且**注意一点**就是每次DFS寻找到增广路返回以后，就不对之前的边进行重复判断，这样就能明显的提高效率~~，至于为啥我，我也不造~~。

Dinic算法的时间复杂度是$O(n^2m)$，如果 **边数$m$** 很大的话，Dinic算法的效率就比EK算法高很多。

> P.s. 在求二分图最大匹配时，可证 Dinic 算法的时间复杂度是 $O(m{\sqrt{n}})$

### Dinic模板

> 模板来自紫书和OI-WIKI，存图使用邻接表
> 

```cpp
#define INF 0x3f3f3f3f
const int maxn = 250;

struct Edge {
	int from, to, cap, flow;
	Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

struct Dinic {
	int n, m, s, t;
	vector<Edge> edges;
	vector<int> G[maxn];
	int d[maxn], cur[maxn];
	bool vis[maxn];

	void init(int n) {
		for (int i = 0; i < n; i++) G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, int cap) {
		edges.push_back(Edge(from, to, cap, 0));
		edges.push_back(Edge(to, from, 0, 0));
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	bool BFS() {
		memset(vis, 0, sizeof(vis));
		queue<int> Q;
		Q.push(s);
		d[s] = 0;
		vis[s] = 1;
		while (!Q.empty()) {
			int x = Q.front();
			Q.pop();
			for (int i = 0; i < G[x].size(); i++) {
				Edge& e = edges[G[x][i]];
				if (!vis[e.to] && e.cap > e.flow) {
					vis[e.to] = 1;
					d[e.to] = d[x] + 1;
					Q.push(e.to);
				}
			}
		}
		return vis[t];
	}

	int DFS(int x, int a) {
		if (x == t || a == 0) return a;
		int flow = 0, f;
		for (int& i = cur[x]; i < G[x].size(); i++) {
			Edge& e = edges[G[x][i]];
			if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
				e.flow += f;
				edges[G[x][i] ^ 1].flow -= f;
				flow += f;
				a -= f;
				if (a == 0) break;
			}
		}
		return flow;
	}

	int Maxflow(int s, int t) {
		this->s = s;
		this->t = t;
		int flow = 0;
		while (BFS()) {
			memset(cur, 0, sizeof(cur));
			flow += DFS(s, INF);
		}
		return flow;
	}
};
```

## 参考文章

[**OIWiki-最大流**](https://oi-wiki.org/graph/flow/max-flow/#edmond-karp-ek)
**《挑战程序设计竞赛（第二版）》- (白书)**
**《算法竞赛（第二版）》-刘汝佳 (紫书)**
**《算法竞赛入门训练-训练指南》**