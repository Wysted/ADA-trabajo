#include<stdio.h>
#include <stdlib.h>

#define MAX 10000000
void cargarArray(FILE *fp,int arr[],int n);
void printArray(int arr[],int size);
int main(){

    FILE* fp = fopen("archivo_generado.csv","rb");
	int *array = (int *)malloc(sizeof(int)* MAX);

	if(!fp){
		printf("Error en el archivo");
		return 1;
	}
	int numero,i=0;
	char lim;

	while(feof(fp) == 0){
		fscanf(fp,"%d%c",&numero,&lim);
		array[i] = numero;
		i++;
	}
	
	for(i = 0;i<MAX;i++){
		printf("%d | %d\n",i,array[i]);
	}
	
	free(array);
    fclose(fp);
    return 0;
}

void cargarArray(FILE *fp,int arr[],int n){
    if(!fp){
		printf("Error en el archivo");
		return;
	}
    int i = 0;
    while(feof(fp) == 0 && i != n){
		fscanf(fp,"%d",&arr[i]);
		i++;
	}
}

void printArray(int arr[],int size){
	int i;
	for(i=0;i<size;i++){
		printf("\n%d / %d",i+1,arr[i]);
	}
}