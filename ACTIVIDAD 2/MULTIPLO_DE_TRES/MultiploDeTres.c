// MultiploDeTres.c
// Programa que verifica si un número es múltiplo de 3

#include <stdio.h>

int main() {
    int numero;

    printf("Ingrese un número: ");
    scanf("%d", &numero);

    if (numero % 3 == 0) {
        printf("El número %d es múltiplo de 3\n", numero);
    } else {
        printf("El número %d NO es múltiplo de 3\n", numero);
    }

    return 0;
}
