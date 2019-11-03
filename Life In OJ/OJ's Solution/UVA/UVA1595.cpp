//AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;

const int maxn = 1200;
struct Node {
	int x,y;
}node[maxn];
int m,a,b;

bool cmp_x(Node a, Node b) {
	return a.x < b.x;
}

int main() {
	int n,cnt=0;
	bool flag;
	cin >> n;
	while(n--) {
		cin >> m;
		for(int i=0; i<m; i++) scanf("%d%d",&node[i].x,&node[i].y);
		sort(node,node+m,cmp_x);
		int tar = node[0].x + node[m-1].x;
		map<int,bool> app;
		for(int i=0; i<m; i++) {
			if(node[i].x*2 == tar || app[i])  continue;
			flag = 1;
			for(int j=i+1; j<m; j++) {
				if(node[j].y==node[i].y && (node[j].x+node[i].x) == tar) {
					app[j] = 1;
					flag = 0;
					break;
				} 
			}
			if(flag) {
				cout << "NO\n";
				break;
			}
		}
		if(flag) continue;
		cout << "YES\n";
	}
	return 0;
}

