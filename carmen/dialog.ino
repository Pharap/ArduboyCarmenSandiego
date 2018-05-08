#include "utilities.h"

const char msgAbout[] PROGMEM = "Programmed by Erwin Ried. Inspired by Carmen Sandiego by Broderbund.";

void doMessageBox(const char msg[])
{
  arduboy.clear();
  arduboy.print(msg);
  arduboy.display();

  delay(400);
  while (arduboy.pressed(B_BUTTON))
    while (arduboy.notPressed(B_BUTTON));
  while (arduboy.pressed(B_BUTTON));
}

void doMessageBox(const __FlashStringHelper * msg)
{
  arduboy.clear();
  arduboy.print(msg);
  arduboy.display();

  delay(400);
  while (arduboy.pressed(B_BUTTON))
    while (arduboy.notPressed(B_BUTTON));
  while (arduboy.pressed(B_BUTTON));
}