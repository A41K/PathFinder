int BUT1 = D0;
int BUT2 = D1;
int BUT3 = D2;

int LED1 = D3;
int LED2 = D4;
int LED3 = D5;

void setup() {
pinMode(BUT1, INPUT_PULLUP);
pinMode(BUT2, INPUT_PULLUP);
pinMode(BUT3, INPUT_PULLUP);
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
long startTime = millis();
}

#define DOT_DURATION 100 
#define DASH_DURATION (3 * DOT_DURATION)
#define ELEMENT_GAP DOT_DURATION
#define LETTER_GAP (3 * DOT_DURATION)
#define WORD_GAP (7 * DOT_DURATION)

const char* morse_code[] = {
  ".-",   // A
  "-...", // B
  "-.-.", // C
  "-..",  // D
  ".",    // E
  "..-.", // F
  "--.",  // G
  "....", // H
  "..",   // I
  ".---", // J
  "-.- ", // K
  ".-..", // L
  "--",   // M
  "-.",   // N
  "---",  // O
  ".--.", // P
  "--.- ",// Q
  ".-.",  // R
  "...",  // S
  "-",    // T
  "..-",  // U
  "...-", // V
  ".--",  // W
  "-..-", // X
  "-.--", // Y
  "--.."  // Z
};

void morse_flash(int ledPin, const char* message) {
  for (int i = 0; message[i] != '\0'; i++) {
    char c = message[i];
    if (c == '.') {
      digitalWrite(ledPin, HIGH);
      delay(DOT_DURATION);
      digitalWrite(ledPin, LOW);
    } else if (c == '-') {
      digitalWrite(ledPin, HIGH);
      delay(DASH_DURATION);
      digitalWrite(ledPin, LOW);
    } else if (c == ' ') {
      delay(WORD_GAP - ELEMENT_GAP); 
    }
    if (message[i+1] != '\0' && message[i] != ' ') {
      delay(ELEMENT_GAP);
    }
  }
}

void loop() {
long but1time;
long but2time;
long but3time = 0;
}

if (digitalRead(BUT1) == LOW) { 
    morse_flash(LED1, "... --- ..."); // SOS
    delay(500); 
  }

  if (digitalRead(BUT2) == LOW) {
    morse_flash(LED2, ".--. .- - .... ..-. .. -. -.. . .-."); // PATHFINDER
    delay(500);
  }

  if (digitalRead(BUT3) == LOW) {
    morse_flash(LED3, "- . ... - "); // TEST
    delay(500);
  }