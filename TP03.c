#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float X;
    float Y;
} Ponto;

// Função para calcular a área de um polígono
float calcularArea(Ponto* pontos, int n) {
    float area = 0.0;
    int j;

    for (int i = 0; i < n; i++) {
        j = (i + 1) % n;
        area += (pontos[i].X * pontos[j].Y) - (pontos[j].X * pontos[i].Y);
    }

    return 0.5 * fabs(area);
}

int main() {
    FILE* arquivo;
    int n;
    
    arquivo = fopen("vertices.txt", "r"); // Substitua "vertices.txt" pelo nome do seu arquivo

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fscanf(arquivo, "%d", &n);

    Ponto* pontos = (Ponto*)malloc(n * sizeof(Ponto));

    for (int i = 0; i < n; i++) {
        fscanf(arquivo, "%f %f", &pontos[i].X, &pontos[i].Y);
    }

    fclose(arquivo);

    float area = calcularArea(pontos, n);
    printf("A área do polígono é %.2f\n", area);

    free(pontos);

    return 0;
}
