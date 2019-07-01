#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[5];

int main() {
	int n,key;
	scanf("%d", &n);
	key = n;
	int sum;
	while(1) {
		sum = 0;
		n = key;
		while (n) {
			sum += n % 10;
			n /= 10;
		}
		if (sum % 4 == 0) break;
		key++;
	}
	printf("%d", key);
	return 0;
}
