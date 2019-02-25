//TLE Version

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        long long int a,b,save=1;
        scanf("%lld%lld",&a,&b);
        long long int Min = min(a,b);
        long long int Max = max(a,b);
        long long int i=2,end = sqrt((double)Min);
        printf("1");
        while(i<=end)
        {
            if((Min%i==0) && (Max%i==0)) 
            {
                printf(" %lld",i);
                save = i;
            }
            i++;
        }
        i=save;
        if(end*end == Min) i--;
        while(i>0)
        {
            if((Min%i==0) && Max%(Min/i)==0) printf(" %lld",Min/i);
            i--;
        }
        printf("\n");
    }
    return 0;
}
