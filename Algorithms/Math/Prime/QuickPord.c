#include <stdio.h>
#include <time.h>

#define M 1000000

long long int pord(long long int a,long long int n);

int main()
{
    long long int a,n,out;
    clock_t st,ed;
    scanf("%lld%lld",&a,&n);
    st = clock();
    out = pord(a,n);
    ed = clock();
    printf("pow(%lld,%lld) = %lld\n",a,n,out);
    printf("time : %lf\n",(double)(ed-st)/CLOCKS_PER_SEC);
    return 0;
}

    /*
long long int pord(long long int a,long long int n)
{
    long long int out = 1; 
    while(n--) out = (out*a) % M;
    return out;
}
    */

///*
long long int pord(long long int a,long long int n)
{
    long long int out = 1;
    while(n)
    {
        if(n%2)
        {
            out = (out * a) % M;
            n -= 1;
        }
        else
        {
            a = (a * a) % M;
     		n /= 2;
        }
    }
    return out;
}
//*/
