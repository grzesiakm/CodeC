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

void print( const node *elem){
	if(!elem)
		return;
	for(;elem; elem = elem -> next)
		printf("(%p)-> %c, next: %p\n", elem, elem -> value, elem -> next);
}

node* rev_all(node *head){
	node *cur = head;
	node *prev = NULL;
	node *next = NULL;
	while(cur){
		next = cur -> next;
		cur -> next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

int main(){
	node *head = insert_begin(NULL, 'i');
	head = insert_begin(head, 'u');
	head = insert_begin(head, 'd');
	head = insert_begin(head, 'f');
	print(head);
	head = rev_all(head);
	printf("\nPo odwroceniu listy:\n"); 
	print(head);

	return 0;
}

