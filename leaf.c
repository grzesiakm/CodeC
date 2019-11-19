#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node * left;
	struct node * right;
	struct node * parent;
};

struct node * createleaf(int war, struct node * parent){
	struct node * new = (struct node*)malloc(sizeof(struct node));
	new->val = war;
	new->right = NULL;
	new->left = NULL;
	new->parent = parent;
	return new;
}

void addleaf(int war,struct node ** head, struct node * parent){
	if ((*head) == NULL){
		(*head) = createleaf(war,parent);
	}else{
		if ((*head)->val < war){
			addleaf(war,&((*head)->right), (*head));
		}else{
			addleaf(war,&((*head)->left), (*head));
		}
	}
}
void  inorder(struct node * head){
	if (head->left != NULL)
		inorder(head->left);
	printf(" %d ", head->val);
	if (head->right != NULL)
		inorder(head->right);
}

void  preorder(struct node * head){
	printf(" %d ", head->val);
	if (head->left != NULL)
		preorder(head->left);
	if (head->right != NULL)
		preorder(head->right);
}

void  postorder(struct node * head){
	if (head->left != NULL)
		postorder(head->left);
	if (head->right != NULL)
		postorder(head->right);
	printf(" %d ", head->val);
}

int main(){
	int i, tab[] = {15,5,16,20,3,12,18,23,10,13,6,7};
	struct node * head = NULL;
	for (i = 0; i < 12; i++){
		addleaf(tab[i], &head, head);
	}
	inorder(head);
	printf("\n");
	printf("head->left->left->parent->val to %d\n", head->left->left->parent->val);

	preorder(head);
	printf("\n");
	postorder(head);
	printf("\n");

	return 0;
}
