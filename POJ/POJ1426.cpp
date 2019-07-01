//AC-188ms
//  English                   Chinese
//  
//  Positive                  积极,自信的，优点，有时，阳性结果
//  Positive number           正数
//  multiple                  倍数 
//  decimal                   十进制
//  assume                    假定
//  representation            表示
//  crresponding              相应
#include <iostream>
#include <stdio.h>
#define LOCAL
using namespace  std;
#define _64int long long unsigned
bool flag;
_64int in;


void dfs(_64int sr, int floor)
{
    if(flag) return;
    if(floor > 19) return;
    if(!(sr%in))
    {
        flag = true;
        printf("%llu\n",sr);
        return;
    }
    dfs(sr*10,floor+1);
    dfs(sr*10+1,floor+1);
    return;
}

int main()
{
#ifdef LOCAL
    freopen("in","r",stdin);
    freopen("out","w",stdout);
#endif
    while(scanf("%llu",&in)!=EOF)
    {
        if(!in) break;
        flag=0;
        dfs(1,0);
    }
    return 0;
}
