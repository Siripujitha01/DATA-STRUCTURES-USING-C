#include <stdio.h>
#define N 5
int stack[5];
int top=-1;
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
void pop()
{
    int ele;
    if (top==-1)
    {
        printf("stack is empty no element to pop");
    }
    else
    {
       ele=stack[top];
       top--;
       printf("poped element is:%d",ele);
    }
}
void peek()
{
     int ele;
     if (top==-1)
     {
        printf("stack is empty no element at peek");
     }
     else
     {
          ele=stack[top];
          printf("peek element is:%d",ele);

     }
}
void isfull()
{
    if (top==N-1)
    {
        printf("stack is full");
    }
    else
    {
        printf("stack not is full");
    }
}
void isempty()
{
      if (top==-1)
      {
          printf("stack is empty");
      }
      else
      {
         printf("stack is not empty");
      }
}
void display()
{
       int i;
       if (top==-1)
       {
            printf("stack is empty");
       }
       else
       {
            for (i=top;i>=0;i--)
                {
                    printf("/t %d",stack[i]);
                }
       }
}
void initialize()
{
           top=-1;
}
int main()
{
          int ch,ele;
          do
          {
             printf("\nSELECT AN  OPERATION TO PERFORM:\n");
             printf("1.PUSH\n2.POP\n3.PEEK\n4.ISFULL\n5.ISEMPTY\n6.DISPLAY\n7.INITIALIZE\n8.EXIT\n");
             printf("ENTER WHICH OPERATION YOU WANT TO PERFORM:\n");
             scanf("%d",&ch);
             switch (ch)
             {
              case 1:
                       printf("ENETR ELEMENT TO PUSH:\n");
                       scanf("%d",&ele);
                       push(ele);
                       break;
              case 2:
                       pop();
                       break;
             case 3:
                       peek();
                       break;
             case 4:
                      isfull();
                      break;
             case 5:
                      isempty();
                      break;
             case 6:
                      display();
                      break;
             case 7:
                      initialize();
                      break;
             case 8:
                      printf("THANKYOU");
                      break;
             default:
                      printf("PLEASE ENTER A VALID NUMBER");
                      break;
            }
        }while(ch!=8);
}

