//big heap
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int maxn = 1e5+100;
int heap[maxn<<3];
int arr[maxn],cnt;

void init() {
	memset(heap,-1,sizeof(heap));
	cnt = 1; //idx base 1
}

void up(int idx) {
	int now = idx,par = idx/2;
	while(par) {
		par = now/2;
		if(heap[par] < heap[now]) swap(heap[par],heap[now]);
		now/=2;
	}
}

void down(int idx) {
	int now = idx;
	int lc,rc,maxx,di;
	//It is a erro version
	while(heap[now] != -1) {
		di = indx<<1;
		lc = di; rc = di|1;
		if(max(heap[lc],heap[rc]) > heap[now]) {
			if(heap[rc] > heap[lc]) di = rc;
			swap(heap[di],heap[now]);
			now = di;
		} else {
			break;
		}
	}
}

int main() {
	int n;
	cout << "Please input the arr's Size: ";
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	return 0;
}
