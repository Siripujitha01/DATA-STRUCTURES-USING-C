#include<stdio.h>
void mergeSort(int [],int,int);
void merge(int[],int,int,int);
int main() {
	int a[100],n,i;

	printf("Enter the size of array : \n");
	scanf("%d",&n);

	printf("Enter the array elements : \n");
	for(i = 0 ;i < n;i++ )
		scanf("%d",&a[i]);

	mergeSort(a , 0 ,n - 1);

	printf("Sorted elements are :\n");
	for(i = 0;i < n ;i++ )
 		printf("%d ",a[i]);

}

void mergeSort(int a[],int lb,int ub) {
	int mid;

	if(lb >= ub)
		return;
	mid = (lb + ub) / 2;

	mergeSort(a , lb , mid);
	mergeSort(a, mid + 1,ub);
	merge(a, lb, mid, ub);
}
void merge(int a[],int lb,int mid,int ub) {
	int b[100],k,i,j;
	i = lb;
	j = mid + 1;
	k = lb;
	while(i <= mid && j <= ub) {
		if(a[i] < a[j]) {
			b[k] = a[i];
			i++;
		 }
		else {
			b[k] = a[j];
			j++;
		}
		k++;
	}
if(i<=mid)
{
	while(i <= mid) {
		b[k] = a[i];
		k++;
		i++;
	}}
else{
	while(j <= ub) {
		b[k] = a[j];
		k++;
		j++;
	}}
	for(i = lb;i <= ub;i++) {
		a[i] = b[i];

}
}
