#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define MAX 10000000


void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);

int main(){
    FILE* fp = fopen("archivo_generado.txt", "r");
    int * array_desordenado = (int*)malloc(sizeof(int) * 10000000);
    int * array_aux = (int*)malloc(sizeof(int) *100000);
    int * array_ordenado = (int*) malloc(sizeof(int) * MAX);

    if (!fp) {
        printf("Error en el archivo");
        return 1;
    }
    int numero,i;

    while (feof(fp) == 0) {
        fscanf(fp, "%d", &numero);
        array_desordenado[i] = numero;
        i++;
    }
    int n = 10;
    for(i=0;i<n;i++){

    }
    merge_sort(array_aux,n);

    for(i=0;i<n;i++){
        printf("%d | %d\n",i+1,array_ordenado[i]);
    }
    fclose(fp);

    free(array_desordenado);
    free(array_ordenado);
    free(array_aux);

    return 0;
}


void merge_sort(int a[], int length)
{

  merge_sort_recursion(a, 0, length - 1);
}


void merge_sort_recursion(int a[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;


    merge_sort_recursion(a, l, m);
    merge_sort_recursion(a, m + 1, r);

    merge_sorted_arrays(a, l, m, r);
  }
}


void merge_sorted_arrays(int a[], int l, int m, int r)
{
  int left_length = m - l + 1;
  int right_length = r - m;

  int temp_left[left_length];
  int temp_right[right_length];

  int i, j, k;

  for (int i = 0; i < left_length; i++)
    temp_left[i] = a[l + i];

  for (int i = 0; i < right_length; i++)
    temp_right[i] = a[m + 1 + i];


  for (i = 0, j = 0, k = l; k <= r; k++)
  {

    if ((i < left_length) &&
        (j >= right_length || temp_left[i] <= temp_right[j]))
    {
      a[k] = temp_left[i];
      i++;
    }

    else
    {
      a[k] = temp_right[j];
      j++;
    }
  }
}


