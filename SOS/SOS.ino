
const uint8_t SELECTED_PIN = D1;
const uint8_t BUTTON_PIN = D2;

unsigned long pressStart = 0;
bool isPressed = false;
String morseCode = "";
String data = "Orest";

void setup() {
  pinMode(SELECTED_PIN, OUTPUT);  // Initialize the LED_BUILTIN pin as an output
   pinMode(BUTTON_PIN, INPUT_PULLUP);  // Ініціалізуємо кнопку як вхід з підтягувальним резистором
}

void LED_D(uint8_t PIN_N) {
  digitalWrite(PIN_N, HIGH);  // Turn the LED on
  delay(250);              // Short delay for dot
  digitalWrite(PIN_N, LOW);   // Turn the LED off
  delay(250);  
}

void LED_L(uint8_t PIN_N) {
  digitalWrite(PIN_N, HIGH);  // Turn the LED on
  delay(750);              // Long delay for dash
  digitalWrite(PIN_N, LOW);   // Turn the LED off
  delay(250); 
}

void stringToMorse(String data, uint8_t PIN_N){
  delay(500);  // Small pause before starting the Morse code
  data.toUpperCase();
  for (int i = 0; i < data.length(); i++) {
    switch (data.charAt(i)) {
      case 'A':
        LED_D(PIN_N);  // dot
        LED_L(PIN_N);  // dash
        break;
      case 'B':
        LED_L(PIN_N);  // dash
        LED_D(PIN_N);  // dot
        LED_D(PIN_N);  // dot
        LED_D(PIN_N);  // dot
        break;
      case 'C':
        LED_L(PIN_N);  // dash
        LED_D(PIN_N);  // dot
        LED_L(PIN_N);  // dash
        LED_D(PIN_N);  // dot
        break;
      case 'D':
        LED_L(PIN_N);  // dash
        LED_D(PIN_N);  // dot
        LED_D(PIN_N);  // dot
        break;
      case 'E':
        LED_D(PIN_N);  // dot
        break;
      case 'F':
        LED_D(PIN_N);  // dot
        LED_D(PIN_N);  // dot
        LED_L(PIN_N);  // dash
        LED_D(PIN_N);  // dot
        break;
      case 'G':
        LED_L(PIN_N);  // dash
        LED_L(PIN_N);  // dash
        LED_D(PIN_N);  // dot
        break;
      case 'H':
        LED_D(PIN_N);  // dot
        LED_D(PIN_N);  // dot
        LED_D(PIN_N);  // dot
        LED_D(PIN_N);  // dot
        break;
      case 'I':
        LED_D(PIN_N);  // dot
        LED_D(PIN_N);  // dot
        break;
      case 'J':
        LED_D(PIN_N);  // dot
        LED_L(PIN_N);  // dash
        LED_L(PIN_N);  // dash
        LED_L(PIN_N);  // dash
        break;
      case 'K':
        LED_L(PIN_N);  // dash
        LED_D(PIN_N);  // dot
        LED_L(PIN_N);  // dash
        break;
      case 'L':
        LED_D(PIN_N);  // dot
        LED_L(PIN_N);  // dash
        LED_D(PIN_N);  // dot
        LED_D(PIN_N);  // dot
        break;
      case 'M':
        LED_L(PIN_N);  // dash
        LED_L(PIN_N);  // dash
        break;
      case 'N':
        LED_L(PIN_N);  // dash
        LED_D(PIN_N);  // dot
        break;
      case 'O':
        LED_L(PIN_N);  // dash
        LED_L(PIN_N);  // dash
        LED_L(PIN_N);  // dash
        break;
      case 'P':
        LED_D(PIN_N);  // dot
        LED_L(PIN_N);  // dash
        LED_L(PIN_N);  // dash
        LED_D(PIN_N);  // dot
        break;
      case 'Q':
        LED_L(PIN_N);  // dash
        LED_L(PIN_N);  // dash
        LED_D(PIN_N);  // dot
        LED_L(PIN_N);  // dash
        break;
      case 'R':
        LED_D(PIN_N);  // dot
        LED_L(PIN_N);  // dash
        LED_D(PIN_N);  // dot
        break;
      case 'S':
        LED_D(PIN_N);  // dot
        LED_D(PIN_N);  // dot
        LED_D(PIN_N);  // dot
        break;
      case 'T':
        LED_L(PIN_N);  // dash
        break;
      case 'U':
        LED_D(PIN_N);  // dot
        LED_D(PIN_N);  // dot
        LED_L(PIN_N);  // dash
        break;
      case 'V':
        LED_D(PIN_N);  // dot
        LED_D(PIN_N);  // dot
        LED_D(PIN_N);  // dot
        LED_L(PIN_N);  // dash
        break;
      case 'W':
        LED_D(PIN_N);  // dot
        LED_L(PIN_N);  // dash
        LED_L(PIN_N);  // dash
        break;
      case 'X':
        LED_L(PIN_N);  // dash
        LED_D(PIN_N);  // dot
        LED_D(PIN_N);  // dot
        LED_L(PIN_N);  // dash
        break;
      case 'Y':
        LED_L(PIN_N);  // dash
        LED_D(PIN_N);  // dot
        LED_L(PIN_N);  // dash
        LED_L(PIN_N);  // dash
        break;
      case 'Z':
        LED_L(PIN_N);  // dash
        LED_L(PIN_N);  // dash
        LED_D(PIN_N);  // dot
        LED_D(PIN_N);  // dot
        break;
      default:
        delay(500);
    }
    delay(500);  // Small delay between letters
  }
}












void loop() {
  // Read morse code


  stringToMorse(data, SELECTED_PIN);
  if (digitalRead(BUTTON_PIN) == LOW && !isPressed) {
    pressStart = millis();  // Початок натискання
    isPressed = true;
  }
  if (digitalRead(BUTTON_PIN) == HIGH && isPressed) {
    unsigned long pressDuration = millis() - pressStart;
    isPressed = false;
  }
}
