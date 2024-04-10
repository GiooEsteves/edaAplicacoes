// TRABALHO DE IMPLEMENTAÇÃO
// (LISTA SIMPLES)

#include <stdio.h>
#include <stdlib.h>

typedef struct no{                                                              //Definindo estrutura de cada nó da fila
    int dado;
    struct no *proximo;
}tFilaSimples;

tFilaSimples *criarNo(int dado){                                                //Cria o nó de uma lista
    tFilaSimples *novoNo = (tFilaSimples *)malloc(sizeof(tFilaSimples));        //Aloca o nó 
   
    novoNo->dado = dado;
    novoNo->proximo = NULL;
    return novoNo;
}

int estaVazia(tFilaSimples *fila){                                              //Retorna se a fila está vazia
    return fila == NULL;
}

void enfileirar(tFilaSimples **fila, int dado){                                 //Enfileira na fila
    tFilaSimples *novoNo = criarNo(dado);

    if(estaVazia(*fila)){                                                       //Se a fila estiver vazia adiciona o elemento como o primeiro
        *fila = novoNo;
    }else{
        tFilaSimples *temp = *fila;                                              
        while(temp->proximo != NULL){                                           //Percorre a fila até encontrar o último elemento
            temp = temp->proximo;
        }
        temp->proximo = novoNo;                                                 //Enfileira no fim da fila
    }
    printf("Elemento %d enfileirado.\n", dado);
}

int desenfileirar(tFilaSimples **fila){
    if(estaVazia(*fila)){
        printf("Erro: Fila vazia. Nada a ser desenfileirado.\n");
        return -1;                                                             //Retornando um valor de erro caso esteja vazia
    }

    int dadoDesenfileirado = (*fila)->dado;                                    //Desenfileira o último elemento
    tFilaSimples *temp = *fila;
    *fila = (*fila)->proximo;
    free(temp);                                                                //Desaloca o elemento da memória

    printf("Elemento %d desenfileirado.\n", dadoDesenfileirado);
    return dadoDesenfileirado;
}

void exibirFila(tFilaSimples *fila){                                           //Exibe a fila
    printf("Elementos da fila:\n");                                                                 
    while(fila != NULL){                                                       //Percorre toda a fila printando os seus elementos
        printf("%d\n", fila->dado);                                         
        fila = fila->proximo;
    }
}

void destruirFila(tFilaSimples **fila){                                        //Destroi a fila
    int count = 0;
    while(*fila != NULL){
        tFilaSimples *temp = *fila;                                            
        *fila = (*fila)->proximo;
        free(temp);                                                            //Libera espaço da memória
        count++;                                                               //Contador de nós liberados
    }
    printf("Fila destruída. %d nós liberados.\n", count);                               
}

int main(){
    tFilaSimples *fila = NULL;
    int opcao, dado;

    do{                                                                        //Loop principal
        printf("\nEscolha uma opcao:\n");
        printf("1. Testar se a fila esta vazia\n");
        printf("2. Criar uma fila unitaria\n");
        printf("3. Enfileirar um numero\n");
        printf("4. Desenfileirar um numero\n");
        printf("5. Mostrar elementos da fila\n");
        printf("6. Finalizar o programa\n");

        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                if (estaVazia(fila)) {
                    printf("A fila esta vazia.\n");
                } else {
                    printf("A fila nao esta vazia.\n");
                }
                break;
            case 2:
                if (estaVazia(fila)) {
                    printf("Digite um numero para criar a fila unitaria: ");
                    scanf("%d", &dado);
                    enfileirar(&fila, dado);
                } else {
                    printf("A fila ja foi criada.\n");
                }
                break;
            case 3:
                printf("Digite um numero para enfileirar: ");
                scanf("%d", &dado);
                enfileirar(&fila, dado);
                break;
            case 4:
                desenfileirar(&fila);
                break;
            case 5:
                exibirFila(fila);
                break;
            case 6:
                destruirFila(&fila);
                printf("Finalizando...\n");
                break;
            default:
                printf("Opcao invalida, tente novamente.\n");
        }
    }while(opcao != 6);
    return 0;
}