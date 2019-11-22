#include<stdio.h>
#include<stdlib.h>

int quickSort(int *vetor, int esquerda, int direita){
    int pivo, menor, maior, temp;
    
    menor = esquerda;
    maior = direita;
    pivo = vetor[(esquerda + direita) / 2];

    do{
        while (vetor[menor] < pivo){
            menor++; 
        }
        while (pivo < vetor[maior]){
            maior--; 
        }
        if(menor <= maior){
            temp = vetor[menor];
            vetor[menor] = vetor[maior];
            vetor[maior] = temp;
            menor++;
            maior--;
            }
        }while (menor <= maior);

    if(esquerda < maior){
        quickSort(vetor, esquerda, maior);
    }    
    if(menor < direita){
        quickSort(vetor, menor, direita);
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

    quickSort(vetor, -1, n);
    //Imprimindo o vetor
    for(int i = 0; i < n; i++){
        printf("Vetor [%d] = %d\n",i, vetor[i]);
    }
    
    //FREE TÁ DANDO ERRO
    free(vetor);
    return 0;
}