//uni[maxn][3] miao~a!
#include <bits/stdc++.h>
using namespace std;

#define mkp make_pair
#define pbk push_back
#define fi first
#define se second
#define pir pair<int,int>

const int maxn = 2e5+100;
int f[maxn],ans[maxn],n,m,ccnt,ttm;
pir p[maxn];
bool vis[maxn],uni[maxn][3];

vector<int> e[maxn];
void dfs(int a) {
	if(vis[a]) return;
	vis[a]=1; ans[a]=ttm; ccnt++;
	int end=e[a].size();
	for(int i=0; i<end; i++) {
		int& b=e[a][i];
		if(vis[b]) continue;
		dfs(b);
	}
}

int find(int a) {
	int r=a,tp;
	while(f[a]!=a) a=f[a];
	while(f[r]!=a) {
		tp=f[r];
		f[r]=a;
		r=tp;
	}
	return a;
}

void merge(int a,int b) {
	int fa=find(a),fb=find(b);
	if(fa==fb) return;
	if(fa==1) {
		f[fb]=fa;
		dfs(fb);
	}
	else if(fb==1) {
		f[fa]=fb;
		dfs(fa);
	} else {
		f[fb]=fa;
	}
}

vector<pir> tmp;
int main() {
	std::ios::sync_with_stdio(false);
	int a,b;
	cin >> n >> m;
	ccnt=0;
	for(int i=0; i<=n; i++) f[i]=i,ans[i]=-1,uni[i][1]=uni[i][2]=1;
	for(int i=1; i<=n; i++) cin >> p[i].fi >> p[i].se;
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		uni[a][b]=0;
		tmp.pbk(mkp(a,b));
	}
	ttm=-1;
	ans[1]=-1,vis[1]=1;
	for(int i=1; i<=n; i++) {
		int &j1 = p[i].fi;
		int &j2 = p[i].se;
		if(uni[i][1]&&j1!=-1) {
			//cout << "i="<< i << " " << "j1=" << j1<< endl;
			merge(i,j1);
			e[i].pbk(j1); e[j1].pbk(i);
		}
		if(uni[i][2]&&j2!=-1) {
			//cout << "i="<< i << " " << "j2=" << j2<< endl;
			merge(i,j2);
			e[i].pbk(j2); e[j2].pbk(i);
		}
	}
	int u,v,k;
	for(int i=m-1; i>=0; i--) {
		ttm=i;
		u = tmp[i].fi,k = tmp[i].se;
		if(k==1) {
			v=p[u].fi;
			e[u].pbk(v); e[v].pbk(u);
			merge(u,v);
		} else {
			v=p[u].se;
			e[u].pbk(v); e[v].pbk(u);
			merge(u,v);
		}
	}
	for(int i=1; i<=n; i++) cout << ans[i] << endl;
	return 0;
}
