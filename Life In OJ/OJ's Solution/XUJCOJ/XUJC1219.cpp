//Template of QuickMartixFactor
#include <iostream>
using namespace std;

const int mod = 1e4;

void MratixFactor(int (*front)[2],int (*last)[2])
{
    int tmp[2][2] = {0};
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            for(int k=0; k<2; k++)
                tmp[i][j] = (tmp[i][j]+front[i][k]*last[k][j]) % mod;
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            last[i][j] = tmp[i][j];
}

void QuickFactor(int (*base)[2],int (*arr)[2],int n)
{
    while(n)
    {
        if(n&1) MratixFactor(&arr[0],&base[0]);
        MratixFactor(&arr[0],&arr[0]);
        n/=2;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a;
        scanf("%d",&a);
        int arr[2][2] = {{1,1},{1,0}},base[2][2] = {0,0,1,0};
        QuickFactor(&base[0],&arr[0],a);
        printf("%d\n",base[0][0]);
    }
    return 0;
}
