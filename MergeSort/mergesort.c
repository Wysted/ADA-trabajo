#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 10000000


void cargarArray(FILE *fp,int arr[],int n);
void printArray(int arr[],int size);
void MergeArray(int *a,int begin,int mid,int end,int *temp);
void imprimir(int vec[], int n);
void MergeSort(int *a,int begin,int end,int *temp);

int main(){
    FILE * fp = fopen("archivo_generado.txt", "r");
    int * array = (int*)malloc(sizeof(int) * MAX);
    int * array_temp = (int*)malloc(sizeof(int) * MAX);

    int i,n;
    double time_spent = 0.0;

    clock_t inicio,fin;


    cargarArray(fp,array,MAX);
    printf("Digite el n: ");scanf("%d",&n);


    if(n != MAX){
        inicio = clock();
        MergeSort(array,0,n,array_temp);
        fin = clock();
    }else{
        inicio = clock();
        MergeSort(array,0,MAX-1,array_temp);
        fin = clock();
    }

    time_spent += ((double)(fin - inicio) / CLOCKS_PER_SEC );//Calcula en segundos, si quiere calcular en mili  CLOCKS_PER_SEC * 1000

    //printArray(array,n)
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
		printf("\n%d / %d",i+1,arr[i]);
	}
}


void MergeArray(int *a,int begin,int mid,int end,int *temp){
    int i = begin,j = mid;
    int m = mid + 1,n = end;
    int k = 0;

    while(i <= j && m <= n){
        if(a[i] <= a[m])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[m++];
        }
    }

    while(i <= j)
    {
        temp[k++] = a[i++];
    }

    while(m <= n)
    {
        temp[k++] = a[m++];
    }

    for(i = 0; i < k; i++)
    {
        a[begin + i] = temp[i];
    }
}

void MergeSort(int *a,int begin,int end,int *temp){
    if(begin < end)
    {
        int mid = (begin + end) / 2;
        MergeSort(a,begin,mid,temp);
        MergeSort(a,mid + 1,end,temp);
        MergeArray(a,begin,mid,end,temp);
    }
}