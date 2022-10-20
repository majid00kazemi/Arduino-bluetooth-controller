const int relay = 7; 
char msg,cmd;
void setup() {
  // Initialization
  pinMode(relay, OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  Serial.begin(9600); 
  msg = "";
  digitalWrite(led2,HIGH);
  digitalWrite(relay, HIGH); 
}

void loop() {
  int status = digitalRead(relay);
  
  if (Serial.available() > 0){ 
    msg = Serial.read();
  }
  if (msg == '1'){
      digitalWrite(relay, LOW); 
      Serial.print(" Opend\n"); 
      msg = ""; 
  } 
  digitalWrite(relay, HIGH);
}
