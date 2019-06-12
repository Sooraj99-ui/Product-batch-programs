#include<stdio.h>
#include<conio.h>
class TIME
{
 //data
  long int totseconds;
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
  printf("\n\tConstruct called");
  if(h<0||h>23||m<0||m>59||s<0||s>59)
   totseconds=36000L+600+10; //10*3600+10*60+10 //10:10:10
  else
   totseconds=h*3600L+m*60+s;
 }
 void TIME::showTime()
 {
  int hh,mm,ss;
  hh=totseconds/3600;
  mm=(totseconds%3600)/60;
  ss=(totseconds%3600)%60;
  printf("\n\t %d : %d : %d",hh,mm,ss);
 }
  TIME TIME::operator + (TIME gt)
 {
  long int sum,h,m,s;
  sum =  totseconds +gt.totseconds;
  h=sum/3600;
  m=(sum%3600)/60;
  s=(sum%3600)%60;
  return TIME(h,m,s);
 }

int main()
{
// TIME now(100,200,300);
 clrscr();
 TIME now(4,22);
 TIME eppudi(1,20,10);
 //now.init(100,200,300);
 now.showTime();
 eppudi.showTime();
// eppudi =now.addTime(eppudi);
 eppudi = eppudi+now;//sum = sum +num;
 eppudi.showTime();
 getch();
 return 0 ;
}
