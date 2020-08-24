#include<stdio.h>
void BinarySearch(int s,int start,int end,int* array){
	if(start>end)
		printf("Element not found");
	else{
		int mid=(start+end)/2;
		if(array[mid]==s){
			printf("Element %d found at %d",s,mid+1);
			return;}
		if(array[mid]>s)
			BinarySearch(s,start,mid-1,array);
		else BinarySearch(s,mid+1,end,array);
	}
	return;
}
void main(){
	int array[10],i,var;
	printf("Enter 10 elements of array in sorted order\n");
	for(i=0;i<10;i++)
		scanf("%d",&array[i]);
	printf("Enter element to be searched : ");
	scanf("%d",&var);
	BinarySearch(var,0,9,array);
	getch();
}
