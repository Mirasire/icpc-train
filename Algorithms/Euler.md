# Euler_Prime


```c
#define N 100001

bool isNotPrime[N]={0};
int Prime[N]={0};

//Euler_Prime

isNotPrime[0] = isNotPrime[1] = 1;
int nums = 0;
for(int i=0; i<N; i++)
{
    if(!isNotPrime[i]) Prime[nums++] = i;
    for(int j=0; j<nums && i*Prime[j]<N; j++) //Question2.1
    {
        isNotPrime[i*Prime[j]] = 1; //Question2.2
        if(!(i % Prime[j])) break; //Question1
    }
}
```
