#include<stdio.h>
#include<stdlib.h>

int bubbleSort(int *vetor, int n){
    int ultimo, temp;
    for (ultimo = vetor[n - 1]; ultimo > 0; ultimo--)
    {
        for (int i = 0; i < ultimo; i++)
        {
            if(vetor[i] > vetor[i + 1]){
                temp = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = temp;
            }
        }          
                
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

    bubbleSort(vetor, n);
    //Imprimindo o vetor
    for(int i = 0; i < n; i++){
        printf("Vetor [%d] = %d\n",i, vetor[i]);
    }
    
    free(vetor);
    return 0;
}