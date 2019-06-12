#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<alloc.h>
class STRING
{
  char *str;
  int len;

  public:
  STRING();
  STRING(STRING&);
  ~STRING();
  STRING(char*);
  STRING& operator=(STRING&);
  void showString();
  friend ostream& operator << (ostream& cout , STRING gs)
  {
     printf("\n%s",gs.str);
    //cout<<gs;
    return cout;
  }
};

 STRING::~STRING()
  {
    free(str);
    len=0;
    printf("\n\tDestructor called");
  }

STRING::STRING()
{
 str=NULL;
 len=0;
}
STRING::STRING(STRING & gs)
{

}

STRING::STRING(char * gstr)
{
 int ind;
 for(len=0 ;gstr[len];len++);
 len++;
 str = (char*)malloc(len);
 for(ind= 0; ind<len ; ind++)
  str[ind] = gstr[ind];
 str[ind]=NULL;
}

void STRING::showString()
{
 printf("\n%s",str);
}

int main()
{
 clrscr();
 STRING myname("Sridhar Arumugasamy");
 STRING stuname("Harsha Vardhan");
// myname.showString();
 cout<<myname<<stuname;
 getch();
 return 0 ;
}
