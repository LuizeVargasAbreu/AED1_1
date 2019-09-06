#include<stdio.h>
#include<stdlib.h>

struct agenda{
    char nome[100];
    int telefone;
    //char cidade[100];
    struct agenda *prox;
};

typedef struct agenda end;
end *criarLista();
void inserirCadastro(end *inicio);
void pesquisarCadastro(end *inicio);
void deletarCadastro(end *inicio);
void listarCadastro(end *inicio);

int main(){

    end *inicio, *pos;
	inicio = criarLista();

   	int opcao;

	do {
		printf("\n--------------- MENU: ----------------\n");
		printf("\t 1. Inserir um novo cadastro\n");
		printf("\t 2. Listar cadastros\n");
		printf("\t 3. Deletar cadastros\n");
		printf("\t 4. Pesquisar cadastros\n");
		printf("\t 5. Sair\n");
		printf("-- Digite uma das opcoes acima: ");
		scanf("%d", &opcao);

    switch (opcao) {
        case 1:
		    inserirCadastro(inicio);
			break;
		case 2:
		    listarCadastro(inicio);
		    break;
		case 3:
			deletarCadastro(inicio);
			break;
		case 4:
			pesquisarCadastro(inicio);
			break;
		case 5:
		    printf("Saindoo ...\n");
			exit(0);
			break;
        default:
            printf("Opcao Invalida!\n");
            break;
        }
     } while (opcao != 5);
}


end *criarLista(){
    end *start;

    start = (end *) malloc(sizeof(end));
    start->prox = NULL;
    return start;
}

void inserirCadastro(end *inicio){
    end *nova;

    nova = (end *) malloc(sizeof(end));
    printf("\n------------ Inserindo Cadastros ---------------\n");
        printf("\tNome: ");
        scanf("%s", nova->nome);
        printf("\tTelefone: ");
        scanf("%d", &nova->telefone);
      //  printf("\tCidade: ");
      //  scanf("%s", nova->cidade);
        printf("\n");
    nova->prox = inicio->prox;
	inicio->prox = nova;
}

void listarCadastro(end *inicio){
    end *listar;

    printf("\n------------ Lista de Cadastros ---------------");
    for(listar = inicio->prox; listar != NULL; listar = listar->prox){
        printf("\n\tNome: %s\n", listar->nome);
        printf("\tTelefone: %d\n", listar->telefone);
        //printf("\tCidade: %s\n", listar->cidade);

    }
}

void pesquisarCadastro(end *inicio){
    end *pesquisar;
    char nm[100];

    printf("\nInforme o nome para a pesquisa: ");
    scanf("%s", nm);

    for(pesquisar = inicio->prox; pesquisar != NULL; pesquisar = pesquisar->prox){
        if (strcmp(pesquisar->nome, nm) == 0){
            printf("\tNome: %s\n", pesquisar->nome);
            printf("\tTelefone: %d\n", pesquisar->telefone);
          //  printf("\tCidade: %s\n", pesquisar->cidade);
        }
    }
}

void deletarCadastro(end *inicio){
    end *p, *q;
    char nome[100];

    printf("\nInforme o nome do cadastro para deletar: ");
    scanf("%s", nome);

	p = inicio;
	q = inicio->prox;
	while ((q != NULL) && (strcmp(q->nome, nome) != 0)) {
		p = q;
		q = q->prox;
	}
	if (q != NULL) {
		p->prox = q->prox;
		free(q);
	}
}
