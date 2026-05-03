#ifndef TETRIS_H_INCLUDED
#define TETRIS_H_INCLUDED

#include <stdint.h>

#define CF 20
#define CC 10
#define CF_MINOS 4
#define CC_MINOS 4
#define CANT_PIEZAS 7

#define TODO_OK 0
#define SIN_MEM 1

// Colores de cada pieza
#define COLOR_O 14
#define COLOR_T 5
#define COLOR_S 10
#define COLOR_Z 12
#define COLOR_L 6
#define COLOR_J 9
#define COLOR_I 11
#define COLOR_VACIO 0

typedef struct
{
    int forma[CF_MINOS][CC_MINOS];
    int fila;
    int col;
    int tipo;
    int color;
} Tetromino;
typedef struct
{
    int celdas[CF][CC];
} Tablero;

//prototipos
void inicializarTablero(Tablero* t);
void inicializarPieza(Tetromino* p, int tipo);
int colisiona(Tablero* t, Tetromino* p, int deltaFila, int deltaCol);
void fijarPieza(Tablero* t, Tetromino* p);
int limpiarFilas(Tablero* t);
#endif // TETRIS_H_INCLUDED
