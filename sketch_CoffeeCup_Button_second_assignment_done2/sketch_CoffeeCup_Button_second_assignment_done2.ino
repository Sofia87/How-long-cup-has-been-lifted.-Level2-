#include "config.h"
AdafruitIO_Feed *coffeecups = io.feed("coffeecups");

int buttonOnTheCup = 1;
int button = 2;
int i = 0;
int x = 1;

void setup(){
  io.connect();
  Serial.begin(9600);
  pinMode(buttonOnTheCup, INPUT);
  pinMode(button, INPUT);
}

void loop(){
  
  io.run();
  int button_Switch = digitalRead(button);
  int buttonOnTheCup_Switch = digitalRead(buttonOnTheCup);
   //If the cup is lifted / the button is not pressed...
  if (buttonOnTheCup_Switch == LOW && i>=0 && i<35){
    if(x==1){
   //...increase the number of oz's...
    i++;
    Serial.println(i);
    coffeecups->save(i);
    x = 2;
  }}
  else if(buttonOnTheCup_Switch == LOW && i >=35){
    i=0;
    coffeecups->save(i);
    x = 2;
  }
     //count oz's. Assumption: 2 seconds are equal to 1 consumed oz.
  delay(2000);
  
  if(buttonOnTheCup_Switch == LOW && i >=0 && i<35){
        if(x==2){
         x = 1;    
  }}


if (button_Switch == HIGH){
    i=0;
    Serial.println(i);
    coffeecups->save(i);
}
}




