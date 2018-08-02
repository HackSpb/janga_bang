/*
jenga
*/

int ledPin = 9;    // LED connected to digital pin 9
int tonePin = 8; 

int cycle=2000;
int peep,minus;
void setup() {
  Serial.begin(9600);
  // nothing happens in setup
}

void loop() {
  cycle=random(5000,30000);
  minus=5000;
  peep=500;
  for(int i=cycle; i>1; i=(i*7)/10){
    Serial.println(i);
    minus/=2;
    if(i<peep) peep=i;
    tone(tonePin,1500,200);
    delay(200+i);
    }
    
    tone(tonePin,1500,2000);
    
  
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(10);
  }

}
