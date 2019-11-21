#include <stdio.h>
#include <stdlib.h>

struct tnode {
	char value;
	struct tnode *next;
};

struct tnode *dodaj_na_poczatek (struct tnode *list, char var){
	struct tnode *wsk = malloc (sizeof (struct tnode ));
	wsk->value = var;
	wsk->next = list;
	return wsk;	
}

void wypisz_list (struct tnode *list){
	if (list == NULL){	
		printf ("PUSTA \n");
	return;
	}

	while (list != NULL){
		printf ("%c   ", list->value);
		list = list->next;
	}
	return;
}


void zwolnij (struct tnode *list){
	struct tnode  *p2 = NULL;
	while (list != NULL){
		p2 = list->next;
		free (list);
		list = p2;
	}
	return;	
}


int main(){
	
struct tnode *head = NULL;
wypisz_list(head);printf (" \n");
head = 	dodaj_na_poczatek (head, 'a');
wypisz_list(head);printf (" \n");
head = 	dodaj_na_poczatek (head, 'c');
wypisz_list(head);printf (" \n");
head = 	dodaj_na_poczatek (head, 'v');
wypisz_list(head);printf (" \n");
head = 	dodaj_na_poczatek (head, 'f');	
wypisz_list(head);printf (" \n");
head = 	dodaj_na_poczatek (head, 't');
wypisz_list(head);printf (" \n");
zwolnij (head);	
}
