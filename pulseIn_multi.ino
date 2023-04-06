const int trigPin = 9;
const int echoPin = 10;
const int LED = 6;
const int BUZZER = 11;
const int BUTTON = 7;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON, INPUT);
	Serial.begin(9600);  
}

void loop() {
  if(digitalRead(BUTTON) == HIGH)
  {
  digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW); 
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);

  if (distance < 20) {
    digitalWrite(LED, HIGH);
    tone(BUZZER, 255);
  }
  else {
    digitalWrite(LED, LOW);
    noTone(BUZZER);
  }
  }
  else {}
}