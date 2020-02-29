#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main()
{
    int cs;
    cin >> cs;
    for(int i=1; i<=cs; i++)
    {
        int n,m;
        string in;
        cin >> n >> m;
        for(int i=0; i<n; i++) cin >> in;
        int out = n*n;
        for(int i=0; i<m; i++)
        {
            cin >> in;
            out -= in.size();
        }
        printf("%d : %d\n",i,out);
    }
    return 0;
}
