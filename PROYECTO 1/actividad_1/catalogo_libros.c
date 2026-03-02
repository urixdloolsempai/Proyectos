#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char titulo[50];
    char autor[50];
    int anio;
} Libro;

void altaLibro(Libro libros[], int* cantidad);
void bajaLibro(Libro libros[], int* cantidad);
void modificarLibro(Libro libros[], int cantidad);
void buscarLibro(Libro libros[], int cantidad);
void mostrarLibros(Libro libros[], int cantidad);

int main() {
    Libro libros[100];
    int cantidad = 0;
    int opcion;

    do {
        printf("\n--- Catalogo de Libros ---\n");
        printf("1. Agregar libro\n");
        printf("2. Eliminar libro\n");
        printf("3. Modificar libro\n");
        printf("4. Buscar libro\n");
        printf("5. Mostrar todos los libros\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: altaLibro(libros, &cantidad); break;
            case 2: bajaLibro(libros, &cantidad); break;
            case 3: modificarLibro(libros, cantidad); break;
            case 4: buscarLibro(libros, cantidad); break;
            case 5: mostrarLibros(libros, cantidad); break;
            case 0: printf("Saliendo del programa...\n"); break;
            default: printf("Opcion invalida.\n");
        }

    } while(opcion != 0);

    return 0;
}

void altaLibro(Libro libros[], int* cantidad) {
    printf("Ingrese ID: ");
    scanf("%d", &libros[*cantidad].id);
    getchar();

    printf("Ingrese titulo: ");
    fgets(libros[*cantidad].titulo, 50, stdin);
    libros[*cantidad].titulo[strcspn(libros[*cantidad].titulo, "\n")] = '\0';

    printf("Ingrese autor: ");
    fgets(libros[*cantidad].autor, 50, stdin);
    libros[*cantidad].autor[strcspn(libros[*cantidad].autor, "\n")] = '\0';

    printf("Ingrese año: ");
    scanf("%d", &libros[*cantidad].anio);

    (*cantidad)++;
    printf("Libro agregado correctamente.\n");
}

void bajaLibro(Libro libros[], int* cantidad) {
    int id, i, encontrado = 0;

    printf("Ingrese ID a eliminar: ");
    scanf("%d", &id);

    for(i = 0; i < *cantidad; i++) {
        if(libros[i].id == id) {
            for(int j = i; j < *cantidad - 1; j++) {
                libros[j] = libros[j+1];
            }
            (*cantidad)--;
            encontrado = 1;
            printf("Libro eliminado correctamente.\n");
            break;
        }
    }

    if(!encontrado) {
        printf("Libro no encontrado.\n");
    }
}

void modificarLibro(Libro libros[], int cantidad) {
    int id;

    printf("Ingrese ID del libro a modificar: ");
    scanf("%d", &id);

    for(int i = 0; i < cantidad; i++) {
        if(libros[i].id == id) {
            getchar();

            printf("Nuevo titulo: ");
            fgets(libros[i].titulo, 50, stdin);
            libros[i].titulo[strcspn(libros[i].titulo, "\n")] = '\0';

            printf("Nuevo autor: ");
            fgets(libros[i].autor, 50, stdin);
            libros[i].autor[strcspn(libros[i].autor, "\n")] = '\0';

            printf("Nuevo año: ");
            scanf("%d", &libros[i].anio);

            printf("Libro modificado correctamente.\n");
            return;
        }
    }

    printf("Libro no encontrado.\n");
}

void buscarLibro(Libro libros[], int cantidad) {
    char titulo[50];
    getchar();

    printf("Ingrese titulo a buscar: ");
    fgets(titulo, 50, stdin);
    titulo[strcspn(titulo, "\n")] = '\0';

    for(int i = 0; i < cantidad; i++) {
        if(strcmp(libros[i].titulo, titulo) == 0) {
            printf("\nID: %d\nTitulo: %s\nAutor: %s\nAño: %d\n",
                   libros[i].id,
                   libros[i].titulo,
                   libros[i].autor,
                   libros[i].anio);
            return;
        }
    }

    printf("Libro no encontrado.\n");
}

void mostrarLibros(Libro libros[], int cantidad) {
    if(cantidad == 0) {
        printf("No hay libros cargados.\n");
        return;
    }

    for(int i = 0; i < cantidad; i++) {
        printf("\nID: %d\nTitulo: %s\nAutor: %s\nAño: %d\n",
               libros[i].id,
               libros[i].titulo,
               libros[i].autor,
               libros[i].anio);
    }
}
