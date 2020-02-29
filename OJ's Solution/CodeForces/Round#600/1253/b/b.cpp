//You can find the repo on https://github.com/mirasire
//Author: Mes2Dasuan
//Time: 2019-11-27 08:55:08

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<int,bool> app;
vector<int> ans;

int main() {
	int n,tmp,cnt=0;
	long long int sum=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&tmp);
		sum += tmp;
		if(sum < 0 || (tmp>0 && app[tmp]) || (tmp<0 && !app[-tmp])) {
			printf("-1\n");
			return 0;
		}
		cnt++;
		if(sum==0) {
			ans.push_back(cnt);
			app.clear();
			cnt=0;
		}
		if(tmp > 0) app[tmp] = 1;
	}
	if(sum != 0) {
		printf("-1\n");
		return 0;
	}
	int size = ans.size();
	printf("%d\n",ans.size());
	for(int i=0; i<size; i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
