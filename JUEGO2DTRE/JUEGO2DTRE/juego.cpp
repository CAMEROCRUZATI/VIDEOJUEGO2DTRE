#include "juego.h"

int juego::w = 800, juego::h = 600;
float juego::fps = 60.f;
float juego::tiempo_actualizar = 1000.f;
figura juego::pieza(rand()%6+1);
list<cuadrado> juego::cuadrados;
juego::juego()
{
	srand(time(NULL));

	pieza = figura(rand() % 6 + 1);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowPosition(50, 50);

	glutInitWindowSize(w, h);


	glutCreateWindow("tetris extremos Super Mega");
	glutDisplayFunc(dibujar);
	glutKeyboardFunc(procesar_teclado);
	glutIdleFunc(actualizar);
	iniciar();
}

void juego::iniciar()
{
	glClearColor(0.5, 0, 0.5, 1);
	glMatrixMode(GL_PROJECTION); glLoadIdentity();
	glOrtho(0, w, 0, h, -1, 1);
	glMatrixMode(GL_MODELVIEW);glLoadIdentity();
}
void juego::dibujar()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPushMatrix();

	glTranslatef(400, 300, 0);

	dibujar_tablero();

	pieza.dibujar();
	dibujar_cuadrados();
	
	glPopMatrix();

	glutSwapBuffers();

}

void juego::procesar_teclado(unsigned char c, int x, int y)
{
	switch (c)
	{
	default:
	case 'A': case 'a':
	pieza.set_x(-30);
	break;

	case 'D': case 'd':
	pieza.set_x(30);
	break;

	case 'S': case 's':
		tiempo_actualizar = 50;
	break;

	case ' ':
	pieza.rotar();
	for (int i = 0; i < 4; i++)
	{
		 pieza.calcular_posicion_x(1) ;
	}
	
	break;


	}

}

void juego::actualizar()
{
	static float tiempo_transcurrido = 0;

	static float actualizar_cuadrado = 0;

	

	if (glutGet(GLUT_ELAPSED_TIME) >  tiempo_transcurrido + 1.f/fps)
	{

		if (glutGet(GLUT_ELAPSED_TIME) > actualizar_cuadrado + tiempo_actualizar)
		{
			chequear_colicion();
			actualizar_cuadrado = glutGet(GLUT_ELAPSED_TIME);
			if (pieza.actualizar())
			{
				for (int i = 0; i < 4; i++)
				{
					cuadrados.push_back(cuadrado(pieza.calcular_posicion_x(i), pieza.calcular_posicion_y(i)));
				}
				pieza = figura(rand()%6+1);
				
			}
		}
		tiempo_transcurrido = glutGet(GLUT_ELAPSED_TIME);
		tiempo_actualizar = 1000;
		glutPostRedisplay();
	}
	

}

void juego::dibujar_tablero()
{
	glPushMatrix();

	glTranslatef(-150, 300, 0);

	glColor3f(0, 0, 0);

	glBegin(GL_QUAD_STRIP);

	glVertex2f(0, 0);

	glVertex2f(300, 0);

	glVertex2f(0, -600);

	glVertex2f(300, -600);

	glEnd();

	glPopMatrix();

}
void juego::dibujar_cuadrados()
{
	glColor3f(1, 1, 1);
	list<cuadrado>::iterator p = cuadrados.begin();
	while (p != cuadrados.end())
	{
		p->dibujar();
		p++;
	}
}

void juego::chequear_colicion()
{
	list<cuadrado>::iterator p = cuadrados.begin();
	while (p != cuadrados.end())
	{
		bool hubo_colision = false;
		for (int i = 0; i < 4; i++)
		{
			if (abs(p->get_y() - ((int)pieza.calcular_posicion_y(i)-30)) < 15)
			{
				if (abs(p->get_x() - (int)pieza.calcular_posicion_x(i)) < 5)
				{
					hubo_colision = true;

				}
			}
		}
		if (hubo_colision)
		{
			for (int i = 0; i < 4; i++)
			{
				cuadrados.push_back(cuadrado(pieza.calcular_posicion_x(i), pieza.calcular_posicion_y(i)));
			}
			chequear_linias();
			pieza = figura(rand() % 6 + 1);

		}
		p++;
	}
}

void juego::chequear_linias()
{
	for (int i = 0; i < 4; i++)
	{
		int contar_cuadraditos = 0;
	    list<cuadrado>::iterator p = cuadrados.begin();
		while (p != cuadrados.end())
		{
			if (abs((int)pieza.calcular_posicion_y(i) - p->get_y()) < 15)
			{
				contar_cuadraditos++;
			}
			p++;
		}
		if (contar_cuadraditos == 10)
		{
			p = cuadrados.begin();
			while (p != cuadrados.end())
			{
				if (abs((int)pieza.calcular_posicion_y(i) - p->get_y()) < 15)
				{
					p = cuadrados.erase(p);
					system("PAUSE");
				}
				else
				{
					if (p->get_y() > ((int)pieza.calcular_posicion_y(i)))
					{
						p->set_y(-30);
					}
					p++;
				}
				
			}
		}
	}

}

