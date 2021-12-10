#include<stdio.h>
void quick_sort(int a[],int lb,int ub)
{
    int temp,i,j,pivot;
    if(lb<ub)
    {
    pivot=lb;
    i=lb;
    j=ub;
    while (i<j)
    {
    while (a[i]<=a[pivot] && i<ub)
    i++;
    while (a[j]>a[pivot])
    j--;
    if (i<j){
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
    }
    }
    temp=a[j];
    a[j]=a[pivot];
    a[pivot]=temp;
    quick_sort(a,lb,j-1);
    quick_sort(a,j+1,ub);
    }
      printf("\nrequired sorted array is :");
      for (i=lb;i<=ub;i++)
      {
      printf("%d",a[i]);
      }
    
}
void main()
{
  int a[100],lb,ub,i;
  printf("enter lower bound in the array:");
  scanf("%d",&lb);
  printf("enter upper bound in the array:");
  scanf("%d",&ub);
  printf("enter elements in array:");
  for (i=lb;i<=ub;i++){
   scanf("%d",&a[i]);
  }
  printf("given unsorted array is :\n");
    for (i=lb;i<=ub;i++){
   printf("%d",a[i]);
  }
  quick_sort(a,lb,ub);
  }