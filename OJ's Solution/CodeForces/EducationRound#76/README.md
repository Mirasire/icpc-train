# CodeForces-EducationRound#76 题解报告

> CodeForces-EducationRound#76 | [**Here**](http://codeforces.com/contest/1257)
> 题解代码 | [**Here**](https://github.com/Mirasire/icpc-train/tree/master/Life%20In%20OJ/OJ's%20Solution/CodeForces/EducationRound%2376)

<!--more-->

# A.[**Two Rival Students**](http://codeforces.com/contest/1257/problem/A)

## 题意

给出一个序列由**1到**$n$个元素组成，起始升序，你能交换$x$次，只能**相邻交换**，给出元素$a,b$，**问*$x$次交换后的最大距离。

> 距离极为坐标相减

## 题解

容易发现$x$就是两者初始距离的增加量，由于距离一定小于**数列的最大长度**，最后的最大距离一定为$min(|a-b|+x,n-1)$。

```cpp
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int n,x,a,b;
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> x >> a >> b;
		cout << min(n-1,abs(a-b)+x) << endl;
	}
	return 0;
}
```


# B.[**Magic Stick**](http://codeforces.com/contest/1257/problem/B)

## 题意

给出一个数$num$，你可以对$num$进行两种操作

-  $num_{new} = \dfrac{num_{old}\*3}{2}$ ，$num =  偶数 $
-  $num_{new} = num_{old} - 1$

题目为多组输入，每组输入有两个数$x$和$y$。

**问:** $y$可否由$x$操作得到?

## 题解

此题第一眼很像**搜索题**，但是仔细分析发现，**当** $x$大于$3$的时候，必定能得到所有的$y$，只要乘到$> y$然后一直步骤2即可，那这题只要特判$x \in [1,3]$ **和** $y=0$的情况即可。

```cpp
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main() {
	int t,x,y;
	cin >> t ;
	while(t--) {
		cin >> x >> y;
		if(x==1 && y!=1) cout << "NO\n"; //特判1
		else if(x>=2 && x <=3 && y>3) cout << "NO\n"; //特判2
		else cout << "YES\n";
	}
	return 0;
}
```


# C.[**Dominated Subarray**](http://codeforces.com/contest/1257/problem/C)

## 题意

规定在一个**区间合法**为，在区间中有一个数的出现次数**严格大于**其他所有的数字。类似[1,2,2,2,3]，[1,1,4,5,1,4]......，否则即为**区间不合法**，如[1,1,2,2]，[1,2,3,4,5]......

给出一个序列$s$，**问:** 合法子序列的**最短长度**？如果不存在就输出 **-1**。

## 题解

显然**最短合法子序列**中最大出现次数为**两次**，所以对于**每个元素**来说只要选择与**最近的他相同的元素**并选择**最小的**即可，**假设**此时选择的区间**不合法**，所以在**当前区间内**肯定能找到**更小的合法区间**，按照思路**一定能**在接下来的寻找中将原来的答案**更新**，所以**算法正确**。

- 可以使用 map 来存储位置。

```cpp
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <limits.h>
using namespace std;

void slove() {
	int n,tmp;
	int ans = INT_MAX;
	map<int,int> per;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&tmp);
		if(per[tmp]) ans = min(ans,i-per[tmp]+1);
		per[tmp] = i;
	}
	if(ans==INT_MAX) printf("-1\n");
	else printf("%d\n",ans);
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		slove();
	}
	return 0;
}
```


# D.[**Yet Another Monster Killing Problem**](http://codeforces.com/contest/1257/problem/D)

## 题意

有$n$个怪兽，你有$m$个勇者，每天只能能使用**一个勇者**，并且要按照**怪物顺序**依次消灭。

第$i$个怪物的防御力为$a_i$，第$i$个勇者的**攻击力**$p_i$和**耐力**$s_i$，每消灭一个怪物以后**耐力-1**，耐力会在第二天恢复。

勇者的撤退条件为

- 耐力归零
- 勇者的攻击力 **<=** 怪物的防御力

**问:** 消灭所有怪物的**最短天数**是多少?

## 题解

我们可以使用一个$bst$**数组**表示**当前耐力所能拥有的最大攻击力**。

**分析：** 当 $p_{t1} > p_{t2}$ &&  $s_{t1} \ge s_{t2}$ 时，$bst[s_{t_2}] = p_{t_1}$ 即选择最佳英雄。

我们按照分析**预处理**$bst$数组，**显然**处理完的$bst$数组必定是**降序的**。

之后我们只要**按照顺序**开始攻略怪兽即可，每次选择$bst[t]$，$t$表示当前攻略到了**当天**开始的第$t$个怪兽，选择最佳的攻击力去攻击。由于$bst$数组是**降序**，可能出现**选择了后面的英雄，消灭不了前面的怪物**，所以需要判断**是否可以消灭**，使用的是当前的**最大的**$a_i$。

```cpp
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxN = 2e5+100;
int moster[maxN],s[maxN],p[maxN];
int bst[maxN];

int main() {
	int t,n,m,i;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		memset(bst,0,sizeof(int)*(n+1));
		for(i=0; i<n; i++) scanf("%d",moster+i);
		scanf("%d",&m);
		for(i=0; i<m; i++) {
			scanf("%d%d",p+i,s+i);
			bst[s[i]] = max(p[i],bst[s[i]]);
		}
		for(i=n-1; i>=0; i--) bst[i] = max(bst[i],bst[i+1]);	//bst为耐力为i的最大攻击力
		int pos = 0;
		bool ok = 1;
		int day = 0;
		while(pos < n) {
			day++;
			int m=0;
			int npos = pos;
			while(1) {
				m = max(m,moster[npos]); 		//最大的a[i]
				if(m > bst[npos - pos + 1]) break;
				npos++;
			}
			if(npos == pos) {
				ok = 0;
				break;
			}
			pos = npos;
		}
		if(!ok) day = -1;
		printf("%d\n",day);
	}
	return 0;
}
```
