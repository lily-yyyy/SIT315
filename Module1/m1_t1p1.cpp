const byte led_pin = 13;
const byte sensor_pin = 2;

int buttonState = 0;

void setup()
{
  pinMode(sensor_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // read the state of the pushbutton
  buttonState = digitalRead(sensor_pin);
  
  // check if pushbutton is pressed. if it is, the
  // button state is HIGH
  if (buttonState == HIGH) {
    digitalWrite(led_pin, HIGH);
    Serial.println("Motion detected!");
  } else {
    digitalWrite(led_pin, LOW);
    Serial.println("Motion ended!");
  }
  delay(10); // Delay a little bit to improve simulation performance
}