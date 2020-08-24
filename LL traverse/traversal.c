#include<stdio.h>
#include<malloc.h>
#include<ctype.h>
struct list{
		int num;
		struct list *p;
	};
struct list *start,*ptr,*prev;
void insert(int n){
	struct list *new;
	new=(struct list *)malloc(sizeof(struct list));
	new->num=n;
	if(start==NULL){
		start=new;
		new->p=NULL;
	}
	else{
		new->p=start;
		start=new;
	}
}
void display_fwd(){
	int i;
	struct list *ptr;
	if(start==NULL)
		printf("Empty list\n");
	else{
		for(ptr=start;ptr!=NULL;ptr=ptr->p)
			printf("%d\t",ptr->num);
		printf("\n");
	}
	return;
}
void display_bwd(struct list *ptr){
	if(start==NULL)
		printf("Empty list\n");
	else if(ptr!=NULL){
		display_bwd(ptr->p);
		printf("%d\t",ptr->num);
	}
	else return;
}
	
void main(){
	start=NULL;
	int i,var;
	char choice;
		for(i=10;i>0;i--)
			insert(i);
	printf("'F' to traverse forwards\n'B' to traverse backwards\n");
	printf("'E' to exit\n");
	while(1){
		printf("Enter your choice :");
		scanf("%c",&choice);
		switch(toupper(choice)){
			case 'F':
				display_fwd();
				break;
			case 'B':
				display_bwd(start);
				printf("\n");
				break;
			case 'E':
				return;
			default:
				printf("Wrong Choice\n");
			}
			fflush(stdin);
	}
	getch();
}
