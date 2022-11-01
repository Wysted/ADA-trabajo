#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define MAX 10000000


// Merge Function
void merge(int arr[], int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
			for (j = 0; j < n2; j++)
			R[j] = arr[m + 1+ j];
				i = 0;
				j = 0;
				k = l;
				
while (i < n1 && j < n2)
{
if (L[i] <= R[j])
{
arr[k] = L[i];
i++;
}
else
{
arr[k] = R[j];
j++;
}
k++;
}
while (i < n1)
{
arr[k] = L[i];
i++;
k++;
}
while (j < n2)
{
arr[k] = R[j];
j++;
k++;
}
}

void mergeSort(int arr[], int l, int r)
{
if (l < r)
{
int m = l+(r-l)/2;
mergeSort(arr, l, m);
mergeSort(arr, m+1, r);
merge(arr, l, m, r);
}
}

void printArray(int A[], int size)
{
int i;
for (i=0; i < size; i++)
printf("%d ", A[i]);
printf("n");
}

int main() {
	
	
	
    FILE* fp = fopen("archivo_generado.csv", "rb");
    int* array = (int*)malloc(sizeof(int) * MAX);

    if (!fp) {
        printf("Error en el archivo");
        return 1;
    }
    int numero, i = 0;
    char lim;

    while (feof(fp) == 0) {
        fscanf(fp, "%d%c", &numero, &lim);
        array[i] = numero;
        i++;
    }
    
//    int tamanio = (sizeof(array)*MAX/2)/sizeof(array[0]);
    
    
	mergeSort(array,0,1000000);	

	for(i = 0;i<100000;i++){
		printf("%d | %d\n",i,array[i]);
	}
	return 0;
}
