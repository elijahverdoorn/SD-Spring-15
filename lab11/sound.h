#ifndef _SOUND_
#define _SOUND_
#include "fmod.hpp"
#include "fmod_errors.h"
#include "wincompat.h"

extern bool USE_SOUND;

void init_sound_system();
FMOD::Sound *loadSoundFile(const char *filename);
void playSound(FMOD::Sound *, int channel);
void setPaused(int channel, bool t);
void soundoff();

#endif // _SOUND_
