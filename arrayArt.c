#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void wypisz_d (double *poczatek, double *koniec){ 
 	while (poczatek < koniec) 
    	printf ("%6.2f", *poczatek++); 
 	printf ("\n");  
	return;  
}

double suma(double **tab, int i, int lenght){
    double sum = 0;
    for(double *pt = tab[i]; pt < tab[i] + lenght; pt++)
        sum += *pt;
    return sum; 
}

double *find_tab(double **tab, int n){
	double *min_pt = *tab;
	double min = suma(tab, 0, 4);
	for(int i = 1; i < n; i++){
		if(suma(tab, i, 4) < min)
			min_pt = tab[i];
	}
	return min_pt;		
}
	
void swap(double *a, double*b){
    double tmp = *a; 
    *a = *b; 
    *b = tmp; 
}

int find_tab1(double **tab, int n){
	int min_pt = 0;
	double min = suma(tab, 0, 4);
	for(int i = 1; i < n; i++){
		if(suma(tab, i, n) < min){
			min_pt = i;
			min = suma(tab, min_pt, 4);
		}
	}
	return min_pt;		
}

void sort(double **tab, int n){
	for(int i = 0; i < n; i++){
		int s = find_tab1(tab + i, n - i);
		swap(tab[s], tab[i]);
		wypisz_d(*tab, *tab+4);
	}
}

int main(){
    int i, j;
    double T_1[4] = {1.0, 3.0, 2.0, 1.5};
    double T_2[4] = {1.8, 2.0, 1.2, 3.8};
    double T_3[4] = {5.6, 1.0, 3.3, 3.3};
    double T_4[4] = {1.1, 2.1, 6.5, 1.7};
    double T_5[4] = {6.7, 7.8, 9.1, 1.0};
    
    double* TAB[5] = {T_1, T_2, T_3, T_4, T_5};

    printf("Wypisanie bez uzycia wskaznikow\n");
    for(i = 0; i < sizeof(TAB)/sizeof(double); i++){
        for(j = 0; j < 4; j++)
            printf(" %.2f ", TAB[i][j]);
        printf("\n");
    }
    
    double **TABLICA;
    TABLICA = TAB;
    printf("Wypisanie za pomoca wypisz_d\n");
    for(i = 0; i < 5; i++){
        wypisz_d(*(TABLICA + i), *(TABLICA + i) + 4);
    }
    for(i = 0; i < 5; i++){
        printf("Suma tablicy T_%d jest rowna %.2lf\n", i, suma(TAB, i, 4));
    }
    
    double *m = find_tab(TAB, 5);
	printf("Wiersz o najmniejszej sumie elementow:\n");
	wypisz_d(m, m + 4);
    
	printf("\n");

	sort(TAB, 5);

    return 0;
}
