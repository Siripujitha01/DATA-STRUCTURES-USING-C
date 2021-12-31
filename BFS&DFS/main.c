#include <stdio.h>
#include <stdlib.h>
#define max 5
int stack[max];
int queue[max];
void bfs(int adj[max][max],int start)
{
    int front=-1,rear=-1,i,visited[max]={0};
    queue[++rear]=start;
    visited[start]=1;
    printf(" %c \t ",start+65);
    while(front!=rear)
    {
        start=queue[++front];
        for (i=0;i<max;i++)
        {
            if(adj[start][i]==1 && visited[i]==0)
            {
                queue[++rear]=i;
                visited[i]=1;
                printf("%c \t ",i+65);

            }
        }
    }
   printf("COMPLETED");
}
void dfs(int adj[max][max],int start)
{
    int top=-1,i,visited[max]={0};
    stack[++top]=start;
    visited[start]=1;
    printf("\n%c \t ",start+65);
    while(top != -1)
    {
        start=stack[top];
        for (i=0;i<max;i++)
        {
            if(adj[start][i]==1 && visited[i]==0)
            {
                stack[++top]=i;
                visited[i]=1;
                printf(" %c \t ",i+65);
                break;
            }
        }
        if (i==max)
            top=top-1;
    }
   printf("COMPLETED");
}
void main()
{
    int adj[max][max],i,j;
    for (i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            printf("\n ENTER ELEMENTS IN MATRIX:");
            scanf("%d",&adj[i][j]);
        }

    }
    bfs(adj,0);
    dfs(adj,0);

}
