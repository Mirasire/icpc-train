#include<stdio.h>

int Pivot(int *arr,int p,int r);
void Quick_sort(int *arr,int p,int r);
void print(int *arr);

int main()
{
    int arr[15] = {12,3,21,34,5,33,76,24,45,88,15,12,5,42,2};
    print(arr);
    Quick_sort(arr,0,14); 
    return 0;
}


//选择最后一位元素作为枢纽元 
int Pivot(int *arr,int p,int r)
{
    int pi=p,pj=r-1,key=*(arr+r);
    while(pi <= pj)
    {
        if(*(arr+pi) <=key || *(arr+pj) > key)
        {
            if(*(arr+pi) <= key) ++pi;
            if(*(arr+pj) > key) --pj; 
        }
        else
        {
            int temp = *(arr + pi);
            *(arr+pi++) = *(arr+pj);
            *(arr+pj--) = temp;
        }
    }
    //将枢纽元插入
    for(int i=r; i>pj && i>0; i--)
        *(arr+i) = *(arr+i-1);
    *(arr+pi) = key;
    return pi;
}


void Quick_sort(int *arr,int p,int r)
{
    if(p < r)
    {
        int q = Pivot(arr,p,r);
        Quick_sort(arr,p,q-1);
        Quick_sort(arr,q+1,r);
        print(arr);
    }
}

void print(int *arr)
{
    for(int i=0; i<15; i++)
        printf("%d\t",*(arr+i));
    printf("\n");
    return;
}
