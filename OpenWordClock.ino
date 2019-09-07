
#define ENGLISH
//#define HUNGARIAN

unsigned int leds[10];
unsigned long seconsdssicemidnight = 0;

void ShowTime(unsigned int sec) {
#if defined( ENGLISH )
  ShowTime_Eng(sec);
#elif defined( HUNGARIAN )
  ShowTime_Hun(sec);
#endif
}

void ClearWords(void) {
  memset(leds, 0, sizeof(leds));
}

void setup() {
  Serial.begin(9600);

  MultiPlex_Init();
  seconsdssicemidnight = 0;

  //ShowTime(seconsdssicemidnight);

  leds[1] = 0b00000000000;
  leds[1] = 0b00000000000;
  leds[2] = 0b00110001100;
  leds[3] = 0b00110001100;
  leds[4] = 0b00000100000;
  leds[5] = 0b00000100000;
  leds[6] = 0b01000000010;
  leds[7] = 0b00100000100;
  leds[8] = 0b00011111000;
  leds[9] = 0b00000000000;
}

int period = 30 * 1000; //update every 30 sec
unsigned long lastmillis = 0;
void loop() {
  return;
  
  if (millis() - lastmillis > period) {
    lastmillis = millis();
    seconsdssicemidnight += period / 1000;

    if (seconsdssicemidnight >= 43200)
      seconsdssicemidnight -= 43200;

    ShowTime(seconsdssicemidnight);
  }

  if (Serial.available()) {
    String asd = Serial.readStringUntil('\n');
    seconsdssicemidnight = asd.toInt();
    ShowTime(seconsdssicemidnight);
  }
}
