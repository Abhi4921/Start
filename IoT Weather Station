#include <LiquidCrystal.h>
#include <DHT.h>
#include <Keypad.h>

#define DHTPIN A0
#define DHTTYPE DHT11
#define LED_PIN 6
#define BUZZER_PIN 7

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
DHT dht(DHTPIN, DHTTYPE);

// --- Keypad Setup ---
const byte ROWS = 3; // Only 3 rows used
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'}
};
byte rowPins[ROWS] = {A1,A2,A3};    // R1 → A5, R2 → D8, R3 → D9
byte colPins[COLS] = {A5,8,9};  // C1 → D10, C2 → A1, C3 → A2

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
String password = "12";
String entered = "";

bool buzzerEnabled = true;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  dht.begin();
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("'C");

  lcd.setCursor(0, 1);
  lcd.print("Humid: ");
  lcd.print(h);
  lcd.print("%");

  // LED and Buzzer Logic
  if (t <= 26) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, LOW);
    buzzerEnabled = true;  // Reset buzzerEnabled each cycle
  } else {
    digitalWrite(LED_PIN, LOW);
    if (buzzerEnabled) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(200);
      digitalWrite(BUZZER_PIN, LOW);
      delay(200);
    }
  }

  // Keypad Logic
  char key = keypad.getKey();
  if (key) {
    entered += key;
    Serial.print("Key pressed: ");
    Serial.println(key);

    if (entered.length() == password.length()) {
      if (entered == password) {
        buzzerEnabled = false; // disable buzzer
        Serial.println("Correct password!");
      } else {
        Serial.println("Wrong password.");
      }
      entered = ""; // reset
    }
  }

  delay(500); // Wait a bit before next loop
}
