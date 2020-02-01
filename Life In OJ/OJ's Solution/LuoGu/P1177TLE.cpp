#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int maxn = 1e5+100;
int arr[maxn],n;

void QKSort(int l,int r) {
	if(l<r) {
		int p=l,q=r;
		int i=l;
		while(p<q) {
			while(p<q && arr[i]<=arr[q]) q--;
			if(arr[i]>arr[q]) swap(arr[i],arr[q]),i=q;
			while(p<q && arr[i]>arr[p]) p++;
			if(arr[i]<=arr[p]) swap(arr[i],arr[p]),i=p;
		}
		//cout << "i = " << i << endl;
		//for(int i=0; i<n; i++) cout << arr[i] << " ";
		//cout << endl;
		QKSort(l,i-1);
		QKSort(i+1,r);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	QKSort(0,n-1);
	for(int i=0; i<n; i++) cout << arr[i] << (i==n-1? '\n' : ' ');
	return 0;
}
