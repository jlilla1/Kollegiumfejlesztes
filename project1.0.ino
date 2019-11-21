





struct tulaj{
  char nev[30];
  char nept[7];
  byte vdb;
};

struct vendeg{
  char nev[30];
  char nept[7];
  int tulaj;
};

struct LED{
  byte ledPin;
  byte buttonPin;
};
const LED myLed[] ={{10,6},{11,7},{12,8},{13,9}};

tulaj T[]={{"Janoki Lilla","G4O424",0},{"Ori Viktoria","KH12Q2",0},{"Soos Brigitta","T42LZ8",0},{"Pap Martin Felician","GW1EP3",0}};
vendeg V[12]={{"Gipsz Jakab","AAAAAA",0},{"John Doe","BBBBBB",0},{"Valaki Valami","CCCCCC",0},{"Michael Jackson","DDDDDD",2},{"Selena Gomez","EEEEEE",3},{"Palvin Barbara","FFFFFF",3}};
byte buttonState = 0; 
byte n = 10;
void setup() {
  Serial.begin(9600);
  for(byte i =0; i<4; i++){
    pinMode(myLed[i].buttonPin, INPUT );
    pinMode (myLed[i].ledPin,OUTPUT );
  }

  for(byte i =0; i<12; i++){
    if(T[V[i].tulaj].vdb < 3){
      T[V[i].tulaj].vdb = T[V[i].tulaj].vdb+1;
    }
  }
}

void loop() {
  for(byte i =0; i<4; i++){
     buttonState = digitalRead(myLed[i].buttonPin);
    if(buttonState == HIGH){
      digitalWrite(myLed[i].ledPin,HIGH); 
      switch(i){
        case 0:
          n = random(4);
          Serial.print( T[n].nev);
          Serial.print(";");
          Serial.print( T[n].nept);
          Serial.print(";");
          Serial.print( "tulaj");
          Serial.print( "\n");
          delay(2000);
          break;
        case 2:
          n = random(6);
          Serial.print( V[n].nev);
          Serial.print(";");
          Serial.print( V[n].nept);
          Serial.print(";");
          Serial.print( T[V[n].tulaj].nev);
          Serial.print( "\n");
          delay(2000);
          break;
        case 1:
          Serial.print("idegen");
          Serial.print(";");
          Serial.print("idegen");
          Serial.print(";");
          Serial.print("idegen");
          Serial.print( "\n");
          delay(2000);
          break;
      }
      
      
    }else{
      digitalWrite(myLed[i].ledPin,LOW);
    }    
  }
}
