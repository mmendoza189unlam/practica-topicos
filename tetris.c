#include "tetris.h"
#include <string.h>

static int piezas[CANT_PIEZAS][CF_MINOS][CC_MINOS] = {
        // O
    {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
    // T
    {{0,1,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
    // S
    {{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
    // Z
    {{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
    // L
    {{1,0,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
    // J
    {{0,0,1,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
    // I
    {{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}}
};

static int colores[CANT_PIEZAS] = {
    COLOR_O, COLOR_T, COLOR_S, COLOR_Z,
    COLOR_L, COLOR_J, COLOR_I
};

void inicializarTablero(Tablero* t)
{
    for(int f = 0; f < CF; f++)
    {
        for(int c = 0; c < CC; c++)
        {
            t->celdas[f][c] = COLOR_VACIO;
        }
    }
}

void inicializarPieza(Tetromino* p, int tipo)
{
    p->tipo  = tipo;
    p->color = colores[tipo];
    p->fila  = 0;
    p->col   = CC / 2 - CF_MINOS / 2; // centro del tablero

    for(int f = 0; f < CF_MINOS; f++)
        for(int c = 0; c < CC_MINOS; c++)
            p->forma[f][c] = piezas[tipo][f][c];
}

int colisiona(Tablero* t, Tetromino* p, int deltaFila, int deltaCol)
{
    for(int f = 0; f < CF_MINOS; f++)
    {
        for(int c = 0; c < CC_MINOS; c++)
        {
            if(p->forma[f][c] == 0)
            {
                continue;
            }

            int nuevaFila = p->fila + f + deltaFila;
            int nuevaCol = p->col + c + deltaCol;

            // chequea bordes
            if(nuevaFila >= CF) return 1;
            if(nuevaCol < 0) return 1;
            if(nuevaCol >= CC) return 1;

            // chequea colision con piezas fijas
            if(nuevaFila >= 0 && t->celdas[nuevaFila][nuevaCol] != COLOR_VACIO)
            {
                return 1;
            }
        }
    }
    return 0;
}

void fijarPieza(Tablero* t, Tetromino* p)
{
    for(int f = 0; f < CF_MINOS; f++)
    {
        for(int c = 0; c < CC_MINOS; c++)
        {
            if(p->forma[f][c] != 0)
                t->celdas[p->fila + f][p->col + c] = p->color;
        }
    }
}

int limpiarFilas(Tablero* t)
{
    int lineas = 0;
    for(int f = CF - 1; f >= 0; f--)
    {
        int completa = 1;
        for(int c = 0; c < CC; c++)
        {
            if(t->celdas[f][c] == COLOR_VACIO)
            {
                completa = 0;
                break;
            }
        }

        if(completa)
        {
            lineas++;
            for(int ff = f; ff > 0; ff--)
            {
                for(int c = 0; c < CC; c++)
                {
                    t->celdas[ff][c] = t->celdas[ff-1][c];
                }
            }

            for(int c = 0; c < CC; c++)
            {
                t->celdas[0][c] = COLOR_VACIO;
            }
            f++;
        }
    }
    return lineas;
}
