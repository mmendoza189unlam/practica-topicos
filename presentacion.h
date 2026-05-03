#ifndef PRESENTACION_#ifndef PRESENTACION_H_INCLUDED
#define PRESENTACION_H_INCLUDED

#include <stdint.h>

// Colores (indices paleta CGA)
#define N  15  // Transparente
#define VE  2  // Verde
#define BL  7  // Gris claro (blanco CGA)
#define AM 14  // Amarillo
#define CI 11  // Cian brillante
#define MA 13  // Magenta brillante

// Tamaño de cada sprite
#define TAM_SPRITE 16

// Logo UNLaM 16x16
extern const uint8_t logo_unlam[TAM_SPRITE][TAM_SPRITE];

// Letras 8x8
extern const uint8_t letra_U[8][8];
extern const uint8_t letra_N[8][8];
extern const uint8_t letra_L[8][8];
extern const uint8_t letra_A[8][8];
extern const uint8_t letra_M[8][8];
extern const uint8_t letra_T[8][8];
extern const uint8_t letra_E[8][8];
extern const uint8_t letra_R[8][8];
extern const uint8_t letra_I[8][8];
extern const uint8_t letra_S[8][8];
extern const uint8_t letra_P[8][8];

// Funciones
void mostrarPresentacion(void);
void dibujarSprite(const uint8_t sprite[][TAM_SPRITE], int x, int y, int tam);
void dibujarLetra(const uint8_t letra[][8], int x, int y, int color);

#endif // PRESENTACION_H_INCLUDED
