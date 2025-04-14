#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// LCD Setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// RFID Setup
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

// Authorized UIDs and corresponding names
byte authorizedUIDs[][4] = {
  {0xA9, 0x7F, 0x89, 0x54},
  {0x83, 0xAD, 0x2E, 0x36},
  {0x91, 0x5D, 0xA4, 0x7B}
};
const char* authorizedNames[] = {
  "Yashasvi Allen",
  "Arjya Banerjee",
  "Mohammad Izaan"
};
const int authorizedCount = sizeof(authorizedUIDs) / sizeof(authorizedUIDs[0]);

// Pins
#define GREEN_LED 4
#define RED_LED 5
#define BUZZER 6
#define SERVO_PIN 7

Servo gateServo;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Scan a card...");

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  gateServo.attach(SERVO_PIN);
  gateServo.write(0); // Gate closed position
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  bool isAuthorized = false;
  const char* detectedName = nullptr;

  Serial.print("UID tag:");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();

  // Check against each authorized UID
  for (int i = 0; i < authorizedCount; i++) {
    bool match = true;
    for (byte j = 0; j < mfrc522.uid.size; j++) {
      if (mfrc522.uid.uidByte[j] != authorizedUIDs[i][j]) {
        match = false;
        break;
      }
    }
    if (match) {
      isAuthorized = true;
      detectedName = authorizedNames[i];
      break;
    }
  }

  // Beep
  digitalWrite(BUZZER, HIGH);
  delay(100);
  digitalWrite(BUZZER, LOW);

  lcd.clear();
  lcd.setCursor(0, 0);

  if (isAuthorized) {
    lcd.print("Welcome, ");
    lcd.setCursor(0, 1);
    lcd.print(detectedName);

    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    // Open gate
    gateServo.write(90);
    delay(2000);
  } else {
    lcd.print("Access Denied");
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    Serial.println("Access attempt denied.");

    for (int i = 0; i < 3; i++) {
      digitalWrite(BUZZER, HIGH);
      delay(150);
      digitalWrite(BUZZER, LOW);
      delay(175);
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scan a card...");
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  gateServo.write(0);
}
