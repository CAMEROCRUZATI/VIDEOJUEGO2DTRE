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
	
	for (int i = 0; i < 4; i++)
	{
		cuadrados[i].dibujar();
	}
}
