
//Works differently than core_eng
//Upper 5 bits store the row number, lower 11 bits store which leds have to be active in the given row

const unsigned int WORD_FEL         = 0b0000000000001110;
const unsigned int WORD_NEGYED      = 0b0000011111100000;
const unsigned int WORD_HAROMNEGYED = 0b0000111111111111;

const unsigned int WORD_EGY         = 0b0001000011100000;
const unsigned int WORD_KETTO       = 0b0001101111100000;
const unsigned int WORD_HAROM       = 0b0010000001111100;
const unsigned int WORD_NEGY        = 0b0010011110000000;
const unsigned int WORD_OT          = 0b0010000000000011;
const unsigned int WORD_HAT         = 0b0010100000111000;
const unsigned int WORD_HET         = 0b0010100000000111;
const unsigned int WORD_NYOLC       = 0b0010111111000000;
const unsigned int WORD_KILENC      = 0b0011000001111110;
const unsigned int WORD_TIZ         = 0b0001011100000000;
const unsigned int WORD_TIZENEGY    = 0b0001000011111111;
const unsigned int WORD_TIZENKETTO  = 0b0001101111111111;

const unsigned int WORD_ORA         = 0b0011011100000000;
const unsigned int WORD_MULT        = 0b0011100000001111;
const unsigned int WORD_LESZ        = 0b0011100011110000;
const unsigned int WORD_OT_         = 0b0011111000000000;
const unsigned int WORD_TIZ_        = 0b0100000000001110;
const unsigned int WORD_PERC        = 0b0100000011110000;
const unsigned int WORD_PERCCEL     = 0b0100011111110000;
const unsigned int WORD_MULVA       = 0b0100111111000000;

//_ F É L _ N E G Y E D
//H Á R O M N E G Y E D
//T I Z E N:E G Y|T í Z
//T I Z E N:K E T T Ő _
//Ö T|H Á R O M|N É G Y
//H É T|H A T|N Y O L C
//_ K I L E N C _ Ó R A
//M Ú L T|L E S Z _ Ö T
//_ T í Z|P E R C:C E L
//_ _ _ _ _ _ M Ú L V A

static void AddWord(const int wordtoadd) {
  leds[wordtoadd >> 11] = wordtoadd & 0x07FF;
}

void ShowTime_Hun(unsigned int sec) {
  ClearWords();
  
  byte hour = sec / 3600;
  sec = sec - hour * 3600;
  byte min = sec / 60;

  AddWord(WORD_MULVA);
}
