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
  {"Birds of America Book", "New York's museum"},
  {"Salvator Mundi paint", "Abu Dhabi cultural house"},
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
  {"Erwin Ried", 1, 0, 1, 2, 2,},
  {"Mariana Burr", 0, 0, 1, 1, 2,},
  {"Simon Filmote", 1, 3, 2, 0, 1,},
  {"Blinky The Phantom", 1, 3, 0, 2, 0,},
};

const byte TOTAL_VILLAINS = ArrayLength(villains);

/*
  hair
  Brown
  Red
  Blond
  Black
*/

const char hair0_1[] PROGMEM = "had brown hair";
const char hair0_2[] PROGMEM = "had hair between black and red";
const char hair0_3[] PROGMEM = "had dark color hair";
const char * hair0[] = {  hair0_1, hair0_2, hair0_3, };

const char hair1_1[] PROGMEM = "had red hair";
const char hair1_2[] PROGMEM = "was redhead";
const char hair1_3[] PROGMEM = "was carrottop";
const char * hair1[] = {  hair1_1, hair1_2, hair1_3, };

const char hair2_1[] PROGMEM = "had blond hair";
const char hair2_2[] PROGMEM = "was fair haired";
const char hair2_3[] PROGMEM = "had bright color hair";
const char * hair2[] = {  hair2_1, hair2_2, hair2_3, };

const char hair3_1[] PROGMEM = "had black hair";
const char hair3_2[] PROGMEM = "had a really dark brown hair";
const char hair3_3[] PROGMEM = "had dark color hair";
const char * hair3[] = {  hair3_1, hair3_2, hair3_3, };

/*
  vehicle
  Convertible
  Limousine
  Bike
*/

const char vehicle0_1[] PROGMEM = "was driving a convertible";
const char vehicle0_2[] PROGMEM = "had a nice sporty car";
const char vehicle0_3[] PROGMEM = "had issues with the car because the rain";
const char * vehicle0[] = {  vehicle0_1, vehicle0_2, vehicle0_3, };

const char vehicle1_1[] PROGMEM = "had a chauffeur";
const char vehicle1_2[] PROGMEM = "was riding in a limousine";
const char vehicle1_3[] PROGMEM = "arrived in a limo";
const char * vehicle1[] = {  vehicle1_1, vehicle1_2, vehicle1_3, };

const char vehicle2_1[] PROGMEM = "was riding a bike";
const char vehicle2_2[] PROGMEM = "seem to use a bike";
const char vehicle2_3[] PROGMEM = "rided a bike";
const char * vehicle2[] = {  vehicle2_1, vehicle2_2, vehicle2_3, };

/*
  feature
  Tattoo
  Jewelry
  Arduboy
*/

const char feature0_1[] PROGMEM = "had an ugly tattoo";
const char feature0_2[] PROGMEM = "had ink on skin";
const char feature0_3[] PROGMEM = "had a tattoo";
const char * feature0[] = {  feature0_1, feature0_2, feature0_3, };

const char feature1_1[] PROGMEM = "had an expensive ring";
const char feature1_2[] PROGMEM = "was wearing a big collar";
const char feature1_3[] PROGMEM = "had special jewelry";
const char * feature1[] = {  feature1_1, feature1_2, feature1_3, };

const char feature2_1[] PROGMEM = "had an awesome tiny device";
const char feature2_2[] PROGMEM = "was playing Arduboy";
const char feature2_3[] PROGMEM = "loved retro and programmable devices";
const char * feature2[] = {  feature2_1, feature2_2, feature2_3, };

/*
  hobby
  Tennis
  Mountain climbing
  Travelling
*/

const char hobby0_1[] PROGMEM = "complained about pain in the arm";
const char hobby0_2[] PROGMEM = "had a sore elbow";
const char hobby0_3[] PROGMEM = "was practicing his backhand";
const char * hobby0[] = {  hobby0_1, hobby0_2, hobby0_3, };

const char hobby1_1[] PROGMEM = "bragged about dangerous sports";
const char hobby1_2[] PROGMEM = "bought boots and carabiners";
const char hobby1_3[] PROGMEM = "had a wind burnt face";
const char * hobby1[] = {  hobby1_1, hobby1_2, hobby1_3, };

const char hobby2_1[] PROGMEM = "was talking about travelling";
const char hobby2_2[] PROGMEM = "checked travel brochures";
const char hobby2_3[] PROGMEM = "talked about so many places";
const char * hobby2[] = {  hobby2_1, hobby2_2, hobby2_3, };
