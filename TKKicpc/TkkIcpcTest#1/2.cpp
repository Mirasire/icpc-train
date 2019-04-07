#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n,m;
        cin >> n >> m;
        if(n==m) cout << "YE5" << endl;
        else cout << "N0" << endl;
    }
    return 0;
}
