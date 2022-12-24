#include "juego.h"

int juego::w = 800, juego::h = 600;
float juego::fps = 60.f;
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
	glLineWidth(3.f);
	glOrtho(800, 0, 600, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void juego::dibujar()
{
	glutSwapBuffers();

}

void juego::procesar_teclado(unsigned char c, int x, int y)
{

}

void juego::actualizar()
{
	glutPostRedisplay();

}



