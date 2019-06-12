#include<stdio.h>
#include<conio.h>
#include<iostream.h>
void swap(int &inp1 , int &inp2)
{
  int temp;
  temp = inp1 ;
  inp1 = inp2;
  inp2 = temp;
}

void swap(short int &inp1 , short int &inp2)
{
  short int temp;
  temp = inp1 ;
  inp1 = inp2;
  inp2 = temp;
}
void swap(long int &inp1 ,long  int &inp2)
{
  long int temp;
  temp = inp1 ;
  inp1 = inp2;
  inp2 = temp;
}
void swap(char &inp1 ,char &inp2)
{
  char temp;
  temp = inp1 ;
  inp1 = inp2;
  inp2 = temp;
}
void dummy(short int num1)
{
 printf("%d",num1);

}
void dummy(long int num1)
{
 printf("%ld",num1);

}

void swap(float &inp1 , float &inp2)
{
  float temp;
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
