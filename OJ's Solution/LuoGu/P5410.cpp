//try a try , more TLE is close to AC
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e7+100;
int z[maxn],extd[maxn];
char p[maxn],t[maxn];
typedef long long int ll;

inline void write(ll x)
{
    if(x<0) {
        putchar('-');
        x = -x;
    }
    if(x>9) write(x / 10);
    putchar(x % 10 + '0');
}

void getZFunc(int n) {
	int l=0,r=0;
	z[0]=n;
	ll ans=(z[0]+1)*1;
	for(int i=1; i<n; i++) {
		if(i<=r) z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n&&p[z[i]]==p[i+z[i]]) z[i]++;
		ans^=1ll*(i+1)*(z[i]+1);
		if(i+z[i]-1>r) l=i,r=z[i]+i-1;
	}
	write(ans);
	cout << endl;
}

void getExtd(int m,int n) {
	ll ans=0;
	getZFunc(n);
	int l=0,r=0;
	for(int i=0; i<m; i++) {
		//!important! if i<=r will Wrong
		//becase if i<=r when i = 0 it will be not correct
		if(i<r) extd[i]=min(r-i+1,z[i-l]);
		while(extd[i]<n&&i+extd[i]<m&&p[extd[i]]==t[i+extd[i]]) extd[i]++;
		ans^=1ll*(i+1)*(extd[i]+1);
		if(i+extd[i]-1>r) l=i,r=extd[i]+i-1;
	}
	write(ans);
	cout << endl;
}

int main() {
	int n,m;
	scanf("%s",t);
	scanf("%s",p);
	m=strlen(t);
	n=strlen(p);
	getExtd(m,n);
	return 0;
}
