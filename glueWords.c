#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

char *lloc(char *napis){
     napis = (char*)malloc(strlen(napis)*sizeof(char)+1);
     return napis;
}

void sklej(char **lancuch, char *napis, int n){
     lancuch[n] = lloc(napis);
     strcat(lancuch[n], napis);     
}

int main(){
	char napis[N];
	char **lancuch, *tekst;
	int dl = 0, n;
	lancuch = (char**)malloc(sizeof(char)*dl);
	for(int i = 0; i <= dl; i++)
		lancuch[i] = lloc(tekst);
	printf("Podaj ile chcesz skleic słów i wcisnij ENTER\n");
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s", napis);
		tekst = lloc(napis);
		strcat(tekst, napis);
		sklej(lancuch, tekst, dl);
		dl++;
	}    
	for(int i = 0; i < dl; i++)
		printf("%s", lancuch[i]);
	printf("\n");  
	return 0;
}

