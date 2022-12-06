
#include <Arduino.h>
#include <WiFi.h>
#include <Firebase_ESP_Client.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

//Dados do wifi
#define WIFI_SSID "SHARE-RESIDENTE"
#define WIFI_PASSWORD "Share@residente"

// CHAVE DA API DO FIREBASE
#define API_KEY "AIzaSyBGxOrXcXZ4pH42Weyum2ek9tWVztP0WyE"

// LINK PARA INSERIR NA PLANILHA EM TEMPO REAL */
#define DATABASE_URL "https://crudjsfb-d5cb2-default-rtdb.firebaseio.com/" 

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int intValue;
float floatValue;
bool signupOK = false;
//Connectando 4 leds e um buzzer na placa
const int idle1 = 9;
const int idle2 = 17;
const int win = 12;
const int loss = 15;
const int buzzer = 45;




void setup() {
  Serial.begin(115200);
  //Definindo os leds como saida 
  pinMode(idle1, OUTPUT);
  pinMode(idle2, OUTPUT);
  pinMode(win, OUTPUT);
  pinMode(loss, OUTPUT);
  pinMode(buzzer, OUTPUT);

  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("ok");
    signupOK = true;
  }
  else {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

//Função que recebe o numero do firebasea
int receiveInputs(){
    if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();
    if (Firebase.RTDB.getInt(&fbdo, "/Data/estate")) {
      if (fbdo.dataType() == "int") {
        intValue = fbdo.intData();
        Serial.println(intValue);
      }
    }
    else {
      Serial.println(fbdo.errorReason());
    }
    
  }
  return intValue;
}

//Função de feedback quando ganhar o jogo
void playerWins(){
    digitalWrite(win, HIGH);
    tone(buzzer, 442, 879);
    delay(250);
    digitalWrite(win, LOW);
    noTone(buzzer);

}

//Função de feedback quando perde o jogo
void playerLoss(){
  digitalWrite(loss, HIGH);
  tone(buzzer, 189, 753);
  delay(250);
  digitalWrite(loss, LOW);
  noTone(buzzer);
}

//Função de feedback quando o esp está esperando o resultado do jogo
void playerIdle(){
  noTone(buzzer);
  digitalWrite(idle1, HIGH);
  digitalWrite(idle2, HIGH);
  delay(200);
  digitalWrite(idle1, LOW);
  digitalWrite(idle2, LOW);

}



void loop() {
    int actualStatus = receiveInputs();
    //Aqui nessa variavel pegamos a requisição do servidor web e comparamos com as condicionais
    //Neste caso significa que o jogador perdeu o jogo 
    if (actualStatus == 0) {
        Serial.println("Lost the game");
        playerLoss();
        delay(100);
        
    } 

    //Neste caso significa que o jogador ganhou o jogo

    if (actualStatus == 1){
        Serial.println("You win");
        playerWins();
        delay(100);
    }

    //Aqui o jogo fica no estado padrão aguardando vitoria ou derrota

    if (actualStatus == 3 ){
     Serial.println("Idle");
     playerIdle();
     delay(100);

    } 
    delay(250);
    
}
