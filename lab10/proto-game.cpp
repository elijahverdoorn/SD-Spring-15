#include<iostream>
#include<iomanip>
#include<sstream>
using namespace std;
#include<vector>
#ifdef MACOSX
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif
#include<stdlib.h>
#include<math.h>

int WIDTH = 500;  // width of the user window
int HEIGHT = 400;  // height of the user window
char programName[] = "proto-game";

double shape_position_x = 250, shape_position_y = 200; // position of the shape
double shape_width = 50, shape_height = 40; // size of the shape
double move_x = 50, move_y = 40; // how far to move for each keypress

// the display function actually does the work of drawing in the window.
//   this function will be called every time the appearance of the window
//   needs to be remade.
void display()
{
  // clear the buffer
  glClear(GL_COLOR_BUFFER_BIT);

  // let's draw a blue triangle
  glColor3f(0., 0., 1.);  // make it blue
  glBegin(GL_POLYGON);
    glVertex2f(shape_position_x, shape_position_y);
    glVertex2f(shape_position_x + shape_width, shape_position_y);
    glVertex2f(shape_position_x + shape_width/2.,
               shape_position_y + shape_height);
  glEnd();

  // draw a red boundary
  glColor3f(1., 0., 0.);
  glBegin(GL_LINE_STRIP);
    glVertex2f(shape_position_x, shape_position_y);
    glVertex2f(shape_position_x + shape_width, shape_position_y);
  glEnd();

  // draw a yellow point
  glColor3f(1., 1., 0.);
  glBegin(GL_POINTS);
    glVertex2f(shape_position_x, shape_position_y);
  glEnd();

  // tell the graphics card that we're done-- go ahead and draw!
  glutSwapBuffers();
}

// process keyboard events
void keyboard( unsigned char c, int x, int y )
{
  int win = glutGetWindow();
  switch(c) {
    case 'q':
    case 'Q':
    case 27:
      // get rid of the window (as part of shutting down)
      glutDestroyWindow(win);
      exit(0);
      break;
    case '\b':
      break;
    default:
      break;
  }
  glutPostRedisplay();
}

// process "special" keyboard events (those having to do with arrow keys)
void special_keyboard(int key,int x, int y)
{
  switch (key) {
    case GLUT_KEY_LEFT:
      shape_position_x -= move_x;
      break;
    case GLUT_KEY_RIGHT:
      shape_position_x += move_x;
      break;
    case GLUT_KEY_UP:
      shape_position_y += move_y;
      break;
    case GLUT_KEY_DOWN:
      // what goes here?
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
   WIDTH = w;  HEIGHT = h;
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0., WIDTH-1, 0., HEIGHT-1, -1.0, 1.0);
}

// the init function sets up the graphics card to draw properly
void init(void)
{
  // clear the window to black
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // set up the coordinate system:  number of pixels along x and y
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0., WIDTH-1, 0., HEIGHT-1, -1.0, 1.0);

  // set up how points and lines will be drawn.  The following
  //  commands make points and lines look nice and smooth.
  glPointSize(3);
  glLineWidth(1.5);
  glEnable(GL_POINT_SMOOTH);
  glEnable(GL_LINE_SMOOTH);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);

  // welcome message
  cout << "Welcome to " << programName << ".  Use the arrow keys to move the shape around." << endl;
}

// init_gl_window is the function that starts the ball rolling, in
//  terms of getting everything set up and passing control over to the
//  glut library for event handling.  It needs to tell the glut library
//  about all the essential functions:  what function to call if the
//  window changes shape, what to do to redraw, handle the keyboard,
//  etc.
void init_gl_window()
{
  char *argv[] = {programName};
  int argc = sizeof(argv) / sizeof(argv[0]);
  glutInit(&argc, argv);
  glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE );
  glutInitWindowSize(WIDTH,HEIGHT);
  glutInitWindowPosition(100,100);
  glutCreateWindow(programName);
  init();

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(special_keyboard);
  glutMainLoop();
}

int main()
{
  init_gl_window();
}
