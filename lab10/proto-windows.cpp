#include<iostream>
#include<fstream>
using namespace std;
#ifdef MACOSX
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdlib.h>
#include"texture.h"

int mainWIDTH = 140;  // width of the main user window
int mainHEIGHT = 100;  // height of the main user window
int secondWIDTH = 200;  // width of the second user window
int secondHEIGHT = 200;  // height of the second user window
char programName[] = "proto-windows";
int calvinT, hobbesT;  // texture ids

// button info
bool buttonIsPressed = false, overButton = false;
double buttonPos[] = { 20, 20,   100, 60 };  // upper left, width, height

// window info:  store the id of a window when it is created, and
//   set this id to zero when the window is destroyed
int mainWindowID = 0, secondWindowID = 0;
int createNewWindow(const char *windowTitle);  // declare this function

// the following function draws a rectangle, given
//   the upper left vertex and the width and height
void drawBox(double x, double y, double width, double height)
{
  glBegin(GL_POLYGON);
    glVertex2f(x, y);  // upper left
    glVertex2f(x, y + height);  // lower left
    glVertex2f(x + width, y + height);  // lower right
    glVertex2f(x + width, y);  // upper right
  glEnd();
}
void drawBox(double *pos)
{
  drawBox(pos[0], pos[1], pos[2], pos[3]);
}

// the drawText function draws some text at location x, y
//   note:  the text to be drawn is a C-style string!
void drawText(double x, double y, const char *text)
{
  glRasterPos2f( x, y );
  int length = strlen(text);
  for (int i = 0; i < length; i++)
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]);
}

void drawMainWindow()
{
  glutSetWindow(mainWindowID);  // this call may not be necessary

  // clear the buffer
  glClear(GL_COLOR_BUFFER_BIT);

  // draw the button
  if ( buttonIsPressed ) glColor3f(1., 0., 0.);  // make it red
  else if ( overButton ) glColor3f(.75,.75,.75);  // light gray
  else glColor3f(.5, .5, .5);  // gray
  drawBox(buttonPos);
  drawTexture(calvinT,  50,20,    40, 60);  // texNum, x,y, width, height

  // tell the graphics card that we're done-- go ahead and draw!
  //   (technically, we are switching between two color buffers...)
  glutSwapBuffers();
}

void drawSecondWindow()
{
  glutSetWindow(secondWindowID);  // this call may not be necessary

  // clear the buffer
  glClear(GL_COLOR_BUFFER_BIT);

  // draw something
  drawTexture(hobbesT,  20,40,    180, 100);  // texNum, x,y, width, height

  // tell the graphics card that we're done-- go ahead and draw!
  //   (technically, we are switching between two color buffers...)
  glutSwapBuffers();
}

// close the window and finish the program
void exitAll()
{
  if ( mainWindowID ) glutDestroyWindow(mainWindowID);
  if ( secondWindowID ) glutDestroyWindow(secondWindowID);
  exit(0);
}

// process keyboard events (for both windows-- you could make this
//   into two functions, just like for the display functions)
void keyboard( unsigned char c, int x, int y )
{
  switch(c) {
    case 'q':
    case 'Q':
    case 27:
      exitAll();
      break;
    default:
      break;
  }
  glutPostRedisplay();
}

// the reshape function handles the case where the user changes the size
//   of the window.  We need to fix the coordinate
//   system, so that the drawing area is still the unit square.
void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   if ( mainWindowID == glutGetWindow() ) {
     mainWIDTH = w;  mainHEIGHT = h;
   } else {
     secondWIDTH = w;  secondHEIGHT = h;
   }
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0., w-1, h-1, 0., -1.0, 1.0);
}

// the following function tests whether a point at position x,y is inside
//   the rectangle on the screen corresponding to the button
bool onButton(int x, int y)
{
  return x >= buttonPos[0]  && y >= buttonPos[1] &&
         x <= buttonPos[0] + buttonPos[2] &&
         y <= buttonPos[1] + buttonPos[3];
}

// the mouse_motion function is called when the mouse is being dragged,
//   and gives the current location of the mouse
void mouse_motion(int x,int y)
{
  // the mouse button is pressed, and the mouse is moving....
  if ( buttonIsPressed ) {
    // do nothing
  } else {
    if ( onButton(x,y) ) overButton = true;
    else overButton = false;
  }
  glutPostRedisplay();
}

// the mouse function is called when a mouse button is pressed down or released
void mouse(int mouseButton, int state, int x, int y)
{
  if ( GLUT_LEFT_BUTTON == mouseButton ) {
    if ( GLUT_DOWN == state ) {
      // the user just pressed down on the mouse-- do something
      if ( onButton(x,y) ) buttonIsPressed = true;
      else buttonIsPressed = false;
    } else {
      // the user just let go the mouse-- do something
      if ( onButton(x,y) && buttonIsPressed ) {
        if ( 0 == secondWindowID ) { // create the second window
          glutInitWindowPosition(300,130);  // choose where to put it
          glutInitWindowSize(secondWIDTH,secondHEIGHT); // how big?
          secondWindowID = createNewWindow("window title 2");
          glutDisplayFunc(drawSecondWindow); // assign the display function
          glOrtho(0., secondWIDTH-1, secondHEIGHT-1, 0., -1.0, 1.0); // coords
          hobbesT = loadTexture("Hobbes.pam");  // loading in the second window
          glutPostWindowRedisplay(secondWindowID);
          glutSetWindow(mainWindowID);    // select the main window again
        } else {  // destroy the second window
          glutDestroyWindow(secondWindowID);
          secondWindowID = 0;
        }
      }
      buttonIsPressed = false;
    }
  } else if ( GLUT_RIGHT_BUTTON == mouseButton ) {
  }
  glutPostRedisplay();
}

// the createNewWindow function creates a window and returns its id
int createNewWindow(const char *windowTitle)
{
  int id = glutCreateWindow(windowTitle);
  assert( 0 != id );
  // clear the window to black
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // begin setting up the coordinate system
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // allow blending (for transparent textures)
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);

  // register callbacks
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);
  glutMotionFunc(mouse_motion);
  glutPassiveMotionFunc(mouse_motion);

  return id;
}

// init_gl_window is the function that starts the ball rolling, in
//  terms of getting everything set up and passing control over to the
//  glut library for event handling.  It needs to tell the glut library
//  about all the essential functions:  what function to call if the
//  window changes shape, what to do to redraw, handle the keyboard,
//  etc.
void init_gl_window()
{
  char *argv[] = { programName };
  int argc = sizeof(argv) / sizeof(argv[0]);
  glutInit(&argc, argv);
  glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );

  // build main window
  glutInitWindowSize(mainWIDTH, mainHEIGHT);
  glutInitWindowPosition(100,100);
  mainWindowID = createNewWindow(programName);
  glutDisplayFunc(drawMainWindow);
  glOrtho(0., mainWIDTH-1, mainHEIGHT-1, 0., -1.0, 1.0);  // coordinate system
  calvinT = loadTexture("Calvin.pam");  // loading in the main window

  // welcome message
  cout << "Welcome to " << programName << ".  Try pressing the button to create or destroy another window." << endl;

  glutMainLoop();
}

int main()
{
  init_gl_window();
}
