#include "head.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

PNode createList()
{
    PNode pNode = malloc(sizeof(Node));
    pNode->_PNext = NULL;
    return pNode;
}

void addNode(PNode pList, SDataType user_login)
{
    PNode pNode = (PNode)malloc(sizeof(Node));
    pNode->_data = user_login;
    pNode->_PNext = pList->_PNext;

    pList->_PNext = pNode;
    // return;
    // PNode tmp = pList;

    // // printf("\nAdding %s\n", user_login.name);
    // while (tmp->_PNext)
    // {
    //     tmp = tmp->_PNext;
    // }
    // tmp->_PNext = pNode;
}

void travelList(PNode pList)
{
    PNode tmp = pList;
    while (tmp->_PNext)
    {
        printf("%s: %d\n", tmp->_PNext->_data.name, tmp->_PNext->_data.totalcount);
        tmp = tmp->_PNext;
    }
    printf("\n");
}

int lessThan(PNode p, PNode q)
{
    return p->_data.totalcount < q->_data.totalcount;
}

void swapData(PNode pList, PNode p, PNode q)
{
    SDataType tmp = p->_data;
    p->_data = q->_data;
    q->_data = tmp;
    // travelList(pList);
}

/*
建立三个工作指针p,q,r，然后p遍历全表。
p每到一个结点，q就从这个结点往后遍历，并与p的数值比较，相同的话就free掉那个结点
*/
void merge(PNode pList)
{
    PNode p, q, r;
    p = pList->_PNext;
    while (p)
    {
        q = p;
        while (q->_PNext)
        {
            if (strcmp(p->_data.name, q->_PNext->_data.name) == 0)
            {
                r = q->_PNext;
                q->_PNext = r->_PNext;
                p->_data.totalcount++;
                free(r);
            }
            else
            {
                q = q->_PNext;
            }
        }
        p = p->_PNext;
    }
}

int listLen(PNode pList)
{
    int cnt=0;
   
    PNode tmp = pList;
    while (tmp->_PNext)
    {
        cnt++;
        tmp = tmp->_PNext;
    }
    return cnt;

}

SDataType* toArray(PNode pList)
{
    int n = listLen(pList);
    SDataType *a = malloc(sizeof(SDataType) * n);
    int i;
    PNode p = pList;
    for (i = 0; i < n; i++)
    {
        a[i] = p->_PNext->_data;
        p = p->_PNext;
    }
    return a;
}