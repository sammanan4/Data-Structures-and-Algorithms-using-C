#include<stdio.h>
void BubbleSort(int *arr,int n){
	int i,j,temp;
	for(i=n-1;i>=0;i--)
		for(j=1;j<=i;j++){
			if(arr[j-1]>arr[j]){
				temp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=temp;			
			}
		}
}
void main(){
	int i,arr[]={9,2,4,7,4};
	BubbleSort(arr,5);
	for(i=0;i<5;i++)
		printf("%d\t",arr[i]);
	
}
