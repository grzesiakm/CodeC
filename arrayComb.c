#include <stdio.h>
#include <stdlib.h>

int main(void){
    float *arg_3;
    float *arg_4;
    int i, j, k, n1, n2, n3, n4;
    float arg_1[] = {1.0, 1.2, 1.2, 1.5, 1.5, 1.5, 1.6, 1.6, 1.8, 1.9};
    float arg_2[] = {1.0, 1.1, 1.1, 1.2, 1.4, 1.5, 1.6, 1.6, 1.8, 1.8, 1.8, 1.9, 1.9, 2.0, 2.0};
    n1 = sizeof(arg_1)/sizeof(float);
    n2 = sizeof(arg_2)/sizeof(float);
    n3 = n1 + n2;
    n4 = n3;
    arg_3 = malloc(n3*sizeof(float));
    for(i = 0, j = 0, k = 0; i < n3; i++){
        if(arg_1[j] > arg_2[k] && k < n2)
        arg_3[i] = arg_2[k++];
        else if(j < n1)
        arg_3[i] = arg_1[j++];
        else if(k < n2)
        arg_3[i] = arg_2[k++];
    }
    printf("Polaczone tablice:\n");
    for(i = 0; i < n3; i++)
    printf("%d. %.1f\n", i, arg_3[i]);
    for(i = n3 - 1; i > 0; i--){
        if(arg_3[i] == arg_3[i-1]){
            arg_3[i] = 0;
            n4--;
        }
    }
    printf("Wyzerowane elementy powtarzajace sie:\n");
    for(i = 0; i < n3; i++)
    printf("%d. %.1f\n", i, arg_3[i]);
    arg_4 = malloc(n4*sizeof(float));
    for(i = 0, j = 0; i < n3; i++){
        if(arg_3[i] != 0){
            arg_4[j] = arg_3[i];
            j++;
        }
    }
    printf("Ostateczna tab:\n");
    for(i = 0; i < n4; i++)
    printf("%d. %.1f\n", i, arg_4[i]);
	return 0;
}
