#include <iostream>
using namespace std;

void bubblesort(int *ar,int lenth)
{
    for(int i=1; i<lenth; i++)
    {
        int LastSwapPos=-1;
        for(int j=0; j<lenth-1; j++)
        {
            if(ar[j] > ar[j+1])
            {
                swap(a[j],a[j+1]);
                LastSwapPos = j;
            }
            i = lenth-1-LastSwapPos;
        }
    }
}

int main()
{
    return 0;
}
