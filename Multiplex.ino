const byte cathodes[] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 14, 15};
const byte anodes[] = {11, 12, 13, 23, 22, 21, 20, 19, 18, 17};

const int latchPin = 2;
const int clockPin = 3;
const int dataPin = 4;

void shiftOut3(unsigned long val) {
  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, MSBFIRST, (val & 0xFF0000) >> 16);
  shiftOut(dataPin, clockPin, MSBFIRST, (val & 0x00FF00) >> 8);
  shiftOut(dataPin, clockPin, MSBFIRST, (val & 0x0000FF));

  digitalWrite(latchPin, HIGH);
}

static int col = 0;

ISR(TIMER1_COMPA_vect) { //timer1 interrupt
  unsigned long val = 0;

  val += 1UL << cathodes[col++];
  if (col > sizeof(cathodes))
    col = 0;

  //THe old (2015) electronics was multiplexed by rows, the new one is by columns
  //In order to keep the old wordlock code portable, the multiplex code ended up a little bit twisty :(
  for (int row = 0; row < sizeof(anodes); row++) {
    if ((leds[row] >> (col - 1)) & 0x01)
      val += 1UL << anodes[row];
  }

  shiftOut3(val);
}

void MultiPlex_Init(void) {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  digitalWrite(latchPin, LOW);
  digitalWrite(clockPin, LOW);
  digitalWrite(dataPin, LOW);

  //http://www.8bit-era.cz/arduino-timer-interrupts-calculator.html
  // TIMER 1 for interrupt frequency 800 Hz:
  cli(); // stop interrupts
  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B
  TCNT1  = 0; // initialize counter value to 0
  // set compare match register for 800 Hz increments
  OCR1A = 19999; // = 16000000 / (1 * 800) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12, CS11 and CS10 bits for 1 prescaler
  TCCR1B |= (0 << CS12) | (0 << CS11) | (1 << CS10);
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei(); // allow interrupts

  memset(leds, 0, sizeof(leds));

  sei();//allow interrupts
}
