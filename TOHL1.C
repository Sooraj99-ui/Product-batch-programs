#include<stdio.h>
#include<conio.h>
#define NOD 7
#include<limits.h>
int main()
{
 int src[NOD+1],des[NOD+1],tem[NOD+1];
 int sTop,dTop,tTop,ind;

 clrscr();
 for(ind=0; ind< NOD ; ind++)
 {
  src[ind] = ind+1;
  des[ind] = tem[ind] = -1;

 }
 src[NOD] = des[NOD] =tem[NOD] = INT_MAX;
 sTop = 0;
 dTop = tTop = NOD;
 while(1)
 {
 if(src[sTop] >des[dTop])
 {
  sTop--;
  src[sTop] = des[dTop];
  des[dTop] = -1;
  dTop++;
 }
 else
 {
  dTop--;
  des[dTop] = src[sTop];
  src[sTop] = -1;
  sTop++;
 }
 if(dTop==0) break;
 if(src[sTop] >tem[tTop])
 {
  sTop--;
  src[sTop] = tem[tTop];
  tem[tTop] = -1;
  tTop++;
 }
 else
 {
  tTop--;
  tem[tTop] = src[sTop];
  src[sTop] = -1;
  sTop++;
 }
 if(tem[tTop] >des[dTop])
 {
  tTop--;
  tem[tTop] = des[dTop];
  des[dTop] = -1;
  dTop++;
 }
 else
 {
  dTop--;
  des[dTop] = tem[tTop];
  tem[tTop] = -1;
  tTop++;
  }
  if(dTop==0) break;
}
 getch();
 return 0 ;
}
