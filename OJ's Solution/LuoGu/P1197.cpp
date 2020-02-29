//逆向解题
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+100;
int f[maxn],ccnt;
bool vis[maxn];
vector<int> o,e[maxn];

int find(int u) {
	int a=u,tp;
	while(f[a]!=a) a=f[a];
	while(f[u]!=a) {
		tp=f[u];
		f[u]=a;
		u=tp;
	}
	return a;
}

int merge(int a) {
	int end=e[a].size(),fa=find(a),fb;
	int cnt=0;
	for(int i=0; i<end; i++) {
		int& b=e[a][i];
		if(vis[b]) {
			fb=find(b);
			if(fa!=fb) {
				f[fb]=fa;
				cnt++;
			}
		}
	}
	return cnt;
}

stack<int> ans;
int main() {
	std::ios::sync_with_stdio(false);
	int n,m,k;
	int u,v;
	cin >> n >> m;
	for(int i=0; i<n; i++) f[i]=i,vis[i]=1;
	for(int i=0; i<m; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	cin >> k;
	for(int i=0; i<k; i++) {
		cin >> u; vis[u]=0;
		o.push_back(u);
	}
	ccnt = max(0,n-k);
	for(int i=0; i<n; i++) {
		if(vis[i]) ccnt-=merge(i);
	}
	ccnt = max(0,ccnt);
	ans.push(ccnt);
	for(int i=k-1; i>=0; i--) {
		ccnt++;
		ccnt-=merge(o[i]);
		vis[o[i]]=1;
		ans.push(ccnt);
	}
	while(!ans.empty()) {
		cout << ans.top() << endl;
		ans.pop();
	}
	return 0;
}
