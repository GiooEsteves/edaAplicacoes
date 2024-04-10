// EXERCICIO
// (Pesquisa Binaria)

#include <stdio.h>

int pesquisaBinaria(int arr[], int esq, int dir, int chave, int *comparacoes){   // Função de pesquisa binária em um vetor ordenado
    while(esq <= dir){      // Percorre enquanto a subárvore não estiver vazia
        (*comparacoes)++;   // Incrementa o contador de comparações
        int meio = esq + (dir - esq)/2;   // Calcula o índice do elemento no meio do vetor

        if(arr[meio] == chave){    // Se a chave está no meio
            return meio;    // Retorna o indice do meio
        }

        if(arr[meio] < chave){   // Se a chave for maior que o elemento no meio
            esq = meio + 1;   // Atualiza para realizar a nova busca do meio para frente (onde os valores crescem)
        }else{    // Se a chave for menor que o elemento no meio
            dir = meio - 1;   // Atualiza para realizar a nova busca do meio para trás (onde os valores diminuem)
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


    int index1 = pesquisaBinaria(v, 0, tamanho - 1, chave1, &comparacao1);   // Chama a função de pesquisa binária para a chave 1 (8) armazenando a posicao em index
    if(index1 != -1){    // Se a chave for encontrada 
        printf("Chave %d encontrada na posição %d.\n", chave1, index1);    // Printa que foi encontrado mostrando a sua posição
    }else{    // Se a chave não for encontrada 
        printf("Chave %d não encontrada.\n", chave1);    // Printa que não foi encontrado
    } 

    int index2 = pesquisaBinaria(v, 0, tamanho - 1, chave2, &comparacao2);   // Chama a função de pesquisa sequencial para a chave 2 (88) armazenando a posicao em index
    if(index2 != -1){   // Se a chave for encontrada 
        printf("Chave %d encontrada na posição %d.\n", chave2, index2);   // Printa que foi encontrado mostrando a sua posição
    }else{    // Se a chave não for encontrada 
        printf("Chave %d não encontrada.\n", chave2);    // Printa que não foi encontrado
    }

    printf("Quantidade de comparações da busca da chave %d: %d\n", chave1, comparacao1);   // Printa o numero de comparações da chave 1
    printf("Quantidade de comparações da busca da chave %d: %d\n", chave2, comparacao2);   // Printa o numero de comparações da chave 2

    return 0;
}
