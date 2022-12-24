#pragma once
#include "GL\glut.h"
class juego
{
public:
	juego();
	static void dibujar();
	static void procesar_teclado(unsigned char c, int x, int y);
	static void actualizar();
	static void iniciar();

private:
	static int  w ,h;
	static float fps;
};
