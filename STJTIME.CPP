#include<stdio.h>
#include<conio.h>
struct time
{
  int hh;
  int mm;
  int ss;
 static long int toSeconds(struct time gt)
 {
  return gt.hh*3600L+gt.mm* 60 + gt.ss;
 }
  long int toSeconds()
 {
  return hh*3600L+mm* 60 +ss;
 }
 static struct time toTime(long int tot_seconds)
 {
  struct time temp;
  temp.hh = tot_seconds/3600;
  temp.mm = (tot_seconds%3600)/60;
  temp.ss = (tot_seconds%3600)%60;
  return temp;
 }
 struct time addTime(struct time t1 )
 {
  long int inseconds1 , inseconds2,sum;
  struct time temp;
  inseconds1 =toSeconds(t1);
  inseconds2 = toSeconds();
  sum = inseconds1  +inseconds2;
  temp = toTime(sum);
  return temp;
 }
 void showTime()
 {
  printf("\n\t%2d:%2d:%2d",hh,mm,ss);
 }
 void validate()
 {
  if(hh <0 || hh >23 || mm <0
    || mm > 59||ss <0 || ss >59)
    hh = mm =ss=10;
 }
};
int main()
{
 struct time now={3,48,20};
 struct time later={35,148,420};
 clrscr();
 later.validate();//validate(&later);
 later.showTime();//showTime(later);
 later = now.addTime(later);//addTime(now,later);
 later.showTime();//showTime(later);
 getch();
 return 0 ;
}
