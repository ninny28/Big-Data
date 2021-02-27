#include "head.h"
#include <stdio.h>

PNode partiion(PNode pStart, PNode pEnd)
{

    PNode key = pStart; // 基准
    PNode p = pStart;
    PNode q = pStart;
    while (q != pEnd)
    {
        if (q->_data.totalcount > key->_data.totalcount)
        {
            p = p->_PNext;
            swapData(NULL, p, q);
        }
        q = q->_PNext;
    }
    swapData(NULL, p, key);
    return p;
}

void quickSort1(PNode pList, PNode pStart, PNode pEnd)
{
    if (pStart == pEnd || pStart->_PNext == pEnd)
        return;
    PNode mid = partiion(pStart, pEnd);
    // printf("mid:%s\n", mid->_data.name);
    // travelList(pList);
    quickSort1(pList, pStart, mid);
    quickSort1(pList, mid->_PNext, pEnd);
}

void quickSort(PNode pList)
{
    // empty or one node
    if (pList == NULL || pList->_PNext == NULL)
        return;
    quickSort1(pList, pList->_PNext, NULL);
}