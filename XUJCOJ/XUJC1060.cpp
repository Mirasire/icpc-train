#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a,int b)
{
    return a > b; //Max->Min
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int m;
        cin >> m;
        int number[m];
        for(int i=0; i<m; i++) cin >> number[i];
        sort(number,number+m,cmp);
        for(int i=1; i<m; i++)
        {
            number[0] += number[i]/2;
        }
        cout << number[0] << endl;
    }
    return 0;
}
