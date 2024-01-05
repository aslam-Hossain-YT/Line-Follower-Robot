#define enA 2//Enable1 L298 Pin enA
#define enB 3 //Enable2 L298 Pin enB

#define in1 4 //Motor1  L298 Pin in1 
#define in2 5 //Motor1  L298 Pin in2 
#define in3 6 //Motor2  L298 Pin in3 
#define in4 7 //Motor2  L298 Pin in4

#define R_S A0
#define L_S A1

void forward(){  //forword
digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 
}

void backward(){ //backword
digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin 
digitalWrite(in3, HIGH); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 
}

void right(){ //turnRight
digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin  
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 
}

void left(){ //turnLeft
digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, HIGH); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 
}

void stop(){ //stop
digitalWrite(in1, LOW); //Right Motor forword Pin 
digitalWrite(in2, LOW); //Right Motor backword Pin 
digitalWrite(in3, LOW); //Left Motor backword Pin 
digitalWrite(in4, LOW); //Left Motor forword Pin 
}
 
int Speed = 60;


void setup() {

pinMode(enA, OUTPUT); // declare as output for L298 Pin enA 
pinMode(in1, OUTPUT); // declare as output for L298 Pin in1 
pinMode(in2, OUTPUT); // declare as output for L298 Pin in2 
pinMode(in3, OUTPUT); // declare as output for L298 Pin in3   
pinMode(in4, OUTPUT); // declare as output for L298 Pin in4 
pinMode(enB, OUTPUT); // declare as output for L298 Pin enB

pinMode(R_S, INPUT); // declare as output for L298 Pin in4 
pinMode(L_S, INPUT); // declare as output for L298 Pin enB

analogWrite(enA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
analogWrite(enB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 

delay(5000);

}

void loop() {

  int RS = digitalRead(R_S);
  int LS = digitalRead(L_S);

  if (LS == 0 && RS == 0) { 
    forward();
    delay(10);
  }
  else if (LS == 1 && RS == 0) {
    right();
    delay(10);
  }
  else if (LS == 0 && RS == 1) {
    left();
    delay(10);
  }
  else if (LS == 1 && RS == 1) {
    stop();
  }
  else {
   stop();
  }
  }

