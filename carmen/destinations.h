#include "utilities.h"

struct Place
{
  const char * Name;
  const char * Subject;
};

const Place places[] =
{
  {"Library", "Librarian"},
  {"Store", "Cashier"},
  {"Museum", "Guard"},
  {"Art gallery", "Curator"},
  {"Embassy", "Secretary"},
  {"Newspaper", "Reporter"},
  {"Minimarket", "Shopper"},
  {"Bank", "Investor"},
  {"Currency exchange", "Cashier"},
  {"Travel agency", "Representative"},
  {"Municipality", "Secretary"},
};

const byte TOTAL_PLACES = ArrayLength(places);

const char noclue_1[] PROGMEM = "I haven't seen anybody with that description";
const char noclue_2[] PROGMEM = "No idea, sorry";
const char noclue_3[] PROGMEM = "No clue about that, sorry";
const char * noclue[] ={  noclue_1, noclue_2, noclue_3, };

struct Destination
{
  const char * Name;
  const char * Country;
  byte X;
  byte Y;
  const char * Description;
  const char * Flag;
  const char * Language;
  const char * Currency;
  const char * HintWanted;
  const char * HintLooking;
  const char * HintResearching;
  const char * HintReading;
};

const Destination destinations[] =
{
  {"Tokyo", 97, 35},
  {"Vienna", 54, 14},
  {"Barcelona", 52, 17},
  {"Tromso", 56, 7},
  {"Paris", 52, 13},
};

const byte TOTAL_DESTINATIONS = ArrayLength(destinations);

const bool connections[][20] PROGMEM  = {
  {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,},
  {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,},
  {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,},
  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0,},
  {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,},
  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,},
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0,},
  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0,},
  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,},
  {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0,},
  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1,},
  {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,},
  {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,},
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,},
  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,},
  {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,},
  {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,},
  {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,},
};

