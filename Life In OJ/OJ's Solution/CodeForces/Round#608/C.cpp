#include <bits/stdc++.h>
using namespace std;

struct NODE {
	int x,y;
	NODE() {}
	NODE(int x,int y):x(x),y(y) {}
	bool operator<(const NODE& oth) const {
		if(oth.y == y) return x < oth.x;
		return y < oth.y;
	}
	void display() {cout << x << " " << y << endl;}
};

map<NODE,int> t;
vector<NODE> arr;
int dirx[4] = {0,1,0,-1};
int diry[4] = {1,0,-1,0};
const int maxn = 1e9;

int main() {
	//imp
	std::ios::sync_with_stdio(false);
	int n,x,y;
	cin >> n >> x >> y;
	NODE sc{x,y};
	for(int i=0; i<n; i++) {
		cin >> x >> y;
		NODE now{x,y};
		if(!t[now]) arr.push_back(now);
		t[now]++;
	}
	int ans = 0;
	NODE out;
	for(int k=0; k<4; k++) {
		x = sc.x + dirx[k];
		y = sc.y + diry[k];
		if(x>=0 && x<=maxn && y>=0 && y<=maxn) {
			int bs = abs(sc.x - x) + abs(sc.y - y);
			int tmp = 0;
			for(NODE n: arr) {
				int dist1 = abs(n.x - sc.x) + abs(n.y - sc.y);
				int dist2 = abs(n.x - x) + abs(n.y - y);
				if(dist1 == dist2 + bs) {
					tmp+=t[n];
				}
			}
			if(tmp > ans) {
				ans = tmp;
				out.x = x;
				out.y = y;
			}
		}
	}
	cout << ans << endl;
	out.display();
	return 0;
}
