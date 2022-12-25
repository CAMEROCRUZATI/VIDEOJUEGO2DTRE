#include "figura.h"

figura::figura(unsigned short num)
{
	id = num;
	rotacion = 1;
	pos_x = 15;
	pos_y = 345;
	switch (id)
	{
	case 1:
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(-30);
		cuadrados[3].set_x(-30);
		cuadrados[3].set_y(30); 
		break;
	case 2:
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(-30);
		cuadrados[3].set_x(30);
		cuadrados[3].set_y(30);
		break;
	case 3:
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(-30);
		cuadrados[3].set_x(0);
		cuadrados[3].set_y(30);
		break;
	case 4:
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(30);
		cuadrados[2].set_y(30);
		cuadrados[3].set_x(0);
		cuadrados[3].set_y(30);
		break;
	case 5:
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(-30);
		cuadrados[3].set_x(-60);
		break;
	case 6:
		cuadrados[1].set_x(-30);
		cuadrados[2].set_y(30);
		cuadrados[3].set_x(30);
		cuadrados[3].set_y(30);
		break;
	}

}
bool figura::actualizar()
{
	bool colisiono = false;

	for (int i = 0; i < 4; i++)
	{
		if ((int)calcular_posicion_y(i) > -280)
		{
			
		}
		else
		{
			colisiono = true;
		}
	}
	if (!colisiono)
	{
		pos_y -= 30;
	}
	

	return colisiono;
}
 
void figura::dibujar()
{

	//cuadrados[0] mantine su pocision

	switch (id)
	{
	case 1:
		glColor3f(1, 1, 0);
		break;
	case 2:
		glColor3f(1, 1, 0);
		break;
	case 3:
		glColor3f(1, 0, 1);
		break;
	case 4:
		glColor3f(0, 0, 1);
		break;
	case 5:
		glColor3f(1, 0, 0);
		break;
	case 6:
		glColor3f(0, 1, 0);
		break;
	}

	

	glPushMatrix();
	glTranslatef(pos_x, pos_y, 0);
	for (int i = 0; i < 4; i++)
	{
		cuadrados[i].dibujar();
	}
	glPopMatrix();
}

void figura::set_x(double x)
{
	bool hay_colision = false;
	if (x > 0)
	{
		for (int i = 0; i < 4; i++)
		{
			if (abs((int)calcular_posicion_x(i) - 130) < 15)
			{
				hay_colision = true;
			}
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (abs((int)calcular_posicion_x(i) + 130) < 15)
			{
				hay_colision = true;

			}
		}

	}

	if (!hay_colision)
	{
		pos_x += x;
	}
	

}

void figura::set_y(double y)
{
	
	if (pos_y > -285)
	{
		pos_y += y;
	}
}

void figura::rotar()
{
	rotacion++;
	if (rotacion > 4) rotacion = 1;

	for (int i = 0; i < 4; i++)
	{
		cuadrados[i].set_rotacion(rotacion);
	}
}

double figura::get_angulo_cuadradito(unsigned short  int num)
{
	double angulo_cuadrado = atan2f(cuadrados[num].get_y(), cuadrados[num].get_x());


	double rotacion_local = (rotacion - 1) * 90;


	return (angulo_cuadrado) + deg2rad(rotacion_local);

}

double figura::calcular_posicion_x(unsigned short num)
{
	double hipotenusa;

	hipotenusa = sqrt(pow((cuadrados[num].get_x()), 2) + pow((cuadrados[num].get_y()), 2));

	
	return cos(get_angulo_cuadradito(num)) * hipotenusa + pos_x;
}

double figura::calcular_posicion_y(unsigned short num)
{
	double hipotenusa;

	hipotenusa = sqrt(pow((cuadrados[num].get_x()), 2) + pow((cuadrados[num].get_y()), 2));


	return sin(get_angulo_cuadradito(num)) * hipotenusa + pos_y;
}

