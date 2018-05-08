#include "utilities.h"
enum class GameState : unsigned char
{
  CaseSetup, // Case initialization, random villain and place
  CaseIntro,
  CaseMenu,
  CaseDepart,
  CaseInvestigate,
  CaseInterpol,
  GameMenu,
  GameSplash,
  GameIntro,
  GameAbout,
};

// Based on: https://github.com/Pharap/EquipmentMenuSystem by Pharap
struct MenuOption
{
  const char * Text;
};

struct Menu
{
  const char * Title;
  const MenuOption * Options;
  uint8_t OptionsLength;
};

// Case Menu
const char CaseMenuTitle[] PROGMEM = "What to do?";
const char CaseMenuOption1[] PROGMEM = "Depart by plane";
const char CaseMenuOption2[] PROGMEM = "Investigate";
const char CaseMenuOption3[] PROGMEM = "Visit Interpol";

const MenuOption CaseMenuOptions[] PROGMEM =
{
  { CaseMenuOption1 },
  { CaseMenuOption2 },
  { CaseMenuOption3 },
};

const Menu CaseMenu =
{
  CaseMenuTitle,
  CaseMenuOptions,
  ArrayLength(CaseMenuOptions)
};

// Main Menu
const char MainMenuTitle[] PROGMEM = "Welcome";
const char MainMenuOption1[] PROGMEM = "New game";
const char MainMenuOption2[] PROGMEM = "Sound ON/OFF";
const char MainMenuOption3[] PROGMEM = "About";

const MenuOption MainMenuOptions[] PROGMEM =
{
  { MainMenuOption1 },
  { MainMenuOption2 },
  { MainMenuOption3 },
};

const Menu MainMenu =
{
  MainMenuTitle,
  MainMenuOptions,
  ArrayLength(MainMenuOptions)
};

