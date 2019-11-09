#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 1e2+50;
int n,m,s,t;
char mp[maxn][maxn];
int cap[maxn][maxn],dis[maxn][maxn],cur[maxn][maxn];

int main() {
	while(~scanf("%d%d",&n,&m)) {
		s = 101,t = 102;
		if(!n || !m) break;
		for(int i=0; i<n; i++) scanf(" %s",mp[i]);
		for(int i=1; i<n; i++)
			for(int j=0; j<m; j++) {
				char cu = mp[i-1][j],cd = mp[i][j];
				if(cu == cj && )
			}
	}
	return 0;
}
