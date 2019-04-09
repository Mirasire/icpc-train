#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 2 * 1e5 + 10;
int arr[maxn];
int increase[maxn];
int decrease[maxn];

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	sort(arr, arr + n);
	int InSize = 1, DeSize = 0;
	increase[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] != arr[i - 1]) increase[InSize++] = arr[i];
		else decrease[DeSize++] = arr[i];
	}
	sort(decrease, decrease + DeSize, cmp);
	int Oin = unique(increase, increase + InSize) - increase;
	int Ode = unique(decrease, decrease + DeSize) - decrease;

	if (Oin == InSize && Ode == DeSize)
	{
		printf("YES\n");
		printf("%d\n", Oin);
		for (int i = 0; i < Oin; i++)
		{
			if (i) printf(" ");
			printf("%d", increase[i]);
		}
		printf("\n");
		printf("%d\n", Ode);
		for (int i = 0; i < Ode; i++)
		{
			if (i) printf(" ");
			printf("%d", decrease[i]);
		}
		printf("\n");
	}
	else printf("NO\n");
	return 0;
}
