/*
 * 双向链表
 * 插入：InsertNode//
 *
 * 创建表头：MakeHead //
 * 
 * 删除Node：Delete
 * 删除链表：DeleteLinklisted
 * >>>>>>>> DeleteHead
 * >>>>>>>> DeleteNode
 * >>>>>>>> DeleteEnd
 *
 * 打印链表：PrintLinklisted //
 * 
 * 链表长度：LinklistedLength//
 * 
 * 表头插入：HeadInsert //
 * 表尾插入：EndInsert //
 * 
 * */

#include <iostream>
#include <cstdio>
#include <new>
using namespace std;

struct Linklisted
{
    int number;
    struct Linklisted *font;
    struct Linklisted *next;
};

typedef struct Linklisted NODE;
typedef NODE *LIST;

NODE *MakeHead(void);
NODE *HeadInsert(NODE *head, int key);
void EndInsert(NODE *head,int key);
void InsertNode(NODE *head,int position,int key);
void DeleteHead(LIST *P,int key);
void DeleteEnd(NODE *P,int key);
void DeleteNode(NODE *P,int key);
void Delete(NODE *head,int position,int key);
void DeleteLinklisted(NODE *head);
void PrintLinklisted(NODE *head);
int LinklistedLength(NODE *head);

/*
 * BUG-click
 * 双向链表
 * 插入：InsertNode //
 *
 * 创建表头：MakeHead //
 * 
 * 删除Node：Delete
 * 删除链表：DeleteLinklisted
 * >>>>>>>> DeleteHead
 * >>>>>>>> DeleteNode
 * >>>>>>>> DeleteEnd
 *
 * 打印链表：PrintLinklisted //
 * 
 * 链表长度：LinklistedLength//
 * 
 * 表头插入：HeadInsert //WA
 * 表尾插入：EndInsert //Accept
 * 
 * */
int main()
{
    int in,lon = 0;
    printf("Now Let's Make a Linklisted\n");
    NODE *head = NULL;
    printf("P.s pleasem enter 0 , if you wanna exit\n");
    while(cin >> in && in != 0)
    {
        if(head == NULL)
        {
            head = MakeHead();
            head->number = in;
            head->font = NULL;
            head->next = NULL;
        }
        else
        {
            EndInsert(head,in);
        }
    }
    PrintLinklisted(head);
    printf("The Linklisted's lenghth = %d\n",LinklistedLength(head));
    printf("All has been Deleted\n");
    return 0;
}
    
//Make list
NODE *MakeHead(void)
{
    NODE *p = new NODE;
    return p;
}

//Insert

NODE *HeadInsert(NODE *head, int key)
{
    NODE *p = new NODE;
    p->font = head->font;
    head->font = p;
    p->number = key;
    return p;
}

void EndInsert(NODE *head,int key)
{
    NODE *Tmp = head;
    while(Tmp->next != NULL) Tmp = Tmp->next;
    NODE *p = new NODE;
    p->number = key;
    p->next = Tmp->next;
    p->font = Tmp;
    Tmp->next = p;
}

void InsertNode(NODE *head,int position,int key)
{
    NODE *Tmp = head;
    /*position base 0*/
    int cnt = 0;
    while(cnt < position && Tmp->next != NULL)
    {
        Tmp = Tmp->next;
        cnt++;
    }
    if(cnt < position) 
    {
        cout << "sorry Memory Exceeded\nPlease Enter Agian" << endl;
        return;
    }
    else
    {
        NODE *p = new NODE;
        p->number = key;
        p->next = Tmp->next;
        Tmp->next = p;
        p->font = Tmp;
    }
}

//Delete

void DeleteHead(LIST *P)
{
    NODE *Tmp = *P;
    *P = (*P)->next; //???
    (*P)->font = Tmp->font;
    delete Tmp;
}

void DeleteEnd(NODE *P)
{
    NODE *Tmp = P->font;
    Tmp->next = P->next;
    delete P;
}

void DeleteNode(NODE *P)
{
    NODE *Tmp = P->font;
    Tmp->next = P->next;
    Tmp = P->next;
    Tmp->font = P->next;
    delete P;
}

void Delete(NODE *head,int position)
{
    NODE *Tmp = head;
    /*position base 0*/
    int cnt = 0;
    while(cnt < position && Tmp->next != NULL)
    {
        Tmp = Tmp->next;
        cnt++;    
    }
    if(cnt < position)
    {
        cout << "The Node is not in the Linklisted\n Please Enter Again" << endl;
        return;
    }
    else
    {
        //head
        if(Tmp->font == NULL)  DeleteHead(&head);
        //end
        else if(Tmp->next == NULL) DeleteEnd(Tmp);
        //middle
        else DeleteNode(Tmp);
    }
}

void DeleteLinklisted(NODE *head)
{
    NODE *Tmp = head;
    while(Tmp != NULL)
    {
        Tmp = Tmp->next;
        delete head;
        head = Tmp;
    }
}


//PrintLinklisted
void PrintLinklisted(NODE *head)
{
    NODE *Tmp = head;
    while(Tmp != NULL) 
    {
        printf("%d ",Tmp->number);
        Tmp = Tmp->next;
    }
    cout << endl;/*\n*/
    return;
}

//LinklistedLength
int LinklistedLength(NODE *head)
{
    int lon = 0;
    NODE *Tmp = head;
    while(Tmp != NULL)
    {
        Tmp = Tmp->next;
        lon++;
    }
    return lon;
}

