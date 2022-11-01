#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define MAX 10000000


void MergeArray(int *a,int begin,int mid,int end,int *temp);
void imprimir(int vec[], int n);
void MergeSort(int *a,int begin,int end,int *temp);
int main(){
    FILE * fp = fopen("archivo_generado.txt", "r");
    int * array = (int*)malloc(sizeof(int) * MAX);
    int * array_temp = (int*)malloc(sizeof(int) * MAX);

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


    if(n != MAX){
        inicio = clock();
        MergeSort(array,0,n,array_temp);
        fin = clock();
    }else{
        inicio = clock();
        MergeSort(array,0,MAX-1,array_temp);
        fin = clock();
    }




    time_spent += ((double)(fin - inicio) / CLOCKS_PER_SEC);
    imprimir(array,n);

    printf("\nSe demoro un total de %f",time_spent);

    fclose(fp);
    free(array);

    return 0;
}

void imprimir(int vec[], int n){
    for(int i=0; i<n; i++){
        printf("\n%d | %d ",i+1,vec[i]);
    }
}
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
    int i = begin,j = mid;
    int m = mid + 1,n = end;
    int k = 0;

    while(i <= j && m <= n)
    {
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

void MergeSort(int *a,int begin,int end,int *temp)
{
    if(begin < end)
    {

        int mid = (begin + end) / 2;


        MergeSort(a,begin,mid,temp);
        MergeSort(a,mid + 1,end,temp);
        MergeArray(a,begin,mid,end,temp);
    }
}

