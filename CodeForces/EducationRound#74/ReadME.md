# CodeForces-EducationRound#74 题解报告

## A.[Prime Subtraction](https://codeforces.com/contest/1238/problem/A)

## 题意

## 题解

## B. [Kill Em All](https://codeforces.com/contest/1238/problem/B)

## 题意

## 题解


## C. [Standard Free2play](https://codeforces.com/contest/1238/problem/C)

## 题意

山的高度是**h** ，有高度为 **1**，**2**，**3**，......，**h** 的移动平台在山上 (默认未移出)。初始位置在平台**h**上，目的是下降到**0**位置。

一开始会将 **n** 个平台移出，高度分别为 p1，p2，p3，...，pn。

每个平台有一个按钮，按下按钮，当前平台 ( x ) 会缩回，下面的平台 ( x-2 ) 会改变状态，即缩回的会被推出，原来推出的会被缩回去。

你只能最多从当前平台 ( x ) 坠落到 **x - 2** 以内的平台，不然你会死亡。

幸运的是你可以买一些魔法石，使用一个魔法石可以改变任何一个平台的状态。每颗魔法石只能使用一次。

**问**: **最少**需要购买多少魔法石。

## 题解

```cpp
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;


int main() {
	int t,n,h,now,in,ans;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&h,&n);
		now = h;
		ans = 1;
		while(n--) {
			scanf("%d",&in);
			if(in==now) ans--;
			else if(in < now) {
				ans++;
				now = in-1;
			}
			if(now==0) ans--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
```
