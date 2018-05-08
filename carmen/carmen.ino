#include <Arduboy2.h>
#include <ArduboyPlaytune.h>
#include "destinations.h"
#include "villains.h"
#include "images.h"
#include "structs.h"
#include "music.h"
#include "Tinyfont.h"

//#define DEBUG
//#define MIRRORING

//Initialize the arduboy object
Arduboy2 arduboy;
ArduboyPlaytune tunes(arduboy.audio.enabled);
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());

// ------ Game parameters -------
// const char STARTINGLEVEL = 0;
// -----------------------------

#define CANCEL 0xFF
//#define TOTAL_VILLAINS 7 // Not including Carmen Sandiego
#define TOTAL_PLACES 20

byte currentVillain, currentPlace, nextPlace, remainingPlaces, elapsedHours;
GameState gameState = GameState::GameSplash;

bool captured[TOTAL_VILLAINS];
bool recovered[TOTAL_ARTIFACTS];
bool visited[TOTAL_PLACES];
byte investigate[3];

void setup()
{
  for (byte i = 0; i < TOTAL_VILLAINS; i++)
    captured[i] = false;

  for (byte i = 0; i < TOTAL_ARTIFACTS; i++)
    recovered[i] = false;

  for (byte i = 0; i < TOTAL_PLACES; i++)
    visited[i] = false;

  arduboy.begin();
  arduboy.setFrameRate(60);
  arduboy.setTextWrap(true);
  arduboy.clear();
  arduboy.initRandomSeed();
  initializeAudio();
}

void initializeAudio()
{
  // audio setup
  tunes.initChannel(PIN_SPEAKER_1);
#ifndef AB_DEVKIT
  // if not a DevKit
  tunes.initChannel(PIN_SPEAKER_2);
#else
  // if it's a DevKit
  tunes.initChannel(PIN_SPEAKER_1); // use the same pin for both channels
  tunes.toneMutesScore(true);       // mute the score when a tone is sounding
#endif
}
