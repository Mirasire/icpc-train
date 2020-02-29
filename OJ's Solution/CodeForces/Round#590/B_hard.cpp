#include <queue>
#include <set>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdio>
#include <map>
using namespace std;

int main() {
	int n,k,tmp,size = 0;
	set<int> s;
	queue<int> list;
	stack<int> ans;
	map<int,bool> app;
	scanf("%d%d",&n,&k);
	while(n--) {
		scanf("%d",&tmp);
		if(size == k) {
			if(!app[tmp]) {
				app[list.front()] = 0;
				list.pop();
				app[tmp] = 1;
				list.push(tmp);
			} 
		}
		else if(!app[tmp]) {
			size++;
			app[tmp] = 1;
			list.push(tmp);
		}
	}
	int anss = 0;
	while(!list.empty()) {
		anss++;
		ans.push(list.front());
		list.pop();
	}
	printf("%d\n",anss);
	while(!ans.empty()) {
		printf("%d ",ans.top());
		ans.pop();
	}
	return 0;
}
