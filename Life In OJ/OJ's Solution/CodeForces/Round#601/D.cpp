#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

#define debug(x) printf(#x " = %d\n",x);

string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const int maxn = 1e2 + 100;
char fr[maxn][maxn];
bool vis[maxn][maxn];
char out[maxn][maxn];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int r,c,k;
int remain = 0;
struct NODE{
	int x,y;
	NODE() {}
	NODE(int x,int y):x(x),y(y) {}
	void init(int a,int b) { x=a;y=b; }
};

void dfs(int x,int y,char c) {
	if(remain==0) return;
	else if(x>0 && x <r && y>0 && y<c && !vis[x][y]) return;
	vis[x][y] = 1;
	remain--;
	out[x][y] = c;
	for(int i=0; i<4; i++) {
		dfs(x+dir[i][0],y+dir[i][1],c);
	}
	return;
}

void bfs(int x,int y,int& cnt,int idx) {
	NODE now;
	now.init(x,y);
	out[x][y] = str[idx];
	cnt--;
	remain--;
	queue<NODE> list;
	list.push(now);
	while(!list.empty()) {
		now = list.front();
		list.pop();
		for(int i=0; i<4; i++) {
			x = now.x + dir[i][0];
			y = now.y + dir[i][1];
			if(x>0 && x <r && y>0 && y<c && !vis[x][y]) {
				remain--;
				vis[x][y] = 1;
				out[x][y] = str[idx];
				list.push(NODE(x,y));
				cnt--;
				if(cnt==0) break;
			}
		}
		if(cnt==0) break;
	}
}

int main() {
	int t;
	int numr;
	scanf("%d",&t);
	while(t--) {
		numr = 0;
		vector<NODE> list;
		scanf("%d%d%d",&r,&c,&k);
		for(int i=0; i<r; i++) {
			scanf(" %s",fr[i]);
			for(int j=0; j<c; j++) if(fr[i][j]=='R') {
				list.push_back(NODE(i,j));
				numr++;
			}
		}
		int mk = numr%r;
		int bt = numr/r;
		//start slove
		remain = r*c;
		//up is init
		int cnt=0;
		for(int i=0; i<numr; i++) {
			int mmbt = bt+1;
			int mbt = bt;
			NODE& nn = list[i];
			if(i<mk && !vis[nn.x][nn.y]) bfs(nn.x,nn.y,mmbt,cnt++);
			else if(!vis[nn.x][nn.y]) bfs(nn.x,nn.y,mbt,cnt++);
		}
		debug(cnt);
		for(int i=0; i<numr; i++) {
			NODE& nn = list[i];
			if(remain == 0) break;
			dfs(nn.x,nn.y,out[nn.x][nn.y]);
		}
		for(int i=0; i<r; i++) {
			for(int j=0; j<c; j++) {
				printf("%c",out[i][j]);
			}
			putchar('\n');
		}
	}
	return 0;
}
