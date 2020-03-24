/* 
 * Autor: Mirasire 
 * GithubRepo: https://github.com/Mirasire/icpc-train/
 * Tag: Z Algorithm (Extended KMP) 
 * ----------------------
 * Example: LuoGu P5410
 */
const int maxn = 2e7+100;
int z[maxn],extd[maxn];
char p[maxn],t[maxn];
void getZFunc(int n) {
	int l=0,r=0;
	z[0]=n;
	for(int i=1; i<n; i++) {
		if(i<=r) z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n&&p[z[i]]==p[i+z[i]]) z[i]++;
		if(i+z[i]-1>r) l=i,r=z[i]+i-1;
	}
}
void getExtd(int m,int n) {
	getZFunc(n);
	int l=0,r=0;
	for(int i=0; i<m; i++) {
		//!important! if i<=r will Wrong
		//becase if i<=r when i = 0 it will be not correct
		if(i<r) extd[i]=min(r-i+1,z[i-l]);
		while(extd[i]<n&&i+extd[i]<m&&p[extd[i]]==t[i+extd[i]]) extd[i]++;
		if(i+extd[i]-1>r) l=i,r=extd[i]+i-1;
	}
}
