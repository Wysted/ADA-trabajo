#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>

#define MAX 10000000

void intercambiar(int *a, int *b);
void quicksort(int arreglo[], int izquierda, int derecha);
int particion(int arreglo[], int izquierda, int derecha);

int main(){
    FILE* fp = fopen("archivo_generado.txt", "r");
    int * array = (int*)malloc(sizeof(int) * MAX);
    int numero,i,n = 0;

    double time_spent = 0.0;



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
    clock_t begin = clock();
    if(n != MAX){
        quicksort(array, 0, n);
    }else{
        quicksort(array, 0, MAX-1);
    }
    clock_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Se demoro un total de %f",time_spent);


    fclose(fp);
    free(array);

    return 0;
}

void intercambiar(int *a, int *b) {
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
    // Mientras cada elemento desde la izquierda esté en orden (sea menor que el
    // pivote) continúa avanzando el índice
    while (arreglo[izquierda] < pivote) {
      izquierda++;
    }
    // Mientras cada elemento desde la derecha esté en orden (sea mayor que el
    // pivote) continúa disminuyendo el índice
    while (arreglo[derecha] > pivote) {
      derecha--;
    }
    /*
    Si la izquierda es mayor o igual que la derecha significa que no
    necesitamos hacer ningún intercambio
    de variables, pues los elementos ya están en orden (al menos en esta
    iteración)
    */
    if (izquierda >= derecha) {
      // Indicar "en dónde nos quedamos" para poder dividir el arreglo de nuevo
      // y ordenar los demás elementos
      return derecha;
    } else {//Nota: yo sé que el else no hace falta por el return de arriba, pero así el algoritmo es más claro
      /*
      Si las variables quedaron "lejos" (es decir, la izquierda no superó ni
      alcanzó a la derecha)
      significa que se detuvieron porque encontraron un valor que no estaba
      en orden, así que lo intercambiamos
      */
      intercambiar(&arreglo[izquierda], &arreglo[derecha]);
      /*
      Ya intercambiamos, pero seguimos avanzando los índices
      */
      izquierda++;
      derecha--;
    }
    // El while se repite hasta que izquierda >= derecha
  }
}
