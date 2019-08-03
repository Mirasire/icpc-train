//2130ms AC
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int size;
vector<string> cip;
int res[20];
bool vis[20],flag;

bool friday(int y,int m,int d)  //蔡勒公式 1580->至今 年月日->星期
{
    if (m <= 2)
    {
        y--; m += 12;
    }
    return (5 == (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7 + 1);
}

bool check() {
    for(int i=0; i<size; i++) {
        int yyyy = 1000*res[cip[i][0]-'A'] + 100*res[cip[i][1]-'A']+10*res[cip[i][2]-'A']+res[cip[i][3]-'A'];
        int mm = 10*res[cip[i][5]-'A']+res[cip[i][6]-'A'];
        int dd = 10*res[cip[i][8]-'A']+res[cip[i][9]-'A'];
        if(yyyy<1600||mm>12||dd>31) return false;
        if(!friday(yyyy,mm,dd)) return false;
    }
    return true;
}

void dfs(int index) {
    if(flag) return;
    if(index >= 10) {
        if(check()) {
            for(int i=0; i<10; i++) {
                cout << res[i];
            }
            cout << endl;
            flag = 1;
        }
        return;
    }

    for(int i=0; i<10; i++) {
        if(!vis[i]) {
            res[index] = i;
            vis[i] = 1;
            dfs(index+1);
            vis[i] = 0;
        }
    }
}
int main() {
    //freopen("in","r",stdin);
    int t,n,m,kase=0;
    scanf("%d",&t);
    while(t--) {
        printf("Case #%d: ",++kase);
        scanf("%d",&n);
        cip.clear();
        memset(vis,0,sizeof(vis));
        string in;
        while(n--) {
            cin >> in;
            cip.push_back(in);
        }
        sort(cip.begin(),cip.end());
        auto end_t = unique(cip.begin(),cip.end());
        cip.erase(end_t,cip.end());
        size = cip.size();
        flag = 0;
        dfs(0);
        if(!flag) cout << "Impossible\n";
    }
    return 0;
}

