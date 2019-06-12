#include<stdio.h>
#include<conio.h>
#include<iostream.h>
void swap(int inp1 , int inp2)
{
  int temp;
  temp = inp1 ;
  inp1 = inp2;
  inp2 = temp;
}
void swapRefVar(int &inp1 , int &inp2)
{
  int temp;
  temp = inp1 ;
  inp1 = inp2;
  inp2 = temp;
}
void swapRef(int *inp1 , int *inp2)
{
  int temp;
  temp = *inp1 ;
  *inp1 = *inp2;
  *inp2 = temp;
}
int main()
{
 int num1=10 ,num2=20;
 clrscr();
  printf("\n\tVAL : Value before swapping  num1 : %d num2 : %d ",num1,num2);
  swapVal(num1,num2);
  printf("\n\tVAL : Value after swapping  num1 : %d num2 : %d ",num1,num2);
  printf("\n\tREF: Value before swapping  num1 : %d num2 : %d ",num1,num2);
  swapRef(&num1,&num2);
  printf("\n\tREF: Value after swapping  num1 : %d num2 : %d ",num1,num2);
  printf("\n\tREFVAR: Value before swapping  num1 : %d num2 : %d ",num1,num2);
  swapRefVar(num1,num2);
  printf("\n\tREFVAR: Value after swapping  num1 : %d num2 : %d ",num1,num2);
 getch();
 return 0 ;
}
