#include<stdio.h>
#include<malloc.h>
#include<ctype.h>
#include<conio.h>
struct node{
	int info;
	struct node* left;
	struct node* right;
};
typedef struct node Node;
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
void Inorder(Node* n){
	int i;
	if(n!=NULL){
		Inorder(n->left);
		printf("%d\t",n->info);
		Inorder(n->right);
	}
}
void Preorder(Node* n){
	int i;
	if(n!=NULL){
		printf("%d\t",n->info);
		Preorder(n->left);
		Preorder(n->right);
	}
}
void Postorder(Node* n){
	int i;
	if(n!=NULL){
		Postorder(n->left);
		Postorder(n->right);
		printf("%d\t",n->info);
	}
}
void main(){
	int list[10]={35,29,37,17,96,15,66,24,2,47},i;
	char choice;
	Node* t;
	t=NULL;
	for(i=0;i<10;i++)
		t=create(t,list[i]);
	printf("'I' -> Inorder traversal\n'J' -> Preorder traversal\n'K' -> Postorder traversal\n'E' -> exit");
	while(1){
		printf("\nSelect and option : ");
		scanf("%c",&choice);
		switch(toupper(choice)){
			case 'I': printf("Inorder traversal is : \n");
					  Inorder(t);
					  break;
			case 'J': printf("Preorder traversal is : \n");
					  Preorder(t);
					  break;
			case 'K': printf("Postorder traversal is : \n");
					  Postorder(t);
					  break;
			case 'E': return;
			default:  printf("Wrong Choice\n");	}
		fflush(stdin);
	}
	getch();
}
