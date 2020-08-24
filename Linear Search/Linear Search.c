#include<stdio.h>
#include<conio.h>
void LinearSearch(int s, int n, int* array){
	int i;
	for(i=0;i<=n;i++)
		if(s==array[i]){
			printf("Element %d found at %d\n",s,i+1);
			return;
		}
	printf("Element not found ! \n");
			
}
void main(){
	int array[10],i,var;
	printf("Enter 10 elements of array : \n");
	for(i=0;i<10;i++)
		scanf("%d",&array[i]);
	printf("Enter element to be searched : ");
	scanf("%d",&var);
	LinearSearch(var,9,array);
	getch();

}
