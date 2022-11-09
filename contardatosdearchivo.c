#include<stdio.h>
#include <stdlib.h>

#define MAX 10000000
void cargarArray(FILE *fp,int arr[],int n);
void printArray(int arr[],int size);
int main(){

    FILE* fp = fopen("archivo_generado.csv","rb");
	int *array = (int *)malloc(sizeof(int)* MAX);


	cargarArray(fp,array,MAX);
	printArray(array,MAX);
	
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