#include <stdio.h>
#define M 1000000007

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        long long m,out=1,Tmp=2;
        scanf("%lld",&m);
        long long pord=m%M;
        m--;
        while(m)
        {
            if(m%2) out = out*Tmp%M;
            m/=2;
            Tmp = Tmp*Tmp%M;
        }
        printf("%lld\n",out*pord%M);
    }
    return 0;
}
