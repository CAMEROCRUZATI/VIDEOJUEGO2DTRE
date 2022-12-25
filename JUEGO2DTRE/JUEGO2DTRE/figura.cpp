#include "figura.h"

figura::figura(unsigned short num)
{
	id = num;

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
	}

}
void figura::actualizar()
{
	for (int i = 0; i < 4; i++)
	{
		cuadrados[i].actualizar();
	}
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
	}
	
	for (int i = 0; i < 4; i++)
	{
		cuadrados[i].dibujar();
	}
}
