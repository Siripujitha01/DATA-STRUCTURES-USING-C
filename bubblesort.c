#include <stdio.h>
#include <stdlib.h>
void print_arr(int a[],int n);
void bubble_sort(int a[],int n);
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
    bubble_sort(a,n);
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
void bubble_sort(int a[],int n)
{
    int i,j,f,temp;
    for (i=0;i<n;i++)
        {
            f=0;
        for (j=0;j<n;j++)
        {
            if (a[i]<a[j])
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
                f+=1;
            }
        }
        if(f==0){
            printf("sorted");
            break;
        }
    }

}
