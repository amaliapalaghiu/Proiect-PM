#define smoke A2
#define humidity A0
#define pump 13

// threshold values
#define smokeThreshold 700
#define humidityThreshold 300

int smokeSensor;
int humiditySensor;

void setup() {
  pinMode(smoke, INPUT);
  pinMode(humidity, INPUT);
  pinMode(pump, OUTPUT);
  digitalWrite(pump, HIGH);
  Serial.begin(9600);
}

void printer() {
  Serial.print("[Gas level: ");
  Serial.print(smokeSensor);
  Serial.print("] [Humidity level: ");
  Serial.print(humiditySensor);
  Serial.print("]");
}

void loop() {
    smokeSensor = analogRead(smoke);
    humiditySensor = analogRead(humidity);
    
    if (humiditySensor > humidityThreshold) {
      digitalWrite(pump, HIGH);
      printer();
      Serial.println("[Pump OFF]");
    } else if (smokeSensor > smokeThreshold) {
      digitalWrite(pump, LOW);
      printer();
      Serial.println("[PUMP ON]"); 
    } else {
      printer();
      Serial.println("");
    }
    
    delay(2000);
}
