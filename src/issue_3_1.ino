const int pinLM35 = 2;   // Sensor temperatura
const int pinLDR = 4;    // Sensor llum
const int pinLED = 25;     // LED alerta

// Llindars
const float TEMP_LIMIT = 18.0;
const int LDR_LIMIT = 2000; // Ajusta segons proves

void setup() {
  Serial.begin(115200);

  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, LOW);

  Serial.println("Sistema de monitorització iniciat...");
}

void loop() {

  // 🔹 Llegir temperatura
  int valorTemp = analogRead(pinLM35);
  float voltatge = valorTemp * (3.3 / 4095.0);
  float temperatura = voltatge * 100;

  // 🔹 Llegir llum
  int valorLlum = analogRead(pinLDR);

  // 🔴 ALERTA DE TEMPERATURA
  if (temperatura > TEMP_LIMIT) {
    digitalWrite(pinLED, HIGH);
    Serial.println("ALERTA: Sobreescalfament CPD!");
  } else {
    digitalWrite(pinLED, LOW);
  }

  // 💡 ALERTA DE LLUM
  if (valorLlum > LDR_LIMIT) {
    Serial.println("AVÍS: Porta oberta o llum encesa");
  }

  // Mostrar valors (opcional per debug)
  Serial.print("Temp: ");
  Serial.print(temperatura);
  Serial.print(" °C | Llum: ");
  Serial.println(valorLlum);

  delay(2000); // cada 2 segons
}
