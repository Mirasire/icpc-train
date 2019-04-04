#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e3+600;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int n;
    //freopen("in","r",stdin);
    scanf("%d",&n);
    int b[maxn] = {0};
    long long int sum=0;
    int i,j=0,o=0;
    for(i=0; i<n; i++) scanf("%d",b+i),sum+=b[i];
    sort(b,b+n,cmp);
    for(i=0; i<n; i++)
        if(b[i]%2) j++;
        else o++;
    int flag = 1;
    if(abs(j-o) == 1) flag = 0;
    int Min = min(j,o);
    for(i=0,j=0; j<Min; i++)
    {
        if(b[i]%2) 
        {
            sum-=b[i];
            b[i]=0;
            j++;
        }
    }
    for(i=0,o=0; o<Min; i++)
    {
        if(b[i]%2 == 0)
        {
            sum-=b[i];
            b[i]=0;
            o++;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(b[i])
        {
            sum -= b[i];
            break;
        }
    }
    printf("%lld\n",sum);
    return 0;
}
