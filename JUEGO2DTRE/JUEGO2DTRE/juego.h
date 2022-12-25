#pragma once
#include "GL\glut.h"
#include "figura.h"
#include <iostream>
#include <list>
#include <ctime>

using namespace std;
class juego
{
public:
	juego();
	static void dibujar();
	static void procesar_teclado(unsigned char c, int x, int y);
	static void actualizar();
	static void iniciar();
	static void dibujar_tablero();
	static void dibujar_cuadrados();

private:
	static int  w ,h;
	static float fps;
	static figura pieza;
	static list <cuadrado> cuadrados;
};
