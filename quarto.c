// EXERCICIO
// (BUSCAS EM UM VETOR)

#include <stdio.h>
#include <stdlib.h>

struct Node{  // Definição do nó da árvore
    int chave;
    struct Node* esquerda;
    struct Node* direita;
};

struct Node* novoNo(int chave){  // Função para criar um nó
    struct Node* no = (struct Node*)malloc(sizeof(struct Node));
    no->chave = chave;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

struct Node* inserir(struct Node* no, int chave){  // Função para inserir uma nova chave em uma árvore
    if(no == NULL){     // Se o nó estiver vazio
        return novoNo(chave);  // Retorna um novo nó
    }
        
    // Se não, percorre a árvore:
    if(chave < no->chave){     // Se a chave for menor que o valor do nó
        no->esquerda = inserir(no->esquerda, chave);    // Insere pela esquerda
    }  
    else if(chave > no->chave){     // Se a chave for maior que o valor do nó
        no->direita = inserir(no->direita, chave);      // Insere pela direita
    }
    return no;  // Retorna o ponteiro do nó
}

// Questão 4.1 (Busca em Largura)
void busca_largura(struct Node* raiz){  // Função de busca em largura 
    if(raiz == NULL){   // Se a raiz estiver vazia, retorna
        return;   
    }

    struct Node** fila = (struct Node**)malloc(sizeof(struct Node*) * 1000);   // Inicializa uma fila
    int frente = 0, tras = 0;

    fila[tras++] = raiz;  // Adiciona a raiz à fila

    while(frente < tras){   // Percorre toda a extensão lateral da frente para trás
        struct Node* temp = fila[frente++];   // Remove o nó da frente da fila
        printf("%d ", temp->chave);    // Imprime sua chave

        // Adiciona os filhos do nó removido à fila:
        if(temp->esquerda != NULL){
            fila[tras++] = temp->esquerda;
        }
        if(temp->direita != NULL){
            fila[tras++] = temp->direita;
        }
    }
    free(fila);
}

// Questão 4.2  (Busca em Profundidade)
void busca_profundidade(struct Node* no){  // Função de busca em profundidade recursiva
    if(no == NULL){    // Se o nó estiver vazio
        return;
    } 
    printf("%d ", no->chave);  // Imprime a chave do nó atual

    // Visita os nós filhos recursivamente:
    busca_profundidade(no->esquerda);   // Esquerda
    busca_profundidade(no->direita);    // Direita
}

// Questão 4.3  (Pesquisa em Arvore Binária)
struct Node* pesquisa(struct Node* raiz, int chave){  // Função de pesquisa em árvore de busca binária
    if(raiz == NULL || raiz->chave == chave){    // Se a raiz for nula ou se a chave for igual a chave da raiz 
        return raiz;   // retorna a raiz
    }
    // Se não:
    if(raiz->chave < chave){  // Se a chave for maior que a chave da raiz, retorna uma busca na subárvore direita
        return pesquisa(raiz->direita, chave);
    }
    return pesquisa(raiz->esquerda, chave);  // Se não, retorna uma busca na subárvore esquerda
}

int main(){
    int v[] = {4, 8, 13, 15, 27, 33, 41, 49, 54, 68, 80, 92};    // Vetor de entrada ordenado passado pela lista
    int tamanho = sizeof(v) / sizeof(v[0]);    // Calculo do tamanho do vetor

    // Constroi a árvore de busca binária:
    struct Node* raiz = NULL;
    for(int i = 0; i < tamanho; i++){
        raiz = inserir(raiz, v[i]);
    }
        
    // Realiza a busca em largura: (Chamada de 4.1)
    printf("Busca em largura: ");
    busca_largura(raiz);
    printf("\n");

    // Realiza a busca em profundidade: (Chamada de 4.2)
    printf("Busca em profundidade: ");
    busca_profundidade(raiz);
    printf("\n");

    // Pesquisa em árvore de busca binária: (Chamada de 4.3)
    // Valores da chaves foram passados pela ficha
    int chave1 = 8;
    int chave2 = 88;

    struct Node* resultado = pesquisa(raiz, chave1);   // Define resultado e armazena o resultado da pesquisa em árvore binária para a chave 1 (8)
    if(resultado != NULL){   // Se houver resultado
        printf("Chave %d encontrada\n", chave1);   // Printa que foi encontrado
    }else{   // Se não houver resultado
        printf("Chave %d não encontrada\n", chave1);   // Printa que não foi encontrado
    }
    
    resultado = pesquisa(raiz, chave2);    // Define resultado e armazena o resultado da pesquisa em árvore binária para a chave 2 (88)
    
    if(resultado != NULL){   // Se houver resultado
        printf("Chave %d encontrada\n", chave2);    // Printa que foi encontrado
    }else{    // Se não houver resultado
        printf("Chave %d não encontrada\n", chave2);   // Printa que não foi encontrado
    }

    return 0;
}
