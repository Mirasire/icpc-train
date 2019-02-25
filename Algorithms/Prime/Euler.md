# Euler_Prime


```c++
#define N 100001

bool isNotPrime[N]={0};
int Prime[N]={0};

//Euler_Prime

isNotPrime[0] = isNotPrime[1] = 1;
int nums = 0;
for(int i=0; i<N; i++)
{
    if(!isNotPrime[i]) Prime[nums++] = i;
    for(int j=0; j<nums && i*Prime[j]<N; j++) 
    {
        isNotPrime[i*Prime[j]] = 1; 
        if(!(i % Prime[j])) break; 
    }
}
```
# Q-1为什门要使用这样子的打表？

```c
/*------Old Version-----*/

#define N 100001

bool isNotPrime[N]={0}; //include <stdbool.h> or _Bool isNotPrime[N]
int Prime[N]={0};

//normal_Prime

isNotPrime[0] = isNotPrime[1] = 1;
int nums = 0;
for(int i=0; i<N; i++)
{
    if(!isNotPrime[i]) 
    {
    	Prime[nums++] = i;
    	for(int j=2*i/*小优化是i*i*/; j<N; j+=i) isNotPrime[j] = 1;
    }
}
```

上面是老的**打表**方法(又被称之为埃氏筛法)，这钟筛法相比较于欧拉筛法会浪费许多时间（由于多次打表同一数据），比如 $24 = 2*12 = 3*8 = 4*6 = 6*4 = 8*3 = 12*2$ ，这样就会有五次徒劳操作。而

欧拉筛法是靠以下的expr来消除这些误操作。

```c++
if(!(i % Prime[j])) break;
```
易证每个数字都能表示成一个素数与另外一个数字的乘积。

该expr来保证目前较大的数字由较大的素数筛掉。即，number = MaxPrime $*$ OtherNumber 。

> MaxPrime = fact(number) --> maxPrime

```c++
for(int j=0; j<nums && i*Prime[j]<N; j++)
```

用来限制打表的范围，且保证每次筛掉的数字，是在该数字的平方以下。
