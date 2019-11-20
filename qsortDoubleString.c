#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

int double_cmp(const void *a, const void *b){  
    double aa = *(double*)a;
    double bb = *(double*)b;
    if(aa < bb) 
        return -1;
    else if(aa == bb) 
        return 0;
    else 
        return 1;
}

int cstring_cmp(const void *a, const void *b ){    
     return strcmp( *(char**) a, *(char**) b);
}
 
void print_double_array(double *poczatek, int koniec){      
    for(int i = 0; i < koniec; i++) 
        printf ("%.1f ", poczatek[i]);    
    printf ("\n");    
    return;
}

void print_cstring_array(char **poczatek, int koniec){   
    for(int i = 0; i < koniec; i++) 
        printf ("%s ", poczatek[i]);    
    printf ("\n");    
    return;
}
 
void sort_double_example(){    
    double numbers[] = { 7.4, 1.3, 14.5, 0.1, -1.0, 2.3, 1,2, 43.0, 2.0, -4.7, 5.8 };
    int numbers_len = sizeof(numbers)/sizeof(*numbers);   
    puts("* Double sorting...");
 
      print_double_array(numbers,numbers_len);      
    qsort(numbers, numbers_len, sizeof(double), double_cmp);    
 
   
    print_double_array(numbers, numbers_len);   
}
 
 
void sort_cstrings_example(){  
    char *strings[] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};
    int strings_len = sizeof(strings)/sizeof(*strings);   
 
   
    puts("* String sorting...");
 
    print_cstring_array(strings, strings_len);    
 
   
    qsort(strings, strings_len, sizeof(char*), cstring_cmp);   
 
   
    print_cstring_array(strings, strings_len);     
}
 
  // MAIN program (wywołanie funkcji sortujacych)  
int main(){
   
    sort_double_example();
    sort_cstrings_example();
   
    return 0;
}
