#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10000000
// Utility function to swap values at two indices in an array
void swap (int i, int j, int *arr);

void bubbleSort (int size, int *numbers);

void cargarArray(FILE *fp,int arr[],int n);

void printArray(int arr[],int size);



int main(){
    

	int *arr = (int *)malloc(sizeof(int)* MAX);
	FILE* fp = fopen("archivo_generado.txt","r");
	int n;
	double time_spent = 0.0;
    clock_t inicio,fin;

    cargarArray(fp,arr,MAX);

    printf("Digite el n: ");scanf("%d",&n);
    inicio = clock();
    bubbleSort(n,arr);
    fin = clock();
    
    time_spent += ((double)(fin - inicio) / CLOCKS_PER_SEC);
    printArray(arr,n);
    printf("\nSe demoro un total de %lf",time_spent);


	free(arr);
	fclose(fp);
    return 0;
}
void swap (int i, int j, int *arr) {
   int tmp = arr[i];
   arr[i] = arr[j];
   arr[j] = tmp;
}

void bubbleSort(int size, int *numbers){
    int i, j;
    for (i = 0 ; i < size - 1; i++) {
        for (j = 0 ; j < size - i - 1; j++) {
          if (numbers[j] > numbers[j+1]) {
            swap(j, j+1, numbers);
          }
        }
    }
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
