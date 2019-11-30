#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;

const int maxn = 120;
int arr[maxn];
map<int,int> happ;

int find(int sj) {
	int per,end,key;
	//1
	per = (sj/10)*10;
	for(int i=0; i<=9; i++) {
		key = per+i;
		if(happ[key]==0) {
			happ[key] = 2;
			return key;
		}
	}

	//2
	per = (sj/100)*100,end = sj%10;
	for(int i=0; i<=9; i++) {
		key = per+end+i*10;
		if(happ[key]==0) {
			happ[key] = 2;
			return key;
		}
	}

	//3
	per = (sj/1000)*1000,end = sj%100;
	for(int i=0; i<=9; i++) {
		key = per+end+i*100;
		if(happ[key]==0) {
			happ[key] = 2;
			return key;
		}
	}

	//4
	end = sj%1000;
	for(int i=0; i<=9; i++) {
		key = end+i*1000;
		if(happ[key]==0) {
			happ[key] = 2;
			return key;
		}
	}
}

int main() {
	int t;
	int n,a;
	scanf("%d",&t);
	while(t--) {
		int tt = 0;
		happ.clear();
		scanf("%d",&n);
		for(int i=0; i<n; i++) {
			scanf("%d",arr+i);
			happ[arr[i]] = 1;
		}
		for(int i=0; i<n; i++) {
			if(happ[arr[i]]==1) {
				happ[arr[i]]++;
			}
			else {
				arr[i] = find(arr[i]);
				tt++;
			}
		}
		printf("%d\n",tt);
		for(int i=0; i<n; i++) 
			printf("%04d\n",arr[i]);
	}
	return 0;
}
