/*Final Project Movie Selector App*/ 

/*This program was made possible thanks to: Comunidad de Programadores: Programas C++ Entradas de cine" 
and MOVIE TICKET BOOKING SYSTEM IN C PROGRAMMING for their helpful videos*/
/* And Tutorialspoint for explaining how the library functions mempcy and struct works*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CADENA 101

struct detalleDePelicula {               /*Part based in Tutorialspoint examples*/
    char nombre[MAX_CADENA];
    char horaInicio[MAX_CADENA];
    char cine[MAX_CADENA];
    char sala[MAX_CADENA];
    char dia[MAX_CADENA];
    char clasificacion;
    struct detalleDePelicula *siguiente;
};
struct detalleDePelicula *superior = NULL;

struct detalleDePelicula *
buscar(char horaInicio[MAX_CADENA], char cine[MAX_CADENA], char sala[MAX_CADENA],
       char dia[MAX_CADENA]) {
    // Vamos a usar este temporal para leer toda la pila
    struct detalleDePelicula *temporal = superior;                       
    
    while (temporal != NULL) {
        if (
                strcmp(cine, temporal->cine) == 0 &&
                strcmp(sala, temporal->sala) == 0 &&
                strcmp(horaInicio, temporal->horaInicio) == 0 &&
                strcmp(dia, temporal->dia) == 0
                ) {
            return temporal;
        }
        temporal = temporal->siguiente;
    }

    return NULL;                              /*Ends*/
}

void
agregarPorPrimeraVez(char nombre[MAX_CADENA], char horaInicio[MAX_CADENA],
                     char cine[MAX_CADENA], char sala[MAX_CADENA],
                     char dia[MAX_CADENA], char clasificacion) {
    struct detalleDePelicula *d = malloc(sizeof(struct detalleDePelicula));
    memcpy(d->nombre, nombre, MAX_CADENA);
    memcpy(d->horaInicio, horaInicio, MAX_CADENA);
    memcpy(d->cine, cine, MAX_CADENA);
    memcpy(d->sala, sala, MAX_CADENA);
    memcpy(d->dia, dia, MAX_CADENA);
    d->clasificacion = clasificacion;
    superior = d;
}


void agregarOActualizar(char nombre[MAX_CADENA], char horaInicio[MAX_CADENA],
                        char cine[MAX_CADENA], char sala[MAX_CADENA],
                        char dia[MAX_CADENA], char clasificacion) {
    struct detalleDePelicula *existente = buscar(horaInicio, cine, sala, dia);
    if (existente == NULL) {
        agregarPorPrimeraVez(nombre, horaInicio, cine, sala, dia, clasificacion);
        printf("\nAdded Movie\n");
    } else {
                                                                
        memcpy(existente->nombre, nombre, MAX_CADENA);              /*Part based in Tutorialspoint examples*/
        memcpy(existente->horaInicio, horaInicio, MAX_CADENA);
        memcpy(existente->cine, cine, MAX_CADENA);
        memcpy(existente->sala, sala, MAX_CADENA);
        memcpy(existente->dia, dia, MAX_CADENA);
        existente->clasificacion = clasificacion;                    /*Ends*/
        printf("\nMovie Already existed, it was replaced\n");
    }
}

void imprimirPelicula(struct detalleDePelicula *detalleDePelicula) {
    printf("Name: %s, Hour: %s, Cinema: %s, Room: %s, Date: %s, Rating: %c\n", detalleDePelicula->nombre,
           detalleDePelicula->horaInicio, detalleDePelicula->cine, detalleDePelicula->sala, detalleDePelicula->dia,
           detalleDePelicula->clasificacion);
}

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

void buscarPeliculaPorDiaYClasificacion(char dia[MAX_CADENA], char clasificacion) {
    printf("\n--Search results by date and rating --\n");
    struct detalleDePelicula *temporal = superior;
    while (temporal != NULL) {
        if (strcmp(dia, temporal->dia) == 0 && temporal->clasificacion == clasificacion) {
            imprimirPelicula(temporal); 
        }
        temporal = temporal->siguiente;
    }
}

int main() {
    int eleccion;
    char nombre[MAX_CADENA];
    char horaInicio[MAX_CADENA];
    char cine[MAX_CADENA];
    char sala[MAX_CADENA];
    char dia[MAX_CADENA];
    char clasificacion;
    while (1) {
        printf("\nFINAL PROYECT PIA\nWelcome to MOVIE SELECTOR APP\n1. Enter movie\n2. Display the information of the cinema's room\n3. Search movie\n4. List movies for age classification\n5. Exit\nSelect:");
        scanf("%d", &eleccion);
        while (getchar() !=
               '\n'); 
        if (eleccion == 5) {
            return 0;
        }
       
        switch (eleccion) {                                            /*Help by MOVIE TICKET BOOKING SYSTEM IN C PROGRAMMING and Comunidad de Programadores: Programas C++ Entradas de cine to create the cases*/
           
            case 1:
                
                printf("Enter name: ");
                
                fgets(nombre, MAX_CADENA - 1, stdin);
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
                printf("Enter the rating (A, B or C):");
                scanf("%c", &clasificacion);
                agregarOActualizar(nombre, horaInicio, cine, sala, dia, clasificacion);
                break;
            case 2:
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
