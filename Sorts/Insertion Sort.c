#include<stdio.h>
#include<time.h>
void InSort(int *arr,int n){
	int hole,i,j;
	for(i=1;i<n;i++){
		hole=arr[i];
		for(j=i;j>0;j--){
			if(hole<arr[j-1])
				arr[j]=arr[j-1];
			else
				break;
		}
		arr[j]=hole;
	}
}
void main(){
	int arr[10000],i;
	for(i=9999;i>=0;--i)
		arr[9999-i]=i;
	clock_t start,end;
	start=clock();
	InSort(arr,10000);
	end=clock();
	for(i=0;i<10000;i++)
		printf("%d\t",arr[i]);
	printf("\nTime taken = %lf",(double)(end-start));
}
