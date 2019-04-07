#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m,n;
        cin >> n >> m;
        if(n==1 || m==1) cout << "N0" << endl;
        else if(n%2==0 || m%2 ==0) cout << "YE5" << endl;
        else cout << "N0" << endl;
    }
    return 0;
}
