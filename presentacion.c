#include "presentacion.h"
#include "GBT/gbt.h"

// Logo UNLaM 16x16 (verde y blanco)
const uint8_t logo_unlam[TAM_SPRITE][TAM_SPRITE] = {
    {N, N, N, VE, VE, VE, VE, VE, VE, VE, VE, N,  N,  N,  N, N},
    {N, N, VE, VE, VE, VE, VE, VE, VE, VE, VE, VE, N,  N,  N, N},
    {N, VE, VE, VE, BL, BL, VE, VE, VE, BL, BL, VE, VE, N,  N, N},
    {VE, VE, VE, BL, BL, BL, VE, VE, VE, BL, BL, BL, VE, VE, N, N},
    {VE, VE, BL, BL, VE, VE, VE, VE, VE, VE, VE, BL, BL, VE, N, N},
    {VE, VE, VE, VE, VE, VE, BL, BL, BL, VE, VE, VE, VE, VE, N, N},
    {N, VE, VE, VE, VE, BL, BL, BL, BL, BL, VE, VE, VE, N,  N, N},
    {N, VE, VE, VE, VE, BL, BL, BL, BL, BL, VE, VE, VE, N,  N, N},
    {N, VE, VE, VE, VE, BL, BL, BL, BL, BL, VE, VE, VE, N,  N, N},
    {VE, VE, VE, VE, VE, VE, BL, BL, BL, VE, VE, VE, VE, VE, N, N},
    {VE, VE, BL, BL, VE, VE, VE, VE, VE, VE, VE, BL, BL, VE, N, N},
    {VE, VE, VE, BL, BL, BL, VE, VE, VE, BL, BL, BL, VE, VE, N, N},
    {N, VE, VE, VE, BL, BL, VE, VE, VE, BL, BL, VE, VE, N,  N, N},
    {N, N, VE, VE, VE, VE, VE, VE, VE, VE, VE, VE, N,  N,  N, N},
    {N, N, N, VE, VE, VE, VE, VE, VE, VE, VE, N,  N,  N,  N, N},
    {N, N, N, N,  N,  N,  N,  N,  N,  N,  N,  N,  N,  N,  N, N}
};

// Letra U
const uint8_t letra_U[8][8] = {
    {CI, N,  N,  N,  N,  N,  CI, N},
    {CI, N,  N,  N,  N,  N,  CI, N},
    {CI, N,  N,  N,  N,  N,  CI, N},
    {CI, N,  N,  N,  N,  N,  CI, N},
    {CI, N,  N,  N,  N,  N,  CI, N},
    {CI, N,  N,  N,  N,  N,  CI, N},
    {N,  CI, CI, CI, CI, CI, N,  N},
    {N,  N,  N,  N,  N,  N,  N,  N}
};

// Letra N
const uint8_t letra_N[8][8] = {
    {CI, N,  N,  N,  N,  N,  CI, N},
    {CI, CI, N,  N,  N,  N,  CI, N},
    {CI, N,  CI, N,  N,  N,  CI, N},
    {CI, N,  N,  CI, N,  N,  CI, N},
    {CI, N,  N,  N,  CI, N,  CI, N},
    {CI, N,  N,  N,  N,  CI, CI, N},
    {CI, N,  N,  N,  N,  N,  CI, N},
    {N,  N,  N,  N,  N,  N,  N,  N}
};

// Letra L
const uint8_t letra_L[8][8] = {
    {CI, N,  N,  N,  N,  N,  N,  N},
    {CI, N,  N,  N,  N,  N,  N,  N},
    {CI, N,  N,  N,  N,  N,  N,  N},
    {CI, N,  N,  N,  N,  N,  N,  N},
    {CI, N,  N,  N,  N,  N,  N,  N},
    {CI, N,  N,  N,  N,  N,  N,  N},
    {CI, CI, CI, CI, CI, CI, N,  N},
    {N,  N,  N,  N,  N,  N,  N,  N}
};

// Letra A
const uint8_t letra_A[8][8] = {
    {N,  N,  CI, CI, CI, N,  N,  N},
    {N,  CI, N,  N,  N,  CI, N,  N},
    {CI, N,  N,  N,  N,  N,  CI, N},
    {CI, N,  N,  N,  N,  N,  CI, N},
    {CI, CI, CI, CI, CI, CI, CI, N},
    {CI, N,  N,  N,  N,  N,  CI, N},
    {CI, N,  N,  N,  N,  N,  CI, N},
    {N,  N,  N,  N,  N,  N,  N,  N}
};

// Letra M
const uint8_t letra_M[8][8] = {
    {CI, N,  N,  N,  N,  N,  CI, N},
    {CI, CI, N,  N,  N,  CI, CI, N},
    {CI, N,  CI, N,  CI, N,  CI, N},
    {CI, N,  N,  CI, N,  N,  CI, N},
    {CI, N,  N,  N,  N,  N,  CI, N},
    {CI, N,  N,  N,  N,  N,  CI, N},
    {CI, N,  N,  N,  N,  N,  CI, N},
    {N,  N,  N,  N,  N,  N,  N,  N}
};

// Letra T
const uint8_t letra_T[8][8] = {
    {CI, CI, CI, CI, CI, CI, CI, N},
    {N,  N,  N,  CI, N,  N,  N,  N},
    {N,  N,  N,  CI, N,  N,  N,  N},
    {N,  N,  N,  CI, N,  N,  N,  N},
    {N,  N,  N,  CI, N,  N,  N,  N},
    {N,  N,  N,  CI, N,  N,  N,  N},
    {N,  N,  N,  CI, N,  N,  N,  N},
    {N,  N,  N,  N,  N,  N,  N,  N}
};

// Letra E
const uint8_t letra_E[8][8] = {
    {CI, CI, CI, CI, CI, CI, N,  N},
    {CI, N,  N,  N,  N,  N,  N,  N},
    {CI, N,  N,  N,  N,  N,  N,  N},
    {CI, CI, CI, CI, CI, N,  N,  N},
    {CI, N,  N,  N,  N,  N,  N,  N},
    {CI, N,  N,  N,  N,  N,  N,  N},
    {CI, CI, CI, CI, CI, CI, N,  N},
    {N,  N,  N,  N,  N,  N,  N,  N}
};

// Letra R
const uint8_t letra_R[8][8] = {
    {CI, CI, CI, CI, CI, N,  N,  N},
    {CI, N,  N,  N,  N,  CI, N,  N},
    {CI, N,  N,  N,  N,  CI, N,  N},
    {CI, CI, CI, CI, CI, N,  N,  N},
    {CI, N,  CI, N,  N,  N,  N,  N},
    {CI, N,  N,  CI, N,  N,  N,  N},
    {CI, N,  N,  N,  CI, N,  N,  N},
    {N,  N,  N,  N,  N,  N,  N,  N}
};

// Letra I
const uint8_t letra_I[8][8] = {
    {N,  CI, CI, CI, CI, CI, N,  N},
    {N,  N,  N,  CI, N,  N,  N,  N},
    {N,  N,  N,  CI, N,  N,  N,  N},
    {N,  N,  N,  CI, N,  N,  N,  N},
    {N,  N,  N,  CI, N,  N,  N,  N},
    {N,  N,  N,  CI, N,  N,  N,  N},
    {N,  CI, CI, CI, CI, CI, N,  N},
    {N,  N,  N,  N,  N,  N,  N,  N}
};

// Letra S
const uint8_t letra_S[8][8] = {
    {N,  CI, CI, CI, CI, CI, N,  N},
    {CI, N,  N,  N,  N,  N,  N,  N},
    {CI, N,  N,  N,  N,  N,  N,  N},
    {N,  CI, CI, CI, CI, N,  N,  N},
    {N,  N,  N,  N,  N,  CI, N,  N},
    {N,  N,  N,  N,  N,  CI, N,  N},
    {N,  CI, CI, CI, CI, N,  N,  N},
    {N,  N,  N,  N,  N,  N,  N,  N}
};

// Letra P
const uint8_t letra_P[8][8] = {
    {CI, CI, CI, CI, CI, N,  N,  N},
    {CI, N,  N,  N,  N,  CI, N,  N},
    {CI, N,  N,  N,  N,  CI, N,  N},
    {CI, CI, CI, CI, CI, N,  N,  N},
    {CI, N,  N,  N,  N,  N,  N,  N},
    {CI, N,  N,  N,  N,  N,  N,  N},
    {CI, N,  N,  N,  N,  N,  N,  N},
    {N,  N,  N,  N,  N,  N,  N,  N}
};


void dibujarSprite(const uint8_t sprite[][TAM_SPRITE], int x, int y, int tam)
{
    for(int f = 0; f < tam; f++)
        for(int c = 0; c < tam; c++)
            if(sprite[f][c] != N)
                gbt_dibujar_pixel(x + c, y + f, sprite[f][c]);
}

void dibujarLetra(const uint8_t letra[][8], int x, int y, int color)
{
    for(int f = 0; f < 8; f++)
        for(int c = 0; c < 8; c++)
            if(letra[f][c] != N)
                gbt_dibujar_pixel(x + c, y + f, color);
}

void mostrarPresentacion(void)
{
    // Fondo negro
    gbt_borrar_backbuffer(0);

    // Logo UNLaM centrado arriba (x=152, y=20)
    dibujarSprite(logo_unlam, 152, 20, TAM_SPRITE);

    // "UNLAM" en cian debajo del logo
    int xUnlam = 120;
    int yUnlam = 45;
    dibujarLetra(letra_U, xUnlam,      yUnlam, CI);
    dibujarLetra(letra_N, xUnlam + 9,  yUnlam, CI);
    dibujarLetra(letra_L, xUnlam + 18, yUnlam, CI);
    dibujarLetra(letra_A, xUnlam + 27, yUnlam, CI);
    dibujarLetra(letra_M, xUnlam + 36, yUnlam, CI);

    // "TETRIS" en amarillo en el centro
    int xTetris = 113;
    int yTetris = 80;
    dibujarLetra(letra_T, xTetris,      yTetris, AM);
    dibujarLetra(letra_E, xTetris + 9,  yTetris, AM);
    dibujarLetra(letra_T, xTetris + 18, yTetris, AM);
    dibujarLetra(letra_R, xTetris + 27, yTetris, AM);
    dibujarLetra(letra_I, xTetris + 36, yTetris, AM);
    dibujarLetra(letra_S, xTetris + 45, yTetris, AM);

    // "PRESS START" en magenta abajo
    int xPress = 100;
    int yPress = 150;
    dibujarLetra(letra_P, xPress,      yPress, MA);
    dibujarLetra(letra_R, xPress + 9,  yPress, MA);
    dibujarLetra(letra_E, xPress + 18, yPress, MA);
    dibujarLetra(letra_S, xPress + 27, yPress, MA);
    dibujarLetra(letra_S, xPress + 36, yPress, MA);

    int xStart = 100;
    int yStart = 162;
    dibujarLetra(letra_S, xStart,      yStart, MA);
    dibujarLetra(letra_T, xStart + 9,  yStart, MA);
    dibujarLetra(letra_A, xStart + 18, yStart, MA);
    dibujarLetra(letra_R, xStart + 27, yStart, MA);
    dibujarLetra(letra_T, xStart + 36, yStart, MA);

    gbt_volcar_backbuffer();
}
