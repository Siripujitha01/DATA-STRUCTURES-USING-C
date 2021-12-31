#include<stdio.h>
#include<malloc.h>
struct node
{
int data;
struct node *next;
};
struct node *top,*temp;
void  push()
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
printf("ENTER THE DATA IN A NEW NODE:");
scanf("%d",&newnode->data);
newnode->next=NULL;
if (top==NULL)
{
top=newnode;
}
else
{
newnode->next=top;
top=newnode;
}
printf("ELEMENT PUSHED SUCCESSFULLY\n");
}
void pop()
{
 temp=top;
 if (top==NULL)
           printf("THERE IS NO ELEMENTS IN THE STACK\n");
 else
{
 top=top->next;
 printf("POPPED ELEMENT IS :%d\n",temp->data);
 free(temp);
}
}
void main()
{
int ch;
top=NULL;
do
{
printf("SELECT WHICH OPTION YOU WANT TO PERFORM\n1.PUSH \n2. POP\n3.EXIT\n");
printf("\nENTER OPTION:");
scanf("%d",&ch);
switch(ch)
{
case 1:
   push();
   break;
case 2:
   pop();
   break;
case 3:
   printf("\n....EXIT....\n");
   break;
default:
   printf("PLEASE ENTER A VALID OPTION");
}
}while(ch !=3);
}
