#include <cstdio>
#include <cstring>
#include <queue>
#include <limits.h>
#define PrtInt(x) printf(#x " =%d\n",x);
using namespace std;

const int maxn = 2 * 1e5 + 100;
int Arr[maxn] = {0};
int Appear[maxn] = { 0 };
bool visite[maxn] = { 0 };

int main()
{
	int n,MaxAppear  = INT_MIN,Val = 0,index = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", Arr + i);
		Appear[Arr[i]]++;
		if (MaxAppear < Appear[Arr[i]])
		{
			MaxAppear = Appear[Arr[i]];
			Val = Arr[i];
		}
	}
	//PrtInt(Val)
	for (int i = 0; i < n; i++)
	{
		if (Val == Arr[i])
		{
			Appear[index++] = i;
			visite[i] = 1;
		}
	}
	//PrtInt(index)
	printf("%d\n", n - index);
	for (int i = 0; i < index; i++)
	{
		for (int j = Appear[i]-1; j >= 0 && !visite[j]; j--)
		{
			printf("%d %d %d\n", Arr[j] - Val < 0 ? 1 : 2, j + 1, j + 2);
			visite[j] = 1;
		}
		for (int j = Appear[i] + 1; j < n && !visite[j]; j++)
		{
			printf("%d %d %d\n", Arr[j] - Val > 0 ? 2 : 1, j+1,j);
			visite[j] = 1;
		}
	}
	return 0;
}
