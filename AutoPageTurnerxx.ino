/*
  1A - Green
  1B - Blue
  2A - Red
  2B - Yellow
*/
#include <Servo.h> // include the servo library

/*Servo testservo;

int testservopos = 0;


*/
int TurningMotorStep = 0;     // Variable counting individual steps of turning motor
int ClampingMotorStep = 0;    // Variable counting individual steps of clamping motor

String keys="123A456B789C*0#D";
int key;
boolean key_lockout=false;

void setup() { // runs once at the start of the program
  // testservo.attach(11);
  Serial.begin(9600); //initiates serial communication at 9600 baud


// DEFINING PIN NUMBERS
  const int TurningPulse = **;                // pulses A9488
  const int TurningDirection = **;       // when set high, motor goes

  const int ClampingPulse = **;                // pulses A9488
  const int ClampingDirection = **;      // when set high, motor goes

  const int Buzzer = 13   ;                    // defines buzzer pin to 13

// const int TggurningPulse = 8;               // pulses A9488
// const int ThreadedMotorDirection = 6;       // when set high, motor goes


 ENABLING PINS
  pinMode(TurningPulse, OUTPUT);              // enables TurningPulse pin
  pinMode(TurningMotorDirection, OUTPUT);     // enables TurningMotorDirection pin

  pinMode(ClampingPulse, OUTPUT);             // enables ClampingPulse pin
  pinMode(ClampingMotorDirection, OUTPUT);    // enables TurningPulse pin

  pinmode(Buzzer, OUTPUT)                     // Sets Buzzer pin to output

// pinMode(TurningMotorDirection, OUTPUT);     // enables TurningPulse pin
// pinMode(TurningMotorDirection, OUTPUT);     // enables TurningPulse pin


}

// the loop function runs over and over again forever
void loop() {

//SERVO
 /*for (testservopos = 0; testservopos <= 180; testservopos +=1) {
    testservo.write (testservopos);
    delay(15);
}

  for (testservopos = 180; testservopos >= 0; testservopos -=1) {
    testservo.write (testservopos);
    delay(15);
}
*/

// Keypad reading
/*  key=getKeypad();
  if(key!=-1)
      Serial.println(keys[key]);
      else
      Serial.println(":(");
    delay(10);
  */
//////////////////////
//B E G I N  L O O P//
//////////////////////
for (int PagesTurned = 0; PagesTurned <= **inputted pagecount**; PagesTurned +=1){

// ClampStepper UP
  for (int ClampingMotorStep = 0; ClampingMotorStep <= 200; ClampingMotorStep +=1){    // Step counter - 200 = FULL REVOLUTION WHEN THE CONDITION BECOMES FALSE, THE LOOP ENDS

    digitalWrite(ClampingDirection, HIGH) //sets direction of clamping motor (should be opposite to ClampStepper DOWN)
    digitalWrite(ClampingPulse, HIGH);         // send one step signal to A9488
    delay(10);                       // wait
    digitalWrite(ClampingPulse), LOW);          // set pin low
    delay(10);                       // wait for a second
  //  Serial.println (ClampingMotorStep);// prints the value of 'ClampingMotorStep' and creates a new line
  }
  Serial.println ("ClampStepper UP");


// Clamp servos DOWN


  Serial.println ("ClampServos DOWN");
// TAKE PICTURE
/*
  for (testservopos = 180; testservopos >= 0; testservopos -=1) {
    testservo.write (testservopos);
    delay(15);
  }

  for (testservopos = 180; testservopos >= 0; testservopos -=1) {
    testservo.write (testservopos);
    delay(15);
  }
*/
  Serial.println ("TakePicture")
// ClampServos UP


  Serial.println ("ClampServos UP")
// ClampStepper DOWN
  for (int ClampingMotorStep = 0; ClampingMotorStep <= 200; ClampingMotorStep +=1){    // Step counter - 200 = FULL REVOLUTION WHEN THE CONDITION BECOMES FALSE, THE LOOP ENDS
    digitalWrite(ClampingDirection, LOW) //sets direction of clamping motor (should be opposite to ClampStepper UP)
    digitalWrite(ClampingPulse, HIGH);         // send one step signal to A9488
    delay(10);                       // wait
    digitalWrite(ClampingPulse), LOW);          // set pin low
    delay(10);                       // wait for a second
  //  Serial.println (ClampingMotorStep);// prints the value of 'ClampingMotorStep' and creates a new line
  }
  Serial.println ("ClampStepper DOWN");


// Wheel servo DOWN


  Serial.println ("WheelServo DOWN")
// Turn Wheel


  Serial.println ("TurnWheel")
// Turning stepper ROTATE
  for (int r=0; r <=1; r++){          // Revolution counter

    for (int TurningMotorStep = 0; TurningMotorStep <= 200; TurningMotorStep +=1){    // Step counter - 200 = FULL REVOLUTION WHEN THE CONDITION BECOMES FALSE, THE LOOP ENDS
      digitalWrite(TurningDirection, LOW) //sets the direction of the turning motor (should never change)
      digitalWrite(TurningPulse, HIGH);         // send one step signal to A9488
      delay(10);                       // wait
      digitalWrite(TurningPulse, LOW);          // set pin low
      delay(10);                       // wait for a second
      //Serial.println (TurningMotorStep); // prints the value of 'TurningMotorStep' and creates a new line
    }
  }
  Serial.println ("TurningStepper ROTATE")
// Wheel servo UP


  Serial.println ("WheelServo UP")
// Buzzer
  digitalWrite (Buzzer, HIGH);      // turns buzzer on
    delay(500);
  digitalWrite (Buzzer, LOW);
  Serial.println ("Buzzer")
}


 /* Keypad stuff
int getKeypad(){
  int ret=-1;
  boolean reset_lockout=false;
  if(analogRead(A0)==0)
    key_lockout=false;
  else if(!key_lockout){
    delay(20);
    ret=15-(log((analogRead(A0)-183.9)/58.24)/0.1623)+0.5;
    key_lockout=true;
  }
  return ret;
}
*/




 //for (int r=0; r <=7; r++){          // Revolution counter

  // for (int s=0; s <= 200; s++){    // Step counter - 200 = FULL REVOLUTION
  //  digitalWrite(8, HIGH);         // send one step signal to A9488
    //delay(10);                       // wait
    //digitalWrite(8, LOW);          // set pin low
    //delay(10);                       // wait for a second
  // }
// }
//}
