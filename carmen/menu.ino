byte drawMenu(const Menu & menu, char & selected)
{
  arduboy.clear();
  arduboy.println(AsFlashStringHelper(menu.Title));

  for (byte i = 0; i < menu.OptionsLength; i++)
  {
    arduboy.print(selected == i ? ">" : " ");
    arduboy.println(AsFlashStringHelper(pgm_read_word(&menu.Options[i].Text)));
  }

  if (selected < 0)
    selected = menu.OptionsLength - 1;
  else if (selected > menu.OptionsLength - 1)
    selected = 0;

  if (arduboy.justPressed(UP_BUTTON))
    selected--;

  if (arduboy.justPressed(DOWN_BUTTON))
    selected++;

  byte output = menu.OptionsLength;

  if (arduboy.justPressed(B_BUTTON))
    output = CANCEL;

  if (arduboy.justPressed(A_BUTTON))
    output = selected;

  arduboy.display();
  return output;
}

