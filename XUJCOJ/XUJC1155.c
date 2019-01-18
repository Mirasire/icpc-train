#include<stdio.h>

int sum=0;

void unmove(int *Arr,int a,int b) //b is a's last position
{
    int temp = *(Arr+a);
    for(int i=a; i<b; i++) *(Arr+i) = *(Arr+i+1);
    *(Arr+b)=temp;
    return;
}

void move(int *Arr,int a,int b) //b  is change positoin
{
    int temp = *(Arr+b);
    for(int i=b; i>a; i--) *(Arr+i) = *(Arr+i-1);
    *(Arr+a)=temp;
    return;
}

void print(int *Arr,int lon)
{
    for(int i=0; i<lon; i++) printf("%d ",*(Arr+i));
    printf("\n");
    return;
}

void perm(int *Arr,int p,int q)
{
    if(p==7)  
    {
        sum++;
        print(Arr,8);
        return;
    }
    for(int i=p; i<q; i++)
    {
        move(Arr, p, i);  //i is change position
        perm(Arr, p+1, q);
        unmove(Arr, p, i);
    }
    return;
}

int main()
{
    int Arr[8]={1,2,3,4,5,6,7,8};
    perm(Arr,0,8);
    //printf("%d\n",sum);
    return 0;
}
