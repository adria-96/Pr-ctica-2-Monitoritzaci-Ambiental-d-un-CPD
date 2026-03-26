const int pinLM35 = 2;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Lectura del sensor LM35...");
}

void loop() {
  int valorADC = analogRead(pinLM35);

  // Convertir a voltatge (0 - 3.3V)
  float voltatge = valorADC * (3.3 / 4095.0);

  // Convertir a temperatura (LM35: 10mV = 1ºC)
  float temperatura = voltatge * 100;

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  delay(2000); // Espera 2 segons
}
