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
#include<sstream>

int WIDTH = 640;  // width of the user window
int HEIGHT = 100;  // height of the user window
char programName[] = "proto-ui";

// button info
bool buttonIsPressed1 = false, overButton1 = false, buttonIsPressed2 = false, overButton2 = false;
double buttonPos1[] = { 20, 20,   80, 60 };  // upper left, width, height
double buttonPos2[] = { 550, 20 ,  80, 60 }; 
// slider info
bool sliderIsPressed = false, overSlider = false;
double sliderBox1[] = { 120, 48,   180, 4 };  // background of slider
double sliderBox2[] = { 115, 40,   10, 20 };  // foreground of slider
double sliderPos = 0;  // where the slider currently is located
double sliderStartPos;  // where the mouse first clicked on the slider
double sliderMax = 180;  // upper limit to the sliderPos

// textbox info
bool overTextBox = false;
string textInBox = "";
double textBox1[] = { 320, 30,   200, 40 };  // outer box for text
double textBox2[] = { 325, 35,   190, 30 };  // inner box for text
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

  // draw button1
  if ( buttonIsPressed1 ) glColor3f(1., 0., 0.);  // make it red
  else if ( overButton1 ) glColor3f(.75,.75,.75);  // light gray
  else glColor3f(.5, .5, .5);  // gray
  drawBox(buttonPos1);

  // draw button2
  if ( buttonIsPressed2 ) glColor3f(1., 0., 0.);  // make it red
  else if ( overButton2 ) glColor3f(.75,.75,.75);  // light gray
  else glColor3f(.5, .5, .5);  // gray
  drawBox(buttonPos2);

  // draw the slider background
  if ( sliderIsPressed || overSlider ) glColor3f(.5, .5, .5);  // gray
  else glColor3f(.25, .25, .25);  // dark gray
  drawBox(sliderBox1);
  // draw the slider foreground
  if ( overSlider ) glColor3f(.95, .95, .95);  // very light gray
  else glColor3f(.75, .75, .75);  // light gray
  drawBox(sliderBox2[0] + sliderPos, sliderBox2[1], 
          sliderBox2[2],  sliderBox2[3]);
  
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
      cout << "textBox content was: " << textInBox << endl;
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
//   the rectangle on the screen corresponding to the button
bool onButton1(int x, int y)
{
  return x >= buttonPos1[0]  && y >= buttonPos1[1] &&
         x <= buttonPos1[0] + buttonPos1[2] &&
         y <= buttonPos1[1] + buttonPos1[3];
}

bool onButton2(int x, int y)
{
    return x >= buttonPos2[0]  && y >= buttonPos2[1] &&
         x <= buttonPos2[0] + buttonPos2[2] &&
         y <= buttonPos2[1] + buttonPos2[3];
}

// the following function tests whether a point at position x,y is inside
//   the rectangle on the screen corresponding to the slider
bool onSliderForeground(int x, int y)
{
  return x >= sliderBox2[0]+sliderPos  && y >= sliderBox2[1] &&
         x <= sliderBox2[0]+sliderBox2[2]+sliderPos &&
         y <= sliderBox2[1]+sliderBox2[3];
}
bool onSliderBackground(int x, int y)
{
  return x >= sliderBox2[0]  && y >= sliderBox2[1] &&
         x <= sliderBox2[0]+sliderMax+sliderBox2[2] &&
         y <= sliderBox2[1]+sliderBox2[3];
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
      if ( onButton1(x,y) ) buttonIsPressed1 = true;
      else buttonIsPressed1 = false;
      if ( onButton2(x,y) ) buttonIsPressed2 = true;
      else buttonIsPressed2 = false;
      if ( onSliderForeground(x,y) ) {
        sliderIsPressed = true;
        sliderStartPos = x - sliderPos;
      } else if ( onSliderBackground(x,y) ) {
        sliderIsPressed = true;
        sliderPos = x - sliderBox1[0];
        sliderStartPos = x-sliderPos;
      } else sliderIsPressed = false;
    } else {
      // the user just let go the mouse-- do something
      if ( onButton1 (x,y) && buttonIsPressed1  )
        cout << "Button 1 press." << endl;
      buttonIsPressed1 = false;
      if ( onButton2 (x,y) && buttonIsPressed2  )
        cout << "button 2 press." << endl;
      buttonIsPressed2 = false; 
      if ( sliderIsPressed )
        cout << "New slider position: " << sliderPos << endl;
      sliderIsPressed = false;
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
  if ( buttonIsPressed1 ) {
    // do nothing
  } else if ( sliderIsPressed ) {
    double newSliderPos = x - sliderStartPos;
    // check that the new slider pos does not go off the end of the slider
    if ( newSliderPos < 0 ) sliderPos = 0;
    else if ( newSliderPos > sliderMax ) sliderPos = sliderMax;
    else sliderPos = newSliderPos;
  } else {
    if ( onButton1(x,y) ) overButton1 = true;
    else overButton1 = false;
    if ( onButton2(x,y) ) overButton2 = true;
    else overButton2 = false;
    if ( onSliderBackground(x,y) ) overSlider = true;
    else overSlider = false;
    if ( onTextBox(x,y) ) overTextBox = true;
    else overTextBox = false;
  }
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
  cout << "Welcome to " << programName << ".  Try pressing the button, moving the slider," << endl;
  cout << " or typing in the text box." << endl;
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
  glutMainLoop();
}

int main()
{
  init_gl_window();
}
