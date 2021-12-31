#include <stdio.h>
#include <stdlib.h>
void print_arr(int a[],int n);
void insertion_sort(int a[],int n);

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
    insertion_sort(a,n);
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
void insertion_sort(int a[],int n)
{
    int i,j,key;
    for (i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while (j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j-=1;
        }
        a[j+1]=key;
    }
}
