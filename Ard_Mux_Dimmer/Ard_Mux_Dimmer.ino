// Testing sketch for 50Hz !!!

#include <TimerOne.h>

unsigned char channel_1 = 7; // Output to Opto Triac pin, channel 1
unsigned char channel_2 = 6; // Output to Opto Triac pin, channel 2
unsigned char channel_3 = 5; // Output to Opto Triac pin, channel 3
unsigned char channel_4 = 4; // Output to Opto Triac pin, channel 4
unsigned char CH1, CH2, CH3, CH4;
unsigned char i=0;
unsigned int delay_time=2500; // delay ms or SPEED
unsigned char clock_tick; // variable for Timer1

void setup() {
pinMode(channel_1, OUTPUT);// Set AC Load pin as output
pinMode(channel_2, OUTPUT);// Set AC Load pin as output
pinMode(channel_3, OUTPUT);// Set AC Load pin as output
pinMode(channel_4, OUTPUT);// Set AC Load pin as output
attachInterrupt(1, zero_crosss_int, RISING);
Timer1.initialize(100); // set a timer of length 100 microseconds for 50Hz or 83 microseconds for 60Hz;
Timer1.attachInterrupt( timerIsr ); // attach the service routine here

}

void timerIsr(){
  clock_tick++;
  
  if (CH1==clock_tick){
    digitalWrite(channel_1, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(channel_1, LOW); // triac Off
  }
  
  if (CH2==clock_tick){
    digitalWrite(channel_2, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(channel_2, LOW); // triac Off
  }
  
  if (CH3==clock_tick){
    digitalWrite(channel_3, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(channel_3, LOW); // triac Off
  }
  
  if (CH4==clock_tick){
    digitalWrite(channel_4, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(channel_4, LOW); // triac Off
  }
}



void zero_crosss_int(){ // function to be fired at the zero crossing to dim the light

  // Every zerocrossing interrupt: For 50Hz (1/2 Cycle) => 10ms ; For 60Hz (1/2 Cycle) => 8.33ms
  // 10ms=10000us , 8.33ms=8330us
  
  clock_tick=0;
}

void loop() {

CH1=5; CH2=45; CH3=65; CH4=80;
delay(delay_time);

CH1=80; CH2=65; CH3=45; CH4=5;
delay(delay_time);

CH1=65; CH2=5; CH3=65; CH4=5;
delay(delay_time);

CH1=5; CH2=65; CH3=5; CH4=65;
delay(delay_time);

CH1=5; CH2=65; CH3=65; CH4=5;
delay(delay_time);

CH1=65; CH2=5; CH3=5; CH4=65;
delay(delay_time);

CH1=5; CH2=5; CH3=5; CH4=5;
delay(delay_time);

CH1=95; CH2=95; CH3=95; CH4=95;
delay(delay_time);

}
