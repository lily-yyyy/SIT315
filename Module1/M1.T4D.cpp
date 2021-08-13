// Counter and compare values
const uint16_t t1_load = 0;
const uint16_t t1_comp = 31250;

const byte led1_pin = 12;
const byte led2_pin = 11;
const byte led3_pin = 10;
const byte sensor1_pin = 7;
const byte sensor2_pin = 4;
const byte sensor3_pin = 3;

int button1State = 0;
int button2State = 0;
int button3State = 0;

void setup()
{
  Serial.begin(9600);
  
  pinMode(led1_pin,OUTPUT);
  pinMode(led2_pin,OUTPUT);
  pinMode(led3_pin,OUTPUT);
  
  PCICR |= B00000100;
  PCMSK2 |= B11100000; 
  
  // set CTC mode
  TCCR1B &= ~(1 << WGM13);
  TCCR1B |= (1 << WGM12);
  
  // set to prescaler of 256
  TCCR1B |= (1 << CS12);
  TCCR1B &= ~(1 << CS11);
  TCCR1B &= ~(1 << CS10);
  
 // reset timer1 and compare value
  TCNT1= t1_load;
  OCR1A= t1_comp;
  
  // enable timer1 compare interrupt
  TIMSK1 = (1 << OCIE1A);
  
  // enable global interrupts
  sei();
}

void loop()
{
  delay(10);
}

ISR(PCINT2_vect)
{
  button1State = digitalRead(sensor1_pin);
  button2State = digitalRead(sensor2_pin);
  button3State = digitalRead(sensor3_pin);  
} 

ISR(TIMER1_COMPA_vect)
{

  if(button1State == HIGH)
  {
    Serial.println("PIR1:HIGH");
    digitalWrite(led1_pin, HIGH);
  }
  digitalWrite(led1_pin, LOW);
  
  if(button2State == HIGH)
  {
    Serial.println("PIR2:HIGH");
    digitalWrite(led2_pin, HIGH);
  }
  digitalWrite(led2_pin, LOW);
  
  if(button3State == HIGH)
  {
    Serial.println("PIR3:HIGH");
    digitalWrite(led3_pin, HIGH);
  }
  digitalWrite(led3_pin, LOW);
}
