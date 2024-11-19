const int pino_trigger = 4;
const int pino_echo = 3;
void setup() {
  Serial.begin(115200);
  // Declaração dos inputs/outputs
  pinMode(pino_echo, INPUT);
  pinMode(pino_trigger, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, INPUT);
  //Verifica o estado do botão
  int botao = digitalRead(6);

}

void loop() {
  int botao = digitalRead(6);
  // Envia e recebe o pulso de ultrasom
  digitalWrite(pino_trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pino_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pino_trigger, LOW);

  long microsegundos = pulseIn(pino_echo, HIGH);
  // calcula o tempo entre os pulsos e retorna a distância dos objetos
  uint8_t centimetros = microsegundos / 29 / 2;
  // Mostra no output 
  Serial.print("Distancia em cm: ");
  Serial.println(centimetros);
  delay(100);
  // Executa o código se o botão estiver ativo
  if (botao == 1){
    //Vibração a partir de 1 metro 
    if (centimetros < 100){
      for (int i = 0; i <3; i++){
        digitalWrite(5,HIGH);
        delay(500);
        digitalWrite(5,LOW);
        delay(2000);
        // condicional de parada se o botão não estiver ativo
        if (botao == 0){
          break;
        }
      }
    }
    // Vibração para distâncias menores que 60cm e maiores que 50cm
    else if (centimetros > 50 and centimetros <60){
      for (int i = 0; i <3; i++){
        digitalWrite(5,HIGH);
        delay(1000);
        digitalWrite(5,LOW);
        delay(1000);
        if (botao == 0){
          break;
        }
      }
    }
    //Vibração para distâncias menores que 50cm e maiores que 30
    else if (centimetros > 30 and centimetros <50){
      for (int i = 0; i <3; i++){
        digitalWrite(5,HIGH);
        delay(2000);
        digitalWrite(5,LOW);
        delay(1000);
        if (botao == 0){
          break;
        }
      }
    }
  }
}
