const int pino_trigger = 4;
const int pino_echo = 3;
const int pino_motor = 5;
const int pino_botao = 8;

bool podeVibrar = true;
bool botaoAnterior = false; // Controle de borda

void setup() {
  Serial.begin(115200);

  // Configuração dos pinos
  pinMode(pino_echo, INPUT);
  pinMode(pino_trigger, OUTPUT);
  pinMode(pino_botao, INPUT);
  pinMode(pino_motor, OUTPUT);
}

void loop() {
 
  int statusTouch = digitalRead(pino_botao);

  
  if (statusTouch == HIGH && !botaoAnterior) {
    podeVibrar = !podeVibrar; 
    botaoAnterior = true;     
    delay(50);                
  } else if (statusTouch == LOW) {
    botaoAnterior = false;
  }

  
  digitalWrite(pino_trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pino_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pino_trigger, LOW);

  
  long microsegundos = pulseIn(pino_echo, HIGH);

  
  uint8_t centimetros = microsegundos / 29 / 2;

 
  Serial.print("Distancia em cm: ");
  Serial.println(centimetros);
  Serial.print("Status botão (touch): ");
  Serial.println(statusTouch);

 
  if (podeVibrar) {
    if (centimetros > 0 && centimetros < 100) {
      analogWrite(pino_motor, 255); 
    }
  } else {
    analogWrite(pino_motor, 0); 
  }


  delay(300);
}
