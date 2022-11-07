#include "pitches.h"
#include <vector>
using namespace std;
#define LIGHT_SENSOR_PIN 2 
#define BUZZER 48
#define LED_GREEN 14
#define LED_BLUE 13
#define LED_YELLOW 12
#define LED_WHITE 11
#define BUTTON_LEFT 16
#define BUTTON_RIGHT 18


int state_buttonLeft = 0;
int state_buttonRight = 0;
int buttonLeft = 0;  
vector<int> valoresMedidas;





void setup() {

  // Definindo os leds como output 
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_WHITE, OUTPUT);
  pinMode(BUTTON_LEFT, INPUT_PULLUP);
  pinMode(BUTTON_RIGHT, INPUT_PULLUP);


}

void sensor(int analogValue)

if (analogValue > 0 && analogValue < 273 && buttonLeft == LOW) {
    Serial.println(" => 0");
    valoresMedidas.push_back(0);
  } else if (analogValue > 273 && analogValue < 546 && buttonLeft == LOW){
    Serial.println(" => 1");
    digitalWrite(LED_GREEN, HIGH);
    valoresMedidas.push_back(1);
    tone(BUZZER, NOTE_E1);}
    else if (analogValue > 546 && analogValue < 819 && buttonLeft == LOW ) {
    Serial.println(" => 2");
    tone(BUZZER, NOTE_C2);
    valoresMedidas.push_back(2);

    digitalWrite(LED_BLUE, HIGH);}
    else if (analogValue > 819 && analogValue < 1092 && buttonLeft == LOW) {
    Serial.println(" => 3");
    tone(BUZZER, NOTE_G2);
    //valoresMedidas.push_back(3);

    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_BLUE, HIGH);}
    else if (analogValue > 1092 && analogValue < 1365  && buttonLeft == LOW ) {
    Serial.println(" => 4");
    tone(BUZZER, NOTE_CS4);
    //valoresMedidas.push_back(4);
    digitalWrite(LED_YELLOW, HIGH);}
    
    else if (analogValue > 1365 && analogValue < 1638 && buttonLeft == LOW) {
    Serial.println(" => 5");
    buttonLeft = 6;
    tone(BUZZER, NOTE_AS5);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_GREEN, HIGH);}
    else if (analogValue > 1638 && analogValue < 1911 && buttonLeft == LOW) {
    Serial.println(" => 6");
    tone(BUZZER, NOTE_FS6);
    digitalWrite(LED_YELLOW, HIGH);
    buttonLeft = 7;
    digitalWrite(LED_BLUE, HIGH);}
    else if (analogValue > 1911 && analogValue < 2184 && buttonLeft == LOW) {
    Serial.println(" => 7");
    tone(BUZZER, NOTE_DS7);
    digitalWrite(LED_GREEN, HIGH);
    buttonLeft = 8;
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_BLUE, HIGH);}
    else if (analogValue > 2184 && analogValue < 2457 && buttonLeft == LOW) {
    Serial.println(" => 8");
    tone(BUZZER, NOTE_B4);
    buttonLeft = 9;
    digitalWrite(LED_WHITE, HIGH);}
    else if (analogValue > 2457 && analogValue < 2730 && buttonLeft == LOW) {
    Serial.println(" => 9");
    tone(BUZZER, NOTE_AS6);
    digitalWrite(LED_GREEN, HIGH);
    buttonLeft = 10;
    digitalWrite(LED_WHITE, HIGH);}
    else if (analogValue > 2730 && analogValue < 3003 && buttonLeft == LOW) {
    Serial.println(" => 10");
    tone(BUZZER, NOTE_A5);
    buttonLeft = 11;
    digitalWrite(LED_BLUE, HIGH);
    digitalWrite(LED_WHITE, HIGH);}
    else if (analogValue > 3003 && analogValue < 3276 && buttonLeft == LOW) {
    Serial.println(" => 11");
    tone(BUZZER, NOTE_D8);
    buttonLeft = 12;
    digitalWrite(LED_WHITE, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    digitalWrite(LED_GREEN, HIGH);}
    else if (analogValue > 3276 && analogValue < 3549  && buttonLeft == LOW) {
    Serial.println(" => 12");
    buttonLeft = 13;
    tone(BUZZER, NOTE_C8);
    digitalWrite(LED_WHITE, HIGH);
    digitalWrite(LED_YELLOW, HIGH);}
    else if (analogValue > 3549 && analogValue < 3822 && buttonLeft == LOW) {
    Serial.println(" => 13");
    buttonLeft = 14;
    tone(BUZZER, NOTE_FS7);
    digitalWrite(LED_WHITE, HIGH);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_BLUE, HIGH);}
    else if (analogValue > 3822 && analogValue <= 4095 && buttonLeft == LOW) {
    Serial.println(" => 14");
    tone(BUZZER, NOTE_CS8);
    //buttonLeft = 15;
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_WHITE, HIGH);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_BLUE, HIGH);}
    
    


  //Após o delay todos os outputs voltam para o estado padrão
  delay(1000);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_WHITE, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_BLUE, LOW);
  noTone(BUZZER);


void botaoDir(){
if (state_buttonRight == LOW){
  for (auto num : nums){
    if (num == 1){
        digitalWrite(LED_WHITE, HIGH);
        delay(100)

    }
    else if ( num == 5){
      digitalWrite(LED_WHITE, HIGH);
      digitalWrite(LED_BLUE, HIGH);
      digitalWrite(LED_GREEN, HIGH);
    }
  }
}
}


sensor(analogValue);

std::vector<int> nums { 1, 2, 3, 4, 5, 6, 7 };

void loop() {

// Ler o valor do sensor 
int state_buttonLeft = digitalRead(BUTTON_LEFT);
int state_buttonRight = digitalRead(BUTTON_RIGHT);
int analogValue2 = analogRead(LIGHT_SENSOR_PIN);
int analogValue = analogRead(LIGHT_SENSOR_PIN);

  // Chamando as funções
  sensor(analogValue);
  botaoDir();
  }

