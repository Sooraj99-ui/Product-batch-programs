#include<stdio.h>
#include<conio.h>
#define NOD 7
#include<limits.h>
typedef struct node
{
 int data;
  struct node * next;
}NODE;


int main()
{
 NODE * sTop=NULL,*dTop=NULL,*tTop=NULL,*tptr,*temp,*newnode;
 int ind;

 clrscr();
   newnode =(NODE*)malloc(sizeof(NODE));
   newnode->data = INT_MAX;
   newnode->next=NULL;
   sTop = newnode;
   newnode =(NODE*)malloc(sizeof(NODE));
   newnode->data = INT_MAX;
   newnode->next=NULL;
   dTop = newnode;
   newnode =(NODE*)malloc(sizeof(NODE));
   newnode->data = INT_MAX;
   newnode->next=NULL;
   tTop=newnode;

 for(ind=NOD; ind>=1; ind--)
 {
   newnode =(NODE*)malloc(sizeof(NODE));
   newnode->data = ind;
   newnode->next=NULL;
   newnode->next = sTop;
   sTop = newnode;
 }
 while(1)
 {
  if(sTop->data > dTop -> data)
  {
    temp = dTop;
    dTop = dTop->next;
    temp->next= sTop;
    sTop = temp;
  }
  else
  {
    temp = sTop;
    sTop = sTop->next;
    temp->next= dTop;
    dTop = temp;
  }
  if(sTop->data==INT_MAX && tTop->data ==INT_MAX) break;
  if(sTop->data > tTop -> data)
  {
    temp = tTop;
    tTop = tTop->next;
    temp->next= sTop;
    sTop = temp;
  }
  else
  {
    temp = sTop;
    sTop = sTop->next;
    temp->next= tTop;
    tTop = temp;
  }
  if(tTop->data > dTop -> data)
  {
    temp = dTop;
    dTop = dTop->next;
    temp->next= tTop;
    tTop = temp;
  }
  else
  {
    temp = tTop;
    tTop = tTop->next;
    temp->next= dTop;
    dTop = temp;
  }
  if(sTop->data==INT_MAX && tTop->data ==INT_MAX) break;
 }
 for(printf("\n\t"),tptr = dTop ; tptr; printf(" %d ",tptr->data),tptr=tptr->next);
 getch();
 return 0 ;
}
