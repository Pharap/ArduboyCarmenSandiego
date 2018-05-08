const char msgAbout[] PROGMEM = "Programmed by Erwin Ried. Inspired by Carmen Sandiego by Broderbund.";

void doMessageBox(char msg[], bool fromProgmem = true)
{
  arduboy.clear();
  if (fromProgmem)
    arduboy.print(AsFlashStringHelper(msg));
  else
    arduboy.print(msg);
  arduboy.display();

  delay(400);
  while (arduboy.pressed(B_BUTTON))
    while (arduboy.notPressed(B_BUTTON));
  while (arduboy.pressed(B_BUTTON));
}
