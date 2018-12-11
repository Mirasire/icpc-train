#include <stdio.h>

void print(int *p,int lenth);

int main()
{
    int A[6]={11,19,27,77,79,80},B[3] = {11,17,19},C[9] = {0};
    printf("A:\t");print(A,6);
    printf("B:\t");print(B,3);
    int ia = 0,ib = 0,ic = 0;
    while(ia < 6 && ib < 3)
    {
        if(*(A+ia) <= *(B+ib))
            *(C+ic++) = *(A+ia++);
        else
            *(C+ic++) = *(B+ib++);
        print(C,9);
    }
    while(ic < 9)
    {
        if(ia < 6)
            *(C+ic++) = *(A+ia++);
        else
            *(C+ic++) = *(B+ib++);
        print(C,9);
    }
    return 0;
}

void print(int *p,int lenth)
{
    for(int i=0; i<lenth; i++)
        printf("%d\t",p[i]);
    printf("\n");
    return;
}
