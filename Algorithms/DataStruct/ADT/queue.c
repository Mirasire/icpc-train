//make sure pop,push,&&front canbe used
//Version 0.01
#include <stdio.h>

#define mod 100000

int queue[mod];
int *MOD=queue+mod;

void push(int *add, int *p, int WaitingNumber);
void prt(int *arr, int cnt, int Font);

int main()
{
    int input,cnt=0;
    int *font = queue;
    int indexFont=0,indexAdd=0;
    //font = font+(indexFont++)%mod
    //insert = font+(indexAdd++)%mod
    while(1)
    {
        int situation;
        printf("switch case:\n1.push\n2.font\n3.pop\n4.break\n");
        scanf("%d",&situation);
        if(situation == 4) break;
        switch(situation)
        {
            case 1:
                cnt++;
                scanf("%d",&input);
                push(&indexAdd,queue,input);
                printf("index = %i\n",indexAdd);
                prt(queue, cnt, indexFont);
                printf("\n");
                break;
            case 2:
                printf("%d\n",*font);
                cnt--;
                break;
            case 3:
                (indexFont++)%mod;
                break;
        }
    }
    prt(queue, cnt, indexFont);
    printf("\n");
    return 0;
}

void prt(int *arr, int cnt, int Font)
{
    while(cnt > 0)
    {
        printf("%d ",*(arr+(Font++)%mod));
        cnt--;
    }
    return;
}

void push(int *add,int *p, int WaitingNumber)
{
    *(p+(*add)%mod) = WaitingNumber;
    (*add)++;
    return;
}
