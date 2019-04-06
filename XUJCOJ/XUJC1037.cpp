#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double x[2],y[2],r[2];
    int n;
    cin >> n;
    while(n--)
    {
        for(int i=0; i<2; i++) cin >> x[i] >> y[i] >> r[i];
        double miner = pow((r[1]-r[0]),2);
        double equal = pow(r[1]+r[0],2);
        double distance = pow(x[0]-x[1],2) + pow(y[0]-y[1],2);
        if(miner==0 && distance == 0) cout << "-1";
        else if(distance < miner) cout << 0;
        else if(distance == equal) cout << 3;
        else if(distance == miner) cout << 1;
        else if(distance > equal) cout << 4;
        else cout << 2;
        cout << endl;
    }
    return 0;
}
