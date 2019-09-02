#include <cstring>
#include <iostream>
using namespace std;
 
int main() {
	string in;
	long long sum = 0;
	cin >> in;
	long long end = in.size();
	bool flag = 0;
	for (long long i = 1; i < end; i++) {
		if (in[i] == '1') {
			//sum += 1;
			flag = 1;
			break;
		}
	}
	sum += (in.size()-1) / 2;
	if(+(in.size() - 1) % 2 || flag) sum += 1;
	cout << sum << endl;
}
