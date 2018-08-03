/*
jenga
*/

int ledPin = 9;    // vibro motor
int tonePin = 8;   // buzzer
int analogRandomPin = A0; // connect wire (antenna)
int bangPin = 13; // motor
int resetButton = 12; // button for new game


int bangNum = 3; // number of vibrations before the bang 
int cycle=2000;
int peep,minus;

void setup() {
  pinMode(ledPin, OUTPUT);  
  pinMode(tonePin, OUTPUT);
  pinMode(analogRandomPin, INPUT);
  pinMode(resetButton, INPUT);
  
  pinMode(bangPin, OUTPUT);
  digitalWrite(bangPin, LOW);
  
  Serial.begin(9600);
  bangNum = analogRandom(4,8);
  bangNum=2;
}

int analogRandom(int a, int b){
  int t = analogRead(A0);
  if(t<=200) t*=2;
  if(t>=600) t/=2;
  return map(t , 200, 600 , a ,b);
  }

void loop() {
  while(digitalRead(resetButton)==LOW){
    delay(200);
    Serial.print(".");
    }
  Serial.println("");
  
  Serial.print("bangNum ");
  Serial.println(bangNum);
  cycle = analogRandom(10000,30000);
  
  minus=5000;
  peep=500;
  for(int i=cycle; i>1; i=(int)(i*0.7)){
    Serial.println(i);
    minus/=2;
    if(i<peep) peep=i;
    tone(tonePin,1500,200);
    delay(200+i);
    }
    
    tone(tonePin,1500,2000);
    
  bangNum--;
  if(bangNum<=0){
    Serial.println("Bang!!!");
    digitalWrite(bangPin, HIGH);
    delay(500);
    digitalWrite(bangPin, LOW);
    bangNum=2;
    while(digitalRead(resetButton)==HIGH){
      delay(800);
      }
    } 
  else{
  Serial.println("vibro");
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(ledPin, fadeValue);
    delay(30);
  }
  delay(500);
  for (int fadeValue = 255 ; fadeValue >= 100; fadeValue -= 5) {
    analogWrite(ledPin, fadeValue);
    delay(10);
  }
  delay(150);
   for (int fadeValue = 100 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(ledPin, fadeValue);
    delay(10);
  }
  delay(500);
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(ledPin, fadeValue);
    delay(10);
  }
  }

  
  digitalWrite(ledPin, 0);

}
