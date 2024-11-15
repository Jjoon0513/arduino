#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

// 모터 드라이버 (L9110) 연결 핀들
#define A_1A 3
#define A_1B 2
#define B_1A 5
#define B_1B 4

// 블루투스에서 방향키를 받는 문자
#define UP 'w'
#define DOWN 's'
#define RIGHT 'a'
#define LEFT 'd'

// 방향키를 때었을 때 모두 r을 출력함.
#define RELEASE 'r'

//기타
#define STATUS_LED 13

SoftwareSerial BTSerial(8, 9);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(STATUS_LED, OUTPUT);
  pinMode(A_1A, OUTPUT);
  pinMode(A_1B, OUTPUT);
  pinMode(B_1A, OUTPUT);
  pinMode(B_1B, OUTPUT);

  Serial.begin(38400);
  BTSerial.begin(38400);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.backlight();

  digitalWrite(STATUS_LED, HIGH);
}

// 블루투스에서만 실행
void loop() {
  if (BTSerial.available()) {
    char command = BTSerial.read();
    exc_c(command);
  }
}

// 모터를 삐끼삐끼함:)
void up() {
  digitalWrite(A_1A, HIGH);
  digitalWrite(B_1A, HIGH);
  digitalWrite(A_1B, LOW);
  digitalWrite(B_1B, LOW);
}

void down() {
  digitalWrite(A_1A, LOW);
  digitalWrite(B_1A, LOW);
  digitalWrite(A_1B, HIGH);
  digitalWrite(B_1B, HIGH);
}

void left() {
  digitalWrite(A_1A, HIGH);
  digitalWrite(B_1A, LOW);
  digitalWrite(A_1B, LOW);
  digitalWrite(B_1B, HIGH);
}

void right() {
  digitalWrite(A_1A, LOW);
  digitalWrite(B_1A, HIGH);
  digitalWrite(A_1B, HIGH);
  digitalWrite(B_1B, LOW);
}

void release() {
  digitalWrite(A_1A, LOW);
  digitalWrite(B_1A, LOW);
  digitalWrite(A_1B, LOW);
  digitalWrite(B_1B, LOW);
}

// 방향키를 눌렀을 때 실행할 함수
void exc_c(char command) {
  lcd.clear();
  switch (command) {
    case UP:
      up();
      lcd.print("UP");
      break;
    case DOWN:
      down();
      lcd.print("DOWN");
      break;
    case RIGHT:
      right();
      lcd.print("RIGHT");
      break;
    case LEFT:
      left();
      lcd.print("LEFT");
      break;
    case RELEASE:
      release();
      lcd.print("STOP");
      break;
    default:
      lcd.print("WTFisThat");
      break;
  }
}
