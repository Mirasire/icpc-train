#include <queue>
#include <set>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	int n,k,tmp;
	set<int> s;
	queue<int> list;
	stack<int> ans;
	cin >> n >> k;
	while(n--) {
		cin >> tmp;
		if(list.size() == k) {
			if(!s.count(tmp)) {
				s.erase(list.front());
				list.pop();
				s.insert(tmp);
				list.push(tmp);
			} 
		}
		else if(!s.count(tmp)) {
			s.insert(tmp);
			list.push(tmp);
		}
	}
	int anss = 0;
	while(!list.empty()) {
		anss++;
		ans.push(list.front());
		list.pop();
	}
	cout << anss << endl;
	while(!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}
	return 0;
}
