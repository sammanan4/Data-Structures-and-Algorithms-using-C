#include<stdio.h>
#include<time.h>

void SelSort(int *arr,int n){
	int i,j,temp;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
}
void main(){
	int arr[10000],i;
	for(i=9999;i>=0;--i)
		arr[9999-i]=i;
	clock_t start,end;
	start=clock();
	SelSort(arr,10000);
	end=clock();
	for(i=0;i<10000;i++)
		printf("%d\t",arr[i]);
	printf("\nTime taken = %lf",(double)(end-start));
}
