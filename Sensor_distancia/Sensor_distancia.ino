const int pino_trigger = D5;
const int pino_echo = D0;
const int pino_motor = D3;
const int pino_botao = D8;

bool podeVibrar = true;
bool botaoPressionadoAnterior = false; 

void setup() {
  Serial.begin(115200);

  // Configuração dos pinos
  pinMode(pino_echo, INPUT);
  pinMode(pino_trigger, OUTPUT);
  pinMode(pino_botao, INPUT); 
  pinMode(pino_motor, OUTPUT);
}

void loop() {
  int statusBotao = digitalRead(pino_botao);

  if (statusBotao == HIGH && !botaoPressionadoAnterior) {
    podeVibrar = !podeVibrar;
    botaoPressionadoAnterior = true;
  } else if (statusBotao == LOW) {
    botaoPressionadoAnterior = false;
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


  if (podeVibrar){
    if (centimetros > 0 && centimetros < 100) {
      digitalWrite(pino_motor, HIGH);
    } else {
      digitalWrite(pino_motor, 0);
    }
  } else {
    digitalWrite(pino_motor, 0);
  }

  delay(300);
}
