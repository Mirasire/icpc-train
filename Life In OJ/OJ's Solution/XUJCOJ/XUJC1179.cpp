#include <iostream>
#include <string.h>
#include <limits.h>
using namespace std;

int main()
{
    int n,m,flag = 0;
    cin >> n >> m;
    int number[n+1],cnt=0;
    memset(number,0,sizeof(int)*(n+1));
    for(int i=1; i<=m; i++)
    {
        int index;
        cin >> index;
        if(!number[index]) cnt++;
        number[index]++;
        if(!(cnt-n))
        {
            if(flag) printf(" ");
            else flag = 1;
            cout << i; 
            for(int j=1; j<=n; j++)
            {
                --number[j];
                if(!number[j]) cnt -= 1;
            }
        }
    }
    return 0;
}
