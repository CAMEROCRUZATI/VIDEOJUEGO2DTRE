#include "cuadrado.h"



cuadrado::cuadrado()
{
	pos_y = 0;
	pos_x = 0;
}

void cuadrado::dibujar()
{
	

	glPushMatrix();
	switch (rotacion)
	{
	case 2:
	glRotatef(90, 0, 0, 1);
	break;
	case 3:
	glRotatef(180, 0, 0, 1);
	break;
	case 4:
	glRotatef(270, 0, 0, 1);
	break;

	}

	glTranslatef(pos_x, pos_y, 0);

	glBegin(GL_QUAD_STRIP);

	glVertex2f(-15, -15);

	glVertex2f(15, -15);

	glVertex2f(-15, 15);

	glVertex2f(15, 15);

	glEnd();

	glPopMatrix();
}

void cuadrado::actualizar()
{
	
}

void cuadrado::set_rotacion(unsigned short num)
{
	rotacion = num;
}
