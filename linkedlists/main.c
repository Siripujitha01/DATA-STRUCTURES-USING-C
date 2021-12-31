#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
struct node
{
    int data;
    struct node *next;
};
   struct node *first,*next,*temp,*p,*last;
void create();
void display();
void insert();
void deleted();
void insert_at_begining();
void insert_at_end();
void insert_at_position();
void delete_at_begining();
void delete_at_end();
void delete_at_position();
void search();
int main()
{
    int op;
    do
    {
    printf("\n select which operation to perform:\n 1.create \n 2.insert \n 3. delete \n 4.display \n 5.exit \n");
    scanf("%d",&op);
        switch (op)
        {
        case 1:
            {
            create();
            break;
            }
        case 2:
            {
                insert();
                 break;
            }
        case 3:
            {
                deleted();
                break;
            }
        case 4:
            {
                display();
                break;
            }
        case 5:
            {
                printf(".....EXIT......");
                break;
            }
        case 6:
            search();
            break;
        default:
            {
                printf("PLEASE ENTER A VALID OPTION");
            }
        }
    }while(op!=5);
}
void create()
{
 char ch='y';
 struct node *newnode= (struct node *)malloc(sizeof(struct node));
 if (first!=NULL)
 {
     printf("list is already created");
 }
 else
    {
        while(ch=='y' || ch=='Y')
            {
    printf("enter the data to list:\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(first==NULL)
    {
        first=last=newnode;
    }
    else
        {

        last->next=newnode;
        last=newnode;
        }
        printf("do you want to continue:");
        fflush(stdin);
        scanf("%c",&ch);
        if (ch=='y' || ch=='Y')
        {
            newnode=(struct node *)(malloc(sizeof(struct node)));
        }
        else
            break;
             }

 }
}
void insert()
{
    int op;
 printf("\n select one option to insert:\n 1.insert at begining \n 2.insert at end \n 3.insert at given position \n");
 scanf("%d",&op);
 switch(op)
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
    if (first ==NULL)
        printf("can't insert select create option");
    else
    {
        struct node *newnode= (struct node *)malloc(sizeof(struct node));
        printf("enter the data :");
        scanf("%d",&newnode->data);
        newnode->next=first;
        first=newnode;
        printf("\n inserted succesfully");
    }

}
void insert_at_end()
{
 if (first ==NULL)
        printf("can't insert select create option");
    else
    {
        struct node *newnode= (struct node *)malloc(sizeof(struct node));
        printf("enter the data :");
        scanf("%d",&newnode->data);
        last->next=newnode;
        last=newnode;
        last->next=NULL;
        printf("\n inserted succesfully");
    }

}
void insert_at_position()
{
    if (first ==NULL)
        printf("can't insert select create option");
    else
    {
        int pos;
        struct node *newnode= (struct node *)malloc(sizeof(struct node));
        printf("enter at which position you want to insert:");
        scanf("%d",&pos);
        if(pos==1)
            insert_at_begining();
        else{
                temp=first;
        for(int i=1;i<=pos-2;i++)
        {
            temp=temp->next;
        }
        if (temp ==NULL)
            printf("invalid position to insert");
        else{
        printf("enter the data :");
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
        }
        }
        printf("\n inserted succesfully");
    }

}
void deleted()
{
int op;
 printf("select one option to insert:\n 1.delete at begining \n 2.delete at end \n 3.delete at given position \n");
 scanf("%d",&op);
 switch(op)
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
    if (first ==NULL)
        printf("can't delete select create option");
    else
    {
       if (first->next==NULL)
       {
           printf("\n deleted element:%d",first->data);
           free(first);
           first=last=NULL;
       }
       else
        {
        temp=first;
       first=temp->next;
       printf("\n deleted element is:%d",temp->data);
       free(temp);
       }
    }
}
void delete_at_end()
{
 if (first ==NULL)
        printf("can't delete select create option");
    else
    {
        if (first->next==NULL)
        {
           printf("\n deleted element:%d",first->data);
           free(first);
           first=last=NULL;
       }
    else
        {
         temp=first;
         while (temp->next!=last)
         {
             temp=temp->next;
         }
         temp->next=NULL;
         printf("\n deleted element is:%d",last->data);
         free(last);
         last=temp;
       }
    }
}
void delete_at_position()
{
int pos;
        printf("enter at which position you want to insert:");
        scanf("%d",&pos);
        if(pos==1)
            delete_at_begining();
        else{
                temp=first;
        for(int i=1;i<=pos-2;i++)
        {
            temp=temp->next;
        }
        if (temp ==NULL)
            printf("invalid position to insert");
        else{
         p=temp->next;
        temp->next=temp->next->next;
        printf("\n deleted element is:%d",p->data);
        }
        }
}
void display()
{
temp=first;
printf("data is:");
while(temp!=NULL)
{
    printf("%d\t",temp->data);
    temp=temp->next;
}
printf("NULL");
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
