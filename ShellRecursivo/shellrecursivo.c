#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include<time.h>

#define MAX 10000000
void cargarArray(FILE *fp,int arr[],int n);
void printArray(int arr[],int size);
void Shell(int vec[], int n, int salto);


int main(){
    FILE * fp = fopen("archivo_generado.txt", "r");
    int * array = (int*)malloc(sizeof(int) * MAX);
    int numero,i,n;

    double time_spent = 0.0;
    clock_t inicio,fin;

    cargarArray(fp,array,MAX);

    printf("Digite el n: ");scanf("%d",&n);
    int salto = n/2;

    inicio = clock();
    Shell(array,n,salto);
    fin = clock();

    time_spent += ((double)(fin - inicio) / CLOCKS_PER_SEC);
    printArray(array,n);

    printf("\nSe demoro un total de %lf",time_spent);

    fclose(fp);
    free(array);

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
		printf("\n%d / %d",(i-size)*-1,arr[i]);
	}
}

void Shell(int vec[], int n, int salto){

  int aux;

    bool band=true;

    while(band){
        band=false;
        int i;
        for(i=0; i+salto < n; i++){

            if(vec[i]<vec[salto+i]){
                aux=vec[i];
                vec[i]=vec[salto+i];
                vec[salto+i]=aux;
                band=true;

            }
        }
    }
    salto=salto/2;
        if(salto!=0)
            Shell(vec, n, salto);

}
