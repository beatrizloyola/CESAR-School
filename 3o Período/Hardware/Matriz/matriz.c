#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <linux/time.h>

#define N 4096

static int m[N][N];

double soma_por_linha(void) {
    struct timespec ini, fim;
    clock_gettime(CLOCK_MONOTONIC, &ini);
    long long soma = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            soma += m[i][j];
    clock_gettime(CLOCK_MONOTONIC, &fim);
    printf(" linha -> soma=%lld ", soma);
    return (fim.tv_sec - ini.tv_sec) + (fim.tv_nsec - ini.tv_nsec) / 1e9;
}

double soma_por_coluna(void) {
    struct timespec ini, fim;
    clock_gettime(CLOCK_MONOTONIC, &ini);
    long long soma = 0;
    for (int j = 0; j < N; j++)
        for (int i = 0; i < N; i++)
            soma += m[i][j];
    clock_gettime(CLOCK_MONOTONIC, &fim);
    printf(" coluna -> soma=%lld ", soma);
    return (fim.tv_sec - ini.tv_sec) + (fim.tv_nsec - ini.tv_nsec) / 1e9;
}

int main(void) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            m[i][j] = i + j;

    double t_coluna = soma_por_coluna();
    printf("  tempo=%.9fs\n", t_coluna);

    double t_linha = soma_por_linha();
    printf("  tempo=%.9fs\n", t_linha);

    return 0;
}