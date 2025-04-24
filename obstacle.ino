const int trigPin = 9;   
const int echoPin = 10;  
const int buzzerPin = 8; 
const int threshold = 50; 
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  long duration;
  int distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance > 0 && distance <= threshold) {
    digitalWrite(buzzerPin, HIGH); // Activate buzzer
  } else {
    digitalWrite(buzzerPin, LOW);  // Deactivate buzzer
  }
  delay(200);
}


