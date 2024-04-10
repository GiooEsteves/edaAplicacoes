// EXERCICIO
// (HeapSort)

#include <stdio.h>

void trocar(int *elemento1, int *elemento2){   // Função para trocar a posição do elemento do vetor de 2 em 2
    int temp = *elemento1;
    *elemento1 = *elemento2;
    *elemento2 = temp;
}

void ajustarHeap(int arr[], int n, int i){     // Função que transforma uma subárvore em um heap máximo
    int maior = i; // Inicializa o maior como sendo o nó raiz da subárvore
    int esquerda = 2*i + 1; // Índice do filho esquerdo
    int direita = 2*i + 2; // Índice do filho direito

    if(esquerda < n && arr[esquerda] > arr[maior]){  // Se o filho esquerdo for maior que o pai
        maior = esquerda;       // O maior recebe o elemento do filho esquerdo
    }

    if(direita < n && arr[direita] > arr[maior]){   // Verifica se o filho direito for maior que o pai
        maior = direita;     // O maior recebe o elemento do filho direito
    }
        
    if(maior != i){      // Se o maior não for o nó raiz, realiza a troca e ajusta o heap
        trocar(&arr[i], &arr[maior]);
        ajustarHeap(arr, n, maior);
    }
}

void heapSort(int arr[], int n){   // Função de ordenação HeapSort em ordem crescente
    for(int i = n/2 - 1; i >= 0; i--){   // Constrói um heap máximo a partir do vetor
        ajustarHeap(arr, n, i);
    }
        
    for(int i = n - 1; i > 0; i--){  // Extrai elementos um por um do heap
        trocar(&arr[0], &arr[i]);    // Move o elemento atual para o final do vetor
        ajustarHeap(arr, i, 0);      // Chama ajustarHeap na subárvore reduzida
    }
}

int main(){
    int v[] = {41, 15, 80, 33, 27, 8, 92, 13, 54, 4, 68, 49};   // Vetor passado pela lista
    int tamanho = sizeof(v) / sizeof(v[0]);  // Calculo do tamanho do vetor

    printf("\nVetor antes: ");
    for(int i = 0; i < tamanho; i++){  // Passando por todo o vetor antes da ordenação
        printf("%d ", v[i]);           // Print número por número do vetor antes da ordenação
    }
    printf("\n");

    heapSort(v, tamanho);   // Chamando a função de ordenação HeapSort

    printf("Vetor ordenado: ");
    for(int i = 0; i < tamanho; i++){  // Passando por todo o vetor depois da ordenação
        printf("%d ", v[i]);           // Print número por número do vetor já ordenado
    }
    printf("\n");

    return 0;
}
