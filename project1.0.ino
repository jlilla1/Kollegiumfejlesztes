



struct LED{
  byte ledPin;
  byte buttonPin;
};

const LED myLed[] ={{10,6},{11,7},{12,8},{13,9}};

byte buttonState = 0; 

void setup() {
  for(int i =0; i<4; i++){
    pinMode(myLed[i].buttonPin, INPUT );
    pinMode (myLed[i].ledPin,OUTPUT );
  }
}

void loop() {
  for(int i =0; i<4; i++){
     buttonState = digitalRead(myLed[i].buttonPin);
    if(buttonState == HIGH){
      digitalWrite(myLed[i].ledPin,HIGH); 
    }else{
      digitalWrite(myLed[i].ledPin,LOW);
    }
  }
}
