#include<stdio.h>
#include<malloc.h>
#include<time.h>
void Merge(int *left,int l,int *right,int r,int *arr,int n){
	int i=0,j=0,k=0;
	while(j<l && k<r){
		if(left[j]<right[k]){
			arr[i]=left[j];
			j++;
		}
		else{
			arr[i]=right[k];
			k++;
		}
		i++;
	}
	while(j<l){
		arr[i]=left[j];
		j++;
		i++;
	}
	while(k<r){
		arr[i]=right[k];
		k++;
		i++;
	}
//	for(i=0;i<l;i++)
//		free(left+i);
//	for(j=0;j<r;j++)
//		free(right+j);
//	return;
}
void MergeSort(int *arr,int n){
	if(n<2)
		return;
	int mid=n/2,i,j;
	int left[mid],right[n-mid];
	for(i=0;i<mid;i++){
		left[i]=arr[i];
	}
	for(j=0;j<n-mid;j++,i++){
		right[j]=arr[i];
	}
	MergeSort(left,mid);
	MergeSort(right,n-mid);
	Merge(left,mid,right,n-mid,arr,n);
	return;
}
void main(){
	int arr[10000],i;
	for(i=9999;i>=0;--i)
		arr[9999-i]=i;
	clock_t start,end;
	start=clock();
	MergeSort(arr,10000);
	end=clock();
	for(i=0;i<10000;i++)
		printf("%d\t",arr[i]);
	printf("\nTime taken = %lf",(double)(end-start));
}
