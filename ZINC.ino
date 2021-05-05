#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define A_BTN 2
#define B_BTN 3
#define C_BTN 4
#define D_BTN 5
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

char choices[100];
int total = 0;
int cur = 0;

void redisplay();
void movecursor();

void setup() {
  Serial.begin(9600);
  
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }
  delay(2000);         // wait for initializing
  oled.clearDisplay(); // clear display
  oled.setTextSize(1);          // text size
  oled.setTextColor(WHITE);     // text color

  redisplay();
  //other
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
}

void loop() {
  if (!digitalRead(A_BTN)) { //A PRESSED
    delay(50);
    while (!digitalRead(A_BTN)) {}

    if (cur != total) {
      choices[cur] = 'A';
      movecursor();
    }
    else {
      choices[total++] = 'A';
      cur++;
      redisplay();
    }
    
  }
  if (!digitalRead(B_BTN)) { //B PRESSED
    delay(50);
    while (!digitalRead(B_BTN)) {}
    if (cur != total) {
      choices[cur] = 'B';
      movecursor();
    }
    else {
      choices[total++] = 'B';
      cur++;
      redisplay();
    }
  }
  if (!digitalRead(C_BTN)) { //C PRESSED
    delay(50);
    while (!digitalRead(C_BTN)) {}
    if (cur != total) {
      choices[cur] = 'C';
      movecursor();
    }
    else {
      choices[total++] = 'C';
      cur++;
      redisplay();
    }
  }
  if (!digitalRead(D_BTN)) { //D PRESSED
    delay(50);
    while (!digitalRead(D_BTN)) {}
    if (cur != total) {
      choices[cur] = 'D';
      movecursor();
    }
    else {
      choices[total++] = 'D';
      cur++;
      redisplay();
    }
  }
  if (!digitalRead(6)) { //PREV PRESSED
    delay(50);
    while (!digitalRead(6)) {}
    if (cur >= 1) {
      cur--;
      movecursor();
    }
  }
  if (!digitalRead(7)) { //PREV PRESSED
    delay(50);
    while (!digitalRead(7)) {}
    if (cur < total) {
      cur++;
      movecursor();
    }
    if (cur == total) {
      redisplay();
    }
  }
  
}


void redisplay() {
  oled.clearDisplay();
  oled.setCursor(0, 0);
  for (int i = 0; i < total; i++) {
    oled.print(choices[i]);
    if ( (i+1)%5 == 0 ) {
      oled.print(" ");
    }
    if ( (i+1)%15 == 0 ){
      oled.println();
    }
  }
  oled.display();
}

void movecursor() {
  oled.clearDisplay();
  oled.setCursor(0, 0);
  for (int i = 0; i < cur; i++) {
    oled.print(choices[i]);
    if ( (i+1)%5 == 0 ) {
      oled.print(" ");
    }
    if ( (i+1)%15 == 0 ){
      oled.println();
    }
  }
  oled.setTextColor(BLACK, WHITE);
  oled.print(choices[cur]);
  oled.setTextColor(WHITE, BLACK);
  if ((cur+1)%5 == 0) oled.print(" ");
  if ((cur+1)%15 == 0) oled.println();
  for (int i = cur+1; i < total; i++) {
    oled.print(choices[i]);
    if ( (i+1)%5 == 0 ) {
      oled.print(" ");
    }
    if ( (i+1)%15 == 0 ){
      oled.println();
    }
  }
  oled.display();
}
