
#include <SoftwareSerial.h>
SoftwareSerial BTserial(4,2);

const int relay = 7; 
char msg;
char c=' ';
String data;
void setup() {
  // Initialization
  pinMode(relay, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); 
  BTserial.begin(9600);
  msg = "";
  digitalWrite(relay, HIGH); 
}

void loop() {
  int status = digitalRead(relay);
  
  while(BTserial.available()){
    c = BTserial.read();
    if(c != -1){
      data +=c;
      if(c=='\n'){
        break;
      }
      
    }
  }

if (data == "majid00kazemi@gmail.com"){
          digitalWrite(relay, LOW);
          Serial.print(" Opend by majid\n"); 
          BTserial.write("opend bye bye.");
          digitalWrite(LED_BUILTIN, HIGH); 
          data="";
        }
  digitalWrite(relay, HIGH);
  digitalWrite(LED_BUILTIN, LOW); 


    // if (BTserial.available())
  // {  
  //       c = BTserial.read();
  //       Serial.write(c);  
  //       if (c == "majid00kazemi@gmail.com"){
  //         digitalWrite(relay, LOW);
  //         Serial.print(" Opend by majid\n"); 
  //         Serial.println();  
  //         digitalWrite(LED_BUILTIN, HIGH); 
  //       }
  // }
}
