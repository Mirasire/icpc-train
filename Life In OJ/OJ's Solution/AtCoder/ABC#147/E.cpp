//AC -- 68ms
#include <bits/stdc++.h>
using namespace std;

int dir[2][2] = {{0,1},{1,0}};
const int maxn = 85;
int t[maxn][maxn];
long long ans;

struct STA {
	int x,y;
	long long val;
	STA() {}
	STA(int x,int y,int val):x(x),y(y),val(val) {}
	void display() {
		cout << x << " " << y << endl;
	}
};
bool app[maxn][maxn][13000];

int H,W;
inline bool isIn(int x,int y) {
	return (x>=1 && x<=H && y>=1 && y<=W);
}

void bfs(int x,int y) {
	STA now;
	queue<STA> list;
	list.push({x,y,t[x][y]});
	while(!list.empty()) {
		now = list.front();
		list.pop();
		if(now.x == H && now.y == W) ans = min(now.val,ans);
		else {
			if(app[now.x][now.y][now.val]) continue;
			app[now.x][now.y][now.val] = 1;
			for(int i=0; i<2; i++) {
				x = now.x + dir[i][0];
				y = now.y + dir[i][1];
				if(isIn(x,y)) {
					list.push({x,y,now.val+(long long int)t[x][y]});
					list.push({x,y,abs(now.val-(long long int)t[x][y])});
				}
			}
		}
	}
}

int main() {
	int tp;
	ans = INT_MAX;
	cin >> H >> W;
	for(int i=1; i<=H; i++)
		for(int j=1; j<=W; j++)
			cin >> t[i][j];
	for(int i=1; i<=H; i++)
		for(int j=1; j<=W; j++) {
			cin >> tp;
			t[i][j] = abs(tp-t[i][j]);
		}
	bfs(1,1);
	cout << ans << endl;
	return 0;
}
