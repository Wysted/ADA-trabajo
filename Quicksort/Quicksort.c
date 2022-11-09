#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10000000

void cargarArray(FILE *fp,int arr[],int n);
void printArray(int arr[],int size);
void swap(int *a, int *b);
void quicksort(int arreglo[], int izquierda, int derecha);
int particion(int arreglo[], int izquierda, int derecha);

int main(){
    FILE* fp = fopen("archivo_generado.txt", "r");
    int * array = (int*)malloc(sizeof(int) * MAX);
    int numero,i,n = 0;
    clock_t inicio,final;
    double time_spent = 0.0;



    cargarArray(fp,array,MAX);

    printf("Digite el n: ");scanf("%d",&n);
    if(n != MAX){
    inicio = clock();
        quicksort(array, 0, n);
    final = clock();
    }else{
    inicio = clock();
        quicksort(array, 0, MAX-1);
    final = clock();
    }

    time_spent += ((double)(final - inicio) / CLOCKS_PER_SEC);
    //printArray(array,n);
    printf("Se demoro un total de %lf",time_spent);


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
		printf("\n%d / %d",i+1,arr[i]);
	}
}


void swap(int *a, int *b) {
  int temporal = *a;
  *a = *b;
  *b = temporal;
}

void quicksort(int arreglo[], int izquierda, int derecha) {
  if (izquierda < derecha) {
    int indiceParticion = particion(arreglo, izquierda, derecha);
    quicksort(arreglo, izquierda, indiceParticion);
    quicksort(arreglo, indiceParticion + 1, derecha);
  }
}

int particion(int arreglo[], int izquierda, int derecha) {
  // Elegimos el pivote, es el primero
  int pivote = arreglo[izquierda];
  // Ciclo infinito
  while (1) {
    // Mientras cada elemento desde la izquierda est� en orden (sea menor que el
    // pivote) contin�a avanzando el �ndice
    while (arreglo[izquierda] < pivote) {
      izquierda++;
    }
    // Mientras cada elemento desde la derecha est� en orden (sea mayor que el
    // pivote) contin�a disminuyendo el �ndice
    while (arreglo[derecha] > pivote) {
      derecha--;
    }
    /*
    Si la izquierda es mayor o igual que la derecha significa que no
    necesitamos hacer ning�n intercambio
    de variables, pues los elementos ya est�n en orden (al menos en esta
    iteraci�n)a
    */
    if (izquierda >= derecha) {
      // Indicar "en d�nde nos quedamos" para poder dividir el arreglo de nuevo
      // y ordenar los dem�s elementos
      return derecha;
    } else {//Nota: yo s� que el else no hace falta por el return de arriba, pero as� el algoritmo es m�s claro
      /*
      Si las variables quedaron "lejos" (es decir, la izquierda no super� ni
      alcanz� a la derecha)
      significa que se detuvieron porque encontraron un valor que no estaba
      en orden, as� que lo intercambiamos
      */
      swap(&arreglo[izquierda], &arreglo[derecha]);
      /*
      Ya intercambiamos, pero seguimos avanzando los �ndices
      */
      izquierda++;
      derecha--;
    }

  }
}
