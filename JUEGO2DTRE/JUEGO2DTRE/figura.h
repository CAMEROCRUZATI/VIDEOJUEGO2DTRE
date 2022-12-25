#pragma once
#include "cuadrado.h"

class figura {
public:
	figura(unsigned short num); //1 ele,2 ele invertida,3 cubo,4 triangulo,5 el palo
	void actualizar();
	void dibujar();
	void set_x(double x);
	void set_y(double y);
	void rotar();
private:
	cuadrado cuadrados[4];
	unsigned short id;
	unsigned short rotacion;
};
