const int Trigger = 13;  // Pin D13 para Trigger
const int Echo = 12;     // Pin D12 para Echo

void setup() {
  Serial.begin(9600);           // Iniciar comunicación serial
  pinMode(Trigger, OUTPUT);     // Configurar D13 como salida
  pinMode(Echo, INPUT);         // Configurar D12 como entrada
}

void loop() {
  long t;  // Tiempo que demora en llegar el eco
  long d;  // Distancia en centímetros

  // Generar pulso en Trigger
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);        // Pulso de 10 microsegundos
  digitalWrite(Trigger, LOW);

  // Medir duración del pulso recibido en Echo
  t = pulseIn(Echo, HIGH);      // Obtener el ancho del pulso
  d = t / 59;                   // Convertir el tiempo a distancia en cm

  // Mostrar la distancia en el monitor serial
  Serial.print("Distancia: ");
  Serial.print(d);             
  Serial.println(" cm");

  delay(100);                   // Pausa de 100 ms
}
