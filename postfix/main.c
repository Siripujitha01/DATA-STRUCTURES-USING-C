#include <stdio.h>
#define N 20
char stack[N];
int top=-1;
int isoperator(char symbol)
{
if(symbol=='^'||symbol=='*'||symbol=='/'||symbol=='+'||symbol=='-')
{
return 1;
}
else
return 0;
}
int precedence(char symbol)
{
if(symbol=='^')
return 3;
else if(symbol=='*'||symbol=='/')
return 2;
else
return 1;
}
void push(int ele)
{
    if (top==N-1)
    {
       printf("stack is full");
    }
    else
    {
       top++;
       stack[top]=ele;
    }
}
int pop()
{
    int ele;
    if (top==-1)
    {
        return -1;
    }
    else
    {
       ele=stack[top];
       top--;
return ele;
    }
}
void main()
{
char infix[N],postfix[N],x,symbol;
int i=0,p=0,j;
printf("enter equation:");
gets(infix);
symbol=infix[i];
i=i+1;
while(symbol!='\0')
{
if(symbol=='(')
push(symbol);
else if((symbol>='A'&& symbol<='Z')||(symbol>='a'&& symbol<='z'))
postfix[j++]=symbol;
else if(isoperator(symbol)==1)
{
x=pop();
while(isoperator(x)==1 && precedence(x)>=precedence(symbol))
{
postfix[j++]=x;
x=pop();
}
push(x);
push(symbol);
}
else if(symbol==')')
{
x=pop();
while(x!='(')
{
postfix[j++]=x;
x=pop();
}
}
else
printf("invalid symbol");
symbol=infix[i++];
}
postfix[j++]='\0';
puts(postfix);
}
