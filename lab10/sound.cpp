#include<iostream>
#include<vector>
using namespace std;
#include "fmod.hpp"
#include "fmod_errors.h"
#include "wincompat.h"
#include <stdio.h>

bool USE_SOUND = true;                  // whether to include sound
FMOD::System     *soundSystem;          // the sound player
FMOD::Channel *channel0=0,*channel1=0;  // sound channels (independent)

FMOD_RESULT       result;
int               key;
unsigned int      version;

// the ERRCHECK function is for printing an error, if needed
void ERRCHECK(FMOD_RESULT result)
{
  if (result != FMOD_OK) { cerr << "FMOD error! (" << result << ") " << FMOD_ErrorString(result) << endl; exit(-1); }
}

// the init_sound_system should be called just once, at the beginning
//   of your program.  You don't have to load the sounds here though...
//   you could wait, since loading sound effects can take awhile.
void init_sound_system()
{
  if (USE_SOUND) {
    // Create a System object and initialize.
    result = FMOD::System_Create(&soundSystem); ERRCHECK(result);
    result = soundSystem->getVersion(&version); ERRCHECK(result);
    if (version < FMOD_VERSION) {
      cerr << "Error!  You are using an old version of FMOD " << version << ".  This program requires " << FMOD_VERSION << endl;
      getch();
    }
    result = soundSystem->init(32, FMOD_INIT_NORMAL, 0); ERRCHECK(result);
  }
}

vector<FMOD::Sound *> allLoadedSounds;
FMOD::Sound *loadSoundFile(const char *filename)
{
  FMOD::Sound *snd=0;
  if (USE_SOUND) {
    result = soundSystem->createSound(filename, FMOD_LOOP_NORMAL, 0, &snd); ERRCHECK(result);
    // the LoopCount says how many times the sound should repeat.  Set this
    //   value to -1 if you want it to repeat indefinitely.
    result = snd->setLoopCount(0); ERRCHECK(result);
    // store this sound in a global vector, so that we can remove it at the end
    allLoadedSounds.push_back(snd);
  }
  return snd;
}

void playSound(FMOD::Sound *snd, int channel)
{
  if ( 0 == channel )
    soundSystem->playSound(FMOD_CHANNEL_FREE, snd, FALSE, &channel0);
  else
    soundSystem->playSound(FMOD_CHANNEL_FREE, snd, FALSE, &channel1);
}

void setPaused(int channel, bool t)
{
  if ( 0 == channel ) channel0->setPaused(t);
  else channel1->setPaused(t);
}

void soundoff()
{
  if (USE_SOUND) { // Shut down
    for ( unsigned i=0,i_end=allLoadedSounds.size(); i<i_end; ++i ) {
      result = allLoadedSounds[i]->release(); ERRCHECK(result);
    }
    result = soundSystem->close(); ERRCHECK(result);
    result = soundSystem->release(); ERRCHECK(result);
  }
}
