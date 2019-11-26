#include <stdio.h>

int add2(int *x, int *y){
    int res;
    res = *x + *y;
    return res;
}

int comp2(int *x, int *y){
    int res;
    res = *x - *y;
    return res;
}

int add2_or_comp2(int x, int y, int(*f1)(int *, int *)){
    int f2;
    f2 = f1(&x, &y);
    return f2;
}

int main(){
    int x, y, res;
    printf("Podaj dwie liczby oddzielone spacja:\n");
    scanf("%d %d", &x, &y);
    res = add2_or_comp2(x, y, add2);
    printf("%d + %d = %d\n", x, y, res);
    res = add2_or_comp2(x, y, comp2);
    printf("%d - %d = %d\n", x, y, res);
    return 0;
}
