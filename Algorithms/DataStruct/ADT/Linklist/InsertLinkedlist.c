#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

struct ListNode
{
    int val;
    struct ListNode* next; 
};

Position Insert(Position L, int x);

int main()
{
    int n,flag=1;
    scanf("%d",&n);
    Position Save = (Position)malloc(sizeof(struct ListNode));
    Position Header;
    Header = NULL;
    Save->next = NULL;
    while(n--)
    {
        /*save the last position*/
        int x;
        scanf("%d",&x);
        Save = Insert(Save,x);
        //save the head
        if(flag)
        {
            Header = Save;
            flag-=1;
        }
    }
    /*printout linkedlist*/
    while(Header!=NULL)
    {
        printf("%d\t",Header->val);
        Header=Header->next;
    }
    printf("\n");
    return 0;
}

// instert linklist
Position Insert(Position L, int x)
{
    Position Tmp;
    Tmp = malloc(sizeof(struct ListNode));
    Tmp->val = x;
    Tmp->next = L->next;
    L->next = Tmp;
    return Tmp;
}
