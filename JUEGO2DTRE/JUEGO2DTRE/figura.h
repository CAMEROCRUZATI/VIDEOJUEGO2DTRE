#pragma once
#include "cuadrado.h"

class figura {
public:
	figura(unsigned short num); //1 ele,2 ele invertida,3 cubo,4 triangulo,5 el palo
	bool actualizar();
	void dibujar();
	void set_x(double x);
	void set_y(double y);
	double get_x(unsigned short num) { return cuadrados[num].get_x(); }
	double get_y(unsigned short num) { return cuadrados[num].get_y(); }
	void rotar();
private:
	cuadrado cuadrados[4];
	unsigned short id;
	unsigned short rotacion;
	double pos_x;
	double pos_y;
};
