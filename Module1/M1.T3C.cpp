const byte led1_pin = 13;
const byte led2_pin = 12;
const byte sensor1_pin = 2;
const byte sensor2_pin = 3;

int button1State = 0;
int button2State = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(sensor1_pin, INPUT);
  pinMode(sensor2_pin, INPUT);
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(sensor1_pin),interrupt1_routine,RISING);
  attachInterrupt(digitalPinToInterrupt(sensor2_pin),interrupt2_routine,RISING);
}

void loop()
{
  delay(10);
}

void interrupt1_routine(){
  button1State = !button1State;
  digitalWrite(led1_pin, button1State);
  Serial.println("Motion1 detected!");
}

void interrupt2_routine(){
  button2State = !button2State;
  digitalWrite(led2_pin, button2State);
  Serial.println("Motion2 detected!");
}