#include<stdio.h>
#include<stdlib.h>

int insertionSort(int *vetor, int n){
    int atual, j;
    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        atual = vetor[i];
        while(j >= 0 && atual < vetor[j]){
           vetor[j+1] = vetor[j];
           j--;                 
        }
        vetor[j+1] = atual;
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

    insertionSort(vetor, n);
    //Imprimindo o vetor
    for(int i = 0; i < n; i++){
        printf("Vetor [%d] = %d\n",i, vetor[i]);
    }

    //printf("\n");
    //printf("%d ", insertionSort(vetor, n));
    
    free(vetor);
    return 0;
}