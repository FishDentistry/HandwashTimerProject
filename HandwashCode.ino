
const int SOUND_PIN = A0;
int led1 = 9;
int led2 = 8;
int led3 = 7;
int led4 = 6;
int led5 = 5;
int led6 = 4;
int led7 = 3;
int led8 = 10;
int led9 = 1;
int led10 = 0;



const int THRESHOLD = 30;                           // Raw ADC
const unsigned long TIMEOUT = 500;                  // ms
const unsigned long TIME_BETWEEN_PULSES_MIN = 300;  // ms
const unsigned long TIME_BETWEEN_PULSES_MAX = 1000; // ms
const int PULSE_MIN = 40;                           // ms
const int PULSE_MAX = 300;                          // ms
const int SERVO_WAIT = 1000;                        // ms
const int SERVO_CCW = 0;                            // deg
const int SERVO_CW = 180;                           // deg
unsigned long last_pulse_time = 0;


void setup() {
  pinMode(SOUND_PIN, INPUT);
int led1 = 9;
int led2 = 8;
int led3 = 7;
int led4 = 6;
int led5 = 5;
int led6 = 4;
int led7 = 3;
int led8 = 10;
int led9 = 1;
int led10 = 0;
}

void loop() {
  unsigned long pulse_length = readPulse(SOUND_PIN, THRESHOLD, TIMEOUT);
  if ( (pulse_length >= PULSE_MIN) && 
       (pulse_length <= PULSE_MAX) ) {
    unsigned long pulse_time = millis();
    //Serial.println(pulse_time - last_pulse_time);

    
    if ( (pulse_time - last_pulse_time >= TIME_BETWEEN_PULSES_MIN) &&
         (pulse_time - last_pulse_time <= TIME_BETWEEN_PULSES_MAX) ) {
      //Serial.println("Clap on!");
      lightOn();
    }

    last_pulse_time = pulse_time;
  }
}


unsigned long readPulse(int pin, int threshold, unsigned long timeout) {

  unsigned long t = 0;

  if ( analogRead(pin) >= threshold ) {
    unsigned long timestamp = millis();
    while ( (analogRead(pin) >= threshold) &&
            (millis() < timestamp + timeout) );
    t = millis() - timestamp;
  }

  return t;
}

void lightOn() {
 digitalWrite(led1,HIGH);
 digitalWrite(led2,HIGH);
 digitalWrite(led3,HIGH);
 digitalWrite(led4,HIGH);
 digitalWrite(led5,HIGH);
 digitalWrite(led6,HIGH);
 digitalWrite(led7,HIGH);
 digitalWrite(led8,HIGH);
 digitalWrite(led9,HIGH);
 digitalWrite(led10,HIGH);
 delay(2000);
 digitalWrite(led10,LOW);
 delay(2000);
 digitalWrite(led9,LOW);
 delay(2000);
 digitalWrite(led8,LOW);
 delay(2000);
 digitalWrite(led7,LOW);
 delay(2000);
 digitalWrite(led6,LOW);
 delay(2000);
 digitalWrite(led5,LOW);
 delay(2000);
 digitalWrite(led4,LOW);
 delay(2000);
 digitalWrite(led3,LOW);
 delay(2000);
 digitalWrite(led2,LOW);
 delay(2000);
 digitalWrite(led1,LOW);
 

  
}
