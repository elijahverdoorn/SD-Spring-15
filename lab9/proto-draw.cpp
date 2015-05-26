#include<iostream>
#include<fstream>
using namespace std;
#ifdef MACOSX
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif
#include<math.h>
#include<stdlib.h>
#include "Circle.h"
#include "Rectangle.h"

//for switching modes
int numModeButtons;
Shape **modeButtonForeground = new Shape*[9]; // update this as more buttons are added
Shape **modeButtonBackground = new Shape*[9]; // ""
Shape *currentModeButton;

enum ModeType {CIRCLE, RECTANGLE, SELECT};
ModeType currentMode;
Shape *currentUserShape;

bool mouseIsDragging = false;

int WIDTH = 720;  // width of the user window (640 + 80)
int HEIGHT = 540;  // height of the user window (480 + 60)
char programName[] = "proto-draw";

//dynamic shapes
Shape *userShape[10000];
int numUserShapes = 0;

//buttons for color
int numColorButtons;
Shape **colorButtonForeground = new Shape*[9]; // update this as more buttons are added
Shape **colorButtonBackground = new Shape*[9]; // ""
Shape *currentColorButton;
Color currentColor;

void loadModeButtons(char *fileName)
{
  ifstream g (fileName);
  if ( ! g.good() ) {
    cerr << "Warning:  Unable to open " << fileName << ", ignoring it." << endl;
    return;
  }
  g >> numModeButtons;
  numModeButtons /= 2;
  for (int i = 0; i < numModeButtons; ++i)
  {
    char *charArr = new char[64];
    g >> charArr;
    switch (charArr[0])
    {
      case 'r':
      case 'R':
        cout << "test" << endl;
        modeButtonBackground[i] = new Rectangle(g);
        break;
      case 'c':
      case 'C':
        modeButtonBackground[i] = new Circle(g);
        break;    
      default:
        cout << "lines must start with either Circle or Rectangle" << endl;
        break;
    }
    char *charArr2 = new char[64];
    g >> charArr2;
    switch (charArr2[0])
    {
      case 'r':
      case 'R':
        modeButtonForeground[i] = new Rectangle(g);
        break;
      case 'c':
      case 'C':
        modeButtonForeground[i] = new Circle(g);
        break;    
      default:
        cout << "lines must start with either Circle or Rectangle" << endl;
        break;
    }
    delete charArr;
    delete charArr2;
  }
  cout << numModeButtons << " mode buttons created" << endl;
}

void loadColorButtons(char *fileName)
{
  ifstream g (fileName);
  if ( ! g.good() ) {
    cerr << "Warning:  Unable to open " << fileName << ", ignoring it." << endl;
    return;
  }
  g >> numColorButtons;
  numColorButtons /= 2;
  for (int i = 0; i < numColorButtons; ++i)
  {
    char *charArr = new char[64];
    g >> charArr;
    switch (charArr[0])
    {
      case 'r':
      case 'R':
        cout << "test" << endl;
        colorButtonBackground[i] = new Rectangle(g);
        break;
      case 'c':
      case 'C':
        colorButtonBackground[i] = new Circle(g);
        break;    
      default:
        cout << "lines must start with either Circle or Rectangle" << endl;
        break;
    }
    char *charArr2 = new char[64];
    g >> charArr2;
    switch (charArr2[0])
    {
      case 'r':
      case 'R':
        colorButtonForeground[i] = new Rectangle(g);
        break;
      case 'c':
      case 'C':
        colorButtonForeground[i] = new Circle(g);
        break;    
      default:
        cout << "lines must start with either Circle or Rectangle" << endl;
        break;
    }
    delete charArr;
    delete charArr2;
  }
  cout << numColorButtons << " color buttons created" << endl;
}

void handleColorButtonPress(int x, int y)
{
  // figure out if we have pressed a color button
  int i;
  for ( i = 0; i < numColorButtons; ++i )
    if ( colorButtonBackground[i]->containsPoint(x,y) ) break;

  // if a button was pressed, show which one
  if ( i < numColorButtons ) {
    if ( currentColorButton )
      currentColorButton->setColor( Color(128,128,128) );
    currentColorButton = colorButtonBackground[i];
    currentColorButton->setColor( Color(255,0,0) );
    // change the current color
    currentColor = colorButtonForeground[i]->getColor();
  }
}

void handleModeButtonPress(int x, int y)
{
  // figure out if we have pressed a mode button
  int i;
  for ( i = 0; i < numModeButtons; ++i )
    if ( modeButtonBackground[i]->containsPoint(x,y) ) break;

  // if a button was pressed, show which one
  if ( i < numModeButtons ) {
    if ( currentModeButton )
      currentModeButton->setColor( Color(128,128,128) );
    currentModeButton = modeButtonBackground[i];
    currentModeButton->setColor( Color(255,0,0) );
    if(modeButtonForeground[i]->isRectangle())
    {
      if (i == 0) 
      {
        currentMode = SELECT;
        cout << "switch to select mode" << endl; 
        return;
      }else{
        currentMode = RECTANGLE;
        cout << "switch to rectangle mode" << endl;
      }
    }else{
      currentMode = CIRCLE;
      cout << "switch to circle mode" << endl;
    }
  }
}

void drawWindow()
{
  // clear the buffer
  glClear(GL_COLOR_BUFFER_BIT);

  // draw the color buttons
  for (int i = 0; i < numColorButtons; ++i)
  {
    colorButtonBackground[i]->draw();
    colorButtonForeground[i]->draw();
  }

  //draw the mode buttons
  for (int i = 0; i < numModeButtons; ++i)
  {
    modeButtonBackground[i]->draw();
    modeButtonForeground[i]->draw();
  }

  //draw the array of shapes
  for (int i = 0; i < numUserShapes; ++i)
  {
    userShape[i]->draw();
  }

  // tell the graphics card that we're done-- go ahead and draw!
  //   (technically, we are switching between two color buffers...)
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
    case 'c': // switch to circle mode
    case 'C':
      if (currentMode == CIRCLE)
      {
        break;
      }
      currentMode = CIRCLE;
      cout << "switch to circle mode" << endl;
      break;
    case 'r': // switch to rectangle mode
    case 'R':
      if (currentMode == RECTANGLE)
      {
        break;
      }
      currentMode = RECTANGLE;
      cout << "switch to rectangle mode" << endl;
      break;
    case 'S':
    case 's':
      if (currentMode == SELECT)
      {
        break;
      }
      currentMode = SELECT;
      cout << "switch to select mode" << endl;
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
   WIDTH = w;  HEIGHT = h;
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0., WIDTH-1, HEIGHT-1, 0., -1.0, 1.0);
}

// the mouse function is called when a mouse button is pressed down or released
void mouse(int button, int state, int x, int y)
{
  if ( GLUT_LEFT_BUTTON == button ) {
    if ( GLUT_DOWN == state ) {
      mouseIsDragging = true;
      // the user just pressed down on the mouse draw a shape
      if (currentMode == CIRCLE)
      {
        handleColorButtonPress(x,y);
        handleModeButtonPress(x,y);
        Circle *circ = new Circle();
        userShape[numUserShapes] = circ;
        userShape[numUserShapes]->setPosition(x,y);
        userShape[numUserShapes]->setColor(currentColor);
        numUserShapes++;
      }else{
        handleColorButtonPress(x,y);
        handleModeButtonPress(x,y);
        Rectangle *rect = new Rectangle();
        userShape[numUserShapes] = rect;
        userShape[numUserShapes]->setPosition(x,y);
        userShape[numUserShapes]->setColor(currentColor);
        numUserShapes++;
      }
    } else {
      // the user just let go the mouse update the shape
      if (numUserShapes > 0)
      {
        userShape[numUserShapes - 1]->update(x,y);
      }
      mouseIsDragging = false;
    }
  } else if ( GLUT_RIGHT_BUTTON == button ) {
  }
  glutPostRedisplay();
}

// the mouse_motion function is called when the mouse is being dragged,
//   and gives the current location of the mouse
void mouse_motion(int x,int y)
{
  // the mouse button is pressed, and the mouse is moving, so update the shape
  if (numUserShapes > 0)
  {
    userShape[numUserShapes - 1]->update(x,y);
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
  cout << "Welcome to " << programName << "." << endl;
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
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutMotionFunc(mouse_motion);
  glutMainLoop();
}

int main()
{
  loadColorButtons("colorButtons.txt");
  loadModeButtons("toolButtons.txt");
  init_gl_window();
}
