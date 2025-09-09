/*
  Simple Electronic Piano for Arduino
  Inspired by https://www.instructables.com/Simple-Electronic-Piano/
*/

const int numKeys = 7;
const int buttonPins[numKeys] = {2, 3, 4, 5, 6, 7, 8}; // change as needed
const int buzzerPin = 9;

// C-major scale frequencies (C D E F G A B)
const int notes[numKeys] = {262, 294, 330, 349, 392, 440, 494};

void setup() {
  for (int i = 0; i < numKeys; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < numKeys; i++) {
    if (digitalRead(buttonPins[i]) == LOW) { // button pressed
      tone(buzzerPin, notes[i]);
      delay(200); // debounce and play note
      noTone(buzzerPin);
    }
  }
}