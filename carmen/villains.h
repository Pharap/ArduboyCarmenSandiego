#include "utilities.h"

struct Artifact
{
  const char * Name;
  const char * StolenFrom;
};

const Artifact artifacts[] PROGMEM = {
  {"Golden Arduboy", "Arduboy Inc"},
  {"Limited Edition Arduboy","bateske's vault"},
  {"Silver Cistern", "Palace of Jaipur"},
  {"The Giuseppe Violin", "Venice museum"},
  {"Diamond Panther Bracelet", "ambassador Mombasa"},
  //{"Birds of America Book", "New York's museum"},
  //{"Salvator Mundi paint", "Abu Dhabi cultural house"},
  {"The Cards Players paint", "State of Qatar"},
  {"Number 17A paint", "an eccentric millionaire"},
  {"a Rembrandt", "Rijksmuseum"},
  {"a Picasso", "Louvre"},
  {"The first spiderman comic", "A collectors house"},
  {"a triple Klein bottle", "Cliff Stoll's house"},
  {"a custom HP41", "Isene's collection"},
  {"The Pythagoras Cup", "Poliakoff's desk"},
};

const byte TOTAL_ARTIFACTS = ArrayLength(artifacts);

struct Villain
{
  const char * Name;
  const bool Male;
  const byte Hair;
  const byte Vehicle;
  const byte Feature;
  const byte Hobby;
};

const Villain villains[] PROGMEM = {
  {"Carmen SanDiego", 0, 0, 0, 1, 0,},
  {"Merey LaRoc", 0, 0, 1, 1, 1,},
  {"Dazzle Annie Nonker", 0, 2, 1, 0, 0,},
  {"Lady Agatha Wayland", 0, 1, 0, 1, 0,},
  {"Katherine Drib", 0, 0, 1, 0, 1,},
  {"Simon Holmes", 1, 0, 2, 2, 2,},
  {"Celine Bins", 0, 1, 2, 2, 1,},
  {"Felipe Manga", 1, 0, 0, 2, 1,},
  {"Pharap Skull", 1, 2, 0, 0, 1,},
  {"Kevin Bates", 1, 3, 2, 2, 2,},
  //{"Erwin Ried", 1, 0, 1, 2, 2,},
  {"Mariana Burr", 0, 0, 1, 1, 2,},
  {"Simon Filmote", 1, 3, 2, 0, 1,},
  //{"Blinky The Phantom", 1, 3, 0, 2, 0,},
};

const byte TOTAL_VILLAINS = ArrayLength(villains);

