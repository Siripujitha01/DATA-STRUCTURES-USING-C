#include <stdio.h>
#include <stdlib.h>
void print_arr(int a[],int n);
void selection_sort(int a[],int n);

int main()
{
    int a[20],n,i;
    printf("enter how many elements in the array:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter the elements in the array:");
        scanf("%d",&a[i]);
    }
    printf("elements before sorted:");
    for(i=0;i<n;i++){
        printf("%d \t",a[i]);
    }
    selection_sort(a,n);
    print_arr(a,n);
    return 0;
}
void print_arr(int a[],int n)
{
    printf("\n elements after sorted:");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}
void selection_sort(int a[],int n)
{
    int i,temp,j,min;
    for (i=0;i<n-1;i++){
            min=i;
      for (j=i+1;j<n;j++){
        if (a[j]<a[min]){
            min=j;
        }
      }
        if(i!=min){
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
    }
    }
}
