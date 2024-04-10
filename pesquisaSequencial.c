// EXERCICIO
// (Pesquisa Sequencial)

#include <stdio.h>

int pesquisaSequencial(int arr[], int tamanho, int chave, int *comparacoes){
    for(int i = 0; i < tamanho; i++){   // Percorre todo o vetor
        (*comparacoes)++;   // Incrementa o contador de comparações
        if(arr[i] == chave){   // Se o elemento atual for igual a chave procurada
            return i;   // Retorna o índice desse elemento
        }
    }
    return -1; // Retorna para chave não encontrada
}

int main(){
    int v[] = {4, 8, 13, 15, 27, 33, 41, 49, 54, 68, 80, 92};  // Vetor passado pela ficha
    int tamanho = sizeof(v) / sizeof(v[0]);  // Calculando o tamanho do vetor

    // Chaves passadas pela ficha:
    int chave1 = 8;
    int chave2 = 88;

    // Inicializa o contador de comparações de cada com 0:
    int comparacao1 = 0;
    int comparacao2 = 0;

    int index1 = pesquisaSequencial(v, tamanho, chave1, &comparacao1);    // Chama a função de pesquisa sequencial para a chave 1 (8) armazenando a posicao em index
    if(index1 != -1){    // Se a chave for encontrada 
        printf("Chave %d encontrada na posição %d.\n", chave1, index1);   // Printa que a chave foi encontrada
    }else{    // Se não foi encontrada
        printf("Chave %d não encontrada.\n", chave1);    // Printa que não foi encontrada
    }

    int index2 = pesquisaSequencial(v, tamanho, chave2, &comparacao2);     // Chama a função de pesquisa sequencial para a chave 2 (88) armazenando a posicao em index
    if(index2 != -1){    // Se a chave for encontrada
        printf("Chave %d encontrada na posição %d.\n", chave2, index2);    // Printa que a chave foi encontrada mostrando a sua posição
    }else{     // Se não foi encontrada
        printf("Chave %d não encontrada.\n", chave2);    // Printa que não foi encontrada
    }

    printf("Quantidade de comparações da busca da chave %d: %d\n", chave1, comparacao1);   // Printa o numero de comparações da chave 1
    printf("Quantidade de comparações da busca da chave %d: %d\n", chave2, comparacao2);   // Printa o numero de comparações da chave 2

    return 0;
}
