#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
 
const int maxn = 2e6;
int arr[maxn];
 
int main() {
	int t,num,cnt,key,size;
	scanf("%d",&t);
	while(t--) {
		size = cnt = 0;
		scanf("%d",&num);
		if(num==3) {
			printf("3\n0 1 3\n");
			continue;
		}
		for(int i=1; i<=num; i++) {
			arr[cnt] = num/i;
			if (cnt && arr[cnt-1]-arr[cnt]==0) break;
			cnt++;
		}
		size = arr[cnt-1]-0;
		printf("%d\n",cnt+size);
		for(int i=0; i<size; i++) printf("%d ",i);
		for(int i=cnt-1; i>=0; i--) printf("%d ",arr[i]);
		putchar('\n');
	}
	return 0;
}
