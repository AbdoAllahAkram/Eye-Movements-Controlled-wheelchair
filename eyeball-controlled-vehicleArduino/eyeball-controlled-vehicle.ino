#include<SoftwareSerial.h>

 SoftwareSerial MySerial(6, 7); // blutooth Module : TX: 6 , RX: 7

  int M1R = 8;
  int M1L = 9;
  int M2R = 10;
  int M2L = 11;

  // UltraSonic Section
  const int UltrsonicHIGH = 2;
  const int trigerPin = 3;
  const int echoPin = 4;
  long period;
  float distance; 

void setup() {
  MySerial.begin(9600);
  Serial.begin(9600);
  
  pinMode(M1R, OUTPUT);
  pinMode(M1L, OUTPUT);
  pinMode(M2R, OUTPUT);
  pinMode(M2L, OUTPUT);

  /*
  // UltraSonic Section
  pinMode(UltrsonicHIGH, OUTPUT);
  pinMode(trigerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(UltrsonicHIGH, HIGH);
*/
}

void loop() {
  
  /*
  // ---------------------UltraSonic Section----------------- \\
  digitalWrite(trigerPin, LOW);
  delayMicroseconds(2);
 
  digitalWrite(trigerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigerPin, LOW);

  period = pulseIn(echoPin, HIGH);

  distance = (period/2) * 0.034 ;

//   if (distance >=400 || distance <= 5) {
//    Serial.println("out of range");
//  } else {
    Serial.println(distance);
    delay(1);
//  }

  // ---------------------UltraSonic Section----------------- \\
  */


  
  if( MySerial.available() ) {

    char R = MySerial.read();

   

      // Stop The Motor
      if( R == 'S' ) {
        
       digitalWrite(M1R, LOW);
       digitalWrite(M1L, LOW);
       digitalWrite(M2R, LOW);
       digitalWrite(M2L, LOW);
       
      }
  
      // Move Forord The Motor
      if( R == 'F') {
        
       digitalWrite(M1R, HIGH);
       digitalWrite(M1L, LOW);
       digitalWrite(M2R, HIGH);
       digitalWrite(M2L, LOW);
       delay(1);
      }
  
       // Move Back The Motor
      if( R == 'B') {
        
       digitalWrite(M1R, LOW);
       digitalWrite(M1L, HIGH);
       digitalWrite(M2R, LOW);
       digitalWrite(M2L, HIGH);
       delay(1);
      }
  
       // Move Right The Motor
      if( R == 'R' || R == 'I') {
        
       digitalWrite(M1R, HIGH);
       digitalWrite(M1L, LOW);
       digitalWrite(M2R, LOW);
       digitalWrite(M2L, LOW);
       
      }
  
       // Move Left The Motor
      if( R == 'L' || R == 'G') {
        
       digitalWrite(M1R, LOW);
       digitalWrite(M1L, LOW);
       digitalWrite(M2R, HIGH);
       digitalWrite(M2L, LOW );
       
      }
  
      // Move Right-Back The Motor
      if(R == 'J') {
        
       digitalWrite(M1R, LOW);
       digitalWrite(M1L, HIGH);
       digitalWrite(M2R, LOW);
       digitalWrite(M2L, LOW);
       
      }
  
       // Move Left-Back The Motor
      if( R == 'H') {
        
       digitalWrite(M1R, LOW);
       digitalWrite(M1L, LOW);
       digitalWrite(M2R, LOW);
       digitalWrite(M2L, HIGH );
       
      }

    

    //Serial.write( R );
  }





//  if( Serial.available() ) {
//    MySerial.write( Serial.read() );
//  }

}
