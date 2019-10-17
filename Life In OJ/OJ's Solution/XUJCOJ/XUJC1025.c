#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int m;
    int index;
    int start;
    int end;
    int length;
} TEMP;

//flag = 0

int main()
{
    int n,cont=0,m_max=INT_MIN,length_min=INT_MAX,cout=0;
    scanf("%d",&n);
    int *number = (int *)malloc(sizeof(int)*n);
    TEMP *temp = (TEMP *)malloc(sizeof(TEMP)*n);
    memset(temp,0,sizeof(TEMP)*n);
    for(int i=0; i<n; i++) scanf("%d",number+i);
    for(int i=0; i<n; i++)
    {
        if(number[i]>0)
        {
            int key=number[i],mtmep=1,endtemp=i;
            temp[cont].start=i;
            for(int j=i+1; j<n; j++) 
                if(number[j] == key) 
                {
                    mtmep++;
                    endtemp = j;
                }
            temp[cont].index = key;
            temp[cont].end = endtemp;
            temp[cont].m = mtmep;
            temp[cont].length = endtemp-i+1;
            if(temp[cont].m >= m_max && temp[cont].length < length_min)
            {
                m_max = temp[cont].m;
                length_min = temp[cont].length;
                cout = cont;
            }
            cont++;
        }
    }
    printf("%d %d",temp[cout].start+1,temp[cout].end+1);
    return 0;
}
