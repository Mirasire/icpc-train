#include <iostream>
using namespace std;

int main()
{
    int n,a,b,c;
    while(cin >> n >> a >> b >> c)
    {
        int min1 = n/a, min2 = (n-c)/(b-c) + (n - ((n-c)/(b-c))*(b-c))/a;
        printf("%d\n",min1 < min2 && (n-c) > 0? min2 : min1);
    }
    return 0;
}
