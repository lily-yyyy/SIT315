const byte led_pin = 13;
const byte interrupt_pin = 2;

int buttonState = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interrupt_pin),interrupt_routine,RISING);
}

void loop()
{
  if (buttonState == HIGH) {
    digitalWrite(led_pin, HIGH);
    delay(500);
    Serial.println("Motion detected!");
  } else  {
    buttonState = LOW;
    digitalWrite(led_pin, LOW);
    Serial.println("Motion ended!");
  }
}

void interrupt_routine(){
  buttonState = HIGH;
  Serial.println("interrupt");
}