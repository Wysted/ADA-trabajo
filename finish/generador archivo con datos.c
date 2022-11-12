#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 10000000

int main() {

	FILE* fp = fopen("archivo_generado.txt", "w");

	int i, aux;

	for (i = 0; i < MAX; i++) {
		aux = rand() % 100000;
		fprintf(fp, "%d\n", aux);
	}


    fclose(fp);
    return 0;
}
