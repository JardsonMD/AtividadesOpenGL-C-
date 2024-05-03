#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

float x= 0.5, y=0.5, z=0.5, a=0, b=0;
GLfloat win = 10;


// Fun��o respons�vel por inicializar par�metros e vari�veis
void Inicializa(){
	// Define a janela de visualiza��o 2D
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-10.0,10.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
}

void Cristal(){
	glBegin(GL_POLYGON);
		glColor3f(0, 0, 0);
		glVertex3f(0.0, 0.0, 0.0);
		glColor3f(x, a, b);
		glVertex3f(-0.5, 1.0, 0.0);
		glColor3f(a, y, b);
		glVertex3f(0.0, 2.0, 0.0);
		glColor3f(a, b, z);
		glVertex3f(0.5, 1.0, 0);
	glEnd();
	glColor3f(0,0,0);
	glLineWidth(2);
	glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(-0.5, 1.0, 0.0);
		glVertex3f(0.0, 2.0, 0.0);
		glVertex3f(0.5, 1.0, 0);
	
	glEnd();
}
void CristalDeLado(){
	glBegin(GL_POLYGON);
		glColor3f(0, 0, 0);
		glVertex3f(0.0, 0.0, 0.0);
		glColor3f(x, b, a);
		glVertex3f(0.5, 1.0, 0.0);
		glColor3f(b, y, a);
		glVertex3f(2.0, 1.0, 0.0);
		glColor3f(b, a, z);
		glVertex3f(1.5, 0.0, 0);
	glEnd();
	glColor3f(0,0,0);
	glLineWidth(2);
	glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.5, 1.0, 0.0);
		glVertex3f(2.0, 1.0, 0.0);
		glVertex3f(1.5, 0.0, 0);
	glEnd();
	
}
void DesenhaIlusao(){   
    glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
    //glColor3f(0,0,0);
    glPushMatrix();
    glScalef(1, 1.25, 1);
	    Cristal();
	    glPushMatrix();
	    glTranslatef(0.0, -2.0, 0.0);
	    Cristal();
	    glPopMatrix();
	    glPushMatrix();
	    glTranslatef(2.0, -1.0,0.0);
	    Cristal();
	    glPopMatrix();
	    glPushMatrix();
	    	glTranslatef(-2.0, -1.0, 0);
	    	Cristal();
	    glPopMatrix();
	    glPushMatrix();
	    	CristalDeLado();
	    glPopMatrix();
	    
	    glPushMatrix();
	    	glTranslatef(0, -2.0, 0);
	    	CristalDeLado();
	    glPopMatrix();
	    
	    glPushMatrix();
	    	glTranslatef(-2.0, -1.0, 0);
	    	CristalDeLado();
	    glPopMatrix();
	    
	    glPushMatrix();
	    	glTranslatef(-2.0, 1.0, 0);
	    	CristalDeLado();
	    glPopMatrix();
	    
	    glPushMatrix();
		    glRotatef(180, 0, 1, 0);
		    
		    glPushMatrix();
	    	CristalDeLado();
		    glPopMatrix();
		    
		    glPushMatrix();
		    	glTranslatef(0, -2.0, 0);
		    	CristalDeLado();
		    glPopMatrix();
		    
		    glPushMatrix();
		    	glTranslatef(-2.0, -1.0, 0);
		    	CristalDeLado();
		    glPopMatrix();
		    
		    glPushMatrix();
		    	glTranslatef(-2.0, 1.0, 0);
		    	CristalDeLado();
		    glPopMatrix();
	    glPopMatrix();
	glPopMatrix();
    
	glFlush();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h){
	GLsizei largura, altura;
                   
	// Evita a divisao por zero
	if(h == 0) h = 1;

	// Atualiza as vari�veis
	largura = w;
	altura = h;
                                              
	// Especifica as dimens�es da Viewport
	glViewport(0, 0, largura, altura);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de sele��o (esquerda, direita, inferior, 
	// superior) mantendo a propor��o com a janela de visualiza��o
	if (largura <= altura) 
	{ 
		gluOrtho2D (-10.0f, 10.0f, -10.0f*altura/largura, 10.0f*altura/largura);
		win = 10.0f;
	}              
	else 
	{ 
		gluOrtho2D (-10.0f*largura/altura, 10.0f*largura/altura, -10.0f, 10.0f);
		win = 10.0f*largura/altura;           
	}             
}

// Fun��o callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y){
	if (key == 27){
		exit(0);	
	}		
}

void MudaCor(int key, int x, int y){
	if(key == GLUT_KEY_DOWN){
		x+=0.1;
		y+=0.1;
		z+=0.1;
		
		if(x>1){
			x=1;
		}
		if(y>1){
			y=1;
		}
		if(z>1){
			z=1;
		}
	}
	if(key == GLUT_KEY_UP){
		x-=0.1;
		y-=0.1;
		z-=0.1;
		if(x<0){
			x=0;
		}
		if(y<0){
			y=0;
		}
		if(z<0){
			z=0;
		}
	}
	if(key == GLUT_KEY_RIGHT){
		a+=0.1;
		if(a>1){
			a=0;
		}
	}
	if(key == GLUT_KEY_LEFT){
		b+=0.1;
		if(b>1){
			b=0;
		}
	}
	glutPostRedisplay();
}

// Programa Principal 
int main(void){
    // Define do modo de opera��o da GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(400,400); 
	// Cria a janela passando como argumento o t�tulo da mesma
	glutCreateWindow("Ilusao");
	// Registra a fun��o callback de redesenho da janela de visualiza��o
	glutDisplayFunc(DesenhaIlusao);
	// Registra a fun��o callback de redimensionamento da janela de visualiza��o
	glutReshapeFunc(AlteraTamanhoJanela);
	// Registra a fun��o callback para tratamento das teclas ASCII
	glutKeyboardFunc (Teclado);
	glutSpecialFunc(MudaCor);
	// Chama a fun��o respons�vel por fazer as inicializa��es 
	Inicializa();
	// Inicia o processamento e aguarda intera��es do usu�rio
	glutMainLoop();
	return 0;
}


