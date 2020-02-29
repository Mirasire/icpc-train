#include <bits/stdc++.h>
using namespace std;

struct NODE {
	int p,sta;
	NODE() {}
	NODE(int p,int sta):p(p),sta(sta) {}
};
const int maxn = 20;
bool k[maxn];
vector<NODE> A[maxn];

int main() {
	int n,m,MM = 0;
	scanf("%d",&n);
	int end = 1<<n;
	for(int i=1; i<=n; i++) {
		scanf("%d",&m);
		for(int j=1; j<=m; j++) {
			int a,b;
			scanf("%d%d",&a,&b);
			A[i].push_back({a,b});
		}
	}
	int tmp = 0,tmax;
	bool ok;
	for(int i=0; i<end; i++) {
		tmp = i;
		tmax = 0;
		ok = 1;
		for(int j=1; j<=n; j++) {
			k[j] = tmp%2;
			tmax+=k[j];
			tmp/=2;
		}
		if(tmax <= MM) continue;
		//cout << "-------------\n";
		for(int j=1; j<=n; j++) {
			if(k[j]) for(NODE now: A[j]) {
				//cout <<now.p << " "<< now.sta << endl;
				if(k[now.p] != now.sta) {
					ok = 0;
					break;
				}
			}
			if(!ok) break;
		}
		if(ok) {
			//for(int j=1; j<=n; j++) printf("%d%c",k[j]," \n"[j==n]);
			MM = max(MM,tmax);
		}
	}
	printf("%d\n",MM);
	return 0;
}
