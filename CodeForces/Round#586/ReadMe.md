# CodeForces-Round#586 题解报告

## A. Cards

### 题意

原来有一字符串由多个one,zero组成，可能没有one,或者zero,将字符串打乱给你，问原来的字符串是怎样的，从one开始输出。

### 题解

**one 和 zero** 个数，就是 **n 和 z** 的个数。

```cpp
#include <iostream>
#include <cstring>
#include <map>
using namespace std;
 
map<char,int> mp;
 
int n[12];
string add1 = " 1",add2 = " 0";
 
//zero
//one
int main() {
	int t;
	mp['z'] = 1;
	mp['e'] = 2;
	mp['r'] = 3;
	mp['o'] = 4;
	mp['n'] = 5;
	string str;
	string out;
	cin >> t >> str;
	for(int i=0; i<t; i++) {
		n[mp[str[i]]]++;
	}
	for(int i=0; i<n[5]; i++) 
		if(out.empty()) {
			out = "1";
		} 
		else out += add1;
	for(int i=0; i<n[1]; i++) 
		if(out.empty()) {
			out = "0";
		} 
		else out += add2;
	cout << out;
	return 0;
}
```

## B - Multiplication Table
### 题意
给出如下表格
||a1|a2|a3|...|
|:--:|:--:|:--:|:--:|:--:|
|a1|0|a1&times;a2|a1&times;a3|...|
|a2|a2&times;a1|0|a2&times;a3|...|
|a3|a3&times;a1|a3&times;a2|0|...|
|...|...|...|...|0|
求**a1到an**的数,题目保证n>=3

## 题解

$$
\begin{aligned}
x_1 &= a_1 * a_2  \\
x_2 &= a_1 * a_3  \\
x_3 &= a_2 * a_3  \\

a_1 &= \sqrt{\frac {x_1 \times x_2 } {x_3}} \\


\end{aligned}
$$
```cpp
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
 
typedef long long ll;
const int M = 1e3+100;
ll el[M][M];
 
ll getSqrt(ll a,ll bsc) {
	ll end = bsc + 1000;
	for(ll i=max(bsc-1000,1ll); i<end; i++) 
		if(i*i == a) return i;
}
 
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			scanf("%lld",&el[i][j]);
		}
	}
	ll a = (el[2][1]*el[1][3])/el[3][2];
	ll mid = sqrt(a);
	if(mid*mid != a) mid = getSqrt(a,mid);
	printf("%lld",mid);
	for(int i=2; i<=n; i++) {
		printf(" %lld",el[1][i]/mid);
	}
	return 0;
}
```

## C - Substring Game in the Lesson
### 题意
**Ann** 和 **Mike** 在完游戏, 游戏规则如下:
- 给出一段长度为s的字符串，**先手**是Ann。
- 当前玩家选择一串**连续**的字符串 (s2) ，s2**包含前面**的字符c且和前面的字符串(s1) **不相同**，并且s1 < s2 (字典序) 。
- 起始字符串是第k位字符, 无法选择时当前玩家输掉。

要求输出**k**从 **0** -> **s-1** 的胜利玩家

### 题解

思考了以下 **Ann** 的胜利条件，只要不开局开局爆死,即**开局字符k是 0-k 中字符串最小的**, 都是**Ann** 胜利，剩下就是Mike胜利。

```cpp
#include <string>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
 
int lletter[39];
set<char> toFind;
const int maxn = 5e5+100;
bool vis[maxn];
 
int main() {
	string s;
	cin >> s;
	int end = s.size();
	int mid = 0;
	char mi = s[0];
	toFind.insert(mi);
    //记录是否是到目前最小的
	for(int i=1; i<end; i++) {
		if(s[i] < mi) {
			mi = s[i];
			mid = i;
			vis[i] = 0;
		} else if(s[i] == mi){
			vis[i] = 0;
		} else {
			vis[i] = 1;
		}
	}
	for(int i=0; i<end; i++) {
		if(!vis[i]) 
			printf("Mike\n");
		else 
			printf("Ann\n");
	}
	return 0;
}
 
```

## D. Alex and Julian

### 题意

B是一个题目给出的集合，要求**删去B**的一个**最小子集**，使得题目要求的构成一个**二分图**，图的构成规则如下。

$$ 
\begin{aligned}
&i \And j \in V \quad(i \And j \in Z)\\
&if \quad |i-j| = b_i\quad (b_i \in B,{i}\And{j} \in Z) \quad then <i,j> \in E
\end{aligned}
$$

### 题解

如果要**构成二分图**，那么图内必定**不存在奇环**。
> 奇环指的是环的边数个数之和为奇数~~还是看他人题解明白的QWQ!!~~

那么我们考虑如何会构成奇数环。
1. 显然，假设我们选择了k，那么k的偶数倍数我们都不能选择。
2. 假设集合中有**1奇1偶(odd1 & even)**，那么必定存在一个 k = odd*even ，由于 奇数+偶数 = 奇数，所以在目标集合中必定不存在一个奇一偶数偶数。
3. 假设集合中**全是奇数**,显然成立。
4. 假设集合中**全是偶数**，由于**偶数都是2的倍数**，那就可以都 **/2** 之后后按照奇数来进行判断，这样我们就能避免排除第一个状况了。

但是组合有**这么多**我们如何排除呢？

普通的找到所有的奇数是十分简单的，但是如何将偶数变成奇数以后进行归纳呢? 这边**显然**的一点就是我们不能将 **/2一次** 变成奇数的和 **/2两次**变成奇数归在同一个集合中，如果知道这个那么做法就很明显了。由于最多不超过64个集合~~因为是long long int~~。那么我们就每次记录偶数位于那个集合，然后塞入即可。

```cpp
//这边使用vector实现的，没有用set，因为觉得set遍历输出好麻烦...
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
 
typedef long long ll;
const int maxn = 2e5+1000;
int n,m;
ll num[maxn],x;
vector<ll> a[90];
 
int main() {
    int k;
    scanf("%d",&n);
    //这边是分段塞入操作。
    for(int i=0; i<n; i++) {
        scanf("%lld",&num[i]);
        k = 0;
        x = num[i];
        while(x%2==0) {
            x/=2;
            k++;
        }
        a[k].push_back(i);
    }
    
    //寻找最小的集合
    m = -1;
    for(int i=0; i<=64; i++) {
        if(m==-1 || a[m].size() < a[i].size()) m=i;
    }
 
    printf("%d\n",n-a[m].size());
 
    for(int i=0; i<=64; i++) {
        if(i==m) continue;
        for(int j=0; j<a[i].size(); j++) 
            printf("%lld ",num[a[i][j]]);
    }
    return 0;
}
```