#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("Podaj wysokosc trojkata Pascala: ");
    int *pas = (int *)malloc(sizeof(int));
    int n = sizeof(int);
    pas = malloc(n*sizeof(float));
    *pas = 1;
    int wys, p, i, j;
    scanf("%d", &wys);
	printf("\n");
    for(i = 0; i < wys; i++){
        for(p = 1; p <= wys - i; p++)
            printf("  ");
		int k, l = i;
        for(k = 0, j = 0; j <= i; j++, k++){
            if(j == 0 || j == i)
                pas[j] = 1;
            else{
                pas[j] = (int)(pas[j-1] * l/k);
				l--;
			}
            n += sizeof(int);
            pas = realloc(pas, n);
            printf("%4d", pas[j]);
        }
        printf("\n");
    }
    return 0;		
}
