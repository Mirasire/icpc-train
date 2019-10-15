# CodeForces-EducationRound#74 题解报告

## A. [Prime Subtraction](https://codeforces.com/contest/1238/problem/A)

## 题意

给出数字 **x** 和 **y** ，问 **y** 是否能由 **x** 减去 2，3，4，5，7，11 组成，若是则输出**YES**，否则输出**NO**

## 题解

容易证明这几个数字能组合出，**除了1** 以外的所有数字，换言之只要

- 两者相差 > 1 就输出 YES
- 否则 就输出 NO

```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
 
typedef long long int ll;
int main() {
	ll n,x,y;
	cin >> n;
	while(n--) {
			cin >> x >> y;
			if(x-y > 1) cout <<"YES\n";
			else cout << "NO\n";
		}
	return 0;
}
```

## B. [Kill Em All](https://codeforces.com/contest/1238/problem/B)

## 题意

事情发生在一个一维的直线上，一开始有 n 个怪物在坐标轴左侧坐标分别为 X1-Xn (Xi > 0) ，你有个技能k，你可以选择这个 K 释放的位置 **c**，怪物受到的影响有如下规则

- 如果 Xi == c ，怪物死亡
- 如果 Xi > c ，怪物坐标变为 Xi + c
- 如果 Xi < c ，怪物坐标变为 Xi - c

如果怪物坐标变化为Xi (Xi <= 0) 则会触发地形杀，导致死亡

**问** 最少的施法次数是几次。

## 题解

最要贪心从最左边开始爆炸就好了，由于输入的为未排序，那就排序后进行模拟即可。

```cpp
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e5+100;
int x[maxn],n,r;

int main() {
	int q,size;
	long long cnt = 0;
	scanf("%d",&q);
	while(q--) {
		cnt = 0;
		scanf("%d%d",&n,&r);
		for(int i=0; i<n; i++) scanf("%d",x+i);
		sort(x,x+n);
		size = unique(x,x+n) - x;
		for(int j=size-1; j>=0; ){
			while(x[j]-cnt*r <= 0) {
				j--;
				if(j==-1) break;
			}
			if(j!=-1) {
				cnt++;
				j--;
			}
		}
		printf("%lld\n",cnt);
	}
}
```


## C. [Standard Free2play](https://codeforces.com/contest/1238/problem/C)

## 题意

山的高度是**h** ，有高度为 **1**，**2**，**3**，......，**h** 的移动平台在山上 (默认未移出)。初始位置在平台**h**上，目的是下降到**0**位置。

一开始会将 **n** 个平台移出，高度分别为 p1，p2，p3，...，pn。

每个平台有一个按钮，按下按钮，当前平台 ( x ) 会缩回，下面的平台 ( x-2 ) 会改变状态，即缩回的会被推出，原来推出的会被缩回去。

你只能最多从当前平台 ( x ) 坠落到 **x - 2** 以内的平台，不然你会死亡。

幸运的是你可以买一些魔法石，使用一个魔法石可以改变任何一个平台的状态。每颗魔法石只能使用一次。

**问**: **最少**需要购买多少魔法石。

## 题解

默认目前所站在p[x]+1上
只要判断是否 p[x] 和 p[x+1] 是否相邻，如果是就直接到 p[x]上否则 就使用一个魔法石到 p[x+1]+1上。


```cpp
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 2e5+100;
int p[maxn];

int main() {
	int t,i;
	int n,h,ans;
	scanf("%d",&t);
	while(t--) {
		ans = 0;
		scanf("%d%d",&h,&n);
		for(i=0; i<n; i++) scanf("%d",&p[i]);
		p[n] = 0;
		for(i=1; i<n; i++) {
			if(p[i]==p[i+1]+1) i++;
			else ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
```

## D. [AB-string](https://codeforces.com/contest/1238/problem/D)

## 题意

一个字符串仅由 A 和 B 构成，定义一个字符串为好的串，如果字符串的每一个字母在字符串中都有回文子串，问给出的字符串有多少个好的子串。

## 题解

由于只有A，B构成，易知长度 >1的子串个数为 **(n-1)\*n/2** ，（ n为字符串长度 ）只要排除类似ABBBB，BAAA，BBBBA，AAAAB，这种类型的子串即可。

```cpp
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const long long int MAXSIZE = 3e5+100;
char str[MAXSIZE];

int main() {
	long long int n,sub = 0;
	long long int i,j;
	scanf("%lld",&n);
	scanf("%s",str);
	for(i=0; i<n; i++) {
		if(str[i] == 'A') {
			for(j=i-1; j>=0; j--) {
				if(str[j]=='B') sub++;
				else break;
			}
			for(j=i+1; j<n; j++) {
				if(str[j]=='B') sub++;
				else break;
			}
		}
		else {
			for(j=i-1; j>=0; j--) {
				if(str[j]=='A') sub++;
				else break;
			}
			for(j=i+1; j<n; j++) {
				if(str[j]=='A') sub++;
				else break;
			}
		}
	}
	for(long long int i=1; i<n; i++) 
		if(str[i] != str[i-1]) sub--; //...BA..，.......AB.....
	printf("%lld",n*(n-1)/2 - sub);
	return 0;
}
```
