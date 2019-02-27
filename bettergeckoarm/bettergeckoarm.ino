//Copyright 2019 Totally Original Code DO NOT STEAL

//Variables to keep track of the position of the joystick.
unsigned int x_pos;
unsigned in y_pos;

//Variable to keep track of whether or not the spring has been activated.
bool spring_state;

//Variables for the servo positions.
unsigned int base_pos;
unsigned int elbow_pos;
unsigned int stabilizer_pos;

//Debug variable so that the print statements can be disabled if need be.
bool _DEBUG = true;

//Sets things up
void setup() {
  //If we want to debug, this if statement will be activated, otherwise, it is ignored.
  if(_DEBUG){
    Serial.begin(9600);
  }
  //Setting Port D pins 0-3 as inputs, 4-7 as outputs.
  DDRD = 0xF0;
  //Disconnecting Channel A, setting channel B to Fast PWM, clear on match.
  TCCR0A = 0x23;
  //Setting the clock to divide by 64 and fixing the rest of the PWM setup.
  TCCR0B = 0x0B;
  //Making the frequency of the output signal about 1 kHz.
  OCR0A = 250;
  //The initial 62. Changing this will change the servo position.
  OCR0B = 62;
}

//Runs until the end of time
void loop() {
  //Joystick input comes later, want to make sure the serve control works first. (Also I don't yet know how analog control works with Arduino :) ).
  //The following is simply a test to see how the servo will react to this. Will be altering it later, more testing must be done...
  OCR0B += 1;
}
