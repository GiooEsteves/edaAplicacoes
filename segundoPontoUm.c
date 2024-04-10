// EXERCICIO
// (BubbleSort)

#include <stdio.h>

void trocar(int *elemento1, int *elemento2){   // Função para trocar a posição do elemento do vetor de 2 em 2
    int temp = *elemento1;
    *elemento1 = *elemento2;
    *elemento2 = temp;
}

void bubbleSort(int arr[], int tamanho){          // Função de ordenação BubbleSort em ordem crescente
    for(int i = 0; i < tamanho - 1; i++){         // Percorre todo os elementos do vetor
        for(int j = 0; j < tamanho - i - 1; j++){ // Compara os elementos adjacentes e como os últimos i elementos já estão ordenados, então não é necessário compará-los
            if(arr[j] > arr[j + 1]){    // Se o elemento atual for maior que o próximo elemento, realizar troca de posição entre eles
                trocar(&arr[j], &arr[j + 1]);
            }
        }
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

    bubbleSort(v, tamanho);   // Chamando a função de ordenação BubbleSort

    printf("Vetor ordenado: ");
    for(int i = 0; i < tamanho; i++){  // Passando por todo o vetor depois da ordenação
        printf("%d ", v[i]);           // Print número por número do vetor depois da ordenação
    }
    printf("\n");

    return 0;
}
