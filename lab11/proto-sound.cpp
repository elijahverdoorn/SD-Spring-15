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
#include "sound.h"

int WIDTH = 500;  // width of the user window
int HEIGHT = 400;  // height of the user window
char programName[] = "proto-sound";

// Sound files
FMOD::Sound *explode, *land, *music;

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
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
      // turn off the sound system
      soundoff();
      // get rid of the window (as part of shutting down)
      glutDestroyWindow(win);
      exit(0);
      break;
    case 'e':
      // play one of the sounds, on channel zero
      if ( USE_SOUND ) playSound(explode, 0);
      break;
    case 'l':
      // play another sound, on channel one.  Note that you can play both
      //    sounds at the same time, since they are on different channels.
      if ( USE_SOUND ) playSound(land, 1);
      break;
    case 'p':
      // pause the current sound on channel zero and channel one
      if ( USE_SOUND ) {
        setPaused(0, true);
        setPaused(1, true);
        setPaused(2, true);
      }
      break;
    case 'P':
      // unpause the current sound on channel zero and channel one
      if ( USE_SOUND ) {
        setPaused(0, false);
        setPaused(1, false);
        setPaused(2, false);
      }
      break;
      case 'm':
        if (USE_SOUND)
        {
           playSound(music, 2);
        }
    default:
      break;
  }
}

// the init function sets up the graphics card to draw properly
void init(void)
{
  // clear the window to black
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // welcome message
  cout << "Welcome to " << programName << ".  Press e | l | m to trigger sound effects." << endl;
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
  glutInitDisplayMode( GLUT_RGB );
  glutInitWindowSize(WIDTH,HEIGHT);
  glutInitWindowPosition(100,100);
  glutCreateWindow(programName);
  init();

  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
}

int main()
{
  init_sound_system();
  explode = loadSoundFile("explosion.wav");
  land = loadSoundFile("eglanded.wav");
  music = loadSoundFile("music.wav");
  init_gl_window();
}
