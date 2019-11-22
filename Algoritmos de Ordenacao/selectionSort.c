#include<stdio.h>
#include<stdlib.h>

int selectionSort(int *vetor, int n){
    int menorInicial, menorFinal, temp;
    for (int i = 0; i < n - 1; i++)
    {
        menorInicial = vetor[i];
        for (int j = i + 1; j < n; j++)
        {
            if(vetor[j] < menorInicial){
                menorInicial = vetor[j];
                menorFinal = j;
            }
        }
        temp = vetor[i];
        vetor[i] = vetor[menorFinal];
        vetor[menorFinal] = temp;
        menorFinal = i + 1;      
                
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

    selectionSort(vetor, n);
    //Imprimindo o vetor
    for(int i = 0; i < n; i++){
        printf("Vetor [%d] = %d\n",i, vetor[i]);
    }
    
    free(vetor);
    return 0;
}