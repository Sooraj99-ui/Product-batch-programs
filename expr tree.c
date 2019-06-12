#include<stdio.h>
#include<windows.h>



// 10: 42 11:09
#define OPERATOR 1
#define OPERAND 2
typedef struct expr
{
    struct expr * left;
    char ope_opr;
    struct expr * right;

} EXPR;

typedef EXPR * EXPR_PTR;
COORD coord={0,0};
void gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

 void draw_tree( int start  , int end , EXPR_PTR  dispptr)
{
   int col;
   static int row = 1;
   col = (end - start )/ 2 + start;
   if(dispptr)  {
   gotoxy(col,row);
   printf("%c",dispptr->ope_opr);

   row+=3;
   draw_tree(start,end/2 + start/2,dispptr->left);
   draw_tree(end/2  +start/2 + 1, end , dispptr -> right);
   row-=3;
   }
}









EXPR_PTR stack[100];
int top = -1;
void push(EXPR_PTR);
EXPR_PTR pop();
EXPR_PTR makenode(char);
int isOperator(char);
int solve(EXPR_PTR);

int main()
{
    char postfix[] = "93+35+*92-82/**";
    int index, output;
    EXPR_PTR node=NULL, root = NULL;
    for(index = 0; postfix[index] ; index++)
    {
        if(isOperator(postfix[index])== OPERATOR)
        {
         node = makenode(postfix[index]);
          node->right = pop();
          node->left = pop();
           push(node);

        }  // operator
        else
        {
           node = makenode(postfix[index]);
           push(node);


        }
    }

    root = pop();

draw_tree(1,80, root);

output = solve(root);

printf("\n\n\n\n\n%d ", output);

return 0;
}

int solve(EXPR_PTR process)
{
    int leftVal, rightVal;
    if(process->left == NULL)
        return process->ope_opr - '0';
    leftVal = solve(process->left);
    rightVal = solve(process->right);
    switch(process->ope_opr)
    {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
        case '%': return leftVal % rightVal;
    //    case '^': return leftVal + rightVal;

    }

}
void push(EXPR_PTR keepit)
{
    stack[++top] = keepit;
}


EXPR_PTR pop()
{
    EXPR_PTR temp;
    temp = stack[top];
    top--;
    return temp;

}
EXPR_PTR makenode(char ch)
{
   EXPR_PTR nn;
   nn = (EXPR_PTR ) malloc(sizeof(EXPR));
   nn->ope_opr = ch;
   nn->left = nn->right = NULL;
   return nn;






}
int isOperator(char ch) {
if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%'\
       || ch == '^') return OPERATOR;
       return OPERAND;


}






