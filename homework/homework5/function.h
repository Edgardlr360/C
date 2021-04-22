/*COPY AND PASTE THIS CODE IN ONLINE GDB IN 3 FILES AND RENAME EACH FILE AS:
THE FIRST ONE: main.c 
THE SECOND: function.c 
The THIRD: function.h (THIS IS THE THIRD ONE)*/ 
#define COLUMNS 10
#define ROWS 10

int obtenerMinasCercanas(int fila, int columna, char tablero[ROWS][COLUMNS]);
int aleatorioEnRango(int minimo, int maximo);
void iniciarTablero(char tablero[ROWS][COLUMNS]);
void colocarMina(int fila, int columna, char tablero[ROWS][COLUMNS]);
void colocarMinasAleatoriamente(char tablero[ROWS][COLUMNS]);
void imprimirEncabezado();
char enteroACaracter(int numero);
void imprimirTablero(char tablero[ROWS][COLUMNS], int deberiaMostrarMinas);
int abrirCasilla(char filaLetra, int columna, char tablero[ROWS][COLUMNS]);
int noHayCasillasSinAbrir(char tablero[ROWS][COLUMNS]);
