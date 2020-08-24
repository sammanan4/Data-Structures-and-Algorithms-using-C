#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<ctype.h>
struct Node{
	int info;
	struct Node *left,*right;
};
typedef struct Node Node;

Node * create(Node *n,int info){
	if(n==NULL){
		n=(Node *)malloc(sizeof(Node));
		n->info=info;
		n->right=NULL;
		n->left=NULL;
		return(n);
	}
	if(n->info<=info)
		n->right=create(n->right,info);
	else
		n->left=create(n->left,info);
	return(n);
}
void Display(Node *n,int level){
	int i;
	if(n){
		Display(n->left,level+1);
		printf("\n");
		for(i=0;i<level;i++)
			printf(" ");
		printf("%d\n",n->info);
		Display(n->right,level+1);
	}
}
void main(){
	int info;
	char choice;
	Node *n;
	n=NULL;
	printf("'I' to insert\n'D' to display the tree\n'E' to exit\n");
	while(1){
		printf("Select an option : ");
		scanf("%c",&choice);
		switch(toupper(choice)){
			case 'I':
				printf("Enter the element : ");
				scanf("%d",&info);
				n=create(n,info);
				break;
			case 'D':
				printf("The Tree is : \n");
				Display(n,1);
				break;
			case 'E':
				return;
			default:printf("\nInvalid Option\n");
		}
		fflush(stdin);
	}
	getch();
}
