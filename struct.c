#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define N 4

int rand_int (int a, int b){
  return (a + rand()%(b - a + 1));
} 
 
struct tab_tab {
	int n;
	int t[];
} *TAB[N];

int suma (int *t, int count){ 
     int i, s = 0;
     for (i = 0; i < count; i++)
        s += t[i];
	return s;
}

int main(){
	int num[] = {3, 6, 4, 2};
	int count = sizeof(num)/sizeof(*num);
	srand(time(0));
	for (int i = 0; i < count; i++){ 
		TAB[i] = malloc(sizeof(struct tab_tab) + sizeof(int) * num[i]);
		TAB[i]->n = num[i];
		for(int j = 0; j < num[i]; j++)
		    TAB[i]->t[j] = rand_int(2, 7);
	}
	for (int i = 0; i < count; i++){
		printf("\n");
		for(int j = 0; j < num[i]; j++){
    		printf("i = %d   j = %d   wartość = %d ", i, j, TAB[i]->t[j]);
    		printf("\n");
		}
	}
	int m = count - 1;
	for (int i = 0; i < count - 1; i++){ 
	    if(suma(TAB[i]->t, num[i]) < suma(TAB[m]->t, num[m]))
	    m = i;
	}
	printf("STRUKTURA O NAJMNIEJSZEJ LICZBIE ELEMENTOW\n%d\n", TAB[m]->n);
	for(int i = 0; i < num[m]; i++)
    	printf("%d  ", TAB[m]->t[i]);
	printf("\n");
	for(int i = 0; i < count; i++)
		free(TAB[i]);
	return 0;
} 
