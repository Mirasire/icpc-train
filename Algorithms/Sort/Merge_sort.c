#include <stdio.h>
#include <stdlib.h>

void Merge(int *number,int p,int q,int r); //用来排序
void Merge_sort(int *number,int p,int r); //用来拆数组
void print(int *number,int n);

int main()
{
    int number[17]={6,12,3,5,2,6,1322,7,8,98,63,23,98,77,23,56,107};
    print(number,17);
    Merge_sort(number,0,16);
    return 0;
}

void print(int *number,int n)
{
    for(int i=0; i<n; i++)
        printf("%d\t",number[i]);
    printf("\n");
    return;
}

void Merge(int *number,int p,int q,int r)
{
    int n1=q-p+1,n2=r-q;
    int ia=0,ib=0,i=0;
    int *B = &number[q+1],*C = &number[p];
    int *A = (int *)malloc(sizeof(int)*n1);
    for(int x=0,j=p; x<n1; x++)
        A[x] = number[j++];
    while(ia < n1 && ib < n2)
    {
        if(*(A+ia) <= *(B+ib))
            *(C+i++) = *(A+ia++);
        else
            *(C+i++) = *(B+ib++);
    }
    int end = n1+n2;
    while(i < end)
    {
        if(ia < n1)
            *(C+i++) = *(A+ia++);
        else
            *(C+i++) = *(B+ib++);
    }
    print(number,17);
    free(A);
    return;
}

void Merge_sort(int *number,int p,int r)
{
    if(p < r)
    {
        int q=(p+r)/2;
        Merge_sort(number,p,q);
        Merge_sort(number,q+1,r);
        Merge(number,p,q,r);
        print(number,17);
    }
}
