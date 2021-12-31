#include <stdio.h>
#include <stdlib.h>
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
}
void print_arr(int a[],int n)
{

      printf("\n required sorted array is :");
      for (int i=0;i<n;i++)
      {
      printf("\t %d",a[i]);
      }

}
void main()
{
  int a[100],lb,ub,i,n;
  printf("enter size of the array:");
  scanf("%d",&n);
  printf("enter elements in array:");
  for (i=0;i<n;i++){
   scanf("%d",&a[i]);
  }
  printf("given unsorted array is :\n");
    for (i=0;i<n;i++){
   printf("\t %d",a[i]);
  }
  lb=0;
  ub=n-1;
  quick_sort(a,lb,ub);
  print_arr(a,n);
  }
