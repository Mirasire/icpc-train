# CodeForces-Round#594 题解报告

> CodeForces-Round#594 | [**Here**](http://codeforces.com/contest/1248)
> 题解代码 | [**Here**](https://github.com/Mirasire/icpc-train/tree/master/Life%20In%20OJ/OJ's%20Solution/CodeForces/Round%23594)

## A. Integer Points

### 题意

DLS和JLS在二维坐标系中画一次函数，想知道DLS和JLS画出的所有交点中有几个是整数点($x,y$都是整数的点)？
DLS的函数是 $y = x+pi$，JLS的函数是 $y = -x+pi$

**输入**

$n$ 组案例，$n$个DLS的$pi$，DLS的$pi$，n个JLS的$pi$，JSL的$pi$

### 题解

由于要求是整数$ x + Dpi = -x + Jpj \Rightarrow 0 = (Dpi+Jpj) \pmod{2}$
所以Dpi和Jpj只能同奇或同偶。

## B. Grow The Tree

### 题意

给你n根棍子和每根棍子的长度，让你将棍子两头连接(连接角度固定为90)，问如何连接能让两端距离最远？

### 题解

$$
\begin{aligned}
		&x + y = t \\
		&x^2 + y ^2 = t^2 - 2xy \\
\end{aligned}
$$

因为要尽量让$x*y$相乘尽量小，所以，只要最大化一个边就好了。

```cpp
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 1e5+100;
typedef long long int ll;
ll arr[maxn];

int main() {
	int n,size;
	ll sum1 = 0,sum2 = 0,sum;
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%lld",arr+i);
	size = n/2;
	sort(arr,arr+n);
	for(int i=0; i<size; i++) sum1 += arr[i];
	for(int i=size; i<n; i++) sum2 += arr[i];
	sum = sum1*sum1 + sum2*sum2;
	printf("%lld",sum);
	return 0;
}
```

## C. Ivan the Fool and the Probability Theory

### 题意
有一个$n*m$的格子，再上面进行黑白染色，但是遵守以下原则:
- 不出现相邻的三个格子颜色相同
求出总染色方案数并且 %1e9+7 输出

### 题解

首先我们知道:

- 假设这一行有格子连续，下一行必定会隔开摆放。
- 没有相邻染色的情况只有两种。

我们先考虑第一行:

- 假设第一行有两个连续的，那么之后格子摆放就确定了。此时每一列必定是黑白黑....，或者白黑白...这样
- 假设第一行是间隔的，那么我们把这个旋转90度以后，这就是上面一种情况。

> $F_m$ 第一行的方案数，$F_n$代表第一列的方案数
> 

这样就发现了所有总方案数为$F_m + F_n - 2$ 这边的2是重复考虑相邻染色的情况，所以要剪去。

而$F_{i}$的方案数为$F_{i-1}加上一个与结尾颜色不同的格子和上上行$F_{i-2}$加上两个颜色相同但是和结尾颜色不同的格子。

所以算一层所有方案数的公式为 $F_{m} = F_{m-1} + F_{m-2}$


```cpp
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int MAXN = 1e5+100,MOD = 1e9+7;
long long int dp[MAXN];

int main() {
	int n,m;
	cin >> n >> m;
	dp[1] = 2,dp[2] = 4;
	for(int i=3; i<=max(n,m); i++) {
		dp[i] = dp[i-1] + dp[i-2];
		dp[i] %= MOD;
	}
	cout << (dp[n] + dp[m] - 2)%MOD << endl;
	return 0;
}
```

## D1. The World Is Just a Programming Task (Easy Version)

### 题意

给出一个长度为$n$的字符串$s$字符串中只包含 '(' 和 ')' ，可以循环移动字符串。
交换两个字符使得最后的合法字符串个数最大。

例子: 

假设$s$=") ( ( ) ( ( ) ( ) ) ( )"，交换**第5个**和**第8个** $s$ = " ) ( ( ) ) ( ) ( ) ( ( )" 循环移动后$s$ = "( ( ) ) ( ) ( ) ( ( ) )" 

因此合法字符串分别为"( ( ) )"，"( )", "( )"，"( ( ) )" 四个。

### 题解

**易知:** 如果'('和')'**数量相等**,通过循环移动，必定成为**合法字符串**，**不相等**则肯定不**存在**。

> 我们将'('看为1，')'看为-1对数组求前缀和。

**这边有个暴力判断的关键:** 就是合法字符串的个数与前缀数组中最小值的出现次数相等。

原因: 
假设括号一开始就是合法字符串的那么，合法字符串的个数就是前缀和中**0**出现个数,**0**一定是前缀和中的最小值。
由于现在的$s$是合法字符串透过平移得到的，平移操作等于对前缀合整体加，或者减，那么前缀和中最小值的必定就是原来的0，其个数也就等于合法字符串的个数。

```cpp
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 120;
char str[maxn];

int main() {
	int n,i,j;
	scanf("%d",&n);
	scanf(" %s",str+1);
	int res=0,oi=1,oj=1;
	for(i=1; i<=n; i++) {
		for(j=i+1; j<=n; j++) {
			swap(str[i],str[j]);
			int st = 0, c = 0, now = 0;
			for(int k=1; k<=n; k++) {
				str[k]=='('? st++ : st-- ;
				if(st == now) c++;
				if(st < now) c=1,now = st;
			}
			if(!st&&c>res) res=c,oi=i,oj=j;
			swap(str[i],str[j]);
		}
	}
	printf("%d\n%d %d",res,oi,oj);
	return 0;
}
```
