//Programa Brazo Robótico MINI 2.0
 #include <Servo.h>
 const int pingPin = 13;
  const int echoPin = 12; 
  Servo servo1; 
  Servo servo2;
   Servo servo3; 
  Servo servo4; 
  int angulo1 = 110; 
  int angulo2 = 90; 
  int angulo3 = 90; 
  int angulo4 = 145; 
  int salto = 3; 
  int Eje_L1 = A2; 
  int Eje_L2 = A1;
  int Eje_R1 = A5;
  int Eje_R2 = A4; 
  int led_pinza = 9; 
  int buzzer = 5; 
  int bt_R3 = 7; 
  int bt_L3 = 8; 
  void setup() { 
    servo1.attach(3); 
    servo2.attach(6); 
    servo3.attach(10); 
    servo4.attach(11); 
    pinMode(led_pinza, OUTPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(bt_R3, INPUT_PULLUP);
    pinMode(bt_L3, INPUT_PULLUP); 
    Serial.begin(9600); 
    }
    void loop() { 
    brazoMain();
    int lecturaBTR = digitalRead(bt_R3);
    int lecturaBTL = digitalRead(bt_L3); 
    //Serial.print("Derecho: ");
     //Serial.print(lecturaBTR); 
     //Serial.print(" Izquierdo: ");
      //Serial.println(lecturaBTL);
       //Serial.println(cm);
        if (lecturaBTR == 0)
        { digitalWrite(led_pinza, HIGH); 
        } if (lecturaBTR == 1) { 
        digitalWrite(led_pinza, LOW); 
        } 
        if (lecturaBTL == 0) {
        digitalWrite(buzzer, HIGH); 
        } 
        if (lecturaBTL == 1) {

        digitalWrite(buzzer, LOW); 
        }
        Serial.print("Distancia: "); 
        } 
        void brazoMain() { 
        int cm = ping(pingPin); 
        int p = analogRead(Eje_L1); 
        // Base if ( p < 200 )angulo1 = angulo1 - salto;
         else if (p > 800) angulo1 = angulo1 + salto; 
         angulo1 = constrain(angulo1, 30, 180); 
         servo1.write(angulo1); 
         int s = analogRead(Eje_L2); 
         //HOMBRO if ( s < 200 ) angulo2 = angulo2 + salto; 
         else if (s > 800) angulo2 = angulo2 - salto; 
         angulo2 = constrain(angulo2, 60, 130); 
         servo2.write(angulo2); 
         int f = analogRead(Eje_R1); 
         if ( f < 200 ) angulo3 = angulo3 - salto; 
         else if (f > 800) angulo3 = angulo3 + salto; 
         angulo3 = constrain(angulo3, 75, 180); 
         //75 180 servo3.write(angulo3); 
         int r = analogRead(Eje_R2); 
         // Pinza if ( r < 200 ) angulo4 = angulo4 - salto; 
         else if (r > 800) angulo4 = angulo4 + salto; 
         angulo4 = constrain(angulo4, 145, 165); 
         //135 175 servo4.write(angulo4); 
         if(cm < 16){ angulo4 = 165; tone(2, 50); 
         delay(50); noTone(2); } 
         delay(25); 
         } 
         int ping(int pingPin) { 
            long duration, cm; 
            pinMode(pingPin, OUTPUT); 
            digitalWrite(pingPin, LOW); 
            delayMicroseconds(2); 
            digitalWrite(pingPin, HIGH); 
            delayMicroseconds(5); 
            digitalWrite(pingPin, LOW); 
            pinMode(echoPin, INPUT); 
            duration = pulseIn(echoPin, HIGH); 
            cm = microSecondsToCentimeters(duration); 
            return cm; 
            } 
            long microSecondsToCentimeters(long microseconds) 
            { 
                return microseconds/29/2; 
                }