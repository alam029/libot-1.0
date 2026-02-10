#define STBY 5
#define AIN1 6
#define AIN2 7
#define PWMA 9
#define BIN1 4
#define BIN2 2
#define PWMB 3

int IRSensor[5] = {A0,A1,A2,A3,A4};
int SValue[5];

// define the constant of pid
float kp = 10;
float ki = 0.02;
float kd = 5;
// define the P,I,D and pasterror
int P, I, D, pastError = 0;

// set motor base speed
int baseSpeed = 150;   // 0–255

void setup() {
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);

  for (int i = 0; i < 5; i++) {
    pinMode(IRSensor[i], INPUT);
  }

  digitalWrite(STBY, HIGH);   // Enable motor driver

  Serial.begin(9600);  // serial monitar
}
void loop() {
  // find error
  int error = sensorValue();
  
  // Calculate PID value
  P = error;
  I = I + error;
  D = error - pastError;
  int PID_value = (P*kp) + (I*ki) + (D*kd);
  pastError = error;

  moveRobot(PID_value);

}

// read sensor value and retun error's weightage
int sensorValue(){
  for (int i=0; i<5; i++){
    SValue[i] = digitalRead(IRSensor[i]);
  }
  // white --> 1
  // black --> 0
  if (SValue[0] == 0){
    return -2;
  }else if (SValue[1] == 0){
    return -1;
  }else if (SValue[2] == 0){
    return 0;
  }else if (SValue[3] == 0){
    return 1;
  }else if (SValue[4] == 0){
    return 2;
  }
}

// logic for move the robot
void moveRobot(int PID_value){
  int forward = baseSpeed + PID_value;
  int backward = baseSpeed - PID_value;

  // speed limit (0 --> 255)
  forward = constrain(forward, 0, 255);
  backward = constrain(backward, 0, 255);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMA, backward);
  analogWrite(PWMB, forward);

}
