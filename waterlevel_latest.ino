const int SpmpSensorPin = A0; // set A0 as the Spump water sensor pin
int SpmpsensorValue = 0;  // variable to store the value coming from the sensor
const int first_level = A2, second_level = A3, third_level = A4, full_level = A5;
int currentLevel = 0;

const int first_led = 6;
const int second_led = 7;
const int third_led = 8;
const int fourth_led = 9;

const int buzzer = 9; //buzzer to arduino pin 9

void setup() {
  Serial.begin(9600);
  pinMode(first_level, INPUT); // Water sensor input pin
  pinMode(second_level, INPUT); // Water sensor input pin
  pinMode(third_level, INPUT); // Water sensor input pin
  pinMode(full_level, INPUT); // Water sensor input pin

  pinMode(first_led, OUTPUT); // Led Output pin
  pinMode(second_led, OUTPUT); // Led Output pin
  pinMode(third_led, OUTPUT); // Led Output pin
  pinMode(fourth_led, OUTPUT); // Led Output pin
}

void loop() {
//   ---- just testing ---
// Serial.println("level 1");
// Serial.println(analogRead(first_level));
// delay(1000);
// Serial.println("level 2");
// Serial.println(analogRead(second_level));
// delay(1000);
// Serial.println("level 3");
// Serial.println(analogRead(third_level));
// delay(1000);
// Serial.println("level 4");
// Serial.println(analogRead(full_level));
 delay(1000);

 //Water going up
if(analogRead(first_level)> 900 && currentLevel==0){
  
  currentLevel=1;
  }
  //down1---------
else if(analogRead(first_level)< 900 && currentLevel>0){
  
  currentLevel=0;
  }
  //---------
else if(analogRead(second_level) > 900 && currentLevel==1){
    currentLevel=2;
  }
  //down2---------
else if(analogRead(second_level)< 900 && currentLevel==2){
  
  currentLevel=1;
  }
  //---------
else if(analogRead(third_level)> 900 && currentLevel==2){
  
   currentLevel=3;
  }
  //down3---------
else if(analogRead(third_level)< 900 && currentLevel==3){
  
  currentLevel=2;
  }
  //---------
else if(analogRead(full_level)> 900 && currentLevel==3){
  
   currentLevel=4;
  }
  //down4---------
else if(analogRead(full_level)< 900 && currentLevel==4){
  
  currentLevel=3;
  }
  //---------
else if(analogRead(first_level)< 900){
  
    currentLevel=0;
  }

 
if(currentLevel == 1){
  Serial.println("25 percentage filled");
  digitalWrite(first_led,HIGH);
  digitalWrite(second_led,LOW);
  digitalWrite(third_led,LOW);
  digitalWrite(fourth_led,LOW);
  }
else if(currentLevel == 2){
  Serial.println("50 percentage filled");
  digitalWrite(first_led,HIGH);
  delay(1000);
  digitalWrite(second_led,HIGH);
  digitalWrite(third_led,LOW);
  digitalWrite(fourth_led,LOW);
  }
else if(currentLevel == 3){
  Serial.println("75 percentage filled");
  digitalWrite(first_led,HIGH);
  delay(1000);
  digitalWrite(second_led,HIGH);
  delay(1000);
  digitalWrite(third_led,HIGH);
  digitalWrite(fourth_led,LOW);
  }
else if(currentLevel == 4){
  Serial.println("Completly Filled");
  digitalWrite(first_led,HIGH);
  delay(1000);
  digitalWrite(second_led,HIGH);
  delay(1000);
  digitalWrite(third_led,HIGH);
  delay(1000);
  digitalWrite(fourth_led,HIGH);
  }
else{
  Serial.println("No Water Detected");
  digitalWrite(first_led,LOW);
  digitalWrite(second_led,LOW);
  digitalWrite(third_led,LOW);
  digitalWrite(fourth_led,LOW);
  }
  
}
