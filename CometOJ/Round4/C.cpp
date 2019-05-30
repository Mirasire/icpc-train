#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1e3+20;
char maze[maxn][maxn];
int t[maxn][maxn];
char eol[] = " \n";

int main(){
    int T;
    scanf("%d",&T);
    memset(t,0,sizeof(t));
    while(T--){
        vector<int> ans;
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0; i<n; i++)  scanf("%s",maze[i] +1);
        /*1*/
        for(int r=1; r<=n; r++){
            for(int c=1; c<=n; c++){
                t[r][c] = t[r-1][c] + t[r][c-1] - t[c-1][r-1] + (maze[r][c] == '0');
            }
        }
        if(!t[n][m]){
            for(int i=1; i<=k; i++){
                printf("%d%c",i,eol[i==k]);
            }
            continue;
        }
        for(int a=0; a<=k && a<n; a++){
            int b = k-a;
            if(b < 0 || b >= m) continue;
            if(t[n][m] % ((a+1)*(b+1))) continue;
            int avg = t[n][m] / ((a+1)*(b+1));
            int row_avg = t[n][m] / (a+1);
            int col_avg = t[n][m] / (b+1);
            vector<int> r,c;
            int ir = 0,ic = 0;
            for(int i=0; i<= n; i++){
                if(t[i][m] % row_avg == 0 && t[i][m] / row_avg == ir){
                    ir++;
                    r.push_back(i);
                }
            }
            if(ir != a+2) continue;
            for(int i=0; i<= m; i++){
                if(t[n][i] % col_avg == 0 && t[n][i] / col_avg == ic){
                    ic++;
                    c.push_back(i);
                }
            }
            if(ic != b+2) continue;

            bool flag = 1;
            for(int i=1; i<ir&&flag; i++){
                for(int j=1; j<ic&&flag; j++){
                    int sum = t[r[i]][c[j]] - t[r[i-1]][c[j]] - t[r[i]][c[j-1]] + t[r[i-1]][c[j-1]];
                    flag = (sum == avg);
                }
            }
            if(flag){
                vector<int> tmp;
                for(int i=1; i<ir; i++) tmp.push_back(r[i]);
                for(int i=1; i<ic; i++) tmp.push_back(c[i] + n -1);
                if(ans.empty() || ans > tmp) ans = tmp;
            }
        }
        if(ans.empty()) printf("Impossible\n");
        else {
            for(int i=0; i<k; i++) printf("%d%c",ans[i],eol[i==(k-1)]);
        }
    }
    return 0;
}

                    
