
#include "head.h"
#include <stdio.h>
void bubbleSort(PNode pList) {
  // int i;
  PNode p = pList;
  while (p->_PNext) {
    PNode q = p;
    while (q->_PNext) {
      if (lessThan(p->_PNext, q->_PNext)) {
        swapData(pList, p->_PNext, q->_PNext);
        // travelList(pList);
      }
      q = q->_PNext;
    }
    p = p->_PNext;
  }
}