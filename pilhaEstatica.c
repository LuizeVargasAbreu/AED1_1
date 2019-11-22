#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 3

struct alunos{
    char nome[30];
    int matricula;
};

struct pilha{
    struct alunos aluno[MAX];
    int topo;
    int base;
    int limite;
};

typedef struct alunos aluno;
typedef struct pilha pilha;
//INICIA A ESTRUTURA DE DADOS
void reset(pilha *pi);
//INSERI ELEMENTO NA PILHA
bool push(pilha *pi);
//REMOVE ELEMENTOS DA PILHA
void pop(pilha *pi, aluno *a);
//TESTA SE A PILHA ESTÁ VAZIA
bool empty(pilha *pi);
//APAGA TODOS OS ELEMENTOS DA PILHA
void clear(pilha *pi);
//TESTA SE A PILHA ESTÁ CHEIA
bool full(pilha *pi);
//LISTA TODOS OS ELEMENTOS DA PILHA
void listar(pilha *pi);

int main(){
    
    int opcao;
    pilha *pi;
    pi = (pilha *) malloc(sizeof(pilha));
    reset(pi);
    
    do{
        printf("\n\t---------------- CADASTRO DE ALUNOS ----------------------\n");
        printf("\t1 - INSERIR ALUNOS NA PILHA\n");
        printf("\t2 - REMOVER ALUNOS DA PILHA\n");
        printf("\t3 - LISTAR ALUNOS DA PILHA\n");
        printf("\t4 - VERIFICAR SE A PILHA ESTÁ VAZIA OU CHEIA\n");
        printf("\t0 - SAIR\n");
        printf("\tDigite a opção desejada: \n");
        scanf("%d", &opcao);
        
    switch(opcao){
        case 1:
            if(full(pi)){
                printf("Não é possível inserir nenhum cadastro, o registro está cheio.\n");
            }else{
                push(pi);
                printf("Cadastro efetuado com sucesso!\n");
            }
            break;
        case 2:
            if(empty(pi)){
                printf("Não é possível remover o cadastro pois o registro de cadastros está vazio.\n");
            }else{
                //pi->topo--;
                pop(pi, pi->aluno);
                printf("Cadastro removido com sucesso!\n");
            }
            break;
        case 3:
            if(empty(pi)){
                printf("Não é possível listar os cadastros, pois o registro está vazio.\n");
            }else{
                listar(pi);
            }            
            break;
        case 4:
            if(empty(pi)){
                printf("O registro de cadastros está vazio.\n");                
            }else if(full(pi)){
                printf("O registro de cadastros está cheio.\n");
            }else{
                printf("O registro de cadastros não está vazio e não está cheio.\n");
            }
            break;
        case 0:
            printf("SAINDOO.......\n");
            break;
        default:
            printf("OPÇÃO INVÁLIDA! TENTE NOVAMENTE.\n");
            break;
            
    }
    }while(opcao != 0);
    
    return 0;
}

void reset(pilha *pi){
    pi->topo = 0;
    pi->base = 0;
    pi->limite = MAX;
}
bool push(pilha *pi){
    if(!full(pi)){
        printf("\n\t---------------------- CADASTRANDO UM ALUNO -------------------\n");
        printf("\tNome: ");
        scanf("%s", pi->aluno[pi->topo].nome);
        printf("\tMatricula: ");
        scanf("%d", &pi->aluno[pi->topo].matricula);
        pi->topo++;
        return true;
    }else{
        return false;
    }
}
bool full(pilha *pi){
    return pi->topo == MAX;
}

bool empty(pilha *pi){
    return pi->topo == 0;
}
void pop(pilha *pi, aluno *a){
    if(pi->topo == 0)
       return;
    
    pi->topo--;
    *a = pi->aluno[pi->topo];
}
void listar(pilha *pi){
    pilha *temp;
    printf("\n\t----------------------LISTA DE CADASTROS---------------------\n");
        //temp = pi;
        while(temp != NULL){
            aluno *a;
            pop(pi, a);
            temp->aluno[temp->topo] = *a;
            printf("\tNome do aluno: %s\n", temp->aluno[temp->topo].nome);
            printf("\tMatricula: %d\n", temp->aluno[temp->topo].matricula);
            temp->topo++;
            
       
    }    
    
}
//FALTA ARRUMAR O LISTAR E COLOCAR O CLEAR