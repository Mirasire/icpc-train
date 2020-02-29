//Ac Thak for the up in Bilibili
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 2e5+100;
int arr[maxn],lis[maxn];

int main() {
	int a,b,c,i,end;
	scanf("%d%d%d",&a,&b,&c);
	end = a+b+c;
	for(i=0; i<end; i++) {
		scanf("%d",arr+i);
	}
	sort(arr,arr+a);
	sort(arr+a,arr+a+b);
	sort(arr+a+b,arr+a+b+c);
	memset(lis,0,sizeof(int)*(a+b+c));
	int ans = 1;
	lis[ans] = arr[0];
	for(i=1; i<end; i++) {
		if(arr[i] > lis[ans]) lis[++ans] = arr[i];
		else *(lower_bound(lis+1,lis+1+ans,arr[i])) = arr[i];
	}
	printf("%d\n",end - ans);
	return 0;
}
