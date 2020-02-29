#include <stdio.h>
#include <math.h>

#define Mod 1000000007
#define N 101
#define prt(x) printf(#x" = %d\n",x);

int Equal(int a)
{
    while(a)
    {
        if(a%10==7) return 1;
        a/=10;
    }
    return 0;
}


int main()
{
    int n,in,ws,product;
    long long int a[N]={0},sum=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&in);
        for(int i=1; i<N; i++)
            if(a[i])
            {
                if(Equal(i) || Equal(in)) sum=(sum+2*a[i]%Mod)%Mod;
                else
                {
                    ws = log10(in)+1;
                    product = pow(10,ws);
                    if((product*i+in)%7 == 0) sum=(sum+a[i])%Mod;
                    //prt(i);
                    //prt(product);
                    //prt(product*i+in);
                    if(i<10) product=10;
                    else if(i<100) product=100;
                    else product=1000;
                    if((i+in*product)%7 == 0) sum=(sum+a[i])%Mod;
                }
            }
        a[in]++;
    }
    printf("%lld\n",sum%Mod);
    return 0;
}
