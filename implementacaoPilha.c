// TRABALHO DE IMPLEMENTAÇÃO
// (PILHA)

#include <stdio.h>
#include <stdlib.h>

typedef struct no{                                                                    //Definição estrutura de cada nó da pilha
    int dado;
    struct no *proximo;
}tPilhaSimples;

tPilhaSimples *criarNo(int novoDado){                                                  //Cria o nó de uma pilha             
    tPilhaSimples *topo = (tPilhaSimples *)malloc(sizeof(tPilhaSimples));              //Alocando o nó no topo da pilha

    topo->dado = novoDado;                              
    topo->proximo = NULL;
    return topo;
}

int estaVazia(tPilhaSimples *pilha){                                                   //Retorna se a pilha está vazia
    return pilha == NULL;
}

void empilhar(tPilhaSimples **pilha, int dado){                                        //Empilha a pilha
    tPilhaSimples *novoNo = criarNo(dado);                                             //Alocando o novo elemento                                             
    novoNo->proximo = *pilha;
    *pilha = novoNo;                                                                   //Passando o novo elemento como o novo topo
    printf("Elemento %d empilhado.\n", dado);
}

int desempilhar(tPilhaSimples **pilha){                                                //Desempilha a pilha
    if(estaVazia(*pilha)){                                                             //Verifica se a pilha está vazia
        printf("Erro: Pilha vazia. Nada a ser desempilhado.\n");
        return -1;                                                                     //Retorna um valor de erro
    }

    int dadoDesempilhado = (*pilha)->dado;
    tPilhaSimples *temp = *pilha;                                                      //Passa o elemento do topo para ser desempilhado
    *pilha = (*pilha)->proximo;                                                        //Passa o segundo elemento como topo
    free(temp);                                                                        //Libera espaço da memória

    printf("Elemento %d desempilhado.\n", dadoDesempilhado);
    return dadoDesempilhado;
}

void exibirPilha(tPilhaSimples *pilha){                                                //Exibir os elementos da pilha
    if(estaVazia(pilha)){                                                              //Verifica se a pilha está vazia
        printf("Pilha vazia.\n");
        return;
    }

    printf("Elementos da pilha:\n");
    while(pilha != NULL){                                                              //Percorre toda a pilha printando os seus elementos
        printf("%d\n", pilha->dado);
        pilha = pilha->proximo;
    }
}

void destruirPilha(tPilhaSimples **pilha){                                             //Destroi a pilha
    int count = 0;
    while(*pilha != NULL){
        tPilhaSimples *temp = *pilha;                                                  //Elimina os elemento do topo até a base
        *pilha = (*pilha)->proximo;
        free(temp);                                                                    //Libera espaço da memória
        count++;                                                                       //Contador de elementos liberados
    }
    printf("Pilha destruída. %d nós liberados.\n", count);
}

int main() {
    tPilhaSimples *pilha = NULL;                                                       //Inicializa a definição de uma pilha vazia
    int opcao, dado;

    do{                                                                                //Loop principal                        
        printf("\nEscolha uma opcao:\n");
        printf("1. Testar se a pilha esta vazia\n");
        printf("2. Criar uma pilha unitaria\n");
        printf("3. Empilhar um numero\n");
        printf("4. Desempilhar um numero\n");
        printf("5. Mostrar elementos da pilha\n");
        printf("6. Finalizar o programa\n");

        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                if(estaVazia(pilha)){
                    printf("A pilha esta vazia.\n");
                }else{
                    printf("A pilha nao esta vazia.\n");
                }
                break;
            case 2:
                if(estaVazia(pilha)){
                    printf("Digite um numero para criar a pilha unitaria: ");
                    scanf("%d", &dado);
                    empilhar(&pilha, dado);
                }else{
                    printf("Pilha ja foi criada.\n");
                }
                break;
            case 3:
                printf("Digite um numero para empilhar: ");
                scanf("%d", &dado);
                empilhar(&pilha, dado);
                break;
            case 4:
                desempilhar(&pilha);
                break;
            case 5:
                exibirPilha(pilha);
                break;
            case 6:
                destruirPilha(&pilha);
                printf("Finalizando...\n");
                break;
            default:
                printf("Opcao invalida, tente novamente.\n");
        }
    }while(opcao != 6);
    return 0;
}