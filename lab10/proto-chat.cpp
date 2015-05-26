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
#include<stdlib.h>
#include"network.h"

int WIDTH = 240;  // width of the user window
int HEIGHT = 200;  // height of the user window
char programName[] = "proto-chat";

// textbox info
bool overTextBox = false;
string textInBox = "";
string storedText1, storedText2, storedText3;
double textBox1[] = { 20, 130,   200, 40 };  // outer box for text
double textBox2[] = { 25, 135,   190, 30 };  // inner box for text

double textBox3[] = { 25, 25,   190, 30 };  // box for stored text
double textBox4[] = { 25, 55,   190, 30 };  // box for stored text
double textBox5[] = { 25, 85,   190, 30 };  // box for stored text
const unsigned int MAX_NUM_CHARS_IN_TEXTBOX = 20;

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

void drawWindow()
{
  // clear the buffer
  glClear(GL_COLOR_BUFFER_BIT);

  // draw the textbox
  glColor3f(.25, .25, .25);  // dark gray
  drawBox(textBox1);
  if ( overTextBox ) glColor3f(1,1,1);  // white
  else glColor3f(.75, .75, .75);  // light gray
  drawBox(textBox2);
  glColor3f(0, 0, 0);  // black
  if ( overTextBox ) { // draw with a cursor
    string withCursor(textInBox);
    withCursor += '|';
    drawText( textBox2[0]+5, textBox2[1]+textBox2[3]-10, withCursor.c_str() );
  } else drawText( textBox2[0]+5, textBox2[1]+textBox2[3]-10, textInBox.c_str() );

  // draw the stored text
  glColor3f(1, 1, 1);  // black
  drawText( textBox3[0]+5, textBox3[1]+textBox3[3]-10, storedText3.c_str());
  drawText( textBox4[0]+5, textBox4[1]+textBox4[3]-10, storedText2.c_str());
  drawText( textBox5[0]+5, textBox5[1]+textBox5[3]-10, storedText1.c_str());

  // tell the graphics card that we're done-- go ahead and draw!
  //   (technically, we are switching between two color buffers...)
  glutSwapBuffers();
}

// close the window and finish the program
void exitAll()
{
  int win = glutGetWindow();
  glutDestroyWindow(win);
  exit(0);
}

// process keyboard events
void keyboard( unsigned char c, int x, int y )
{
  if ( overTextBox ) { // intercept keyboard press, to place in text box
    if ( 27==c ) exitAll();  // escape terminates the program, even in textbox
    if ( 13==c ) {
      // cout << "textBox content was: " << textInBox << endl;
      multicast(textInBox.c_str());
      textInBox = "";
    } else if ( '\b'==c || 127==c ) { // handle backspace
      if ( textInBox.length() > 0 ) textInBox.erase(textInBox.end()-1);
    } else if ( c >= 32 && c <= 126 ) { // check for printable character
      // check that we don't overflow the box
      if ( textInBox.length() < MAX_NUM_CHARS_IN_TEXTBOX ) textInBox += c;
    }
  } else {
    switch(c) {
      case 'q':
      case 'Q':
      case 27:
        exitAll();
        break;
      default:
        break;
    }
  }
  glutPostRedisplay();
}

// process multicast events
void receiveMulticast( const char *msg )
{
  storedText3 = storedText2;
  storedText2 = storedText1;
  storedText1 = msg;
  glutPostRedisplay();
}

// the idle function is called when nothing else is happening
//   in this case, it is critical to have an idle function, since
//   we want something to happen even when the user does nothing
void idle()
{
  const int bufMaxLen = 1000;  // choose a max size for messages
  char buffer[bufMaxLen];
  listen(buffer, bufMaxLen);
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
   glOrtho(0., WIDTH-1, HEIGHT-1, 0., -1.0, 1.0);
}

// the following function tests whether a point at position x,y is inside
//   the rectangle on the screen corresponding to the textBox background
bool onTextBox(int x, int y)
{
  return x >= textBox1[0] && y >= textBox1[1] &&
         x <= textBox1[0]+textBox1[2] &&
         y <= textBox1[1]+textBox1[3];
}

// the mouse function is called when a mouse button is pressed down or released
void mouse(int mouseButton, int state, int x, int y)
{
  if ( GLUT_LEFT_BUTTON == mouseButton ) {
    if ( GLUT_DOWN == state ) {
      // the user just pressed down on the mouse-- do something
    } else {
      // the user just let go the mouse-- do something
    }
  } else if ( GLUT_RIGHT_BUTTON == mouseButton ) {
  }
  glutPostRedisplay();
}

// the mouse_motion function is called when the mouse is being dragged,
//   and gives the current location of the mouse
void mouse_motion(int x,int y)
{
  // the mouse button is pressed, and the mouse is moving....
  if ( onTextBox(x,y) ) overTextBox = true;
  else overTextBox = false;
  glutPostRedisplay();
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
  cout << "Welcome to " << programName << ". Try running several of these, and typing in the text box." << endl;
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
  glutInitWindowSize(WIDTH,HEIGHT);
  glutInitWindowPosition(100,100);
  glutCreateWindow(programName);
  init();

  glutDisplayFunc(drawWindow);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutMotionFunc(mouse_motion);
  glutPassiveMotionFunc(mouse_motion);
  glutIdleFunc(idle);
  glutMainLoop();
}

int main()
{
  initNetwork(25100);
  init_gl_window();
}
