#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
struct bstnode
{
    int data;
    struct bstnode *left;
    struct bstnode *right;
};
   struct bstnode   *root=NULL;
   void bstinsert();
   void traverse();
   void preorder_traverse();
   void inoreder_traverse();
   void post_traverse();
   int bstsearch(struct bstnode *root,int ele);
   struct bstnode *delminnode(struct bstnode *node);
   struct bstnode *delnode(struct bstnode *node,int key);
void main()
{
    int ch,sar,ele;
    struct bstnode *search_r,*del_r;
    do
    {
        printf("\n ........MENU.........");
        printf("\n 1.INSERT\t 2.SEARCH \t 3.TRAVERSE\t 4.DELETE \t 5.EXIT:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            bstinsert();
            break;
        case 2:
            printf("ENTER ELEMENT TO SEARCH:");
            scanf("%d",&sar);
            ele=bstsearch(root,sar);
            if (ele!=NULL)
            printf("ELEMENT IS FOUND");
            else
            printf("ELEMENT IS NOT FOUND");
            break;
        case 3:
            traverse();
            break;
        case 4:
            printf("ENTER ELEMENT TO SEARCH:");
            scanf("%d",&sar);
            del_r=delnode(root,sar);
            if (del_r->data!=NULL)
            printf("ELEMENT IS Deleted");
            else
            printf("ELEMENT IS NOT FOUND");
            break;
        case 5:
            printf("........EXIT........");
            break;
        default :
            printf("PLEASE ENTER A VALID OPTION");
        }
    }while(ch != 5);
}
void bstinsert()
{
    int ele;
    printf("ENTER ELEMENT TO INSERT:");
    scanf("%d",&ele);
    struct bstnode *newnode=(struct bstnode *)malloc(sizeof(struct bstnode));
    newnode->data=ele;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root == NULL)
    {
        root=newnode;
        return;
    }
    else{
        struct bstnode *current =root;
        struct bstnode *parent=NULL;
        while(1)
        {
            parent=current;
            if(ele<=current->data)
            {
                current=current->left;
                if(current ==NULL)
                {
                    parent->left=newnode;
                    return;
                }
            }
            else{
                current=current->right;
                if(current ==NULL)
                {
                    parent->right=newnode;
                    return;
                }
            }
        }
    }
}
void traverse()
{
    printf("\n ELEMENTS IN PREORDER:");
    preorder_traverse(root);
    printf("\n ELEMENTS IN INORDER:");
    inorder_traverse(root);
    printf("\n ELEMENTS IN POSTORDER:");
    postorder_traverse(root );
}
void preorder_traverse(struct bstnode *node)
{
    if(node == NULL)
        printf("TREE IS EMPTY");
    else
    {
    printf("%d\t",node->data);
                if(node->left != NULL)
                    preorder_traverse(node->left);
                if(node->right != NULL)
                    preorder_traverse(node->right);

    }

}
void inorder_traverse(struct bstnode *node)
{
    if(node == NULL)
        printf("TREE IS EMPTY");
    else
    {
                if(node->left != NULL)
                    inorder_traverse(node->left);
            printf("%d\t",node->data);
                if(node->right != NULL)
                    inorder_traverse(node->right);

    }

}
void postorder_traverse(struct bstnode *node)
{
    if(node == NULL)
        printf("TREE IS EMPTY");
    else
    {
                if(node->left != NULL)
                    postorder_traverse(node->left);
                if(node->right != NULL)
                    postorder_traverse(node->right);
                        printf("  %d\t",node->data);


    }

}
int bstsearch(struct bstnode *root,int ele)
{
if (root==NULL || root->data==ele)
    return root;
else if(ele<root->data)
    return bstsearch(root->left,ele);
else if(ele>root->data)
    return bstsearch(root->right,ele);

}
struct bstnode *delminnode(struct bstnode *node)
{
   struct bstnode *current=node;
   while(current && current->left !=NULL)
        current=current->left;
   return current;
}
struct bstnode *delnode(struct bstnode *node,int key)
{
    if(node==NULL)
        return node;
    else if(key<node->data)
        node->left=delnode(node->left,key);
    else if(key>node->data)
        node->right=delnode(node->right,key);
    else if(node->left==NULL)
        {
             struct bstnode *temp=node->right;
             free(node);
             node=temp;
             return node;
        }
    else if(node->right==NULL)
        {
             struct bstnode *temp=node->left;
             free(node);
             node=temp;
             return node;
        }
    else
    {
              struct bstnode *temp=delminnode(node->right);
              node->data=temp->data;
              node->right=delnode(node->right,temp->data);
              return node;
    }
}



