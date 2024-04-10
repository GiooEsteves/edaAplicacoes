// TRABALHO DE IMPLEMENTAÇÃO
// (QUICKSORT)

#include <stdio.h>

int trocas = 0; // Variável global para contar o número de trocas

void trocar(int *elemento1, int *elemento2){ // Função para trocar a posição do elemento do vetor de 2 em 2
    int temp = *elemento1;
    *elemento1 = *elemento2;
    *elemento2 = temp;
    trocas++;   // Contador de trocas
}

int partir(int vetor[], int baixo, int alto){ // Função para partir o array e encontrar o pivô
    int pivo = vetor[alto]; // Pivô é o elemento mais à direita
    int i = (baixo - 1);    // Indice do menor elemento

    for(int j = baixo; j <= alto - 1; j++){  // Passa por todos os elementos do array da esquerda para a direita
        if(vetor[j] <= pivo){   // Se o elemento atual é menor ou igual ao pivô
            i++;                // Atualiza o índice do menor elemento
            trocar(&vetor[i], &vetor[j]);   // Troca as posições do novo menor elemento encontrado com o vetor atual
        }
    }
    trocar(&vetor[i + 1], &vetor[alto]);    // Troca as posições do pivô com o vetor seguinte ao menor elemento encontrado
    return (i + 1);  // Novo índice do pivô
}

void quickSort(int vetor[], int baixo, int alto){ // Função de ordenação QuickSort em ordem crescente
    if(baixo < alto){   // Se a posição mais a esquerda for menor que a posição mais a direita (teste)
        int pi = partir(vetor, baixo, alto); // parte o vetor e obtém o índice do pivô

        // Ordena os elementos antes e depois do pivô:
        quickSort(vetor, baixo, pi - 1);
        quickSort(vetor, pi + 1, alto);
    }
}

int main(){
    int vetor[] = {45, 21, 37, 12, 64, 9, 0, 71}; // Passando um vetor com números aleatórios
    int tamanho = sizeof(vetor) / sizeof(vetor[0]); // Calculo do tamanho do vetor

    printf("\nTamanho do vetor: %d\n", tamanho); // Print do tamanho do vetor

    printf("Vetor antes: ");
    for(int i = 0; i < tamanho; i++){ // Passando por todo o vetor antes da ordenação
        printf("%d ", vetor[i]); // Print número por número do vetor antes da ordenação
    }
    printf("\n");

    quickSort(vetor, 0, tamanho - 1); // Chama a função QuickSort para ordenar o vetor 

    printf("Vetor depois: ");
    for(int i = 0; i < tamanho; i++){ // Passando por todo o vetor depois da ordenação
        printf("%d ", vetor[i]); // Print número por número do vetor já ordenado
    }
    printf("\n");
    printf("\nQuantidade de trocas realizadas: %d\n\n", trocas); // Print da quantidade de trocas realizadas

    return 0;
}
