#include<stdio.h>
#include<stdlib.h>

int mergeSort(int *vetor, int inicio, int fim){
    int meio;

    if(inicio < fim){
        meio = (inicio + fim) / 2;
        mergeSort(vetor, inicio, fim);
        mergeSort(vetor, meio + 1, fim);
        //continuar
    }
    
   return 0;
}

int main(){

    int *vetor, n;

    printf("Digite o numero de elementos do vetor: ");
    scanf("%d", &n);

    vetor = (int *)malloc(sizeof(int) * n);

    //Inserindo valores no vetor
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    mergeSort(vetor, -1, n);
    //Imprimindo o vetor
    for(int i = 0; i < n; i++){
        printf("Vetor [%d] = %d\n",i, vetor[i]);
    }
    
    free(vetor);
    return 0;
}