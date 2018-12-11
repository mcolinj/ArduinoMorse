/*
  Morse (limited, but works)

  
*/

/* note, subtract 'a' from letter before lookup */
/* in this array, 'a' maps to 0 index. */
const char *morse_encode[] = {
  ".-",                      /* a */
  "_...",                    /* b */
  "_._.",                    /* c */
  "_..",                     /* d */
  "."                        /* e */
};

/* These represent the standard values
 * for relative duration in Morse code
 */
#define UNIT 100
#define DOT_WIDTH 1*UNIT
#define DASH_WIDTH 3*UNIT
#define BETWEEN_UNITS 1*UNIT
#define BETWEEN_LETTERS 3*UNIT
#define BETWEEN_WORDS 7*UNIT

void play_morse(const char *pattern) {
  for (char *unit = pattern; *unit; unit++) {
    if (*unit == '.') {
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(DOT_WIDTH);                       // wait for a second
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    } else if (*unit == '-') {
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(DASH_WIDTH);                       // wait for a second
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    }
    delay(BETWEEN_UNITS);
  }
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  const char *message = "be a bad bed bead ada";
  for (char *m = message; *m; m++) {
    if (*m == ' ') {
      delay(BETWEEN_WORDS);
    } else {
      /* we may have a real letter, base is 'a' */
      uint8_t e = *m - 'a';
      play_morse(morse_encode[e]);
    }
  }
}
