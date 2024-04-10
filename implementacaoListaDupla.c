// TRABALHO DE IMPLEMENTAÇÃO
// (LISTA DUPLA)

#include <stdio.h>
#include <stdlib.h>

typedef struct no {                                                     //Definição da estrutura de cada nó da lista
    int dado;
    struct no *anterior, *proximo;
} tListaDupla;

tListaDupla *criarLista(int dado){                                      //Criação o nó de uma lista
    tListaDupla *cabeca = (tListaDupla *)malloc(sizeof(tListaDupla));   //Alocando o nó na cabeça da lista
    
    cabeca->dado = dado;
    cabeca->anterior = NULL;
    cabeca->proximo = NULL;
    return cabeca;
}

void listaVazia(tListaDupla *lista){                                    //Verifica se a lista está vazia
    if(lista == NULL){
        printf("A lista esta vazia.\n");
    }else{
        printf("A lista nao esta vazia.\n");
    }
    return;
}

void inserirElemento(tListaDupla **lista, int novoDado){               //Insere um novo elemento antes de um nó
    tListaDupla *novo = criarLista(novoDado);

    if(*lista == NULL){                                                //Se a lista estiver vazia, o novo elemento será a cabeça
        *lista = novo;
    }else{                                                             //Senão será adicionado
        tListaDupla *temp = *lista;
        tListaDupla *anterior = NULL;

        while(temp != NULL && temp->dado < novoDado){                  //Vasculha toda a lista em ordem crescente
            anterior = temp;
            temp = temp->proximo;
        }

        if(anterior == NULL){                                          //Se a lista não possuir um elemento menor, então será adicionado como o primeiro da lista
            novo->proximo = *lista;
            (*lista)->anterior = novo;
            *lista = novo;
        }else{                                                         //Senão apenas adiciona antes do elemento de ordem sucessiva
            novo->proximo = temp;
            novo->anterior = anterior;
            anterior->proximo = novo;
            if (temp != NULL) {
                temp->anterior = novo;
            }
        }
    }
}

void removerElemento(tListaDupla **lista, int dado){                  //Remove um elemento selecionado
    tListaDupla *temp = *lista;
    tListaDupla *anterior = NULL;

    while(temp != NULL && temp->dado != dado){                        //Vasculha toda a lista enquanto não encontra o elemento equivalente
        anterior = temp;
        temp = temp->proximo;
    }

    if(temp == NULL){                                                //Se acabou a lista e ainda não encontrou
        printf("Elemento %d nao encontrado na lista.\n", dado);
        return;
    }

    if(anterior == NULL){                                           //Se for o primeiro elemento da lista, apaga ele e realoca o segundo para posição de cabeça
        *lista = temp->proximo;
        if (*lista != NULL) {
            (*lista)->anterior = NULL;
        }
    }else{                                                          //Senão apenas apaga ele e realoca os elementos seguintes uma posição atrás
        anterior->proximo = temp->proximo;
        if (temp->proximo != NULL) {
            temp->proximo->anterior = anterior;
        }
    }

    free(temp);
    printf("Elemento %d removido da lista.\n", dado);
}

void encontrouNo(tListaDupla *lista, int dado){                      //Localiza um elemento
    tListaDupla *temp = lista;
    while(temp != NULL && temp->dado != dado) {                     //Vasculha toda a lista até achar elementos equivalentes
        temp = temp->proximo;
    }
    if (temp == NULL) {
        printf("Numero nao encontrado na lista.\n");
    }else{
        printf("Numero encontrado na lista.\n");
    }
}

void exibirLista(tListaDupla *lista, int ordemCrescente){           //Exibe a lista tanto em ordem crescente como decrescente
    listaVazia(lista);
    printf("Lista em ordem %s:\n", ordemCrescente ? "crescente" : "decrescente");   //Crescente = 1 , Decrescente = 0 

    if(ordemCrescente){
        while(lista != NULL){                                       //Percorre a lista printando os dados em ordem crescente
            printf("%d ", lista->dado);
            lista = lista->proximo;
        }
    }else{
        while(lista->proximo != NULL){                              //Leva o ponteiro até o final da lista
            lista = lista->proximo;
        }
        while(lista != NULL) {
            printf("%d ", lista->dado);
            lista = lista->anterior;                                //Printa vindo do final da lista até o inicio
        }
    }

    printf("\n");
}

void destruirLista(tListaDupla **lista){                            //Destroi a lista
    while(*lista != NULL) {
        tListaDupla *temp = *lista;
        *lista = (*lista)->proximo;
        free(temp);                                                 //Libera espaço de armazenamento
    }
}

int main() {
    tListaDupla *lista = NULL;                                      //Inicializa a definição de uma lista vazia
    int opcao, dado;

    do{                                                             //Loop principal do código
        printf("\nEscolha uma opcao:\n");
        printf("1. Verificar se a lista esta vazia\n");
        printf("2. Criar uma lista unitaria\n");
        printf("3. Inserir um numero na lista\n");
        printf("4. Remover um numero da lista\n");
        printf("5. Pesquisar um numero na lista\n");
        printf("6. Exibir a lista em ordem crescente\n");
        printf("7. Exibir a lista em ordem decrescente\n");
        printf("8. Finalizar o programa\n");

        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                listaVazia(lista);
                break;
            case 2:
                if (lista == NULL) {
                    printf("Digite um numero para criar a lista unitaria: ");
                    scanf("%d", &dado);
                    lista = criarLista(dado);
                    printf("Lista unitaria criada.\n");
                } else {
                    printf("A lista ja foi criada.\n");
                }
                break;
            case 3:
                printf("Digite um numero para inserir na lista: ");
                scanf("%d", &dado);
                inserirElemento(&lista, dado);
                break;
            case 4:
                printf("Digite um numero para remover da lista: ");
                scanf("%d", &dado);
                removerElemento(&lista, dado);
                break;
            case 5:
                printf("Digite um numero para pesquisar na lista: ");
                scanf("%d", &dado);
                encontrouNo(lista, dado);
                break;
            case 6:
                exibirLista(lista, 1);
                break;
            case 7:
                exibirLista(lista, 0);
                break;
            case 8:
                destruirLista(&lista);
                printf("Finalizado... Lista destruida.\n");
                break;
            default:
                printf("Opcao invalida, tente novamente.\n");
        }
    }while(opcao != 8);
    return 0;
}