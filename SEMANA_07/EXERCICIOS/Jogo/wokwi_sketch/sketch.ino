const int idle1 = 9;
const int idle2 = 17;
const int win = 12;
const int loss = 15;
const int buzzer = 45;


void setup() {
  Serial.begin(115200);
  pinMode(idle1, OUTPUT);
  pinMode(idle2, OUTPUT);
  pinMode(win, OUTPUT);
  pinMode(loss, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  delay(10); 
  digitalWrite(idle1, HIGH);
  digitalWrite(idle2, HIGH);
  digitalWrite(loss, HIGH);
  digitalWrite(win, HIGH);
  tone(buzzer, 442, 800);

}
