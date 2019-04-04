#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 2 * 1e3 + 5;
const int maxnn = 4 * 1e6 + 100;
int in[maxn];
int Target[maxnn];
int Find[maxnn];

void Qsort(int *arr,int *p,int *r)
{
    if(p >=r) return;
    bool flag=1;
    int *front = p, *back = r;
    int pivot=*r;
    while(p < r)
    {
        if(flag)
        {
            if(*p > pivot) 
            {
                *(r--) = *p;
                flag=0;
            }
            else p++;
        }
        else
        {
            if( *r < pivot)
            {
                *(p++) = *r;
                flag = 1;
            }
            else r--;
        }
    }
    *p = pivot;
    Qsort(arr, front, p-1);
    Qsort(arr, p+1, back);
}

int main()
{
        //freopen("in","r",stdin);
	int m,cnt=0,input,tmp;
	scanf("%d", &m);
	tmp = m;
	while(m--) scanf("%d", in + m);
	m = tmp;
	while(m--)
	{
		scanf("%d", &input);
		for (int j = 0; j < tmp; j++)
		{
			Find[cnt++] = -(input+in[j]);
		}
	}
	cnt = 0;
	m = tmp;
	while (m--) scanf("%d", in + m);
	m = tmp;
	while (m--)
	{
		scanf("%d", &input);
		for (int j = 0; j < tmp; j++)
		{
			Target[cnt++] = input + in[j];
		}
	}
	Qsort(Find, Find , Find+cnt-1);
	Qsort(Target, Target , Target+cnt-1);
	int *f = Find, *t = Target;
	int *endF = Find + cnt,*endT = Target+cnt;
	long long out = 0;
	while (f < endF && t < endT)
	{
		if (*f == *t)
		{
			int NumberF = 0, NumberT = 0;
			int key = *f;
			while (key == *f && f < endF) f++, NumberF++;
			key = *t;
			while (key == *t && t < endT) t++, NumberT++;
			out += NumberF * NumberT;
		}
		if (*f < *t) f++;
		else if (*f > *t) t++;
	}
	printf("%lld", out);
	return 0;
}
