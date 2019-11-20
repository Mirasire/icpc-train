#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int maxn=1e5+100;
vector<int> a[maxn];
bool vis[maxn];
int cnt[maxn];

int main() {
	int n;
	int x,y,z;
	scanf("%d",&n);
	for(int i=0; i<n-2; i++) {
		scanf("%d%d%d",&x,&y,&z);
		a[x].push_back(y);a[x].push_back(z);
		a[y].push_back(x);a[y].push_back(z);
		a[z].push_back(x);a[z].push_back(y);
		cnt[x]++;cnt[y]++;cnt[z]++;
	}
	for(int i=1; i<=n; i++)  {
		if(cnt[i]==1) 	x = i;
	}
	if(cnt[a[x][0]] == 2)  y=a[x][0];
	else y=a[x][1];
	printf("%d %d",x,y);
	vis[x] = vis[y] = 1;
	for(int i=n-2; i>0; i--) {
		for(int j=0; j<a[x].size(); j++) {
			if(!vis[a[x][j]]) z = a[x][j];
		}
		vis[z] = 1;
		printf(" %d",z);
		x = y;
		y = z;
	}
	return 0;
}
