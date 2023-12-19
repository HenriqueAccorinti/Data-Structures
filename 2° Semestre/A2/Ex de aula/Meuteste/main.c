#include <stdio.h>
#include <stdlib.h>

#define N 10

void trocar(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int particionar(int *v, int l, int r, int p) {
    int i, j;
    int valor_pivo = v[p];
    trocar(&v[p], &v[r]);
    j = l;
    for (i = l; i <= r - 1; i++) {
        if (v[i] <= valor_pivo) {
            trocar(&v[i], &v[j]);
            j++;
        }
    }
    trocar(&v[j], &v[r]);
    return j;
}

void quicksort(int *v, int l, int r) {
    int pivo, novoPivo;
    /* se a lista possui 2 ou mais elementos */
    if (l < r) {
        /* escolher o índice do meio como pivô */
        pivo = (l + r) / 2;
        novoPivo = particionar(v, l, r, pivo);
        /* ordenação recursiva dos subvetores */
        quicksort(v, l, novoPivo - 1);
        quicksort(v, novoPivo + 1, r);
    }
}

void exibir_vetor(int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int busca_binaria_iterativa(int *v, int l, int r, int valor) {
    int pos = -1;
    int m;
    do {
        m = (l + r) / 2;
        if (valor == v[m])  //achou
            pos = m;
        else if (valor < v[m])
            r = m - 1;
        else
            l = m + 1;
    } while (v[m] != valor && l <= r);
    return pos;
}

int busca_binaria_recursiva(int *v, int l, int r, int valor) {
    int m;
    if (l > r)
        return -1;
    m = (l + r) / 2;
    if (valor == v[m])  //achou
        return m;
    else if (valor < v[m])
        return busca_binaria_recursiva(v, l, m - 1, valor);
    else
        return busca_binaria_recursiva(v, m + 1, r, valor);
}

int main(void) {
    int v[N] = {4, 0, 11, 8, 9, -2, 3, 8, 2, 3};
    exibir_vetor(v, N);
    quicksort(v, 0, N - 1);
    exibir_vetor(v, N);

    printf("%d\n", busca_binaria_iterativa(v, 0, N - 1, -2));

    printf("%d\n", busca_binaria_recursiva(v, 0, N - 1, -2));

    return 0;
}
