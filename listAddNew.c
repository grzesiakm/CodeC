#include <stdio.h>
#include <stdlib.h>

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

node *insert_order(node *head, char val){
	node *temp = malloc(sizeof(node));
	if(!temp)
		return head;
	temp -> value = val;
	temp -> next = NULL;
	if(head){
		if(head -> value > val){
			temp -> next = head;
			head = temp;
		} else {
			node *tmp = head;
			for(;tmp -> next && tmp -> next -> value < val; tmp = tmp -> next);
				temp -> next = tmp -> next;
				tmp -> next = temp;
			}
		} else 
			head = temp;
	return head;
}

void print( const node *elem){
	if(!elem)
		return;
	for(;elem; elem = elem -> next)
		printf("(%p)-> %c, next: %p\n", elem, elem -> value, elem -> next);
}

int main(){
	node *head = insert_begin(NULL, 'z');
	head = insert_order(head, 'k');
	head = insert_order(head, 'j');
	head = insert_order(head, 'a');
	print(head);
	head = insert_order(head, 'w');
	printf("\nPo dodaniu rosnąco nowego elementu:\n"); 
	print(head);

	return 0;
}
