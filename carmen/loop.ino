char caseMenuSelection = 0, caseDepartSelection = 0, mainMenuSelection = 0, caseInvestigateSelection = 0;
bool color = BLACK;

// Total captured villains
byte getCurrentLevel()
{
  byte v = 0;
  for (byte i = 0; i < TOTAL_VILLAINS; i++)
    if (captured[i])
      v++;

  return v;
}
/*
char * computerDayHour(byte hours)
{
  String s;

  switch ((hours / 24) % 7)
  {
    case 0: s += "MON"; break;
    case 1: s += "TUE"; break;
    case 2: s += "WED"; break;
    case 3: s += "THU"; break;
    case 4: s += "FRI"; break;
    case 5: s += "SAT"; break;
    case 6: s += "SUN"; break;
  }

  s += " ";
  byte h = hours % 24;

  if (h > 12)
  {
    s += h - 12;
    s += "PM";
  }
  else
  {
    s += h;
    s += "AM";
  }
  return s.c_str();
}
*/

void loop()
{
  if (!arduboy.nextFrame())
    return;

  // If needs to sleep...


  arduboy.pollButtons();

  switch (gameState)
  {
    case GameState::CaseSetup:

      // Select villain
      if (getCurrentLevel() < TOTAL_VILLAINS) // Not the boss
      {
        do
        {
          currentVillain = random(1, TOTAL_VILLAINS);
        } while (captured[currentVillain]);
      }
      else
      {
        // Final search
        currentVillain = 0;
      }

      // Select place
      do
      {
        currentPlace = 0;
        investigate[0] = random(0, TOTAL_PLACES);
      } while (visited[currentPlace]);

      //visited[currentPlace] = true;

      // Select next place
      remainingPlaces = 5; // To capture the villain

      byte p, c[5];
      
      DEBUG_PRINTLN(F("Next case is: "));
      for (int place = 1; place < remainingPlaces; place++)
      {
        p = 0;
        for (int i = 0; i < TOTAL_DESTINATIONS; i++)
        {
          if (pgm_read_byte(&connections[0] + investigate[place - 1] * TOTAL_DESTINATIONS + i))
            c[p++] = i;
        }

        // Select next place
        investigate[place] = c[random(0, p)];
        DEBUG_PRINT(investigate[place]);
        DEBUG_PRINT(" ");
      }

      //nextPlace = 1; // Id of the new place (random in the connections)
      // setup investigate[] array to the places to investigate
      caseInvestigateSelection = 0;
      caseDepartSelection = 0;
      elapsedHours = 9; //6 * 24 + 8;
      stolenPiece = random(0,TOTAL_ARTIFACTS);

      gameState = GameState::CaseIntro;

      break;

    case GameState::CaseIntro:
      {
        //String s = "Hello, the";
        //s += AsFlashStringHelper(pgm_read_word(&artifacts[stolenPiece].Name));
        //s += " was stolen from ";
        //s += AsFlashStringHelper(pgm_read_word(&artifacts[stolenPiece].StolenFrom));;
        //doMessageBox(s.c_str(), false);
		
        doMessageBox(F("Hello, the"));
        gameState = GameState::CaseMenu;
      }
      break;

    case GameState::CaseMenu:
      switch (drawMenu(CaseMenu, caseMenuSelection))
      {
        case 0: gameState = GameState::CaseDepart; break;
        case 1: gameState = GameState::CaseInvestigate; break;
        case 2: gameState = GameState::CaseInterpol; break;
        case CANCEL: gameState = GameState::CaseIntro; break;
      }
      break;

    case GameState::CaseInvestigate:
      arduboy.clear();

      // Draw the 3 places
      for (byte i = 0; i < 3; i++)
        arduboy.print(places[i].Name);

      if (arduboy.justPressed(DOWN_BUTTON) || arduboy.justPressed(LEFT_BUTTON))
        caseInvestigateSelection++;
      if (arduboy.justPressed(UP_BUTTON) || arduboy.justPressed(RIGHT_BUTTON))
        caseInvestigateSelection--;

      if (arduboy.justPressed(B_BUTTON))
        gameState = GameState::CaseMenu;

      if (arduboy.justPressed(A_BUTTON))
      {
        doMessageBox(F("hint 1"));
        gameState = GameState::CaseMenu;
      }
      arduboy.display();

      break;

    case GameState::CaseInterpol:
      arduboy.clear();

      arduboy.print("Interpol");

      if (arduboy.justPressed(DOWN_BUTTON) || arduboy.justPressed(LEFT_BUTTON))
        caseInvestigateSelection++;
      if (arduboy.justPressed(UP_BUTTON) || arduboy.justPressed(RIGHT_BUTTON))
        caseInvestigateSelection--;

      if (arduboy.justPressed(B_BUTTON))
        gameState = GameState::CaseMenu;

      if (arduboy.justPressed(A_BUTTON))
        gameState = GameState::CaseMenu;
      arduboy.display();
      break;

    case GameState::CaseDepart:
      arduboy.clear();
      arduboy.drawCompressed(0, 0, world);

      if (arduboy.justPressed(DOWN_BUTTON) || arduboy.justPressed(LEFT_BUTTON))
        caseDepartSelection++;
      if (arduboy.justPressed(UP_BUTTON) || arduboy.justPressed(RIGHT_BUTTON))
        caseDepartSelection--;

      if (arduboy.everyXFrames(10))
        color = !color;

      {
        int x = destinations[caseDepartSelection].X, y = destinations[caseDepartSelection].Y;
        arduboy.fillCircle(x - 2, y - 2, 3, color);
        arduboy.fillCircle(x - 2 , y - 2, 2, !color);
        x += 6;
        //y += 6;

        if (x > WIDTH / 2)
          x -= 12;

        if (y > HEIGHT / 2)
          y -= 20;

        arduboy.setCursor(x, y);
        arduboy.print(destinations[caseDepartSelection].Name);
      }

      if (arduboy.justPressed(A_BUTTON))
      {
        // Switch country if correct

        gameState = GameState::CaseMenu;
      }

      if (arduboy.justPressed(B_BUTTON))
        gameState = GameState::CaseMenu;

      arduboy.display();
      break;

    case GameState::GameMenu:
      switch (drawMenu(MainMenu, mainMenuSelection))
      {
        case 0: gameState = GameState::CaseSetup; break;
        case 1: arduboy.audio.toggle(); arduboy.audio.saveOnOff(); break;
        case 2: doMessageBox(AsFlashStringHelper(msgAbout)); break;
        case CANCEL: gameState = GameState::GameSplash; break;
      }
      break;

    case GameState::GameIntro:
      gameState = GameState::CaseIntro;
      break;

    case GameState::GameSplash:
      arduboy.clear();
      if (!tunes.playing())
        tunes.playScore(intro);

      arduboy.drawCompressed(0, 0, carmen_title);

      if (arduboy.justPressed(A_BUTTON))
        gameState = GameState::GameMenu;

      arduboy.display();
      break;

    default:
      DEBUG_PRINT("PLAYING, NEXT STATE: ");
      DEBUG_PRINT((int)gameState);
      break;
  }

  // HUD with place and time
  /*tinyfont.setCursor(20, 0);
  tinyfont.print(computerDayHour(elapsedHours));
  arduboy.display();*/
}


