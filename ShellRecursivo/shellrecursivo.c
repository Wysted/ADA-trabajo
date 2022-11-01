#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include<time.h>

#define MAX 10000000

void imprimir(int vec[], int n);
void Shell(int vec[], int n, int salto);


int main(){
    FILE * fp = fopen("archivo_generado.txt", "r");
    int * array = (int*)malloc(sizeof(int) * MAX);
    int numero,i,n;

    double time_spent = 0.0;
    clock_t inicio,fin;


    if (!fp) {
        printf("Error en el archivo");
        return 1;
    }
    while (feof(fp) == 0) {
        fscanf(fp, "%d", &numero);
        array[i] = numero;
        i++;
    }

    printf("Digite el n: ");scanf("%d",&n);
    int salto = n/2;

    inicio = clock();
    Shell(array,n,salto);
    fin = clock();

    time_spent += ((double)(fin - inicio) / CLOCKS_PER_SEC) * 1000;
    imprimir(array,n);

    printf("\nSe demoro un total de %f",time_spent);

    fclose(fp);
    free(array);

    return 0;
}


void imprimir(int vec[], int n){
    for(int i=0; i<n; i++){
        printf("\n %d | %d ",i+1,vec[i]);
    }
}

void Shell(int vec[], int n, int salto){

  int aux;

    bool band=true;


    while(band){
        band=false;
        for(int i=0; i+salto < n; i++){

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
