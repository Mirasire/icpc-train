#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+100;
struct RANGE {
	int tx,ty,dx,dy;
} ra[maxn];

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	int x,y,w,h;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> ra[i].dx >> ra[i].dy >> w >> h;
		ra[i].tx = ra[i].dx + w;
		ra[i].ty = ra[i].dy + h;
	}
	cin >> x >> y;
	for(int i=n-1; i>=0; i--) {
		if(x>=ra[i].dx && x<=ra[i].tx && y>=ra[i].dy && y<=ra[i].ty) {
			cout << (i+1) << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
