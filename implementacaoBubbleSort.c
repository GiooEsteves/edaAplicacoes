// TRABALHO DE IMPLEMENTAÇÃO
// (BUBBLESORT)

#include <stdio.h>

int trocas = 0;

void trocar(int *elemento1, int *elemento2){   // Função para trocar a posição do elemento do vetor de 2 em 2
    int temp = *elemento1;
    *elemento1 = *elemento2;
    *elemento2 = temp;
}

void bubbleSort(int arr[], int n){  // Função de ordenação BubbleSort em ordem crescente
    int i, j;

    for(i = 0; i < n-1; i++){        // Percorre todo os elementos do vetor
        for(j = 0; j < n-i-1; j++){  // Compara os elementos adjacentes e como os últimos i elementos já estão ordenados, então não é necessário compará-los
            if(arr[j] > arr[j+1]){   // Se o elemento atual for maior que o próximo elemento, realizar troca de posição entre eles
                trocar(&arr[j], &arr[j+1]);
                trocas++;            // Contador de trocas
            }
        }
    }
}

int main() {
    int vetor[] = {46, 21, 37, 12, 64, 9, 0, 71};  // Passando um vetor com números aleatórios
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);  // Calculo do tamanho do vetor

    printf("\nTamanho do vetor: %d\n", tamanho);  // Print do tamanho do vetor

    printf("Vetor antes: ");
    for(int i = 0; i < tamanho; i++){  // Passando por todo o vetor antes da ordenação
        printf("%d ", vetor[i]);       // Print número por número do vetor antes da ordenação
    }
    printf("\n");

    bubbleSort(vetor, tamanho);  // Chamando a função de ordenação BubbleSort

    printf("Vetor depois: ");
    for(int i = 0; i < tamanho; i++){  // Passando por todo o vetor depois da ordenação
        printf("%d ", vetor[i]);       // Print número por número do vetor já ordenado
    }
    printf("\n");
    printf("\nQuantidade de acoes realizadas: %d\n\n", trocas);  // Print da quantidade de trocas realizadas
    
    return 0;
}
