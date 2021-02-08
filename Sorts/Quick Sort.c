#include<stdio.h>
#include<time.h>
int Partition(int *arr,int start, int end){
	int Pivot=end,i,PIndex=start,temp;
	for(i=start;i<end;i++){
		if(arr[i]<=arr[Pivot]){
			temp=arr[i];
			arr[i]=arr[PIndex];
			arr[PIndex]=temp;
			PIndex++;
		}
	}
	temp=arr[Pivot];
	arr[Pivot]=arr[PIndex];
	arr[PIndex]=temp;
	return PIndex;
}
void QuickSort(int *arr,int start,int end){
	int PIndex;
	if(start<end){
		PIndex=Partition(arr,start,end);
		QuickSort(arr,start,PIndex-1);
		QuickSort(arr,PIndex+1,end);
	}
}
void main(){
	int arr[10000],i;
	for(i=9999;i>=0;--i)
		arr[9999-i]=i;
	clock_t start,end;
	start=clock();
	QuickSort(arr,0,9999);
	end=clock();
	for(i=0;i<10000;i++)
		printf("%d\t",arr[i]);
	printf("\nTime taken = %lf",(double)(end-start));
}
