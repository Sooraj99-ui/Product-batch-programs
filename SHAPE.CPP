#include<stdio.h>
#include<conio.h>
#include<iostream.h>
class SHAPE
{
 public:
 virtual DRAW();
 chumma();
 dummy();
};
SHAPE ::dummy()
{
  printf("\n\t Dummy");
}
SHAPE :: chumma()
{
  printf("\n\t Chumma in shape");
}
SHAPE :: DRAW()
{

}
class SQR : public SHAPE
{
  private:
  int side;
  public:
  DRAW();
  chumma();
};
SQR::DRAW()
{
  printf("\n\tDraw in sqr");
}
SQR :: chumma()
{
  printf("\n\t Chumma in square");
}
class RECT : public SHAPE
{
  private:
  int len;
  int breadth;
  public:
  DRAW();
  chumma();

};
RECT::DRAW()
{
  printf("\n\tDraw in Rect");
}
RECT :: chumma()
{
  printf("\n\t Chumma in rect");
}
class CIRCLE :  public SHAPE
{
  private:
  int radius;
  public:
  DRAW();
  chumma();

};
CIRCLE::DRAW()
{
  printf("\n\tDraw in Circle");
}
CIRCLE :: chumma()
{
  printf("\n\t Chumma in circle");
}

int main()
{
 clrscr();
 SHAPE sh;
 SHAPE * common= NULL;
 SQR sqr1;
 RECT rect1;
 CIRCLE cir1;
// common=&sh;
 common = &rect1;
 common->DRAW();
 getch();
 return 0 ;
}
