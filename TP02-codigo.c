#include <stdio.h>
#include <string.h>

int trocas = 0; 
int comparacoes = 0; 

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
    trocas++; 
}

int partition(char *arr[], int low, int high) {
    char *pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        comparacoes++; 
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(char *arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi", "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }

    printf("\n");

    quicksort(arr, 0, n - 1);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }

    printf("\n");

    printf("Numero de trocas: %d\n", trocas);
    printf("Numero de comparacoes: %d\n", comparacoes);

    
    char *mediana = arr[n / 2];
    printf("Mediana: %s\n", mediana);

    
    FILE *arquivo = fopen("saida.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(arquivo, "%s\n", arr[i]);
    }

    fclose(arquivo);

    return 0;
}
