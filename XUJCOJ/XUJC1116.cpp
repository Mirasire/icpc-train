#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int in;
        cin >> in;
        while(in > 9)
        {
            int temp = in % 10;
            in = in/10+temp;
        }
        cout << in << endl;
    }
    return 0;
}

        


