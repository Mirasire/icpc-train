# CodeForces-Round#588 题解报告

[CodeForce-Round#588](https://codeforces.com/contest/1230)

## A. Dawid and Bags of Candies

### 题意
有**四个背包**，是否能分成**等质量**的**两堆**，背包不能丢弃。

**输入：** a1，a2，a3，a4
**输出：** YES，NO

### 题解

从大到小 **排序**判断 **a1+a4 == a2+a3** 或者 **a1+a2+a3 == a4** 是就输出 **YES**，否则就输出**NO**。


```cpp
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[10];

int main() {
    cin >> a[0];
    cin >> a[1];
    cin >> a[2];
    cin >> a[3];
    sort(a,a+4);
    if(a[0]+a[3] == a[1] + a[2]) cout << "YES";
    else if(a[3] == a[0] + a[1] + a[2])  cout << "YES";
    else cout << "NO";
    return 0;
}
```

## B. Ania and Minimizing

### 题意

给你一串数字，并且给你更改的**次数**，每次只能更改**一个数字**并且不能改变**位数**（即如果多个数字前面第一位不能为0），要求输出改完后最小的数字。

### 题解

显然如果是 **一位数字** 就改成 **0**，其他情况就改称 **100....** 这样的类型，这边注意如果与目标要改的一样，可以跳过这个字符，节省次数。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n,k;
    string str;
    cin >> n >> k >> str;
    k = min(n,k);
    if(n==k && k==1) putchar('0');
    else {
        int i;
        for(i=0; i<n&&k; i++) {
            if(i==0) {
                putchar('1');
                if(str[i] != '1') k--;  //相等状况
            } else {
                putchar('0');
                if(str[i] != '0') k--;  //同上
            }
        }
        while(i<n) {
            putchar(str[i]);
            i++;
        }
    }
}
```

## C. Anadi and Domino

### 题意

[题目连接](https://codeforces.com/contest/1230/problem/C)

给出一个无向图，没有自环，**点集**大小是**( 1 - 7 )**，Anadi 有一套多米诺骨牌，牌数是**21**张。牌子由两部分组成，每个部分由点数组成 ( 详情请看题目连接 ) 。

每个牌子可以用来表示一条边，但是注意 每个指向**同一节点**的多米诺骨牌的点数需要**相等**，问**最多**可以放入多少块多米诺骨牌。

### 题解

我们可以很轻松的分析出，如果**节点个数小于6**，那一定是可以放满的。那么问题就变成了，当**节点个数为7**的我们该怎么放置骨牌。

容易发现在**节点个数为7**的时候我们**一定**会对一个节点**使用**多米诺骨牌中左右两边**一样的牌**。如果两个点的节点数字一样同时这两个点连接在同一条边上，那么这两条边中必定有**一条边无法放置**多米诺骨牌。

那么只要找出**最少的**重复边，然后用**输入边数减去它**就是最大能够摆放的数量。


```cpp
#include <cstdio>
#include <algorithm>
using namespace std;

int mp[12][12];

int main() {
    int n,m,tmp1,tmp2;
    scanf("%d%d",&n,&m);

    for(int i=1; i<=m; i++) {
        scanf("%d%d",&tmp1,&tmp2);
        mp[tmp1][tmp2] = mp[tmp2][tmp1] = 1;
    }
    if(n<=6) {
        printf("%d",m);
        return 0;
    }
    int res = 56; //因为最大的最小重复边为6，所以初始化为56
    //寻找最小重复边
    for(int i=1; i<=7; i++) {
        for(int j=i+1; j<=7; j++) {
            int cnt = 0;
            for(int k=1; k<=7; k++) {
                if(mp[i][k]&&mp[j][k]) cnt++;
            }
            res = min(res,cnt);
        }
    }
    //输出答案
    printf("%d",m-res);
    return 0;
}
```

## D. Marcin and Training Camp

> 看不起可能翻译的不大好，就是b决定比a棒棒的意思。

### 题意

想要选一堆人 ( 人数 >= 2 ) 来相互合作，每个人会多种技能，技能**总数**为**60种**技能 （ 编号从 0 - 59 ），每个人有个参数 **a** 和 **b**
- **a** 表示那个人所会的技能，假设会编号为 j 的技能，那么 **a** 的二进制的第 j 位就为 1 ，不然为0
- **b**表示那个人的技能等级

假设a有个技能b不会，那么a看不起b。选一堆人的要求是 没有一个人能看不起所有人。

**输入：** n ，n 个 ai，n 个 bi
**输出：** 最大的技能等级和

### 题解

**易知**重复出现的肯定可以选择。之后就是选择**重复出现的看不起的**并且不能相互看不起。

这边判断**j**是否看不起**i**有个小技巧
```cpp
if( a[i] < a[j] && (a[i] | a[j]) == a[j]) a[j] 看不起 a[i]
else 互相看不起 或者 a[i] 看不起 a[j]
```
~~这样就变成一道大水题~~

```cpp
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

typedef long long int ll;
map<ll,ll> cnt;
bool vis[7100];
vector<ll> a,b,ans;
ll res;

int main() {
    res = 0;
    int n;
    ll tmp;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%lld",&tmp);
        cnt[tmp]++;
        a.push_back(tmp);
    }
    for(int i=0; i<n; i++) {
        scanf("%lld",&tmp);
        b.push_back(tmp);
        if(cnt[a[i]] >= 2) {
            vis[i] = 1;
            ans.push_back(a[i]);
            res+=tmp;
        }
    }
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            int end = ans.size();
            for(int j=0; j<end; j++) {
                if(a[i] < ans[j] && (a[i] | ans[j]) == ans[j]) {
                    ans.push_back(a[i]);
                    res += b[i];
                    break;
                }
            }
        }
    }
    printf("%lld\n",res);
    return 0;
}
```

