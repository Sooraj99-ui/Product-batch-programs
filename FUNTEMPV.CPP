#include<stdio.h>
#include<conio.h>
#include<iostream.h>
template <class T>
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
 char* str1="selva";
 char *str2="arun";
 int num1=10 ,num2=20;
 float  fnum1=7.29,fnum2=8.79;
 long int lnum1=100000,lnum2=200000;

 clrscr();
 printf("\n%s %s " ,str1,str2);
 swap(str1,str2);
 printf("\n%s %s " ,str1,str2);


 getch();
 return 0 ;
}
