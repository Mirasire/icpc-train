#include <bits/stdc++.h>
using namespace std;

map<char,int> v;
const int maxn = 1e5+100;
int z[maxn],extd[maxn];
char s[30],p[maxn],t[maxn];

void getZFunc(int n) {
	for(int i=0; i<=n; i++) z[i]=0;
	int l=0,r=0;
	for(int i=1; i<n; i++) {
			if(i<r) z[i]=min(r-i+1,z[i-l]);
			while(i+z[i]<n&&p[z[i]]==p[i+z[i]]) z[i]++;
			if(i+z[i]-1>r) l=i,r=i+z[i]-1;
		}
}

void getExtd(int m) {
	int l=0,r=0;
	for(int i=0; i<=m; i++) extd[i]=0;
	getZFunc(m);
	for(int i=0; i<m; i++) {
			if(i<r) extd[i]=min(r-i+1,z[i-l]);
			while(i+extd[i]<m&&p[extd[i]]==t[i+extd[i]]) extd[i]++;
			if(i+extd[i]-1>r) l=i,r=i+extd[i]-1;
		}
}

void slove(int m) {
	for(int i=0; i<26; i++) v[s[i]]=i;
	for(int i=0; i<m; i++) p[i]=(char)('a'+v[t[i]]);
	p[m]='\0';
	getExtd(m);
	int j=(m+1)/2;
	for(; j<m; j++) {
			if(extd[j]==(m-j)) {
						for(int i=0; i<j; i++) putchar(t[i]);
						for(int i=0; i<j; i++) putchar((char)('a'+v[t[i]]));
						putchar('\n');
						return;
					}
		}
	printf("%s%s\n",t,p);
}

int main() {
	int T,m;
	scanf("%d",&T);
	while(T--) {
			scanf("%s",s);
			scanf("%s",t);
			m=strlen(t);
			slove(m);
		}
	return 0;
}
