#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#define max 100
char st[max];
int top=-1;
void push(float st[],float val){
if(top==max-1)
    printf("overflow");
    else{
        top++;
        st[top]=val;
        }

}
float pop(float st[]){
    float val=-1;
if(top==-1)
    printf("underflow");
    else{

        val=st[top];
        top--;
        }
    return val;
}
float evaluate(char exp[]){
 int i=0;
 float op1,op2,value;
 while(exp[i] !='\0')
 {

     if (isdigit(exp[i]))
        push(st,(float)(exp[i]-'0'));
     else{
        op2=pop(st);
        op1=pop(st);
        switch(exp[i])
        {
        case '+':
            value=op1+op2;
            break;
        case '-':
            value=op1-op2;
            break;
        case '*':
            value=op1*op2;
            break;
        case '/':
            value=op1/op2;
            break;
        case '%':
            value=(int)op1%(int)op2;
            break;
        }
        push(st,value);
     }
     i++;
 }
  return(pop(st));
}
void display()
{
    printf("%d",top);
    if (top==-1)
        printf("underflow");
    else {
        for (int i=0;i<=top;i++)
            printf("%d",st[i]);
    }
}

int main()
{
    float val;
    char exp[100];
    printf("enter postfix expression:");
    gets(exp);
    val=evaluate(exp);
    display();
    printf("%.2f",val);
    getch();
    return 0;
}
