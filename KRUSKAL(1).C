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

INP data[NOE]={{'B','G',1},{'C','D',2},{'A','C',3},{'B','E',3},{'F','G',4},
{'A','D',5},{'E','I',5}, {'H','I',6},{'D','G',6}, {'C','F',9},
{'A','B',9},{'G','I',10},{'F','H',12},{'G','E',15}
};

int main()
{

 clrscr();

 getch();
 return 0 ;
}
