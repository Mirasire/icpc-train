#include <iostream>

using namespace std;

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
    int n;
    cin >> n;
    while(n--)
    {
        printf("Please cin the Arr's lon ");
        int m;
        cin >> m;
        int arr[m];
        for(int i=0; i<m; i++) scanf("%d",arr+i);
        Qsort(arr,arr,arr+m-1);
        for(int i=0; i<m; i++) printf("%d ",arr[i]);
        printf("\n");
    }
    return 0;
}
