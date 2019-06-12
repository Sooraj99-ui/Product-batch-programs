#include<stdio.h>
#include<conio.h>
class TIME
{
 //data
  int hh;
  int mm;
  int ss;
 //functions act on that data
 public:
 TIME(int h ,int m  ,int s);
 TIME operator+(TIME);
 void showTime();
};

/* TIME()
 {
   hh=mm=ss=16;
 }
 */
 TIME::TIME(int h=0, int m=0, int s=0)
 {
  if(h<0||h>23||m<0||m>59||s<0||s>59)
   hh=mm=ss=10;
  else
  {
   hh=h;
   mm=m;
   ss=s;
  }
 }
 void TIME::showTime()
 {
  printf("\n\t %d : %d : %d",hh,mm,ss);
 }
  TIME TIME::operator + (TIME gt)
 {
  long int inseconds1 , inseconds2,sum;
  TIME temp;
  inseconds1 = gt.hh*3600L+gt.mm*60+gt.ss;
  inseconds2 = hh*3600L+mm*60+ss;
  sum = inseconds1  +inseconds2;
  temp.hh = sum/3600;
  temp.mm = (sum%3600)/60;
  temp.ss = (sum%3600)%60;
  return temp;
 }
int main()
{
// TIME now(100,200,300);
 TIME now(4,22);
 TIME eppudi(1,20,10);
 clrscr();
 //now.init(100,200,300);
 //now.showTime();
// eppudi.showTime();
// eppudi =now.addTime(eppudi);
 eppudi = eppudi+now;//sum = sum +num;
 eppudi.showTime();
 getch();
 return 0 ;
}
