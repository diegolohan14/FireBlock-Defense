#include <ESP32Servo.h>
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL2jWUfpH9G"
#define BLYNK_TEMPLATE_NAME "Fire"
#include <BlynkSimpleEsp32.h>

char auth[] = "A0f7k8dgzyjD0GPMiFOVRK8xyndVmyJw";
char ssid[] = "Nome da Rede";
char pass[] = "Senha da Rede";

Servo servoMotor;
BlynkTimer timer;

// Definição dos pinos
const int KY028_AO = 34;    // KY-028 saída analógica
const int MQ7_AO   = 33;    // MQ-7 saída analógica
const int BUZZER_PIN = 15;  // Buzzer
const int SERVO_PIN  = 27;  // Servo Motor

void sendSensorData() {
  // Leitura analógica dos sensores
  int leituraTemp = analogRead(KY028_AO);  // 0 a 4095
  int leituraGas  = analogRead(MQ7_AO);    // 0 a 4095

  // Conversão aproximada da temperatura
  float temperaturaC = (leituraTemp * 3.3 / 4095.0) * 100.0;

  // Enviar dados ao Blynk
  Blynk.virtualWrite(V0, temperaturaC); // ky-028
  Blynk.virtualWrite(V2, leituraGas);   // MQ-7 

  // Exibir no monitor serial
  Serial.print("Temperatura (°C): ");
  Serial.print(temperaturaC);
  Serial.print(" | Gás ): ");
  Serial.println(leituraGas);

  // Verificar condições de alarme
  if (temperaturaC > 50 || leituraGas > 400) {
    digitalWrite(BUZZER_PIN, HIGH);
    servoMotor.write(90);
    Blynk.virtualWrite(V1, 90);
    Serial.println("Alarme e Garra ativado");
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    servoMotor.write(0);
    Blynk.virtualWrite(V1, 0);
    Serial.println("Alarme e Garra desativado");
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);
  servoMotor.attach(SERVO_PIN);

  Serial.println("conectando ao blink");
  Blynk.begin(auth, ssid, pass);

  // Atualiza leitura a cada 3 segundos
  timer.setInterval(3000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}

// Conexão com Blynk
BLYNK_CONNECTED() {
  Serial.println("conectado ao blynk");
}

// Controle manual do buzzer (V3)
BLYNK_WRITE(V3) {
  int estado = param.asInt();
  digitalWrite(BUZZER_PIN, estado);
}

// Controle manual do servo (V1)
BLYNK_WRITE(V1) {
  int angulo = param.asInt();
  servoMotor.write(angulo);
}