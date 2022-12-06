
#include <Arduino.h>
#include <WiFi.h>
#include <Firebase_ESP_Client.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Insert your network credentials
#define WIFI_SSID "SHARE-RESIDENTE"
#define WIFI_PASSWORD "Share@residente"

// Insert Firebase project API Key
#define API_KEY "AIzaSyBGxOrXcXZ4pH42Weyum2ek9tWVztP0WyE"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://crudjsfb-d5cb2-default-rtdb.firebaseio.com/" 

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int intValue;
float floatValue;
bool signupOK = false;

void setup() {
  Serial.begin(115200);
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
    if (Firebase.ready() || sendDataPrevMillis == 0) {
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

//Nesta função são recebidos os dados do firebase e apartir disso o esp tem uma reação
int espStatus(int x){
    int status = x;

    //Neste caso significa que o jogador perdeu o jogo 
    if (status == 0) {
        Serial.println("Lost the game");
        delay(1000);
    } 

    //Neste caso significa que o jogador ganhou o jogo

    if (status == 1){
        Serial.println("You win");
        delay(1000);
    }

    //Aqui o jogo fica no estado padrão aguardando vitoria ou derrota

    if (status == 3 ){
     Serial.println("Idle");
     delay(1000);

    } 

}


void loop() {
    int actualStatus = receiveInputs();
    delay(100);
    espStatus(actualStatus);
}
