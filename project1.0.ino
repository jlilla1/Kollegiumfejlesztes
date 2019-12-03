byte motorPin1=13;
byte motorPin2=12;
byte motorPin3=8;
byte motorPin4=6;
byte motorPin5=5;
byte motorPin6=3;

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
const LED myLed[] ={{10,4},{9,2},{11,7}};

tulaj T[]={{"Janoki Lilla","G4O424",0},{"Ori Viktoria","KH12Q2",0},{"Soos Brigitta","T42LZ8",0},{"Pap Martin Felician","GW1EP3",0}};
vendeg V[12]={{"Gipsz Jakab","AAAAAA",0},{"John Doe","BBBBBB",0},{"Valaki Valami","CCCCCC",0},{"Michael Jackson","DDDDDD",2},{"Selena Gomez","EEEEEE",3},{"Palvin Barbara","FFFFFF",3}};
byte buttonState = 0; 
byte n = 10;

void setup() {
  
  Serial.begin(9600);
   Serial.println("CLEARSHEET"); 
   Serial.println("CLEARDATA"); 
   Serial.println("LABEL,Date,Time,Name,Neptun,Jogok");
   
  pinMode(motorPin1,OUTPUT);
  pinMode(motorPin2,OUTPUT);
  pinMode(motorPin3,OUTPUT);
  pinMode(motorPin4,OUTPUT);
  pinMode(motorPin5,OUTPUT);
  pinMode(motorPin6,OUTPUT);
  
  for(byte i =0; i<3; i++){
    pinMode(myLed[i].buttonPin, INPUT );
    pinMode (myLed[i].ledPin,OUTPUT );
  }
  
  for(byte i =0; i<12; i++){
    if(T[V[i].tulaj].vdb < 4){
      T[V[i].tulaj].vdb = T[V[i].tulaj].vdb+1;
    }
  }
  

  Serial.println("RESETTIMER"); 
}

void loop() {
  for(byte i =0; i<3; i++){
     buttonState = digitalRead(myLed[i].buttonPin);
    if(buttonState == HIGH){
      analogWrite(myLed[i].ledPin,255); 
      switch(i){
        case 0:
          n = random(4);
          Serial.print("DATA,DATE,TIME,");
          Serial.print(T[n].nev);
          Serial.print(",");
          Serial.print(T[n].nept);
          Serial.print(",");
          Serial.print("nincs");
          Serial.print(",");
          Serial.println("Tulaj");
          open();
          delay(2000);
          break;
        case 2:
          n = random(6);
         

          Serial.print("DATA,DATE,TIME,");
          Serial.print(V[n].nev);
          Serial.print(",");
          Serial.print(V[n].nept);
          Serial.print(",");
          Serial.print(T[V[n].tulaj].nev);
          Serial.print(",");
          Serial.println("vendeg");
          open();
          delay(2000);
          break;
       case 1:
          Serial.print("DATA,DATE,TIME,");
          Serial.print("idegen");
          Serial.print(",");
          Serial.print("idegen");
          Serial.print(",");
          Serial.print("nincs");
          Serial.print(",");
          Serial.println("nincs");
          delay(2000);
          break;
      }

      
      
    }else{
      analogWrite(myLed[i].ledPin,0);
    }    
  }
}

void open(){
  digitalWrite(13,0);
  digitalWrite(12,0);
  digitalWrite(8,0);

  digitalWrite(6,1);
  digitalWrite(5,1);
  digitalWrite(3,1);
  delay(350);
  
  digitalWrite(13,0);
  digitalWrite(12,0);
  digitalWrite(8,0);

  digitalWrite(6,0);
  digitalWrite(5,0);
  digitalWrite(3,0);
  delay(5000);
  
  digitalWrite(13,1);
  digitalWrite(12,1);
  digitalWrite(8,1);

  digitalWrite(6,0);
  digitalWrite(5,0);
  digitalWrite(3,0);
  delay(350);

  digitalWrite(13,0);
  digitalWrite(12,0);
  digitalWrite(8,0);

  digitalWrite(6,0);
  digitalWrite(5,0);
  digitalWrite(3,0);

}
