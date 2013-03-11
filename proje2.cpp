/**
**Oğuzhan Karslı	
**
**040070257
**
**/
#include <windows.h> 
#include <stdlib.h> 

#include <GL/gl.h>

#include <GL/glu.h>	
#include <GLUT/glut.h>	

void OpenGLInit(void);

static void Animate(void );
GLint LoadGLTexture(const char *, int , int);
static void ResizeWindow(int w, int h);

static GLenum turning = GL_TRUE;
static GLenum change = GL_FALSE;

static float sunn = 0.0;
static float earthrotate = 0.0;
static float earthposition = 0.0;
static float AnimateIncrement = 5.0;  


static void Action(void)
{
	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	
    if (turning) {
		
		sunn+=AnimateIncrement/5.0/2.0;
		earthrotate =earthrotate+ AnimateIncrement;
		earthposition =earthposition+ AnimateIncrement/5.0;

        earthrotate = earthrotate - ((int)(earthrotate/5))*5;
        earthposition = earthposition - ((int)(earthposition/360))*360;
		}
	
	
    glLoadIdentity();

    glTranslatef ( 0.0, 0.0, -10.0 );

	glRotatef( 15.0, 0.0, 0.0, 1.0 );
	
	glColor3f( 1.0, 1.0, 0.0 );		
	 glRotatef( sunn, 0.0, 0.0, 1.0 );
    glutSolidSphere( 1.0, 15, 15 );
	glPushMatrix();

    glRotatef( 360.0*earthposition/360.0, 0.0, 1.0, 0.0 );
    glTranslatef( 0.0, 0.0, 4.0 );
    glPushMatrix();						
	
	glRotatef( 360.0*earthrotate/5.0, 1.0, 0.0, 0.0 );

    glColor3f( 0.2, 0.2, 1.0 );
    glutSolidSphere( 0.4, 10, 10);
    glPopMatrix();						
	
   	glRotatef( 360.0*2.0*earthposition/360.0, 0.0, -1.0, 0.0 );
    glTranslatef( 0.9, 0.0, 0.0 );
    glColor3f( 0.3, 0.7, 0.3 );
    glutSolidSphere( 0.1, 5, 5 );
	glPopMatrix();
	 glRotatef( 360.0*earthposition/360.0, 0.0, 1.0, 0.0 );
    glTranslatef( 0.0, 0.0, 2.0 );
	glPushMatrix();
	glPushMatrix();
	glRotatef( 360.0*earthrotate/5.0, 0.0, -1.0, 0.0 );

	
    glColor3f( 0.2, 0.2, 1.0 );
    glutSolidSphere( 0.5, 10, 10);
	glPopMatrix();
	glRotatef( 360.0*12.0*earthposition/360.0, 1.0, 0.0, 0.0 );
    glTranslatef( 0.8, 0.0, 0.0 );
    glColor3f( 0.3, 0.7, 0.3 );
    glutSolidSphere( 0.1, 5, 5 );
	
	glPopMatrix();
	
	glRotatef( 360.0*2.0*earthposition/360.0, -1.0, 0.0, 0.0 );
    glTranslatef( 0.5, 0.0, 0.0 );
    glColor3f( 0.3, 0.7, 0.3 );
    glutSolidSphere( 0.1, 5, 5 );
	
    glFlush();
    glutSwapBuffers();

	if ( change==true ) {
		turning = GL_FALSE;
	}

	glutPostRedisplay();		

}

void OpenGLInit(void)
{	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,0.0, 0.0,0.0,0.0, 0.0,0.0,0.0);

	GLfloat light[] = {0.0,0.0,-10.0,0.0};
	glLightfv(GL_LIGHT5, GL_POSITION, light);
	glShadeModel( GL_SMOOTH );
    glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glClearDepth( 5.0 );

}

static void drawWindow(int h, int s)
{
    float widthheight;
	if(s==0){
		s=1;
	}
	else{
		s=s;
	}
	if(h==0){
		h=1;
	}
	else{
		h=h;
	}
	
	glViewport( 0, 0, h, s );	
	widthheight = (float)h/(float)s;

	
    glMatrixMode( GL_PROJECTION );
	
    glLoadIdentity();
    gluPerspective( 60.0, widthheight, 1.0, 30.0 );

	
    glMatrixMode( GL_MODELVIEW );
}



int main( int argc, char** argv )
{

	glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowPosition( 0, 0 );
    glutInitWindowSize( 800, 480 );
    glutCreateWindow( "HomeWork 1" );

    OpenGLInit();
    glutReshapeFunc( drawWindow );

    glutDisplayFunc( Action );
	
	glutMainLoop(  );

    return(0);		
}
