#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool nb[12] = {0};//a-0 b-1 c-2 d-3
char String[13] = {0};

int findChar(char p)
{
    int position = 0;
    int index = p-'a';
    for(int i=0; i<12; i++)
    {
        if(index == i)
        {
            //printf("index = %d\n",p-'a');
            nb[index] = 1;
            break;
        }
        else if(nb[i] == 0) 
        {
            //printf("nb[%d] = %d\n",index,nb[index]);
            position++;
        }
    }
    //printf("position = %d\n",position);
    return position;
}

int factorial(int end)
{
    int rt = 1;
    for(int i=1; i<end; i++) rt*=i;
    return rt;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        memset(nb,0,sizeof(bool)*12);
        getchar();
        scanf("%s",String);
        //printf("%s\n",String);
        int sum = 0;
        for(int i=0,j=12; i<12; i++,j--)
        {
            sum += findChar(String[i])*factorial(j);
        }
        printf("%d\n",sum+1);
    }
    return 0;
}
