//AC Tips:strictly bigger than
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
using namespace std;

stack<int> st;
typedef long long int ll;

int main() {
	ll tmp,n;
	ll res = 0,size = 0;
	scanf("%lld",&n);
	while(n--) {
		scanf("%lld",&tmp);
		while(!st.empty() && tmp >= st.top()) {
			st.pop();
			size--;
		}
		st.push(tmp);
		res+=size;
		size++;
	}
	printf("%lld\n",res);
	return 0;
}
