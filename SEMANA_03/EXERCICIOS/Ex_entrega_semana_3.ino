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


int state_buttonLeft = HIGH;
int state_buttonRight = HIGH;
int buttonLeft = 0;  
std::vector<int> valoresMedidas;
int state_buttonRight2 = 0;
int analogValue = analogRead(LIGHT_SENSOR_PIN);






void setup() {

  // Definindo os leds como output 
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_WHITE, OUTPUT);
  pinMode(BUTTON_LEFT, INPUT_PULLUP);
  pinMode(BUTTON_RIGHT, INPUT_PULLUP);


}



//Nessa funçao rodamos um loop por todo o vetor valores medidas
void botaoDir(){
if (state_buttonRight == LOW){
  for (auto num : valoresMedidas){
        resposta(num);
        delay(100);
    }
  }
}


//Função que grava os valores do sensor de luminosidade
void botaoEsq(){
    if (analogValue > 0 && analogValue < 273 && buttonLeft == LOW) {
    Serial.println(" => 0");
    valoresMedidas.push_back(0);
    } 
    
    else if (analogValue > 273 && analogValue < 546 && buttonLeft == LOW){
    Serial.println(" => 1");
    digitalWrite(LED_GREEN, HIGH);
    valoresMedidas.push_back(1);
    tone(BUZZER, NOTE_E1);
    }

    else if (analogValue > 546 && analogValue < 819 && buttonLeft == LOW ) {
    Serial.println(" => 2");
    tone(BUZZER, NOTE_C2);
    valoresMedidas.push_back(2);
    digitalWrite(LED_BLUE, HIGH);
    }

    else if (analogValue > 819 && analogValue < 1092 && buttonLeft == LOW) {
    Serial.println(" => 3");
    tone(BUZZER, NOTE_G2);
    valoresMedidas.push_back(3);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    }
    
    else if (analogValue > 1092 && analogValue < 1365  && buttonLeft == LOW ) {
    valoresMedidas.push_back(4);
    tone(BUZZER, NOTE_CS4);
    digitalWrite(LED_YELLOW, HIGH);
    }
    
    else if (analogValue > 1365 && analogValue < 1638 && buttonLeft == LOW) {
    tone(BUZZER, NOTE_AS5);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_GREEN, HIGH);
    valoresMedidas.push_back(5);
    }

    else if (analogValue > 1638 && analogValue < 1911 && buttonLeft == LOW) {
    
    tone(BUZZER, NOTE_FS6);
    digitalWrite(LED_YELLOW, HIGH);
    valoresMedidas.push_back(6);
    digitalWrite(LED_BLUE, HIGH);}

    else if (analogValue > 1911 && analogValue < 2184 && buttonLeft == LOW) {
    
    tone(BUZZER, NOTE_DS7);
    digitalWrite(LED_GREEN, HIGH);
    valoresMedidas.push_back(7);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_BLUE, HIGH);}

    else if (analogValue > 2184 && analogValue < 2457 && buttonLeft == LOW) {
    
    tone(BUZZER, NOTE_B4);
    valoresMedidas.push_back(8);
    digitalWrite(LED_WHITE, HIGH);}


    else if (analogValue > 2457 && analogValue < 2730 && buttonLeft == LOW) {
    
    tone(BUZZER, NOTE_AS6);
    digitalWrite(LED_GREEN, HIGH);
    valoresMedidas.push_back(9);
    digitalWrite(LED_WHITE, HIGH);
    }


    else if (analogValue > 2730 && analogValue < 3003 && buttonLeft == LOW) {
    
    tone(BUZZER, NOTE_A5);
    valoresMedidas.push_back(10);
    digitalWrite(LED_BLUE, HIGH);
    digitalWrite(LED_WHITE, HIGH);}


    else if (analogValue > 3003 && analogValue < 3276 && buttonLeft == LOW) {
    
    tone(BUZZER, NOTE_D8);
    valoresMedidas.push_back(11);
    digitalWrite(LED_WHITE, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    digitalWrite(LED_GREEN, HIGH);}

    else if (analogValue > 3276 && analogValue < 3549  && buttonLeft == LOW) {
    
    valoresMedidas.push_back(12);
    tone(BUZZER, NOTE_C8);
    digitalWrite(LED_WHITE, HIGH);
    digitalWrite(LED_YELLOW, HIGH);}


    else if (analogValue > 3549 && analogValue < 3822 && buttonLeft == LOW) {

    valoresMedidas.push_back(13);
    tone(BUZZER, NOTE_FS7);
    digitalWrite(LED_WHITE, HIGH);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    }

    else if (analogValue > 3822 && analogValue <= 4095 && buttonLeft == LOW) {
    tone(BUZZER, NOTE_CS8);
    valoresMedidas.push_back(14);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_WHITE, HIGH);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_BLUE, HIGH);}
        
    }

//Função que define o comportamento de acordo com o numero no led
void resposta (int elemento){
    if (elemento == 0){
        delay(1000);
    }

    else if ( elemento == 1){
    digitalWrite(LED_GREEN, HIGH);
    tone(BUZZER, NOTE_E1);
    delay(1000);
    }

    else if ( elemento == 2){
    tone(BUZZER, NOTE_C2);
    digitalWrite(LED_BLUE, HIGH);
    delay(1000);
    }

    else if ( elemento == 3){
    tone(BUZZER, NOTE_G2);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    delay(1000);
    }

     else if ( elemento == 4){
    digitalWrite(LED_YELLOW, HIGH);
    tone(BUZZER, NOTE_E1);
    delay(1000);
    }

    else if ( elemento == 5){
    tone(BUZZER, NOTE_AS5);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_GREEN, HIGH);
    delay(1000);
    }

    else if ( elemento == 6){
    tone(BUZZER, NOTE_FS6);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    delay(1000);
    }

    else if ( elemento == 7){
    tone(BUZZER, NOTE_DS7);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    delay(1000);
    }

    else if ( elemento == 8){
    tone(BUZZER, NOTE_B4);
    digitalWrite(LED_WHITE, HIGH);
    delay(1000);
    }
    else if ( elemento == 9){
    tone(BUZZER, NOTE_AS6);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_WHITE, HIGH);
      delay(1000);
    }

    else if ( elemento == 10){
    tone(BUZZER, NOTE_A5);
    digitalWrite(LED_BLUE, HIGH);
    digitalWrite(LED_WHITE, HIGH);
      delay(1000);
    }    
    
    else if ( elemento == 11){
    tone(BUZZER, NOTE_D8);
    digitalWrite(LED_WHITE, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    digitalWrite(LED_GREEN, HIGH);
      delay(1000);

    } 
    
    else if ( elemento == 12){
    tone(BUZZER, NOTE_C8);
    digitalWrite(LED_WHITE, HIGH);
    digitalWrite(LED_YELLOW, HIGH);
      delay(1000);
    }    
    
    else if ( elemento == 13){
    tone(BUZZER, NOTE_FS7);
    digitalWrite(LED_WHITE, HIGH);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_BLUE, HIGH);
      delay(1000);
    }    
    
    else if ( elemento == 14){
    tone(BUZZER, NOTE_CS8);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_WHITE, HIGH);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    delay(1000);
    }
}

void loop() {

// Ler o valor do sensor 
int state_buttonLeft = digitalRead(BUTTON_LEFT);
int state_buttonRight = digitalRead(BUTTON_RIGHT);
int analogValue2 = analogRead(LIGHT_SENSOR_PIN);
int analogValue = analogRead(LIGHT_SENSOR_PIN);

// Chamando as funções
botaoDir();
botaoEsq();
}
