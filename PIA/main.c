{
    int eleccion;
    char nombre[MAX_CADENA];
    char horaInicio[MAX_CADENA];
    char cine[MAX_CADENA];
    char sala[MAX_CADENA];
    char dia[MAX_CADENA];
    char clasificacion;
    
    while (1) {
        printf("\n1. Enter movie\n2. Display the information of the cinema's room\n3. Search movie\n4. List movies for age classification\n5. Exit\nSelect:");
        scanf("%d", &eleccion);
        while (getchar() !=
               '\n'); 
        if (eleccion == 5) {
            return 0;
        }
        switch (eleccion) {
            case 1:
                
                printf("Enter name: ");
                
                fgets(nombre, MAX_CADENA - 1, stdin);
                strtok(nombre, "\n");
                printf("Enter movie's hour");
                fgets(horaInicio, MAX_CADENA - 1, stdin);
                strtok(horaInicio, "\n");
                printf("Enter the cinema:");
                fgets(cine, MAX_CADENA - 1, stdin);
                strtok(cine, "\n");
                printf("Enter the cinema's room:");
                fgets(sala, MAX_CADENA - 1, stdin);
                strtok(sala, "\n");
                printf("Enter the date: YYYY-MM-DD:");
                fgets(dia, MAX_CADENA - 1, stdin);
                strtok(dia, "\n");
                printf("Enter the classification (A, B or C):");
                scanf("%c", &clasificacion);
                
                agregarOActualizar(nombre, horaInicio, cine, sala, dia, clasificacion);
                break;
            case 2:
                printf("Enter the movie's hour:");
                fgets(horaInicio, MAX_CADENA - 1, stdin);
                strtok(horaInicio, "\n");
                printf("Enter the cinema:");
                fgets(cine, MAX_CADENA - 1, stdin);
                strtok(cine, "\n");
                printf("Enter the cinema's room:");
                fgets(sala, MAX_CADENA - 1, stdin);
                strtok(sala, "\n");
                printf("Enter the date: YYYY-MM-DD:");
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
                printf("Enter the date: YYYY-MM-DD:");
                fgets(dia, MAX_CADENA - 1, stdin);
                strtok(dia, "\n");
                printf("Enter the classification (A, B or C):");
                scanf("%c", &clasificacion);
                buscarPeliculaPorDiaYClasificacion(dia, clasificacion);
                break;
            default:
                printf("Invalid Option");
                break;
        }
    }
}
