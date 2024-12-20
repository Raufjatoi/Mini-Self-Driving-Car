int lfp = 11; // left forward pin (white)
int lbp = 12; // left backward pin (blue)
int rfp = 9;  // right forward pin (green)
int rbp = 10; // right backward pin (yellow)
int lsp = 6;  // left motor speed pin (white)
int rsp = 5;  // right motor speed pin (orange)
const int tp = 8; // trigger pin (black)
const int ep = 7; // echo pin (green)

long dis; // distance
long cm;  // centimeter

void setup() {
  Serial.begin(9600);
  pinMode(tp, OUTPUT);
  pinMode(ep, INPUT);
  pinMode(lfp, OUTPUT);
  pinMode(lbp, OUTPUT);
  pinMode(rfp, OUTPUT);
  pinMode(rbp, OUTPUT);
  pinMode(lsp, OUTPUT);
  pinMode(rsp, OUTPUT);
}

void forward(int ls, int rs) { // Move forward
  analogWrite(lsp, ls);
  analogWrite(rsp, rs);
  digitalWrite(lfp, HIGH);
  digitalWrite(lbp, LOW);
  digitalWrite(rfp, HIGH);
  digitalWrite(rbp, LOW);
}

void stop() { // Stop motors
  digitalWrite(lfp, LOW);
  digitalWrite(lbp, LOW);
  digitalWrite(rfp, LOW);
  digitalWrite(rbp, LOW);
}

void loop() {
  // Measure distance using the ultrasonic sensor
  digitalWrite(tp, LOW);
  delayMicroseconds(2);
  digitalWrite(tp, HIGH);
  delayMicroseconds(10);
  digitalWrite(tp, LOW);

  dis = pulseIn(ep, HIGH);
  cm = dis / 58;

  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.println(" cm");

  if (cm > 0 && cm <= 15) { // If an object is within 15 cm
    Serial.println("Obstacle detected! Stopping.");
    stop(); // Stop the robot
  } else {
    Serial.println("Path clear. Moving forward.");
    forward(200, 200); // Move forward
  }

  delay(100); // Small delay to avoid too frequent updates
}
