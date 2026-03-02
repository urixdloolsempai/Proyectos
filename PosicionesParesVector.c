// PosicionesParesVector.c
// Programa que muestra los números almacenados en posiciones pares de un vector

#include <stdio.h>

int main() {
    int numeros[20];
    int i;

    for (i = 0; i < 20; i++) {
        printf("Ingrese el número en la posición %d: ", i);
        scanf("%d", &numeros[i]);
    }

    printf("\nNúmeros en posiciones pares:\n");

    for (i = 0; i < 20; i++) {
        if (i % 2 == 0) {
            printf("Posición %d: %d\n", i, numeros[i]);
        }
    }

    return 0;
}
