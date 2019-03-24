/*
 * 输入两个多项式
 * 输出两个多项式的和
 * 输入
 * 
 * 输入m n代表两个多项式的长度，下面n+m行内输入 ai,bi 代表系数和幂次方
 * 
 * 
 * 输出
 *  
 * 从小到大每行输出求和后的数的系数和幂次方
 *
 * 样例输入
 * 2 3
 * 3 3
 * 4 5
 * 3 7
 * 1 1
 * 5 7
 *
 * 样例输出
 * 
 * 1 1
 * 3 3
 * 4 5
 * 8 7
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int a;
    int b;
    struct Node *next;
};
typedef struct Node LINK;
typedef LINK* NODE;

NODE Makehead()
{
    NODE head = (NODE)malloc(sizeof(LINK));
    head->a = 0;
    head->b = 0;
    head->next = NULL;
    return head;
}

//bydegree
void AddNode(NODE head, NODE add, NODE *headAdress)
{
    int flag=1;
    NODE tmp=head;
    NODE save=head;
    //head Add
    if(head->b > add->b)
    {
        add->next = tmp;
        *headAdress = add;
        flag=0;
    }
    //Middle Add
    while(flag&&tmp!=NULL)
    {
        if(tmp->b > add->b)
        {
            add->next = save->next;
            save->next = add;
            flag=0;
        }
        else if(tmp->b == add->b)
        {
            tmp->a+=add->a;
            flag=0;
            break;
        }
        save = tmp;
        tmp = tmp->next;
        //printf("tmp = %p\n",tmp);
        //printf("in circle\n");
    }

    //Back add
    if(flag)
    {
        add->next = save->next;
        save->next = add;
    }
    return;
}

void PrintLink(NODE head)
{
    NODE tmp = head;
    while(head != NULL)
    {
        tmp = head;
        head=head->next;
        if(tmp->a != 0) printf("%d %d\n",tmp->a,tmp->b);
        free(tmp);
    }
    printf("All has been cleared\n");
}

int main()
{
    freopen("in","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    int all = m+n;
    NODE head = Makehead();
    while(all--)
    {
        //printf("head's address = %p\n",head);
        int x,y;
        scanf("%d%d",&x,&y);
        NODE add = (NODE)malloc(sizeof(LINK));
        add->a = x;
        add->b = y;
        add->next = NULL;
        AddNode(head,add,&head);
    }
    PrintLink(head);
    return 0;
}
