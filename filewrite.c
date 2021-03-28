#include "head.h"
#include <stdio.h>
#include <string.h>


void write(char *fileName, PNode pList) {
  FILE *fp = NULL;
  fp = fopen(fileName, "w+");
  PNode tmp = pList;
  while (tmp->_PNext) {
    fprintf(fp, "%s,%d\n", tmp->_PNext->_data.name,
            tmp->_PNext->_data.totalcount);
    tmp = tmp->_PNext;
  }
  //    fputs("This is testing for fputs...\n", fp);
  fclose(fp);
}