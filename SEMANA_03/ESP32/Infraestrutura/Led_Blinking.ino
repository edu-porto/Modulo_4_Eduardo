void setup()
{
  //Define a porta do led como saida
  pinMode(11, OUTPUT);
  pinMode(21, OUTPUT);
}
  
void loop()
{
  //Acende o led
  digitalWrite(11, HIGH);
  digitalWrite(21, HIGH);
    
  //Aguarda intervalo de tempo em milissegundos
  
  delay(500);
  digitalWrite(21, LOW);
  //Apaga o led
  delay(1000);
  digitalWrite(11, LOW);
    
  //Aguarda intervalo de tempo em milissegundos
  delay(1000);
}
