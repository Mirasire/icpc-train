//AC
//输出精度有毛病的题目
//题目大意: 寻找所有可行解中的，最小的最大边。
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

const int maxn = 220;
int x[maxn],y[maxn];
double gph[maxn][maxn];
int n;

void floyd() {
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				gph[i][j] = min(gph[i][j],max(gph[i][k],gph[k][j]));
}

int main() {
	int cnt = 0;
	while(~scanf("%d",&n)) {
		if(!n) break;
		for(int i=1; i<=n; i++) scanf("%d%d",x+i,y+i);
		for(int i=1; i<=n; i++) 
			for(int j=i+1; j<=n; j++) 
				gph[i][j] = gph[j][i] = sqrt(pow(1.0*(x[i]-x[j]),2) + pow(1.0*(y[i]-y[j]),2));
		floyd();
		printf("Scenario #%d\n",++cnt);
		printf("Frog Distance = %.3f\n\n",gph[1][2]);
	}
	return 0;
}
