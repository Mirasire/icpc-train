#include<stdio.h>

int sum=0;

void swap(int *Arr,int a,int b)
{
    int temp = *(Arr+a);
    *(Arr+a) = *(Arr+b);
    *(Arr+b) = temp;
    return;
}

void print(int *Arr,int lon)
{
    for(int i=0; i<lon; i++) printf("%d",*(Arr+i));
    printf("\n");
    return;
}

void perm(int *Arr,int p,int q)
{
    if(p==7)  print(Arr,8);
    for(int i=p; i<q; i++)
    {
        swap(Arr, p, i);
        perm(Arr, p+1, q);
        swap(Arr, p, i);
    }
    return;
}

int main()
{
    int Arr[8]={1,2,3,4,5,6,7,8};
    perm(Arr,0,8);
    printf("%d\n",sum);
    return 0;
}
