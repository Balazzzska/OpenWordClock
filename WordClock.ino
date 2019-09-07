//#define ENGLISH
#define HUNGARIAN



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

  ShowTime(seconsdssicemidnight);
}

int period = 30 * 1000; //update every 30 sec
unsigned long lastmillis = 0;
void loop() {
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
