// Definición de la estructura Libro con sus campos typedef struct { int id; char titulo[50]; char autor[50]; int anio; } Libro;

#include <stdio.h> #include <string.h>

// Declaración de las funciones del programa void altaLibro(Libro libros[], int* cantidad); void bajaLibro(Libro libros[], int* cantidad); void modificarLibro(Libro libros[], int cantidad); void buscarLibro(Libro libros[], int cantidad); void mostrarLibros(Libro libros[], int cantidad);

int main() { Libro libros[100]; // Arreglo para almacenar hasta 100 libros int cantidad = 0; // Cantidad actual de libros cargados int opcion; // Variable para el menú de opciones

// Menú principal con opciones hasta que el usuario elija salir
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

    // Según la opción, se llama a la función correspondiente
    switch(opcion) {
        case 1: altaLibro(libros, &cantidad); break;
        case 2: bajaLibro(libros, &cantidad); break;
        case 3: modificarLibro(libros, cantidad); break;
        case 4: buscarLibro(libros, cantidad); break;
        case 5: mostrarLibros(libros, cantidad); break;
    }
} while(opcion != 0); // Repite hasta que se elija "0. Salir"

return 0;
}

// Función para dar de alta un nuevo libro void altaLibro(Libro libros[], int* cantidad) { printf("Ingrese ID: "); scanf("%d", &libros[*cantidad].id); getchar(); // limpiar buffer de entrada

printf("Ingrese titulo: ");
fgets(libros[*cantidad].titulo, 50, stdin); // leer título con espacios
libros[*cantidad].titulo[strcspn(libros[*cantidad].titulo, "\n")] = '\0'; // quitar salto de línea

printf("Ingrese autor: ");
fgets(libros[*cantidad].autor, 50, stdin); // leer autor con espacios
libros[*cantidad].autor[strcspn(libros[*cantidad].autor, "\n")] = '\0'; // quitar salto de línea

printf("Ingrese año: ");
scanf("%d", &libros[*cantidad].anio);

(*cantidad)++; // aumentar cantidad de libros registrados
}

// Función para eliminar un libro por ID void bajaLibro(Libro libros[], int* cantidad) { int id, i, encontrado = 0; printf("Ingrese ID a eliminar: "); scanf("%d", &id);

// Buscar el libro por ID
for(i = 0; i < *cantidad; i++) {
    if(libros[i].id == id) {
        // Si lo encuentra, recorre el arreglo para eliminarlo
        for(int j = i; j < *cantidad - 1; j++)
            libros[j] = libros[j+1];
        (*cantidad)--;  // reducir cantidad
        encontrado = 1;
        break;
    }
}
if(!encontrado) {
    printf("Libro no encontrado.\n");
}
}

// Función para modificar los datos de un libro por ID void modificarLibro(Libro libros[], int cantidad) { int id, i; printf("Ingrese ID del libro a modificar: "); scanf("%d", &id);

// Buscar el libro
for(i = 0; i < cantidad; i++) {
    if(libros[i].id == id) {
        getchar(); // limpiar buffer
        printf("Nuevo titulo: ");
        fgets(libros[i].titulo, 50, stdin);
        libros[i].titulo[strcspn(libros[i].titulo, "\n")] = '\0';

        printf("Nuevo autor: ");
        fgets(libros[i].autor, 50, stdin);
        libros[i].autor[strcspn(libros[i].autor, "\n")] = '\0';

        printf("Nuevo año: ");
        scanf("%d", &libros[i].anio);
        return;
    }
}
printf("Libro no encontrado.\n");
}

// Función para buscar un libro por título void buscarLibro(Libro libros[], int cantidad) { char titulo[50]; getchar(); // limpiar buffer printf("Ingrese titulo a buscar: "); fgets(titulo, 50, stdin); titulo[strcspn(titulo, "\n")] = '\0';

// Comparar títulos con los libros guardados
for(int i = 0; i < cantidad; i++) {
    if(strcmp(libros[i].titulo, titulo) == 0) {
        printf("ID: %d\nTitulo: %s\nAutor: %s\nAño: %d\n",
               libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio);
        return;
    }
}
printf("Libro no encontrado.\n");
}

// Función para mostrar todos los libros registrados void mostrarLibros(Libro libros[], int cantidad) { if(cantidad == 0) { // Si no hay libros printf("No hay libros cargados.\n"); return; }

// Mostrar datos de cada libro
for(int i = 0; i < cantidad; i++) {
    printf("\nID: %d\nTitulo: %s\nAutor: %s\nAño: %d\n",
           libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio);
}
}
