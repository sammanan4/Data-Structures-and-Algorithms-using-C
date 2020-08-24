#include<stdio.h>
#include<malloc.h>
struct list{
	int num;
	struct list *prev,*next;
};
struct list *start=NULL,*ptr;
void insert(int n){
	struct list *new;
	new=(struct list *)malloc(sizeof(struct list));
	new->num=n;
	if(!start){
		start=new;
		new->next=start;
		new->prev=start;
		ptr=start;
	}
	else{
		new->next=start;
		new->prev=start->prev;
		start->prev->next=new;
		start->prev=new;
	}
	return;
}
void display(char traverse){
	int i;
	if(!start)
		printf("Empty list");
	else{
		if(traverse=='F'){
			for(ptr=start;ptr->next!=start;ptr=ptr->next)
				printf("%d\t",ptr->num);
			printf("%d\n",ptr->num);	}
		else{ for(ptr=start->prev;ptr!=start;ptr=ptr->prev)
				printf("%d\t",ptr->num);
			  printf("%d\n",ptr->num);	}
	}
	return;
}
void main(){
	int i,var;
	char choice;
	for(i=1;i<=10;i++)
		insert(i);
	printf("'F' to traverse forwards\n'B' to traverse backwards\n");
	printf("'E' to exit\n");
	while(1){
		printf("Enter your choice :");
		scanf("%c",&choice);
		switch(toupper(choice)){
			case 'F':
				display('F');
				break;
			case 'B':
				display('B');
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
