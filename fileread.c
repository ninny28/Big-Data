#include "head.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LINE 1024
const int MAXS = 1 * 1024 * 1024;
// const int MAXN = 100000;
void read(char *fileName, PNode pList) {
  FILE *fp;
  char strLine[MAX_LINE];                  //读取缓冲区
  if ((fp = fopen(fileName, "r")) == NULL) //判断文件是否存在及可读
  {
    printf("Open Falied!");
  }
  void *ret;
  while (1) {
    ret = fgets(strLine, MAX_LINE,
                fp); //将fp所指向的文件一行内容读到strLine缓冲区
    if (ret == NULL)
      break; // 正确地退出
    cutStr(strLine, ',');
    SDataType *userLogin = (SDataType *)malloc(sizeof(SDataType));
    strcpy(userLogin->name, strLine);
    userLogin->totalcount = 1;
    addNode(pList, *userLogin);
  }
  // travelList(pList);
  fclose(fp); //关闭文件
}

SDataType makeStruct(char *token) {
  int nameLen = strlen(token) - strlen(",2016-01-01");
  // char *name = malloc(nameLen + 1);
  // strncpy(name, token, nameLen);
  // name[nameLen] = '\0';
  SDataType *userLogin = (SDataType *)malloc(sizeof(SDataType));
  memset(userLogin, 0, sizeof(SDataType));
  strncpy(userLogin->name, token, nameLen);
  // userLogin->name[nameLen] = '\0';
  userLogin->totalcount = 1;
  return *userLogin;
}

void readFast(char *fileName, PNode pList) {
  FILE *fp;
  if ((fp = fopen(fileName, "r")) == NULL) //判断文件是否存在及可读
  {
    printf("Open Falied!");
  }
  char buf[MAXS]; //读取缓冲区
  int len = fread(buf, 1, MAXS, fp);
  fclose(fp);
  buf[len] = '\0';

  char *token;
  const char s[2] = "\n";

  token = strtok(buf, s);
  addNode(pList, makeStruct(token));

  while (token) {
    token = strtok(NULL, s);
    if (token == NULL) {
      break;
    }
    addNode(pList, makeStruct(token));
  }
}

void cutStr(char *str, char c) {
  int N = strlen(str);
  int i;
  for (i = 0; i < N; i++) {
    if (str[i] == c) {
      str[i] = '\0';
      break;
    }
  }
}