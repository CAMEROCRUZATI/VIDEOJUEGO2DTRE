#pragma once
#include "cuadrado.h"
#include <cmath>
#include <iostream>

using namespace std;

class figura {
public:
	figura(unsigned short num); //1 ele,2 ele invertida,3 cubo,4 triangulo,5 el palo
	bool actualizar();
	void dibujar();
	void set_x(double x);
	void set_y(double y);
	double get_x(unsigned short num) { return cuadrados[num].get_x() + pos_x; }
	double get_y(unsigned short num) { return cuadrados[num].get_y() + pos_y; }
	void rotar();
	double get_angulo_cuadradito(unsigned short int);
	float rad2deg(float radianes) { return radianes * 180 / 3.14; }
private:
	cuadrado cuadrados[4];
	unsigned short id;
	unsigned short rotacion;
	double pos_x;
	double pos_y;
};
