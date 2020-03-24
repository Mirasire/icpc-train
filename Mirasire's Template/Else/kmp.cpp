/* 
 * Autor: Mirasire 
 * GithubRepo: https://github.com/Mirasire/icpc-train/
 * Tag: KMP
 *
 */
const int maxn = 1e3+100;
int n,nxt[maxn];
char p[maxn],s[maxn];
void getMax() {
	int i=0,j=-1;
	nxt[0]=-1;
	while(i<n) {
		if(j==-1||p[i]==p[j]) {
			i++,j++;
			nxt[i]=j;
			//optimization
			//nxt[i]= (p[i]==p[j])? nxt[j] : j;
		} else {
			j=nxt[j];
		}
	}
}
