#include <iostream>
#include <map>
using namespace std;

const int maxn = 2*1e3+5;
const int maxnn = 4*1e6+100;
int a[maxn] = {0};

int main()
{
    map<int,int> Target;
    int m,in;
    //freopen("in","r",stdin);
    scanf("%d",&m);
    for(int i=0; i<m; i++) scanf("%d",a+i);
    for(int i=0; i<m; i++)
    {
        scanf("%d",&in);
        for(int j=0; j<m; j++)
        {
            int key = in+a[j];
            Target[-key] += 1;
        }
    }
    long long out = 0;
    for(int i=0; i<m; i++) scanf("%d",a+i);
    for(int i=0; i<m; i++)
    {
        scanf("%d",&in);
        for(int j=0; j<m; j++)
        {
            out+=Target[in+a[j]];
        }
    }
    printf("%lld\n",out);
    return 0;
}
