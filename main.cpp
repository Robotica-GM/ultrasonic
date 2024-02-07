const int trigPin = 5;
const int echoPin = 6;
long duration;
float distanceCm;
float distanceInch;
unsigned long currentTime = millis();
unsigned long previousTime = 0;
const long timeoutTime = 2000;
String distanciaCm;

#define SOUND_SPEED 0.034

void setup() {
  Serial.begin(115200);      
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
}


void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * SOUND_SPEED/2;

  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  
  delay(1000);
}