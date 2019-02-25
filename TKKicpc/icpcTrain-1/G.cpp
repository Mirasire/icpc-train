#include <iostream>
#define prtInt(x) printf(#x "= %d\n",x);
#define LOCAL
using namespace std;

int main()
{
#ifdef LOCAL
freopen("in","r",stdin);
freopen("out","w",stdout);
#endif
    int T;
    cin >> T;
    while(T--)
    {
        int x[2],y[2],w[2],h[2];
        for(int i=0; i<2; i++) cin >> x[i] >> y[i] >> w[i] >> h[i];
        int allX = w[0]+w[1];
        int allY = h[0]+h[1];
        int maxX = max(x[0]+w[0],x[1]+w[1]) - min(x[0],x[1]);
        int maxY = max(y[0]+h[0],y[1]+h[1]) - min(y[0],y[1]);
        if(maxX >= allX || maxY >= allY)
            cout << "0.00" << endl;
        else
        {
            //prtInt(maxX);
            //prtInt(maxY);
            int overlapX = allX - maxX;
            int overlapY = allY - maxY;
            int overArea = overlapY*overlapX;
            int unionArea = w[0]*h[0]+w[1]*h[1]-overArea;
            printf("%.2f\n",1.0*overArea/unionArea);
        }
    }
    return 0;
}
