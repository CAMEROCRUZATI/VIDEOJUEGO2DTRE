#include "juego.h"

int juego::w = 800, juego::h = 600;
float juego::fps = 60.f;
cuadrado juego::obj1;
juego::juego()
{
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
	glClearColor(0, 0, 1, 1);
	glMatrixMode(GL_PROJECTION); glLoadIdentity();
	glOrtho(0, w, 0, h, -1, 1);
	glMatrixMode(GL_MODELVIEW);glLoadIdentity();
}
void juego::dibujar()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//cout << "Funciona" << endl;
	glPushMatrix();

	glTranslatef(400, 300, 0);
	dibujar_tablero();

	obj1.dibujar();
	
	glPopMatrix();
	glutSwapBuffers();

}

void juego::procesar_teclado(unsigned char c, int x, int y)
{


}

void juego::actualizar()
{
	static float tiempo_transcurrido = 0;

	static float actualizar_cuadrado = 0;
	if (glutGet(GLUT_ELAPSED_TIME) >  tiempo_transcurrido + 1.f/fps)
	{

		if (glutGet(GLUT_ELAPSED_TIME) > actualizar_cuadrado + 1000.f)
		{
			actualizar_cuadrado = glutGet(GLUT_ELAPSED_TIME);
			obj1.actualizar();
		}
		tiempo_transcurrido = glutGet(GLUT_ELAPSED_TIME);
		glutPostRedisplay();
	}
	

}

void juego::dibujar_tablero()
{
	glPushMatrix();

	glTranslatef(-150, 300, 0);

	glColor3f(1, 1, 1);

	glBegin(GL_QUAD_STRIP);

	glVertex2f(0, 0);

	glVertex2f(300, 0);

	glVertex2f(0, -600);

	glVertex2f(300, -600);

	glEnd();

	glPopMatrix();

}



