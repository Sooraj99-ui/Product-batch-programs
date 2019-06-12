#include<stdio.h>
#include<conio.h>
#include<limits.h>//inlcuding
void fun(int * arr , int size , int curr_ind,int prev ,int*seq,int s_ind)
{
 int ind;
 if(curr_ind==size)//base condition
 {
  for(printf("\n\t"),ind= 0 ;ind < s_ind ; ind++)
     printf("%d ",seq[ind]);
  return;
 }
   fun(arr,size,curr_ind+1,prev,seq,s_ind);  //excluding
   if(arr[curr_ind] > prev)
   {
    prev= seq[s_ind++]=arr[curr_ind];//inlcuding
    fun(arr,size,curr_ind+1,prev,seq,s_ind);
   }
}
int main()
{
 int arr[]={3,1,2,4,5};
 int size,prev=INT_MIN;
 int seq[5];
 clrscr();
 size= sizeof arr / sizeof arr[0];
 fun(arr,size,0,prev,seq,0);
 getch();
 return 0 ;
}
