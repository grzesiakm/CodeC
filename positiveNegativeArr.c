#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float rand_float(float a, float b){
  return (a + (rand()/(1.0 * RAND_MAX)) * (b - a));
}  

int main(){
    srand(time(NULL));
    int n, d, u, i;
    d = u = 0;
    printf("Podaj rozmiar tablicy: ");
    scanf("%d", &n);
	printf("\n");
    float *tab;
    tab = malloc(n*sizeof(float));
    for(i = 0; i < n; i++)
    tab[i] = rand_float(-1.5, 1.5);
    for(i = 0; i < n; i++)
        printf("tab[%d] = %f\n", i, tab[i]);
    for(i = 0; i < n; i++){
        if(tab[i] < 0.0)
            u++;
        else
            d++;
    }
    printf("\nLiczba elementow dodatnich: %d | ujemnych: %d\n", d, u);
    float *tab_ujemne;
    tab_ujemne = malloc(d*sizeof(float));
    float *tab_dodatnie;
    tab_dodatnie = malloc(u*sizeof(float));
    int k = 0, l = 0;
    for(i = 0; i < n; i++){
        if(tab[i] < 0.0){
            *(tab_dodatnie + k) = tab[i];
            k++; 
        }else{
            *(tab_ujemne + l) = tab[i];
            l++; 
        }
    }    
    printf("\n");
    for(i = 0; i < d; i++)
        printf("dod[%d] = %f\n", i, tab_ujemne[i]);
    printf("\n");
	for(i = 0; i < u; i++)
        printf("uje[%d] = %f\n", i, tab_dodatnie[i]);
    return 0;
}
