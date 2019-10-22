#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
using namespace std;

const int maxn = 2e2;
set<int> s[maxn];

int main() {
	int n;
	int t;
	scanf("%d",&n);
	while(n--) {
		for(int i=0; i<maxn; i++) s[i].clear();
		int  cnt = 0,tmp;
		scanf("%d",&t);
		for(int i=0; i<t; i++) {
			scanf("%d",&tmp);
			bool flag = 1;
			for(int i=0; i<cnt; i++) {
				if(s[i].count(tmp-1) || s[i].count(tmp+1)) continue;
				s[i].insert(tmp);
				flag=0;
				break;
			}
			if(cnt==0 || flag) s[cnt++].insert(tmp);
		}
		printf("%d\n",cnt);
	}
	return 0;
}
