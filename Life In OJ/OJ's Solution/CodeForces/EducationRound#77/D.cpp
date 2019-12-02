#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int Pmaxn = 2e5+100;
int soldier[Pmaxn],m,n,k,t;

struct TRAP {
	int l,r,d;
	bool operator < (const struct& o) {
		return o.l==l? r < o.r : l < o.l;
	}
};

int check(int mini) {
}

int binary_search(int val) {
}

int main() {
	scanf("%d%d%d%d",&m,&n,&k,&t);
	for(int i=0; i<m; i++) scanf("%d",&soldier[i]);
	sort(soldier,soldier+m);
	return 0;
}
