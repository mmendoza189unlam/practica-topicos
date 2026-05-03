#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "GBT/gbt.h"
#include "tetris.h"
#include "presentacion.h"

#define ANCHO_VENTANA  320
#define ALTO_VENTANA   200
#define ESCALA_VENTANA 3
#define TAM_CELDA      8
#define OFFSET_X       16
#define OFFSET_Y       4
#define CANT_COLORES   16

tGBT_ColorRGB paletaCGA[CANT_COLORES] = {
    {0x00, 0x00, 0x00}, // 0:  Negro
    {0x00, 0x00, 0xAA}, // 1:  Azul
    {0x00, 0xAA, 0x00}, // 2:  Verde
    {0x00, 0xAA, 0xAA}, // 3:  Cian
    {0xAA, 0x00, 0x00}, // 4:  Rojo
    {0xAA, 0x00, 0xAA}, // 5:  Magenta
    {0xAA, 0x55, 0x00}, // 6:  Marron
    {0xAA, 0xAA, 0xAA}, // 7:  Gris claro
    {0x55, 0x55, 0x55}, // 8:  Gris oscuro
    {0x55, 0x55, 0xFF}, // 9:  Azul brillante
    {0x55, 0xFF, 0x55}, // 10: Verde brillante
    {0x55, 0xFF, 0xFF}, // 11: Cian brillante
    {0xFF, 0x55, 0x55}, // 12: Rojo brillante
    {0xFF, 0x55, 0xFF}, // 13: Magenta brillante
    {0xFF, 0xFF, 0x55}, // 14: Amarillo
    {0xFF, 0xFF, 0xFF}  // 15: Blanco/Transparente
};

void dibujarTablero(Tablero* t);
void dibujarPieza(Tetromino* p);
void dibujarCelda(int fila, int col, int color);

int main(int argc, char* argv[])
{
    srand(time(0));

    // Iniciar GBT
    if(gbt_iniciar() != 0) {
        fprintf(stderr, "Error GBT: %s\n", gbt_obtener_log());
        return -1;
    }
    if(gbt_crear_ventana("TETRIS PIXEL", ANCHO_VENTANA, ALTO_VENTANA, ESCALA_VENTANA) != 0) {
        fprintf(stderr, "Error ventana: %s\n", gbt_obtener_log());
        return -1;
    }
    if(gbt_aplicar_paleta(paletaCGA, CANT_COLORES, GBT_FORMATO_888) != 0) {
        fprintf(stderr, "Error paleta: %s\n", gbt_obtener_log());
        return -1;
    }

    // Temporizador de caída
    tGBT_Temporizador* timer = gbt_temporizador_crear(1.0);

    // Estado del juego
    Tablero tablero;
    Tetromino pieza;
    inicializarTablero(&tablero);
    inicializarPieza(&pieza, rand() % CANT_PIEZAS);

    // Pantalla de presentación
    uint8_t enPresentacion = 1;
    while(enPresentacion)
    {
        mostrarPresentacion();
        gbt_procesar_entrada();
        eGBT_Tecla tecla = gbt_obtener_tecla_presionada();
        if(tecla == GBTK_ENTER || tecla == GBTK_ESPACIO || tecla == GBTK_ESCAPE)
        {
            enPresentacion = 0;
        }
        gbt_esperar(16);
    }
    gbt_borrar_backbuffer(0);

    uint8_t corriendo = 1;

    while(corriendo)
    {
        gbt_procesar_entrada();
        eGBT_Tecla tecla = gbt_obtener_tecla_presionada();

        // Controles
        if(tecla == GBTK_ESCAPE) {
            corriendo = 0;
        } else if(tecla == GBTK_IZQUIERDA) {
            if(!colisiona(&tablero, &pieza, 0, -1))
                pieza.col--;
        } else if(tecla == GBTK_DERECHA) {
            if(!colisiona(&tablero, &pieza, 0, 1))
                pieza.col++;
        } else if(tecla == GBTK_ABAJO) {
            if(!colisiona(&tablero, &pieza, 1, 0))
                pieza.fila++;
        }

        // Caída automática
        if(gbt_temporizador_consumir(timer))
        {
            if(!colisiona(&tablero, &pieza, 1, 0))
            {
                pieza.fila++;
            }
            else
            {
                fijarPieza(&tablero, &pieza);
                limpiarFilas(&tablero);
                inicializarPieza(&pieza, rand() % CANT_PIEZAS);
            }
        }

        // Dibujar
        gbt_borrar_backbuffer(0);
        dibujarTablero(&tablero);
        dibujarPieza(&pieza);
        gbt_volcar_backbuffer();
        gbt_esperar(16);
    }

    gbt_temporizador_destruir(timer);
    gbt_destruir_ventana();
    gbt_cerrar();
    return 0;
}

void dibujarCelda(int fila, int col, int color)
{
    int x = OFFSET_X + col * TAM_CELDA;
    int y = OFFSET_Y + fila * TAM_CELDA;
    for(int py = 0; py < TAM_CELDA - 1; py++)
        for(int px = 0; px < TAM_CELDA - 1; px++)
            gbt_dibujar_pixel(x + px, y + py, color);
}

void dibujarTablero(Tablero* t)
{
    for(int f = 0; f < CF; f++)
        for(int c = 0; c < CC; c++)
            if(t->celdas[f][c] != COLOR_VACIO)
                dibujarCelda(f, c, t->celdas[f][c]);
}

void dibujarPieza(Tetromino* p)
{
    for(int f = 0; f < CF_MINOS; f++)
        for(int c = 0; c < CC_MINOS; c++)
            if(p->forma[f][c] != 0)
                dibujarCelda(p->fila + f, p->col + c, p->color);
}
