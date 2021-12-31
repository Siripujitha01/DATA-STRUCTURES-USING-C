#include<stdio.h>
#include<malloc.h>
struct node
{
int data;
struct node *next;
};
struct node *front,*last,*temp;
void  enqueue()
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
printf("ENTER THE DATA IN A NEW NODE:");
scanf("%d",&newnode->data);
newnode->next=NULL;
if (front==NULL)
{
front=last=newnode;
}
else
{
last->next=newnode;
last=newnode;
}
printf("ELEMENT PUSHED SUCCESSFULLY\n");
}
void dequeue()
{
 temp=front;
 if (front==NULL)
           printf("THERE IS NO ELEMENTS IN THE QUEUE\n");
 else
{
 front=front->next;
 printf("POPPED ELEMENT IS :%d\n",temp->data);
 free(temp);
}
}
void display()
{

    if(front==NULL)
        printf("queue is empty");
    else{
        temp=front;
        while(temp != NULL)
        {
            printf("%d",temp->data);
            temp=temp->next;
        }

    }
}
void main()
{
int ch;
front=NULL;
last=NULL;
do
{
printf("SELECT WHICH OPTION YOU WANT TO PERFORM\n1.ENQUEUE \n2. DEQUEUE\n3.DISPLAY\n4.EXIT\n");
printf("\nENTER OPTION:");
scanf("%d",&ch);
switch(ch)
{
case 1:
   enqueue();
   break;
case 2:
   dequeue();
   break;
case 3:
    display();
    break;
case 4:
   printf("\n....EXIT....\n");
   break;
default:
   printf("PLEASE ENTER A VALID OPTION");
}
}while(ch !=4);
}
