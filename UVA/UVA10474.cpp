#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 1e4;

int main()
{
    freopen("in","r",stdin);
    int n,m,kase=0,a[maxn],ToFind;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        printf("CASE# %d:\n",++kase);
        for(int i=0; i<n; i++) scanf("%d",a+i);
        sort(a,a+n);
        while(m--)
        {
            scanf("%d",&ToFind);
            int p = lower_bound(a,a+n,ToFind) - a;
            if(a[p] == ToFind) printf("%d found at %d\n",ToFind,p+1);
            else printf("%d not found\n",ToFind);
        }
    }
    return 0;
}


