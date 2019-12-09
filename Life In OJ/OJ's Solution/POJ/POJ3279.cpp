//AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 20;
int n,m;
int mazz[maxn][maxn],grid[maxn][maxn],ans[maxn][maxn];
int dir[5][2] = {{0,0},{1,0},{0,1},{-1,0},{0,-1}};

bool legal(int x,int y) { return (x>=0 && x<n && y>=0 && y<m); }

void filp(int x,int y) {
	ans[x][y] = 1;
	int nx,ny;
	for(int i=0; i<5; i++) {
		nx = x + dir[i][0];
		ny = y + dir[i][1];
		if(legal(nx,ny)) grid[nx][ny]^=1;
	}
}

void slove() {
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) 
			printf("%d%c",ans[i][j]," \n"[j==(m-1)]);
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d",&mazz[i][j]);
	int end = 1<<m,bsk;
	bool ok = 1;
	for(int i=0; i<end; i++) {
		ok = 1;
		bsk = i;
		memcpy(grid,mazz,sizeof(mazz));
		memset(ans,0,sizeof(ans));

		//玄学字典序？？？
		for(int k=0; k<m; k++) {
			if(bsk%2) filp(0,k);
			bsk/=2;
		}
		for(int j=1; j<n; j++) {
			for(int k=0; k<m; k++) {
				if(grid[j-1][k]) filp(j,k);
			}
		}
		for(int k=0,j=n-1; k<m; k++) 
			if(grid[j][k]) {
				ok = 0;
				continue;
			}
		if(ok) {
			slove();
			break;
		}
	}
	if(!ok) printf("IMPOSSIBLE\n");
	return 0;
}
