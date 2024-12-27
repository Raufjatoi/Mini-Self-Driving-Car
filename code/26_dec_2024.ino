int pin1 = 11;  
int pin2 = 12; 
int pin3 = 9;   
int pin4 = 10;  

void setup() {
  Serial.begin(9600);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
}

void loop() {

  digitalWrite(pin1, HIGH);  
  digitalWrite(pin2, HIGH); 
  digitalWrite(pin3, HIGH);  
  digitalWrite(pin4, HIGH);   
}