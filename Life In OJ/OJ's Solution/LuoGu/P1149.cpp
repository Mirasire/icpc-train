#include <bits/stdc++.h>
using namespace std;

int cost[10] = {6,2,5,5,4,5,6,3,7,6};
typedef long long int ll;
map<pair<pair<int,int>,int>,bool> app;

ll getNum(vector<int> arr,int a,int b) {
	int res = 0;
	//Imp 前导零的情况
	if(b-a>=1 && arr[a]==0) return -1;
	for(int i=a; i<=b; i++) {
		res*=10; res+=arr[i];
	}
	return res;
}

int dealWith(vector<int> arr) {
	int size = arr.size();
	if(size < 3) return 0;
	int cnt = 0;
	ll a,b,c;
	for(int i=1; i<size-1; i++) {
		for(int j=i+1; j<size; j++) {
			a = getNum(arr,0,i-1);
			b = getNum(arr,i,j-1);
			c = getNum(arr,j,size-1);
			if(a==-1 || b==-1 || c==-1) continue;
			else if(a+b == c && !app[make_pair(make_pair(a,b),c)]) {
				//cout << a << "+" << b << "=" << c << endl;
				app[make_pair(make_pair(a,b),c)] = 1;
				cnt++;
			}
		}
	}
	return cnt;
}

int ans = 0;
void slove(vector<int> arr,int size) {
	if(size==0) {
		ans+=dealWith(arr);
		return;
	}
	else if(size<0) return;
	arr.push_back(-1);
	for(int i=0; i<10; i++) {
		arr.back() = i;
		slove(arr,size-cost[i]);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int num;
	cin >> num;
	num -= 4;
	vector<int> arr;
	slove(arr,num);
	cout << ans << endl;
	return 0;
}
