#pragma once
#include "GL\glut.h"
class cuadrado
{
public:
	cuadrado();
	void dibujar();
	void set_x(double x) { pos_x += x; }
	void set_y(double y) { pos_y += y; }
	void set_rotacion(unsigned short num);
	void actualizar();

	double get_x() { return pos_x; }
	double get_y() { return pos_y; }
private:
	double pos_x;
	double pos_y;
	unsigned short rotacion;
};