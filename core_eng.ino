
//Old (2015) code ported from MikroPascal
const int WORD_IT        [] = {0x0003, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};
const int WORD_IS_       [] = {0x0018, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};
const int WORD_HALF      [] = {0x03C0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};
const int WORD_QUARTER   [] = {0x0000, 0x007F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};
const int WORD_TEN_      [] = {0x0000, 0x0700, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};
const int WORD_TWENTY    [] = {0x0000, 0x0000, 0x003F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};
const int WORD_FIVE_     [] = {0x0000, 0x0000, 0x0780, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};
const int WORD_MINUTES   [] = {0x0000, 0x0000, 0x0000, 0x007F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};
const int WORD_TO__      [] = {0x0000, 0x0000, 0x0000, 0x0600, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};
const int WORD_PAST      [] = {0x0000, 0x0000, 0x0000, 0x0000, 0x000F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};
const int WORD_ONE       [] = {0x0000, 0x0000, 0x0000, 0x0000, 0x00E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};
const int WORD_TWO       [] = {0x0000, 0x0000, 0x0000, 0x0000, 0x0700, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};
const int WORD_THREE     [] = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001F, 0x0000, 0x0000, 0x0000, 0x0000};
const int WORD_FOUR      [] = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0780, 0x0000, 0x0000, 0x0000, 0x0000};
const int WORD_FIVE      [] = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x000F, 0x0000, 0x0000, 0x0000};
const int WORD_SIX       [] = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x00E0, 0x0000, 0x0000, 0x0000};
const int WORD_SEVEN     [] = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001F, 0x0000, 0x0000};
const int WORD_EIGHT     [] = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001F, 0x0000};
const int WORD_NINE      [] = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x000F};
const int WORD_TEN       [] = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0700, 0x0000, 0x0000, 0x0000};
const int WORD_ELEVEN    [] = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07E0, 0x0000, 0x0000};
const int WORD_TWELVE    [] = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07E0, 0x0000};
const int WORD_OCLOCK    [] = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07E0};

//I T _ I S _ H A L F _
//Q U A R T E R _ T E N
//T W E N T Y _ F I V E
//M I N U T E S _ _ T O
//P A S T _ O N E|T W O
//T H R E E _ _ F O U R
//F I V E _ S I X|T E N
//S E V E N|E L E V E N
//E I G H T|T W E L V E
//N I N E _ O C L O C K

static void AddWord(const int wordtoadd []) {
  for (int i = 0; i < 10; i++)
    leds[i] |= wordtoadd[i];
}

void ShowTime_Eng(unsigned int sec) {
  ClearWords();
  
  byte hour = sec / 3600;
  sec = sec - hour * 3600;
  byte min = sec / 60;

  AddWord(WORD_IT);
  AddWord(WORD_IS_);
  //***************************
  if (min < 5)
  {
    switch (hour) {
      case 0    : AddWord(WORD_TWELVE);  break;
      case 12   : AddWord(WORD_TWELVE);  break;
      case 1    : AddWord(WORD_ONE);     break;
      case 2    : AddWord(WORD_TWO);     break;
      case 3    : AddWord(WORD_THREE);   break;
      case 4    : AddWord(WORD_FOUR);    break;
      case 5    : AddWord(WORD_FIVE);    break;
      case 6    : AddWord(WORD_SIX);     break;
      case 7    : AddWord(WORD_SEVEN);   break;
      case 8    : AddWord(WORD_EIGHT);   break;
      case 9    : AddWord(WORD_NINE);    break;
      case 10   : AddWord(WORD_TEN);     break;
      case 11   : AddWord(WORD_ELEVEN);  break;
    }
    AddWord(WORD_OCLOCK);
  }
  //***************************
  if ((min > 4) && (min < 35))
  {
    //"It is FIVE minutes past "
    if ((min > 4)  && (min < 10))
    {
      AddWord(WORD_FIVE_);
      AddWord(WORD_MINUTES);
    }

    //"It is TEN MINUTES past "
    if ((min > 9)  && (min < 15))
    {
      AddWord(WORD_TEN_);
      AddWord(WORD_MINUTES);
    }

    //"It is QUARTER past "
    if ((min > 14) && (min < 20))
      AddWord(WORD_QUARTER);

    //"It is TWENTY MINUTES past "
    if ((min > 19) && (min < 25))
    {
      AddWord(WORD_TWENTY);
      AddWord(WORD_MINUTES);
    }

    //"It is TWENTY FIVE MINUTES past "
    if ((min > 24) && (min < 30))
    {
      AddWord(WORD_TWENTY);
      AddWord(WORD_FIVE_);
      AddWord(WORD_MINUTES);
    }

    //"It is HALF past "
    if ((min > 29) && (min < 35))
      AddWord(WORD_HALF);

    AddWord(WORD_PAST);
    switch (hour) {
      case 0    : AddWord(WORD_TWELVE);  break;
      case 12   : AddWord(WORD_TWELVE);  break;

      case 1    : AddWord(WORD_ONE);     break;
      case 2    : AddWord(WORD_TWO);     break;
      case 3    : AddWord(WORD_THREE);   break;
      case 4    : AddWord(WORD_FOUR);    break;
      case 5    : AddWord(WORD_FIVE);    break;
      case 6    : AddWord(WORD_SIX);     break;
      case 7    : AddWord(WORD_SEVEN);   break;
      case 8    : AddWord(WORD_EIGHT);   break;
      case 9    : AddWord(WORD_NINE);    break;
      case 10   : AddWord(WORD_TEN);     break;
      case 11   : AddWord(WORD_ELEVEN);  break;
    }
  }
  //***************************
  if (min > 34)
  {
    //"It is TWENTY FIVE minutes to "
    if ((min > 34) && (min < 40) )
    {
      AddWord(WORD_TWENTY);
      AddWord(WORD_FIVE_);
      AddWord(WORD_MINUTES);
    }
    //"It is TWENTY  minutes to "
    if ((min > 39) && (min < 45))
    {
      AddWord(WORD_TWENTY);
      AddWord(WORD_MINUTES);
    }
    //"It is QUARTER to "
    if ((min > 44) && (min < 50))
      AddWord(WORD_QUARTER);

    //"It is TEN minutes to "
    if ((min > 49) && (min < 55))
    {
      AddWord(WORD_TEN_);
      AddWord(WORD_MINUTES);
    }
    //"It is FIVE minutes to "
    if (min > 54)
    {
      AddWord(WORD_FIVE_);
      AddWord(WORD_MINUTES);
    }

    AddWord(WORD_TO__);
    switch (hour) {
      case  11   : AddWord(WORD_TWELVE);  break;
      case  0    : AddWord(WORD_ONE);     break;
      case  12   : AddWord(WORD_ONE);     break;
      case  1    : AddWord(WORD_TWO);     break;
      case  2    : AddWord(WORD_THREE);   break;
      case  3    : AddWord(WORD_FOUR);    break;
      case  4    : AddWord(WORD_FIVE);    break;
      case  5    : AddWord(WORD_SIX);     break;
      case  6    : AddWord(WORD_SEVEN);   break;
      case  7    : AddWord(WORD_EIGHT);   break;
      case  8    : AddWord(WORD_NINE);    break;
      case  9    : AddWord(WORD_TEN);     break;
      case  10   : AddWord(WORD_ELEVEN);  break;
    }
  }
}
