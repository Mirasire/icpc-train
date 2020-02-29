//匈牙利算法
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 1e5+100;
int line[maxn][12],size[12],cnt[12],match[12][maxn],n,m;
int vis[12];

bool dfs(int u) {
	for(int i=1; i<=m; i++) {
		if(line[u][i] && !vis[i]) {
			vis[i] = 1;
			if(size[i] > cnt[i]) {
				match[i][cnt[i]++] = u;
				return 1;
			} else {
				for(int j=0; j<cnt[i]; j++) {
					if(dfs(match[i][j])) {
						match[i][j] = u;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

int main() {
	//tmp_var init
	int i,j;
	bool flag;

	//slove()
	while(~scanf("%d%d",&n,&m)) {
		memset(cnt,0,sizeof(cnt));
		for(i=1; i<=n; i++) {
			for(j=1; j<=m; j++) {
				scanf("%d",&line[i][j]);
			}
		}
		for(i=1; i<=m; i++) scanf("%d",size+i);
		flag = 0;
		for(i=1; i<=n; i++) {
			memset(vis,0,sizeof(vis));
			flag = dfs(i);
			if(!flag) break;
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
