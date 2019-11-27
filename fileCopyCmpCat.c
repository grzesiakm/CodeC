#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void file_copy(FILE* x, FILE* y){

	fseek(y, 0, 2);
	int l = ftell(y);
	char* w = malloc(l);
	rewind(y);
	fread(w, l, 1, y);
	rewind(x);
	fwrite(w, l, 1, x);
	free(w);
}

void file_cmp(FILE* x, FILE* y){

	fseek(x, 0, 2);
	fseek(y, 0, 2);
	int l1 = ftell(y);
	int l2 = ftell(x);
	char* a = malloc(l1);
	char* b = malloc(l2);
	
	fread(a, l1, 1, x);
	fread(b, l2, 1, y);

	rewind(x);
	rewind(y);
	
	if (memcmp(a, b, 1)) {
		printf("Pliki sa rozne\n");
	}
	else {
		printf("Pliki sa takie same\n");
	}

	free(a);
	free(b);
}
void file_cat(FILE* x, FILE* y){
	
	fseek(x, 0, 2);
	fseek(y, 0, 2);

	int l1 = ftell(y);
	rewind(y);
	

	char* a = malloc(l1);
	fread(a, l1, 1, x);
	fwrite(a, l1, 1, y);

	free(a);
}

int main(int argc, const char *argv[]) {

	if (argc < 3) {
		fprintf(stderr, "Za malo arg\n");
		return 1;
	}
	FILE* x = fopen(argv[1], "rb+");
	FILE* y = fopen(argv[2], "rb+");

	if (x == NULL || y == NULL) {
		fprintf(stderr, "Error przy otwieraniu\n");
		return -1;
	}
	file_copy(x, y);
	file_cmp(x, y);
	file_cat(x, y);

	fclose(x);
	fclose(y);
	return 0;
}






