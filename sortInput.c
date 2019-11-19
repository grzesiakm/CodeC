#include <stdio.h>
#include <string.h>
#define ROZMIAR 81        //maksymalna dlugość łańcuchów
#define GRAN 20           // maksymalna liczba łańcuchów

void sortlan(char *lan[], int num);  //procedura sortująca łancuchy  

int main(void){
  char dane[GRAN][ROZMIAR];    //tablica przechowujaca łańcuchy nie dłuzsze niz ROZMIAR znakow nie wiecej niz GRAN
  char *wsklan[GRAN];    //wskaźnik na tablicę wskaźników - rozmiar zależny od ilości wczytanych łańcuchów            
  int licz = 0;                //licznik danych wejsciowych    
  int k;                         
  printf("Podaj maksymalnie %d wierszy \n",GRAN);
  printf("Aby zakonczyc, wcisnij Enter na poczatku wiersza.\n");
 
  while(licz < GRAN && gets(dane[licz]) != '\0' && dane[licz][0] != '\0'){
     wsklan[licz] = dane[licz];       
     licz++;
  }
  puts("\n Wczytano:\n");
  for (k = 0; k < licz; k++)
     puts(wsklan[k]) ;   // z użyciem identyfikataora wsklan
  sortlan(wsklan, licz); // wywłoanie procedury sortującej
 
  puts("\n Oto uporzadkowana lista:\n");
  for (k = 0; k < licz; k++) 
  puts(wsklan[k]);  // z użyciem identyfikataora dane
  return 0;
}
// procedura sortująca  
void sortlan(char *lan[], int num){
 int p, x; //potrzebne zmienne lokalne
 char *tmp;
 for (p = 0; p < num - 1; p++)
   for (x = p + 1; x < num; x++)
     if(strcmp(lan[p], lan[x]) > 0){ 
        tmp = lan[p];
        lan[p] = lan[x];
        lan[x] = tmp; 
     }
}
