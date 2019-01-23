/* From 数据结构与算法分析———-c语言描述
 * Goal:Learn Linked list
 */

#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
#include "Linklist.h"

struct Node
{
    ElementType Element;
    Position Next;
};

#define FatalError(x) printf(x"\n");

/*Return ture if L is Empty*/
/*测试是否为空表*/

int IsEmpty( List L )
{
    return L->Next == NULL;
}

//2
/*Return ture if P is the last position in list L*/
/*Parameter L is unused in this implementation*/
/*测试当前位置是否是链表的末尾的函数*/

int IsLast( Position P, List L )
{
    return P->Next == NULL;
}

/* Return Position of X in L; NULL if NotFound */
/*寻找相符的位置(最先出现的一次)*/

Position Find( ElementType X, List L )
{
    Position P;
    P = L->Next;
    
    while( P != NULL && P->Element != X )
        P = P->Next;
    return P;
}

/*Delete first occurrence of X from a list*/
/*Assume use of a header node*/
/*链表的删除操作*/

void Delete( ElementType X, List L )
{
    Position P,TempCell;

    P = FindPrevious( X, L ); //1

    if(!IsLast( P, L )) //2
    {
        TempCell = P->Next;
        P->Next = TempCell->Next;
        free(TempCell);
    }
    /*
     *meskill's idea
        else 
        {
            P->Next = NULL;
            free(TempCell);
        }
    */
}

//1
/*IF X is not fond, then Next field of returned*/
/*Position is NULL*/
/*Assumes a header*/
/*找到链表前面的地址*/

Position FindPrevious( ElementType X, List L )
{
    Position P;
    
    P = L;
    while( P->Next != NULL && P->Next->Element != X ) //Q1: if P.Element == X
        P = P->Next;
    return P;
}

/*Insert (after legal position p)*/
/*Header implement assumed*/
/*Parameter L is unused in this implementation*/
/*链表的插入操作*/

void Insert( ElementType X, List L, Position P )
{
    Position TmpCell;

    TmpCell = malloc( sizeof( struct Node ) );
    if( TmpCell == NULL )
        FatalError( "Out of space!!!" );
    
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

/*Delete List*/

void DeleteList( List L )
{
    Position P, Tmp;
    
    P = L->Next; /*Header assumed*/
    L->Next = NULL;

    while( P != NULL )
    {
        Tmp = P->Next;
        free( P );
        P = Tmp;
    }
}
