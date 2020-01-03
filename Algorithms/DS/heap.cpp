/*
-	Titile -> Binary Heap(Max Heap)

-	by -> mirasire
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+100;

class MAXHEAP {
	public:
	//_size equals to the number of the heap's element
	int data[maxn<<2];
	int _size;
	MAXHEAP() { data[0] = 0; }
	MAXHEAP(int arr[],int size) {
		_size = size;
		for(int i=1; i<=size; i++) data[i] = arr[i];
		//balance the new heap from the leaves O(n)
		for(int i=n; i>=1; i--) down(i);
		/*
		balance the new heap from the root O(nlogn)
		for(int i=1; i<=n; i++) down(i);
		*/
	}
	void up(int x) {
		while(x>1 && data[x] > data[x/2]) {
			swap(data[x],data[x/2]);
			x/=2;
		}
	}
	void down(int x) {
		int t;
		while((x<<1) < n) {
			t = x<<1;
			if(t+1<n && data[t]<data[t+1]) t++;
			if(data[t]<data[x]) break;
			swap(data[x],data[t]);
			x=t;
		}
	}
	//TODO insert
	void insert(int data) {

	}
	//TODO getMax
	int getMax() {

	}
	//TODO delete Max
	int delMax() {

	}
	int delkey() {

	}
};