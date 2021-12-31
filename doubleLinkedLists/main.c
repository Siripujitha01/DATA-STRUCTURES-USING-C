#include <stdio.h>
#include <malloc.h>
struct node
{
struct node *prev;
int data;
struct node *next;
};
struct node *first,*last,*temp,*p;
void create();
void delete();
void delete_at_begining();
void delete_at_end();
void delete_at_position();
void insert();
void insert_at_begining();
void insert_at_end();
void insert_at_position();
void display();
void search();
int main()
{
first=NULL;
last=NULL;
int ch;
do
{
printf("select one option \n1,create\n2.insert\n3.delete \n4.display\n5.Search\n 6.exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
create();
break;
case 2:
insert();
break;
case 3:
delete();
break;
case 4:
display();
break;
case 5:
    search();
    break;
case 6:
printf(".............EXIT.............");
break;
default:
printf("enter a valid option");
}
}while(ch!=6);
}
void create()
{
char ch='y';
struct node *newnode=(struct node*)malloc(sizeof(struct node));
if (first !=NULL)
printf("list is already created");
else
{
while(ch=='y' || ch=='Y')
{
    printf("enter the element:");
scanf("%d",&newnode->data);
newnode->next=NULL;
if (first ==NULL)
{
 newnode->prev=NULL;
 first=last=newnode;
}
else
{
newnode->prev=last;
last->next=newnode;
last=newnode;
}
printf("do you want to continue(y/n):");
fflush(stdin);
scanf("%c",&ch);
if (ch=='y' || ch=='Y')
newnode=(struct node*)malloc(sizeof(struct node));
else
break;
}
}
}
void insert()
{
int ch;
printf("select one option \n1.insert_at_begining\n2.insert_at_end\n3.insert_at_position:");
scanf("%d",&ch);
switch(ch)
{
case 1:
insert_at_begining();
break;
case 2:
insert_at_end();
break;
case 3:
insert_at_position();
break;
}
}
void insert_at_begining()
{
if (first==NULL)
printf("USE CREATE OPTION");
else
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
printf("enter the element:");
scanf("%d",&newnode->data);
newnode->next=first;
first->prev=newnode;
first=newnode;
newnode->prev=NULL;
}
}
void insert_at_end()
{
if (first==NULL)
printf("USE CREATE OPTION");
else
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
printf("enter the element:");
scanf("%d",&newnode->data);
newnode->prev=last;
last->next=newnode;
last=newnode;
newnode->next=NULL;
}
}
void insert_at_position()
{
int pos;
if (first==NULL)
printf("USE CREATE OPTION");
else
{
printf("enter position to insert:");
scanf("%d",&pos);
if (pos==1)
insert_at_begining();
else
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
printf("enter the element:");
scanf("%d",&newnode->data);
temp=first;
for(int i=1;i<=pos-2;i++)
temp=temp->next;
if(temp==NULL)
printf("invalid position");
else
{
newnode->prev=temp;
newnode->next=temp->next;
temp->next->prev=newnode;
temp->next=newnode;
}
}
printf("ELEMENT INSERTED");
}
}

void delete()
{
int ch;
printf("select one option \n1.delete_at_begining\n2.delete_at_end\n3.delete_at_position:");
scanf("%d",&ch);
switch(ch)
{
case 1:
delete_at_begining();
break;
case 2:
delete_at_end();
break;
case 3:
delete_at_position();
break;
}
}
void delete_at_begining()
{
if (first==NULL)
printf("USE CREATE OPTION");
else
{
printf("deleted element:%d",first->data);
first=first->next;
first->prev=NULL;
}
}
void delete_at_end()
{
if (first==NULL)
printf("USE CREATE OPTION");
else
{
printf("deleted element:%d",last->data);
last=last->prev;
last->next=NULL;

}
}
void delete_at_position()
{
int pos;
if (first==NULL)
printf("USE CREATE OPTION");
else
{
printf("enter position to delete:");
scanf("%d",&pos);
if (pos==1)
delete_at_begining();
else
{
temp=first;
for(int i=1;i<=pos-2;i++)
temp=temp->next;
if(temp==NULL)
printf("invalid position");
else
{
p=temp->next;
temp->next->next->prev=temp;
temp->next=temp->next->next;
printf("deleted element:%d",p->data);
free(p);
}
}
}
}
void display()
{
if (first==NULL)
printf("USE CREATE OPTION");
else
{
temp=first;
while(temp != NULL)
{
printf("\t %d",temp->data);
temp=temp->next;
}
printf("NULL");
}
}
void search()
{
    int ele,i=0;
    printf("enter element:");
    scanf("%d",&ele);
    temp=first;
    while(temp != NULL)
    {
        if(temp->data==ele)
        {
            printf("element found");
            i++;
        }
        temp=temp->next;
    }
    if (i==0)
        printf("element not found");
}





