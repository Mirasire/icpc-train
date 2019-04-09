#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 2100;
int arrO[maxn],arrJ[maxn];
int main()
{
	int n,O=0,J=0;
	scanf("%d", &n);
	int in;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &in);
		if (in & 1) arrJ[J++] = in;
		else arrO[O++] = in;
	}
	sort(arrJ, arrJ + J);
	sort(arrO, arrO + O);
	int Min = min(J, O);
	int miner = abs(J - O)-1;
	int out = 0;
	if (Min == J)
		for (int i = 0; i < miner; i++) out += arrO[i];
	else
		for (int i = 0; i < miner; i++) out += arrJ[i];
	printf("%d", out);
	return 0;
}
