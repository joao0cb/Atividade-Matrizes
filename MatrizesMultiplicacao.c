#include <stdio.h>

#define QTD_LINHAS 100
#define QTD_COLUNAS 100

int lerMatriz(int min, int max);
void preencherMatriz(int matriz[][QTD_COLUNAS], int lin, int col);
void imprimirMatriz(int matriz[][QTD_COLUNAS], int lin, int col);
void multiplicarMatrizes(int matrizA[QTD_LINHAS][QTD_COLUNAS], int linA, int colA, int matrizB[QTD_LINHAS][QTD_COLUNAS], int linB, int colB, int matrizMult[QTD_LINHAS][QTD_COLUNAS]);

int main() {
    int matrizA[QTD_LINHAS][QTD_COLUNAS];
    int matrizB[QTD_LINHAS][QTD_COLUNAS];
    int matrizMult[QTD_LINHAS][QTD_COLUNAS];
    int qtdLinhasA, qtdLinhasB, qtdColunasA, qtdColunasB;

    printf("Qual a quantidade de linhas da matriz A? (1-%d): ", QTD_LINHAS);
    qtdLinhasA = lerMatriz(1, QTD_LINHAS);
    printf("Qual a quantidade de colunas da matriz A? (1-%d): ", QTD_COLUNAS);
    qtdColunasA = lerMatriz(1, QTD_COLUNAS);
    printf("\nQual a quantidade de linhas da matriz B? (1-%d): ", QTD_LINHAS);
    qtdLinhasB = lerMatriz(1, QTD_LINHAS);
    printf("Qual a quantidade de colunas da matriz B? (1-%d): ", QTD_COLUNAS);
    qtdColunasB = lerMatriz(1, QTD_COLUNAS);

    printf("\nPreencha a matriz A:\n");
    preencherMatriz(matrizA, qtdLinhasA, qtdColunasA);
    printf("\nPreencha a matriz B:\n");
    preencherMatriz(matrizB, qtdLinhasB, qtdColunasB);

    printf("\nMatriz A:\n");
    imprimirMatriz(matrizA, qtdLinhasA, qtdColunasA);
    printf("Matriz B:\n");
    imprimirMatriz(matrizB, qtdLinhasB, qtdColunasB);

    multiplicarMatrizes(matrizA, qtdLinhasA, qtdColunasA, matrizB, qtdLinhasB, qtdColunasB, matrizMult);

    return 0;
}

int lerMatriz(int min, int max) {
    int valor;
    scanf("%d", &valor);
    while(valor < min || valor > max) {
        printf("Valor inválido! Tnete novamente.\n");
        scanf("%d", &valor);
    }
    return valor;
}

void preencherMatriz(int matriz[][QTD_COLUNAS], int lin, int col) {
    for(int i = 0; i < lin; ++i) {
        for(int j = 0; j < col; ++j) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimirMatriz(int matriz[][QTD_COLUNAS], int lin, int col) {
    for(int i = 0; i < lin; ++i) {
        for(int j = 0; j < col; ++j) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void multiplicarMatrizes(int matrizA[QTD_LINHAS][QTD_COLUNAS], int linA, int colA, int matrizB[QTD_LINHAS][QTD_COLUNAS], int linB, int colB, int matrizMult[QTD_LINHAS][QTD_COLUNAS]) {
    if(colA != linB) {
        printf("Não é possível multiplicar essas duas matrizes! O número de colunas da matriz A deve ser igual ao número de linhas\nda matriz B. Tente novamente!\n\n");
        return;
    }
    for(int i = 0; i < linA; ++i) {
        for(int j = 0; j < colB; ++j) {
            matrizMult[i][j] = 0;
        }
    }

    for(int i = 0; i < linA; ++i) {
        for(int j = 0; j < colB; ++j) {
            for(int k = 0; k < colA; ++k) {
                matrizMult[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    printf("Resultado da multiplicação\n");
    imprimirMatriz(matrizMult, linA, colB);
}