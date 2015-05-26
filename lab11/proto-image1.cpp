#include<iostream>
#include<iomanip>
#include<sstream>
#include<stdlib.h>
using namespace std;
#include<GL/glut.h>
#include<math.h>
#include"Image.h"

Image *img;  // the image that will fill the window
pixel RED;   // default color
char programName = "proto-image1";

// the drawWindow function actually does the work of drawing in the window.
//   this function will be called every time the appearance of the window
//   needs to be remade.
void drawWindow()
{
  glRasterPos2d(0.,0.); // where to draw one corner
  glDrawPixels(img->getWidth(), img->getHeight(),  // image width and height
               GL_RGB, GL_UNSIGNED_BYTE,           // low-level flags
               img->getData() );      // actual data (must be a flat array!)
  glutSwapBuffers();
}

// the mouse function is called when a mouse button is pressed down or released
void mouse(int button, int state, int x, int y)
{
  if ( GLUT_LEFT_BUTTON == button ) {
    if ( GLUT_DOWN == state ) {
      img->setPixel(x,y,RED);
    }
  } else if ( GLUT_RIGHT_BUTTON == button ) {
    cout << "Bye!" << endl;
    exit(0);
  }
  glutPostRedisplay();
}
                                                                                
// the mouseMotion function is called when the mouse is being dragged,
//   and gives the current location of the mouse
void mouseMotion(int x,int y)
{
  img->setPixel(x,y,RED);
  glutPostRedisplay();
}

// the init function sets up the graphics card to draw properly
void init(void)
{
  // set up the coordinate system:  number of pixels along x and y
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0., img->getWidth()-1., img->getHeight()-1., 0., -1.0, 1.0);

  // set up various default parameters
  glPixelZoom(1,-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT,1);
  glPixelStorei(GL_UNPACK_SKIP_PIXELS,0);
  glPixelStorei(GL_UNPACK_SKIP_ROWS,0);

  // welcome message
  cout << "Welcome to " << programName << ".  Use the mouse to scribble." << endl;
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
  glutInitWindowSize(img->getWidth(),img->getHeight());
  glutInitWindowPosition(100,100);
  glutCreateWindow(programName);
  init();
  glutDisplayFunc(drawWindow);
  glutMouseFunc(mouse);
  glutMotionFunc(mouseMotion);
  glutMainLoop();
}

// simple usage message for how to use this program
void usage(char *progname)
{
  cerr << "Usage: " << progname << " [image.ppm]" << endl;
  exit(-1);
}

int main(int argc, char **argv)
{
  RED.red = 255; RED.green = 0; RED.blue = 0;
  if ( 2 != argc ) usage(argv[0]);
  img = new Image(argv[1]);
  init_gl_window();
}
