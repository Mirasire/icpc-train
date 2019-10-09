#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define prt(x) printf(#x " = %d\n",x)

const int maxn = 2e5+100;
int p[maxn],h,n;
int ct[maxn];

int main() {
	int t,cnt,i,j,p_now,con;
	int tmp;
	scanf("%d",&t);
	while(t--) {
		//init
		cnt = 0;

		scanf("%d%d",&h,&n);

		p[0] = 0;
		for(int i=n-1; i>=0; i--) scanf("%d",p+i);
		for(int i=0; i<n; i++) 
			ct[i] = (i && p[i] == p[i-1]+1)? ct[i-1]+1 : 0;

		j = n-1;
		p_now = p[j];

		while(j) {
			if(p_now <= 2) break;

			con = (p_now == p[j]);
			//TODO
			if(p_now-1 == p[j]) con = ct[j]+1;

			if(j==0) break;
			if(con) {
				//TODO
				tmp = (con+1)/2;
				p_now = p_now - tmp*2;
				cnt += con%2;
				j -= tmp*2;
			}
			else if(p_now - p[j-1] == 2) {
				p_now = p[--j];
			}
			else {
				//cout << 2 << endl;
				cnt++;
				p_now = p[--j];
			}
		}
		cout << endl;
		printf("%d\n",cnt);
		cout << endl;
	}
	return 0;
}
