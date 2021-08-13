const byte led_pin = 13;
const byte sensor_pin = 2;

int buttonState = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(sensor_pin),interrupt_routine,RISING);
}

void loop()
{
  delay(10);
}

void interrupt_routine(){
  buttonState = !buttonState;
  digitalWrite(led_pin, buttonState);
  Serial.println("Motion detected!");
}
