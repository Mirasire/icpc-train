//from https://practice.geeksforgeeks.org/problems/linked-list-insertion/1
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void insertAtBegining(struct node** headRef, int newData);
void insertAtEnd(struct node** headRef, int newData);

//printf the Linklist
void printList(struct node *node)
{
    while (node != NULL)
    {
        cout<<node->data<<' ';
        node = node->next;
    }
    cout<<endl;
}

/*Main Function*/
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n, ch, tmp;
        struct node* head = NULL;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>tmp>>ch;
            if(ch) insertAtEnd(&head, tmp);
            else insertAtBegining(&head, tmp);
        }
        printList(head);
    }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
Structure of the linked list node is as
struct node
{
    int data;
    struct node *next;
};
*/
// function inserts the data in front of the list
void insertAtBegining(struct node** headRef, int newData)
{
    // Code her
    node *P = new node;
    P->next = *headRef;
    P->data = newData;
    *headRef = P;
}
// function appends the data at the end of the list
void insertAtEnd(struct node** headRef, int newData)
{
    // Code here
    node *P = new node;
    if(*headRef == NULL)
    {
        P->next = *headRef;
        P-data = newData;
        *headRef = P;
    }
    else
    {
        node *Tmp = *headRef;
        while(Tmp->next != NULL)
            Tmp = Tmp->next;
        P->next = Tmp->next;
        P->data = newData;
        Tmp->next = P;
    }
}
