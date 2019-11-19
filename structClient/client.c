#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

typedef struct Klient{
	char f_name[N];
	char l_name[N];
	char code[7];
	int age;
} Klient;

int main (){
	int n;
	printf ("Podaj rozmiar tablicy\n");
	scanf("%d",&n);
	Klient * tab = malloc(sizeof(Klient)*n);
	
	FILE * pFile;
	pFile = fopen("dane.txt", "r");
	for(int i = 0; i < n; i++)
		fscanf(pFile,"%s%s%s%d", tab[i].f_name, tab[i].l_name, tab[i].code, &(tab[i].age));

	for(int i = 0; i < n; i++)
		printf("%s %s %s %d\n", tab[i].f_name, tab[i].l_name, tab[i].code, tab[i].age);




	FILE * fb1;
	fb1 = fopen("dane.dat", "wb");
	fwrite(tab, n*sizeof(Klient), n, fb1);
	fclose(fb1);

	FILE * fb2;
	fb2 = fopen("dane.dat", "rb+");

	for (int i = 0; i < n; i++){
		fread(tab+i, sizeof(Klient), 1, fb2);
		if(tab[i].age >= 18){
			printf("\nPELNOLETNI : \n%s  %s  %s  %d \n", tab[i].f_name, tab[i].l_name, tab[i].code, tab[i].age);
		printf("\n\n");
		}
	}
	fclose(fb2);
	fclose(pFile);
	free(tab);

	return 0;
}
