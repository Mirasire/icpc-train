#include <stdio.h>
#include <string.h>

char inPut[120];
char popo[120];

int main()
{
    while(scanf("%s",inPut) != EOF)
    {
        memset(popo,'\0',sizeof(popo[0])*120);
        char *r = popo;
        int lon = strlen(inPut);
        for(int i=0; i<lon; i++)
        {
            *r = *(inPut+i);
            if(*(r-1) == *r && r > popo)
            {
                if(*r == 'o')
                {   
                    *r = '\0';
                    *--r = 'O';
                    if(*(r-1) == *r && r>popo) 
                    {
                        *(r-1) = *r = '\0';
                        r--;
                    }
                    else r++;
                }
                else if(*r == 'O')
                {
                    *(r-1) = *r = '\0';
                    r--;
                }
            }
            else 
                r++;
        }
        printf("%s\n",popo);
    }
    return 0;
}
