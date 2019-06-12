#include<stdio.h>
#include<conio.h>
#include<iostream.h>
template <typename T>
void swap(T &inp1 , T &inp2)
{
  T temp;
  temp = inp1 ;
  inp1 = inp2;
  inp2 = temp;
}

int main()
{
char ch1 = 'A',ch2='S';
 int num1=10 ,num2=20;
 float  fnum1=7.29,fnum2=8.79;
 long int lnum1=100000,lnum2=200000;

 clrscr();
  printf("\n\tREFVAR: Value before swapping  num1 : %d num2 : %d ",num1,num2);
  swap(num1,num2);
  printf("\n\tREFVAR: Value after swapping  num1 : %d num2 : %d ",num1,num2);
  printf("\n\tREFVAR: Value before swapping  fnum1 : %f fnum2 : %f ",fnum1,fnum2);
  swap(fnum1,fnum2);
  printf("\n\tREFVAR: Value after swapping  fnum1 : %f fnum2 : %f ",fnum1,fnum2);
  printf("\n\tREFVAR: Value before swapping  ch1 : %c ch2 : %c ",ch1,ch2);
  swap(ch1,ch2);
  printf("\n\tREFVAR: Value after swapping  ch1 : %c ch2 : %c ",ch1,ch2);
  printf("\n\tREFVAR: Value before swapping lnum1 : %ld lnum2 : %ld ",lnum1,lnum2);
  swap(lnum1,lnum2);
  printf("\n\tREFVAR: Value after swapping  lnum1 : %ld lnum2 : %ld ",lnum1,lnum2);
   dummy(10);
 getch();
 return 0 ;
}
