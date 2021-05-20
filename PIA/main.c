#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// En C no podemos tener cadenas sin límite, por eso definimos un límite considerable
#define MAX_CADENA 101


// El struct que guarda los datos de las películas
struct detalleDePelicula {
    char nombre[MAX_CADENA];
    char horaInicio[MAX_CADENA];
    char cine[MAX_CADENA];
    char sala[MAX_CADENA];
    char dia[MAX_CADENA];
    char clasificacion;
    // Aquí hay un struct dentro de un struct, pues vamos a guardar los datos en una "pila" en donde este dato puede tener
    // otro dato en "siguiente"
    struct detalleDePelicula *siguiente;
};

// El inicio de la pila es un nodo superior que al inicio es NULL
struct detalleDePelicula *superior = NULL;


// Función que regresará un detalle de película en caso de encontrarla
struct detalleDePelicula *
buscar(char horaInicio[MAX_CADENA], char cine[MAX_CADENA], char sala[MAX_CADENA],
       char dia[MAX_CADENA]) {
    // Vamos a usar este temporal para leer toda la pila
    struct detalleDePelicula *temporal = superior;
    // Recorremos toda la pila
    while (temporal != NULL) {
        // Si encontramos que coincide lo buscado con lo que hay en la pila en este momento, entonces regresamos el detalle
        if (
                strcmp(cine, temporal->cine) == 0 &&
                strcmp(sala, temporal->sala) == 0 &&
                strcmp(horaInicio, temporal->horaInicio) == 0 &&
                strcmp(dia, temporal->dia) == 0
                ) {
            return temporal;
        }
        // Y vamos avanzando
        temporal = temporal->siguiente;
    }
    // En caso de terminar de recorrer la pila y que no haya nada, regresamos NULL
    return NULL;
}


// Agrega una película por primera vez
void
agregarPorPrimeraVez(char nombre[MAX_CADENA], char horaInicio[MAX_CADENA],
                     char cine[MAX_CADENA], char sala[MAX_CADENA],
                     char dia[MAX_CADENA], char clasificacion) {
    // Requerir RAM para alojar este detalle de película
    struct detalleDePelicula *d = malloc(sizeof(struct detalleDePelicula));
    // Llenamos el struct. Copiamos el nombre, hora, etcétera
    memcpy(d->nombre, nombre, MAX_CADENA);
    memcpy(d->horaInicio, horaInicio, MAX_CADENA);
    memcpy(d->cine, cine, MAX_CADENA);
    memcpy(d->sala, sala, MAX_CADENA);
    memcpy(d->dia, dia, MAX_CADENA);
    d->clasificacion = clasificacion;
    // Y como estamos agregando un elemento, ahora éste es el superior, y su siguiente es el que antes era el superior
    d->siguiente = superior;
    superior = d;
}


// Si ya existe, la actualiza. Si no, la agrega por primera vez
void agregarOActualizar(char nombre[MAX_CADENA], char horaInicio[MAX_CADENA],
                        char cine[MAX_CADENA], char sala[MAX_CADENA],
                        char dia[MAX_CADENA], char clasificacion) {
    // Buscar película con estos datos
    struct detalleDePelicula *existente = buscar(horaInicio, cine, sala, dia);
    // Si no existe, lo agregamos por primera vez
    if (existente == NULL) {
        agregarPorPrimeraVez(nombre, horaInicio, cine, sala, dia, clasificacion);
        printf("\nAdded Movie\n");
    } else {
        // Si no, solo actualizamos (y lo indicamos)
        memcpy(existente->nombre, nombre, MAX_CADENA);
        memcpy(existente->horaInicio, horaInicio, MAX_CADENA);
        memcpy(existente->cine, cine, MAX_CADENA);
        memcpy(existente->sala, sala, MAX_CADENA);
        memcpy(existente->dia, dia, MAX_CADENA);
        existente->clasificacion = clasificacion;
        printf("\nMovie Already existed, it was replaced\n");
    }
}


// Esta función se reutiliza varias veces. Simplemente recibe un detalle de película y lo imprime
void imprimirPelicula(struct detalleDePelicula *detalleDePelicula) {
    printf("Name: %s, Hour: %s, Cinema: %s, Room: %s, Date: %s, Rating: %c\n", detalleDePelicula->nombre,
           detalleDePelicula->horaInicio, detalleDePelicula->cine, detalleDePelicula->sala, detalleDePelicula->dia,
           detalleDePelicula->clasificacion);
}

// Esta función busca una película existente con los datos (usando la función "buscar" vista anteriormente
// En caso de que encuentre datos, invoca a "imprimirPelicula" vista anteriormente de igual modo
void desplegarInformacion(char horaInicio[MAX_CADENA], char cine[MAX_CADENA],
                          char sala[MAX_CADENA], char dia[MAX_CADENA]) {
    printf("\n--Search results from hour, cinema, room and date --\n");
    struct detalleDePelicula *existente = buscar(horaInicio, cine, sala, dia);
    if (existente == NULL) {
        printf("There's no movie with that information");
    } else {
        imprimirPelicula(existente);
    }
}

// Recorre toda la pila de películas y en caso de que encuentre una en la que coincide el nombre, la imprime
void buscarPeliculaPorNombre(char nombre[MAX_CADENA]) {
    printf("\n--Search results by name --\n");
    struct detalleDePelicula *temporal = superior;
    while (temporal != NULL) {
        if (strcmp(nombre, temporal->nombre) == 0) {
            imprimirPelicula(temporal);
        }
        temporal = temporal->siguiente;
    }
}

// Lo mismo que "buscarPeliculaPorNombre" pero ahora también busca por día y clasificación
void buscarPeliculaPorDiaYClasificacion(char dia[MAX_CADENA], char clasificacion) {
    printf("\n--Search results by date and rating --\n");
    struct detalleDePelicula *temporal = superior;
    while (temporal != NULL) {
        if (strcmp(dia, temporal->dia) == 0 && temporal->clasificacion == clasificacion) {
            imprimirPelicula(temporal); // <-- Aquí reusamos la función "imprimirPelicula"
        }
        temporal = temporal->siguiente;
    }
}

int main() {
    // Declarar variables que vamos a reusar durante toda la ejecución
    int eleccion;
    char nombre[MAX_CADENA];
    char horaInicio[MAX_CADENA];
    char cine[MAX_CADENA];
    char sala[MAX_CADENA];
    char dia[MAX_CADENA];
    char clasificacion;
    // Ciclo infinito. Se termina cuando se hace un "return"
    while (1) {
        printf("\nFINAL PROYECT PIA\nWelcome to MOVIE SELECTOR APP\n1. Enter movie\n2. Display the information of the cinema's room\n3. Search movie\n4. List movies for age classification\n5. Exit\nSelect:");
        scanf("%d", &eleccion);
        while (getchar() !=
               '\n'); // <-- Limpiar el búfer de entrada, esto es porque en ocasiones hay errores al usar scanf
        // Si la elección es 5, salimos inmediatamente
        if (eleccion == 5) {
            return 0;
        }
        // Si no, evaluamos la elección
        switch (eleccion) {
            // Caso 1: registrar película
            case 1:
                // Solicitar todos los datos
                printf("Enter name: ");
                // Leer lo que el usuario ha escrito
                fgets(nombre, MAX_CADENA - 1, stdin);
                // Pero remover el salto de línea (Enter) que hay al final
                // (eso de remover y leer se repite varias veces)
                strtok(nombre, "\n");
                printf("Enter the hour:");
                fgets(horaInicio, MAX_CADENA - 1, stdin);
                strtok(horaInicio, "\n");
                printf("Enter the cinema:");
                fgets(cine, MAX_CADENA - 1, stdin);
                strtok(cine, "\n");
                printf("Enter the room:");
                fgets(sala, MAX_CADENA - 1, stdin);
                strtok(sala, "\n");
                printf("Enter the date in format YYYY-MM-DD:");
                fgets(dia, MAX_CADENA - 1, stdin);
                strtok(dia, "\n");
                // Aquí no usamos fgets porque es un solo caracter, no una cadena
                printf("Enter the rating (A, B or C):");
                scanf("%c", &clasificacion);
                // Invocamos a la función agregarOActualizar con los datos definidos
                agregarOActualizar(nombre, horaInicio, cine, sala, dia, clasificacion);
                break;
            case 2:
                // De aquí en adelante son cosas similares
                printf("Enter the hour:");
                fgets(horaInicio, MAX_CADENA - 1, stdin);
                strtok(horaInicio, "\n");
                printf("Enter the cinema:");
                fgets(cine, MAX_CADENA - 1, stdin);
                strtok(cine, "\n");
                printf("Enter the room:");
                fgets(sala, MAX_CADENA - 1, stdin);
                strtok(sala, "\n");
                printf("Enter the room in format YYYY-MM-DD:");
                fgets(dia, MAX_CADENA - 1, stdin);
                strtok(dia, "\n");
                desplegarInformacion(horaInicio, cine, sala, dia);
                break;
            case 3:
                printf("Enter the name:");
                fgets(nombre, MAX_CADENA - 1, stdin);
                strtok(nombre, "\n");
                buscarPeliculaPorNombre(nombre);
                break;
            case 4:
                printf("Enter the date in format YYYY-MM-DD:");
                fgets(dia, MAX_CADENA - 1, stdin);
                strtok(dia, "\n");
                printf("Enter the rating (A, B or C):");
                scanf("%c", &clasificacion);
                buscarPeliculaPorDiaYClasificacion(dia, clasificacion);
                break;
            default:
                printf("Invalid Option");
                break;
        }
    }
}
