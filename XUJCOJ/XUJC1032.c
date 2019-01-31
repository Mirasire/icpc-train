#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

const char UP[5] = "up";
const char DOWN[5] = "down";

struct Node
{
    char Where[5];
    char Name[200];
    bool situation;
};

typedef struct Node Arr;

int main()
{
    Arr person[51];
    memset(person,0,sizeof(Arr)*51);
    int n,m,tmp=0;
    scanf("%d%d",&n,&m);
    n-=1;
    for(int i=0; i<m; i++) scanf(" %s %s",person[i].Where,person[i].Name);
    for(int i=0; i<m; i++)
    {
        if(strcmp(UP,person[i].Where)==0 && tmp<n)
        {
            person[i].situation=1;
            tmp++;
        }
        else if(strcmp(DOWN,person[i].Where)==0)
        {
            for(int j=0; j<i; j++)
            {
                if(person[j].situation && strcmp(person[j].Name,person[i].Name)==0)
                {
                    person[j].situation=0;
                    tmp--;
                    break;
                }
            }
        }
    }
    for(int i=0; i<m; i++)
    {
        if(person[i].situation)
        {
            printf("%s\n",person[i].Name);
        }
    }
    return 0;
}

        


