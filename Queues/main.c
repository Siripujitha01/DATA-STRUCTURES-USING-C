#include <stdio.h>
#define N 5
int queue[10];
int front=-1,rear=-1;
void enqueue(int ele)
{
    if (rear==N-1)
    {
       printf("Queue is full");
    }
    else
    {
        if(front==-1 && rear==-1)
               front=rear=0;
      else
                 rear++;
       queue[rear]=ele;
    }
}
void dequeue()
{
    int ele;
    if(front>rear || front==-1)
    {
        printf("stack is empty no element to pop");
        front=rear=-1;
    }
    else
    {
       ele=queue[front];
       front++;
       printf("poped element is:%d",ele);
    }
}
void peek()
{
     int ele;
     if (front==-1)
     {
        printf("Queue is empty no element at peek");
     }
     else
     {
          ele=queue[front];
          printf("peek element is:%d",ele);

     }
}
void isfull()
{
    if (rear==N-1)
    {
        printf("Queue is full");
    }
    else
    {
        printf("Queue is not  full");
    }
}
void isempty()
{
      if (front==-1 || front>rear)
      {
          printf("Queue is empty");
      }
      else
      {
         printf("Queue is not empty");
      }
}
void display()
{
       int i;
       if (front==-1 || front>rear)
       {
            printf("Queue is empty");
       }
       else
       {
            for (i=front;i<=rear;i++)
                {
                    printf("\t %d",queue[i]);
                }
       }
}
void initialize()
{
           front=rear=-1;
}
int main()
{
          int ch,ele;
          do
          {
             printf("\nSELECT AN  OPERATION TO PERFORM:\n");
             printf("1.ENQUEUE\n2.DEQUEUE\n3.PEEK\n4.ISFULL\n5.ISEMPTY\n6.DISPLAY\n7.INITIALIZE\n8.EXIT\n");
             printf("ENTER WHICH OPERATION YOU WANT TO PERFORM:\n");
             scanf("%d",&ch);
             switch (ch)
             {
              case 1:
                       printf("ENETR ELEMENT TO PUSH:\n");
                       scanf("%d",&ele);
                       enqueue(ele);
                       break;
              case 2:
                       dequeue();
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
