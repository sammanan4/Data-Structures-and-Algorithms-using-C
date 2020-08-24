#include<stdio.h>
#include<malloc.h>
#include<conio.h>
void BubbleSort(int *arr,int n){
	int i,j,temp;
	for(i=n-1;i>=0;i--)
		for(j=1;j<=i;j++){
			if(arr[j-1]>arr[j]){
				temp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=temp;	}
		}
}
void SelectionSort(int *arr,int n){
	int i,j,temp;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;	}
		}
}
void InsertionSort(int *arr,int n){
	int hole,i,j;
	for(i=1,hole=arr[i];i<n;i++,hole=arr[i]){
		for(j=i;j>0;j--)
			if(hole<arr[j-1])
					arr[j]=arr[j-1];
			else	break;	
		arr[j]=hole;
	}
}
void main(){
	int *arr,*arr1,*arr2,i,n;
	char choice;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	arr1=(int *)malloc(n*sizeof(int));
	arr2=(int *)malloc(n*sizeof(int));
	printf("Enter the elements of array\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		arr1[i]=arr[i];
		arr2[i]=arr[i];
	}
	BubbleSort(arr,n);
	printf("Bubble Sorted : \n");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	SelectionSort(arr1,n);
	printf("\n\nSelection Sorted : \n");
	for(i=0;i<n;i++)
		printf("%d\t",arr1[i]);
	InsertionSort(arr2,n);
	printf("\n\nInsertion Sorted : \n");
	for(i=0;i<n;i++)
		printf("%d\t",arr2[i]);
	getch();
}
