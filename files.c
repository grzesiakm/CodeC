#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv){

	FILE *fp;
    int c;
    if (argc < 2)
        exit(-1);
   
    fp = fopen (argv[1], "bw");
    if (!fp)
        exit(-1);
    
    while ((c = fgetc(stdin)) != EOF){
        fputc(c, stdout);
        fputc(c, fp);
    }
    fclose(fp);

    FILE *fp1;
    if((fp1=fopen(argv[2], "w"))==NULL) exit(1);
	fclose (fp1);

    int n;    
    int dl1, dl2;
    printf("Podaj rozmiar tablicy: ");
    scanf("%d", &n);

    double *tab = malloc(sizeof(double)*n);

    for(int i=0; i<n; i++){
        tab[i] = rand()%100*0.2;
        printf(" %.1f;", tab[i]);
    }
    printf("\n\n");
    
    for(int i=0; i<n; i++){
        fprintf(fp, "%.6f\n", tab[i]);
        fprintf(fp1, "%.6f\n", tab[i]);
    }
	fp = fopen(argv[1], "rb+");
    fseek(fp, 0, SEEK_END);
    dl1 = ftell(fp);
    printf("Wielkosc pliku binarnego: %d\n", dl1);
	fclose (fp);

	fp1 = fopen(argv[2], "r+");
    fseek(fp1, 0, SEEK_END);
    dl2 = ftell(fp1);
    printf("Wielkosc pliku tekstowego: %d\n", dl2);
	fclose (fp1);
    
    int k=0;
    char znak; 
    while((znak = getc(fp1)) != EOF){
        if(znak == '\n')
            k++;
    }
    printf("Dlugosc pliku txt = %d\n", k);

   
    double *tab_bin = malloc(dl1);
    if(tab_bin == NULL) exit(1);
    double *tab_txt = malloc(dl2);
    if(tab_txt == NULL) exit(1);

    for(int i=0; i<dl2/sizeof(double); i++){
        fscanf(fp, "%f", tab_txt[i]);
    }
        
     

    fclose(fp);
    fclose(fp1);
    free(tab);
        
return 0;
}  
