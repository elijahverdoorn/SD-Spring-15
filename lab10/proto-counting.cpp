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
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>

int WIDTH = 100;  // width of the user window
int HEIGHT = 100;  // height of the user window
char programName[] = "counting";

int counter = 0;
double startTime;

// the drawText function draws some text at location x, y
//   note:  the text to be drawn is a C-style string!
void drawText(float x, float y, const char *text)
{
  glRasterPos2f( x, y );
  int length = strlen(text);
  for (int i = 0; i < length; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

// the drawNumber function draws a number at location x, y
void drawNumber(double x, double y, double num)
{
  stringstream oss;
  oss << num; oss.flush();
  drawText(x, y, oss.str().c_str());
}

// the drawWindow function actually does the work of drawing in the window.
//   this function will be called every time the appearance of the window
//   needs to be remade.
void drawWindow()
{
  // clear the buffer
  glClear(GL_COLOR_BUFFER_BIT);

  // draw the number
  drawNumber(50, 50, counter);

  // tell the graphics card that we're done-- go ahead and draw!
  glutSwapBuffers();
}

// function to return the current time, in seconds, since Jan 1, 1970.
//   depends on the sys/time.h library
double getCurrentTime()
{
  struct timeval tv = {0,0};
  struct timezone tz;
  gettimeofday(&tv, &tz);
  // cout << "tv is " << tv.tv_sec << " micro " << tv.tv_usec << endl;
  return tv.tv_sec + tv.tv_usec/(double)1000000.;
}

// the idle function is called when nothing else is happening
//   in this case, it is critical to have an idle function, since
//   we want something to happen even when the user does nothing
void idle()
{
  // figure out whether it is time to change the counter.
  //   we want the counter to change once per second, so we want the
  //   elapsed time (since the beginning of the program) to be 
  //   the same as the elapsedTime (rounded down)
  double elapsedTime = getCurrentTime() - startTime;
  if ( (int)elapsedTime > counter/5 ) {
    // ok, enough time has passed that we should increase the counter
    ++counter;
    if ( counter >= 100 ) {  // done with the count
      cout << "Yay!" << endl;
      exit(0);
    }
    glutPostRedisplay();
  }
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
  glOrtho(0., WIDTH-1, HEIGHT-1, 0., -1.0, 1.0);

  // welcome message
  cout << "Let's count..." << endl;
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

  glutDisplayFunc(drawWindow);
  glutIdleFunc(idle);
  glutMainLoop();
}

int main()
{
  startTime = getCurrentTime();
  init_gl_window();
}
