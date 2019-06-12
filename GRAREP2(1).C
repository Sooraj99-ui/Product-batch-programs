#include<stdio.h>
#include<conio.h>
#define NOV 9
#define NOE 14
struct edge
{
 char ch1;
 char ch2;
 int wt;
};
typedef struct edge EDGE;

EDGE data[NOE]={{'A','C',3},{'A','D',5},{'A','B',9},{'B','G',1},{'B','E',3},
 {'C','D',2},{'H','I',6},{'F','H',12},{'F','G',4},{'G','I',10},{'G','E',15},
 {'E','I',5},{'C','F',9},{'D','G',6} };

int mat[NOV][NOV];
struct node
{
 char ch;
 int wght;
 struct node*next;
};
typedef struct node NODE;
NODE *newnode,*tptr;
NODE *header[NOV];
char queue[100];
int front =-1, rear=-1;
int bfs_visited[NOV];
int dfs_visited[NOV];
void enQ( char inp)
{
 if(front==-1)
     front++;
 rear++;
 queue[rear]=inp;
}
char deQ()
{
 char toReturn;
 if(front ==-1 || front > rear)
  return 0;
 toReturn = queue[front];
 front++;
 return toReturn;
}
void BFS(char st)
{
 char deQval;
 int col;
 enQ(st);
 while(1)
 {
   deQval= deQ();
   if(deQval== 0 )
     break;
   if(bfs_visited[deQval-65]==0)
     printf("%c ",deQval);
   bfs_visited[deQval-65]=1;
   for(col = 0 ; col< NOV; col++)
    if(mat[deQval-65][col]!=0 && bfs_visited[col]==0)
     enQ(col+65);
 }
}
typedef struct head
{
  char ch;
  NODE * sllstart;
  struct head * hnext;
}HEAD;
HEAD * hstart, *hnewnode,*hptr,*hprev;

void LLconnector(char head_ch, char con_ch , int weit)
{

 newnode=(NODE*)malloc(sizeof(NODE));
 newnode->ch =con_ch;
 newnode->wght = weit;
 newnode->next=NULL;
 for(hptr = hstart ;hptr!=NULL && hptr->ch!=head_ch;
      hprev=hptr,hptr=hptr->hnext);
 if(hptr==NULL)
 {
  hnewnode=(HEAD*)malloc(sizeof(HEAD));
  hnewnode ->ch = head_ch;
  hnewnode->sllstart=newnode;
  hnewnode->hnext=NULL;
  if(hstart==NULL)
     hstart=hnewnode;
  else
    hprev->hnext=hnewnode;
 }
 else
 {
  if(hptr->sllstart==NULL)
    hptr->sllstart = newnode;
  else
  {
   for(tptr= hptr->sllstart ;  tptr->next!=NULL; tptr=tptr->next);
     tptr->next = newnode;
   }
 }
}


void connector(char ind_ch, char con_ch , int weit)
{
 newnode=(NODE*)malloc(sizeof(NODE));
 newnode->ch =con_ch;
 newnode->wght = weit;
 newnode->next=NULL;
 if(header[ind_ch-65]==NULL)
   header[ind_ch-65] = newnode;
 else
 {
  for(tptr= header[ind_ch-65] ;  tptr->next!=NULL; tptr=tptr->next);
  tptr->next = newnode;
 }
}

int stack[100];
int top=-1;
int mydfs_visited[NOV];
void push(char ch)
{
 top++;
 stack[top]= ch;
}
char pop()
{
 char toReturn;
 if(top==-1)
   return 0;
 toReturn = stack[top];
 top--;
 return toReturn;
}
void myDFS(char inp)
{
 char pop_ch;
 int col;
 push(inp);
 while(1)
 {
 pop_ch=pop();
 if(pop_ch==0) break;
 if(mydfs_visited[pop_ch-65]==0)
 printf("%c ",pop_ch);
 mydfs_visited[pop_ch-65]=1;
 for(col = NOV -1 ; col>=0 ; col--)
    if(mat[pop_ch-65][col]!=0&&mydfs_visited[col]==0)
       push(col+65);
 }
}
void DFS(char inp)
{
int col;
 if(dfs_visited[inp-65] ==1)
   return;
 printf("%c ",inp);
 dfs_visited[inp-65]=1;
 for(col= 0 ;col<NOV; col++)
   if(mat[inp-65][col]!=0 && dfs_visited[col]==0)
       DFS(col+65);
}


int main()
{
 int row,col,ind;
 clrscr();
//adjaceny matrix
 for(ind=0  ;ind < NOE;ind++)
 {
  mat[data[ind].ch1 -65][data[ind].ch2-65]=data[ind].wt;
  mat[data[ind].ch2 -65][data[ind].ch1-65]=data[ind].wt;
 }
 for(printf("\n\t    "),ind=0  ;ind < NOV;ind++)
    printf("%2c  ",ind+65);
 for(printf("\n\t"),row=0 ;row<NOV; row++,printf("\n\t"))
 {
   printf("%2c  ",row+65);
   for(col=0 ;col<NOV; col++)
     printf("%2d  ",mat[row][col]);
 }

//array of list
 for(ind=0  ;ind < NOE;ind++)
 {
  connector(data[ind].ch1,data[ind].ch2,data[ind].wt);
  connector(data[ind].ch2,data[ind].ch1,data[ind].wt);
 }

 for(printf("\n\t"),row=0 ;row<NOV; row++,printf("\n\t"))
 {
   printf("%2c  ",row+65);

  // for(col=0 ;col<NOV; col++)
     for(tptr=header[row] ; tptr ; tptr=tptr->next)
      printf("%2c(%2d)->",tptr->ch,tptr->wght);
 }
 //Linked list of linked list
 for(ind=0  ;ind < NOE;ind++)
 {
  LLconnector(data[ind].ch1,data[ind].ch2,data[ind].wt);
  LLconnector(data[ind].ch2,data[ind].ch1,data[ind].wt);
 }
 printf("\n\t");
 for(hptr = hstart ; hptr; hptr=hptr->hnext,printf("\n\t"))
 {
   printf("%2c  ",hptr->ch);
     for(tptr=hptr->sllstart ; tptr ; tptr=tptr->next)
	 printf("%2c(%2d)->",tptr->ch,tptr->wght);

 }
/*
 printf("\n\tBFS : ");
 BFS('A');
 printf("\n\tDFS REC : ");
 DFS('A');
 printf("\n\tDFS NONREC: ");
 myDFS('A');
  */
 getch();
 return 0 ;
}
