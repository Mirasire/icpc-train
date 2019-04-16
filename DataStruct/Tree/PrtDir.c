#include <stdio.d>
#include <stdlib.h>
#include <string.h>

const int maxn = 1e2;

struct Node
{
    char Dir[maxn];
    struct Node *FirstChild;
    struct Node *NextSiling;
};

typedef struct Node NODE;
typedef NODE * PNODE;

PNODE Position,root;
void Init()
{
    Postion = (PNODE)maloc(sizeof(NODE));
    root = (PNODE)maloc(sizeof(NODE));
}

void mkdir(PNODE Fc,NODE a)
{
    PNODE add = (PNODE)malloc(sizeof(NODE));
    add = a;
    PNODE tmp = Fc;
    while(tmp->NextSiling != NULL) tmp = tmp->NextSiling;
    tmp->NextSiling = add;
}

void cd(PNODE Fc,NODE add)
{
    PNODE tmp = Fc; 
