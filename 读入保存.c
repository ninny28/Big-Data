#include<stdio.h>
#include<stdlib.h>
#include<memory.h>


typedef struct node {
int data;
struct node *next;
}node;
//从文件中读取数据存入链表
node *createlink()
{
node *head =(node*)malloc(sizeof(node));
int t;
node *p;
node *q;
p=q=head;
FILE * r= fopen(" user_login.txt.txt","r");
if(r==NULL)
{
printf("打开文件失败!");
return NULL;
}
while(fscanf(r,"%d",&t)!=EOF)
{
q= (node*)malloc(sizeof(node));
q->data=t;
p->next=q;
p=q;
}
p->next=NULL;
return head;
}
//输出链表到屏幕和文件output.txt
void outlink(node *head)
{
node *p=head->next;
FILE *w =fopen("output.txt","w");
if(w==NULL)
{
printf("打开文件失败!");
return;
}
while(p)
{
//输出链表节点数据到屏幕
printf("%d ",p->data);
//输出链表节点数据到文件output.txt
fprintf(w,"%d ",p->data);
p=p->next;
}
printf("\n");
fprintf(w,"\n");
fclose(w);
return;
}

int main()
{
node *head;
int n,m;
head=createlink();
outlink(head);
system("pause");
return 0;
}