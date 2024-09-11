#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD_LINHAS 100
#define QTD_COLUNAS 100

int lerMatriz(int min, int max);
void preencherMatrizAleatoria(int matriz[][QTD_COLUNAS], int lin, int col);
void imprimirMatriz(int matriz[][QTD_COLUNAS], int lin, int col);
int quantidadeImpares(int matriz[][QTD_COLUNAS], int lin, int col);
int encontrarValor(int matriz[][QTD_COLUNAS], int lin, int col, int *linEncontrada, int *colEncontrada);
int somatorioMatriz(int matriz[][QTD_COLUNAS], int lin, int col);
int mediaElementos(int matriz[][QTD_COLUNAS], int lin, int col);
void mediaElementosLinhas(int matriz[][QTD_COLUNAS], int lin, int col);

int main() {
    int qtdLinhas, qtdColunas, qtdImpares, valor, linhaEncontrada, colunaEncontrada, somatorio, media;
    int matriz[QTD_LINHAS][QTD_COLUNAS];

    srand(time(0));

    printf("Qual a quantidade de linhas? (1-%d): ", QTD_LINHAS);
    qtdLinhas = lerMatriz(1, QTD_LINHAS);
    printf("Qual a quantidade de colunas? (1-%d): ", QTD_COLUNAS);
    qtdColunas = lerMatriz(1, QTD_COLUNAS);

    preencherMatrizAleatoria(matriz, qtdLinhas, qtdColunas);
    printf("\n--------------------\n");
    imprimirMatriz(matriz, qtdLinhas, qtdColunas);

    qtdImpares = quantidadeImpares(matriz, qtdLinhas, qtdColunas);
    printf("A quantidade de números ímpares é: %d\n\n", qtdImpares);

    printf("Qual valor você deseja encontrar na matriz?\n");
    valor = encontrarValor(matriz, qtdLinhas, qtdColunas, &linhaEncontrada, &colunaEncontrada);
    while(valor == 0) {
        printf("Valor não encontrado. Tente novamente. Qual valor você deseja encontrar na matriz?\n");
        valor = encontrarValor(matriz, qtdLinhas, qtdColunas, &linhaEncontrada, &colunaEncontrada);
    }
    printf("Valor encontrado na posição i = %d, j = %d\n\n", linhaEncontrada, colunaEncontrada);

    somatorio = somatorioMatriz(matriz, qtdLinhas, qtdColunas);
    printf("O somatório dos valores da matriz é: %d\n\n", somatorio);

    media = somatorioMatriz(matriz, qtdLinhas, qtdColunas) / mediaElementos(matriz, qtdLinhas, qtdColunas);
    printf("A média de todos os elementos da matriz é: %d\n\n", media);

    mediaElementosLinhas(matriz, qtdLinhas, qtdColunas);

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

void preencherMatrizAleatoria(int matriz[][QTD_COLUNAS], int lin, int col) {
    for(int i = 0; i < lin; ++i) {
        for(int j = 0; j < col; ++j) {
            matriz[i][j] = rand() % 100 + 1;
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

int quantidadeImpares(int matriz[][QTD_COLUNAS], int lin, int col) {
    int qtdImpar = 0;
    for(int i = 0; i < lin; ++i) {
        for(int j = 0; j < col; ++j) {
            if(matriz[i][j] % 2 != 0) {
                ++qtdImpar;
            }
        }
    }
    return qtdImpar;
}

int encontrarValor(int matriz[][QTD_COLUNAS], int lin, int col, int *linEncontrada, int *colEncontrada) {
    int valor, valorEncontrado;
    scanf("%d", &valor);
    for(int i = 0; i < lin; ++i) {
        for(int j = 0; j < col; ++j) {
            if(matriz[i][j] == valor) {
                *linEncontrada = i+1;
                *colEncontrada = j+1;
                return 1;
            }
        }
    } return 0;
}

int somatorioMatriz(int matriz[][QTD_COLUNAS], int lin, int col) {
    int soma = 0;
    for(int i = 0; i < lin; ++i) {
        for(int j = 0; j < col; ++j) {
            soma += matriz[i][j];
        }
    } return soma;
}

int mediaElementos(int matriz[][QTD_COLUNAS], int lin, int col) {
    int soma = 0;
    for(int i = 0; i < lin; ++i) {
        for(int j = 0; j < col; ++j) {
            ++soma;
        }
    } return soma;
}

void mediaElementosLinhas(int matriz[][QTD_COLUNAS], int lin, int col) {
    int linha = 0, medialinha;
    for(int i = 0; i < lin; ++i) {
        linha = 0;
        for(int j = 0; j < col; ++j) {
            linha += matriz[i][j];
            medialinha = linha / col;
        }
        printf("A média dos elementos da linha %d é: %d\n", i+1, medialinha);
    }
    printf("\n");
}