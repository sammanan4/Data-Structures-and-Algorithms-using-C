#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<math.h>
struct Num{
	int info;
	struct Num *next;
	struct Num *prev;
};
typedef struct Num Num;

Num *start[10]={NULL},*end[10]={NULL},*x=NULL;

void BackIntoArray(int *arr){
	int i=0,j=0;
	Num *ptr=start[0],*temp;
	start[i]=NULL;
	while(i<10){
		while(ptr!=NULL){
			arr[j]=ptr->info;
			j++;
			temp=ptr;
			ptr=ptr->next;
			free(temp);
		}
		i++;
		ptr=start[i];
		start[i]=NULL;
	}
}
void InsertIntoList(int info,int temp){
	Num *n=(Num *)malloc(sizeof(Num));
	n->info=info;
	if(start[temp]==NULL){
		start[temp]=n;
		n->next=NULL;
		n->prev=NULL;
		end[temp]=start[temp];
	}
	else{
		end[temp]->next=n;
		n->prev=end[temp];
		n->next=NULL;
		end[temp]=n;
	}
}
void RadixSort(int *arr,int n,int lim){
	int i,m,l,temp;
	for(m=10,l=1;m<=lim;m*=10,l*=10){
		for(i=0;i<n;i++){
			temp=((arr[i]%m)/l);
			InsertIntoList(arr[i],temp);
			}
		BackIntoArray(arr);
	}
}
void main(){
	int arr[]={5,7,3,2,4,33,23,56,47,98,12,90,67,8,55,78,98,127,563,24,7,88,55,89,23,45,675,453,68,879,456,234},i,max=0;
	for(i=0;i<32;i++)
		if(max<arr[i])
			max=arr[i];
	i=0;
	while(max!=0){
		max=max/10;
		i++;
	}
	clock_t start,end;
	start=clock();
	RadixSort(arr,32,(i==1)?10:pow(10,i));
	end=clock();
	for(i=0;i<32;i++)
		printf("%d\t",arr[i]);
	printf("\nTime taken = %lf",(double)(end-start));
}
