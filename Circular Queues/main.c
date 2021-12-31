#include <stdio.h>
#define N 5
int queue[10];
int front=-1,rear=-1;
void enqueue(int ele)
{
    if ((front==0 && rear==N-1)||(front>0&&rear==front-1))
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
    if(rear==-1 && front==-1)
    {
        printf("stack is empty no element to pop");
    }
    else
    {
       ele=queue[front];
       if(front==rear)
            front=rear=-1;
       else if(front==N-1)
             front=0;
       else
        front++;
       printf("poped element is:%d",ele);
    }
}
void isfull()
{
    if ((front==0 && rear==N-1)||(front>0&&rear==front-1))
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
      if (front==-1 || rear==-1)
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
       if (front==-1 || rear==-1)
       {
            printf("Queue is empty");
       }
       else if(front<= rear)
       {
            for (i=front;i<=rear;i++)
                {
                    printf("\t %d",queue[i]);
                }
       }
        else
       {
            for (i=front;i<=N-1;i++)
            printf("\t %d",queue[i]);
            for (int j=0;j<=rear;j++)
            printf("\t %d",queue[j]);
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
             printf("1.ENQUEUE\n2.DEQUEUE\n3.ISFULL\n4.ISEMPTY\n5.DISPLAY\n6.INITIALIZE\n7.EXIT\n");
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
                      isfull();
                      break;
             case 4:
                      isempty();
                      break;
             case 5:
                      display();
                      break;
             case 6:
                      initialize();
                      break;
             case 7:
                      printf("THANKYOU");
                      break;
             default:
                      printf("PLEASE ENTER A VALID NUMBER");
                      break;
            }
        }while(ch!=7);
}
