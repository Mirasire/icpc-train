#include <cstdio>
#include <algorithm>
using namespace std;

int mp[12][12];

int main() {
    int n,m,tmp1,tmp2;
    scanf("%d%d",&n,&m);

    for(int i=1; i<=m; i++) {
        scanf("%d%d",&tmp1,&tmp2);
        mp[tmp1][tmp2] = mp[tmp2][tmp1] = 1;
    }
    if(n<=6) {
        printf("%d",m);
        return 0;
    }
    int res = 56;
    for(int i=1; i<=7; i++) {
        for(int j=i+1; j<=7; j++) {
            int cnt = 0;
            for(int k=1; k<=7; k++) {
                if(mp[i][k]&&mp[j][k]) cnt++;
            }
            res = min(res,cnt);
        }
    }
    printf("%d",m-res);
    return 0;
}
