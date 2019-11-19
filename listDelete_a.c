#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct tnode {
	char value;
	struct tnode *next;
} node;

node *insert_begin(node *head, char val){
	node *temp = malloc(sizeof(node));
	if(!temp)
		return head;
	temp -> value = val;
	temp -> next = head;
	return temp;
}

node *del_nod(node **head, char val){
	node *temp = *head, *left = NULL;
	while(temp != NULL && toupper(temp -> value) == toupper(val)){
		*head = temp -> next;
		left = insert_begin(left, temp -> value);
		free(temp);
		temp = *head;
	}
	while(temp -> next != NULL){
		if(toupper(temp -> next -> value) == toupper(val)){
			left = insert_begin(left, temp -> next -> value);
			node *tmp = temp -> next -> next;
			free(temp -> next);
			temp -> next = tmp;
		} else {
			temp = temp -> next; 
		}
	}
	return left;
}

void print(const node *elem){
	if(!elem)
		return;
	for(;elem; elem = elem -> next)
		printf("(%p)-> %c, next: %p\n", elem, elem -> value, elem -> next);
}

int main(){
	node *left = insert_begin(NULL, ' ');
	node *head = insert_begin(NULL, 'A');
	head = insert_begin(head, 'l');
	head = insert_begin(head, 'a');
	head = insert_begin(head, ' ');
	head = insert_begin(head, 'm');
	head = insert_begin(head, 'a');
	head = insert_begin(head, ' ');
	head = insert_begin(head, 'k');
	head = insert_begin(head, 'o');
	head = insert_begin(head, 't');
	head = insert_begin(head, 'a');
	print(head);
	left = del_nod(&head , 'a');
	printf("\nPo usunieciu elementu z listy:\n"); 
	print(head);
	printf("\nLista elementow usunietych:\n");
	print(left);

	return 0;
}
