#include "glos.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <glaux.h>
#include <math.h>

void myinit(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK MutaStanga(void);
void CALLBACK MutaDreapta(void);
void CALLBACK MutaSus(void);
void CALLBACK MutaJos(void);
void CALLBACK rot_z_up(void);
void CALLBACK rot_z_down(void);
void CALLBACK DeseneazaStele(void);
void CALLBACK UrcaRacheta(void);
void CALLBACK CoboaraRacheta(void);

void CALLBACK DeseneazaRacheta(int esteUmbra);
void CALLBACK IdleFunction(void);

static GLfloat scaleFlacara = 1.0f;
static GLfloat pasFlacara = 0.05f;
static GLfloat pozitieY = 0.0f; 
static GLfloat x = 30.0f, y = 20.0f, z = 0, alfa = 0.0f;

void myinit(void) {
   
    glClearColor(0.0f, 0.0f, 0.15f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    GLfloat light_position[] = { 5.0f, 5.0f, 5.0f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}

void CALLBACK MutaStanga(void) { x = x - 10; }
void CALLBACK MutaDreapta(void) { x = x + 10; }
void CALLBACK UrcaRacheta(void)
{
    pozitieY += 0.2f;
    if (pozitieY > 3.0f) {
        pozitieY = 3.0f;
    }
}

void CALLBACK CoboaraRacheta(void)
{
    pozitieY -= 0.2f;
    if (pozitieY < 0.0f) {
        pozitieY = 0.0f;
    }
}
void CALLBACK MutaJos(void) { y = y - 5.0f; }
void CALLBACK MutaSus(void) { y = y + 5.0f; }
void CALLBACK rot_z_up(void) { alfa = alfa + 5.0f; }
void CALLBACK rot_z_down(void) { alfa = alfa - 5.0f; }

void CALLBACK DeseneazaStele(void)
{
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(2.0f);

    glBegin(GL_POINTS);
    glVertex3f(-5.0f, 6.0f, -3.0f);
    glVertex3f(4.0f, 7.0f, -4.0f);
    glVertex3f(-7.0f, 4.0f, -5.0f);
    glVertex3f(6.0f, 5.0f, -2.0f);
    glVertex3f(0.0f, 8.0f, -6.0f);
    glVertex3f(-3.0f, 9.0f, -4.0f);
    glVertex3f(8.0f, 8.0f, -5.0f);
    glVertex3f(-8.0f, 7.0f, -2.0f);
    glVertex3f(2.0f, 9.0f, -3.0f);
    glVertex3f(-2.0f, 5.0f, -7.0f);
    glVertex3f(-6.0f, 8.5f, -4.0f);
    glVertex3f( 5.5f, 6.5f, -5.0f);
    glVertex3f( 1.0f, 7.5f, -7.0f);
    glVertex3f(-4.0f, 4.5f, -6.0f);
    glVertex3f( 7.0f, 9.0f, -3.0f);
    glVertex3f(-1.0f, 6.0f, -5.0f);
    glVertex3f( 3.0f, 8.0f, -2.0f);
    glVertex3f(-9.0f, 5.5f, -4.0f);
    glVertex3f( 9.0f, 6.0f, -6.0f);
    glVertex3f(-5.0f, 7.5f, -8.0f);
    glVertex3f( 4.5f, 9.5f, -5.0f);
    glVertex3f(-2.5f, 8.5f, -3.0f);
    glVertex3f( 2.5f, 5.5f, -8.0f);
    glVertex3f(-7.5f, 6.5f, -6.0f);
    glVertex3f( 8.5f, 4.5f, -4.0f);
    glVertex3f(-0.5f, 9.5f, -7.0f);
    glVertex3f( 6.5f, 7.5f, -8.0f);
    glVertex3f(-3.5f, 5.0f, -2.0f);
    glVertex3f( 1.5f, 4.0f, -5.0f);
    glVertex3f(-8.5f, 8.0f, -3.0f);

    glEnd();
    glEnable(GL_LIGHTING);
    glPopMatrix();
}
void CALLBACK IdleFunction(void)
{
    scaleFlacara += pasFlacara;
    if (scaleFlacara > 1.5f || scaleFlacara < 0.5f) {
        pasFlacara = -pasFlacara;
    }
    
    display();
    Sleep(30);
}

void CALLBACK DeseneazaRacheta(int esteUmbra)
{
    GLUquadricObj* quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricNormals(quadric, GLU_SMOOTH);

    glPushMatrix();
    if (esteUmbra)
        glColor3f(0.1f, 0.1f, 0.1f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluCylinder(quadric, 0.5, 0.5, 1.5, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 1.5f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    if (esteUmbra) 
        glColor3f(0.1f, 0.1f, 0.1f);
    else 
        glColor3f(0.9f, 0.1f, 0.1f);
    gluCylinder(quadric, 0.5, 0.0, 0.8, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.8f, 0.45f);
    if (esteUmbra) 
        glColor3f(0.1f, 0.1f, 0.1f);
    else 
        glColor3f(0.2f, 0.6f, 0.8f);
    gluSphere(quadric, 0.25, 32, 32);
    glPopMatrix();

    glPushMatrix();
    if (esteUmbra) 
        glColor3f(0.1f, 0.1f, 0.1f);
    else 
        glColor3f(0.9f, 0.1f, 0.1f);
    glBegin(GL_TRIANGLES);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, 0.0f);
    glVertex3f(-1.2f, -0.2f, 0.0f);
    glVertex3f(-0.5f, -0.2f, 0.0f);
    glVertex3f(0.5f, 0.5f, 0.0f);
    glVertex3f(1.2f, -0.2f, 0.0f);
    glVertex3f(0.5f, -0.2f, 0.0f);
    glEnd();
    glPopMatrix();

    if (!esteUmbra) {
        glDepthMask(GL_FALSE);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glDisable(GL_LIGHTING);

        glPushMatrix();
        glTranslatef(0.0f, -0.2f, 0.0f);
        glScalef(1.0f, scaleFlacara, 1.0f);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        glColor4f(1.0f, 0.5f, 0.0f, 0.6f);
        gluCylinder(quadric, 0.4, 0.0, 1.2, 32, 32);
        glPopMatrix();

        glEnable(GL_LIGHTING);

        glDisable(GL_BLEND);
        glDepthMask(GL_TRUE);
    }
    gluDeleteQuadric(quadric);
}

void CALLBACK display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(y, 1.0, 0.0, 0.0);
    glRotatef(x, 0.0, 1.0, 0.0);
    glTranslatef(0.0, -0.5, 0.0);
    DeseneazaStele();

    glPushMatrix();
    glTranslatef(0.0f, -2.5f, 0.0f);
    glColor3f(0.3f, 0.3f, 0.35f);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-10.0f, 0.0f, -10.0f);
    glVertex3f(-10.0f, 0.0f, 10.0f);
    glVertex3f(10.0f, 0.0f, 10.0f);
    glVertex3f(10.0f, 0.0f, -10.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, pozitieY, 0.0f);
    glRotatef(alfa, 0.0, 1.0, 0.0);
    DeseneazaRacheta(0);
    glPopMatrix();

    glPushMatrix();
    glDisable(GL_LIGHTING);
    GLfloat factorUmbra = 1.0f - (pozitieY / 3.0f);
    if (factorUmbra < 0.0f) factorUmbra = 0.0f;
    glTranslatef(0.0f, -2.49f, 0.0f);
    glScalef(factorUmbra, 0.0f, factorUmbra);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.2f, 0.2f, 0.2f, factorUmbra);
    glRotatef(45.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 2.4f, 0.0f);
    glRotatef(alfa, 0.0, 1.0, 0.0);
    DeseneazaRacheta(1);

    glDisable(GL_BLEND);
    glEnable(GL_LIGHTING);
    glPopMatrix();

    glFlush();
}
void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-4.0, 4.0,
            -4.0 * (GLfloat)h / (GLfloat)w,
            4.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-4.0 * (GLfloat)w / (GLfloat)h,
            4.0 * (GLfloat)w / (GLfloat)h,
            -4.0, 4.0, -10.0, 10.0);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB | AUX_DEPTH);
    auxInitPosition(0, 0, 600, 600);
    auxInitWindow("Racheta 3D");
    myinit();

    auxKeyFunc(AUX_LEFT, MutaStanga);
    auxKeyFunc(AUX_RIGHT, MutaDreapta);
    auxKeyFunc(AUX_UP, MutaSus);
    auxKeyFunc(AUX_DOWN, MutaJos);
    auxMouseFunc(AUX_LEFTBUTTON, AUX_MOUSEDOWN, rot_z_up);
    auxMouseFunc(AUX_RIGHTBUTTON, AUX_MOUSEDOWN, rot_z_down);
    auxKeyFunc('S', UrcaRacheta);
    auxKeyFunc('J', CoboaraRacheta);
    auxReshapeFunc(myReshape);
    auxIdleFunc(IdleFunction);
    auxMainLoop(display);
    return(0);
}