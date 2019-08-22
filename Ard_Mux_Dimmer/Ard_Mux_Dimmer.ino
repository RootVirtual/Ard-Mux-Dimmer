// Testing sketch for 50Hz !!!

#include <TimerOne.h>
#include <Mux.h>

Mux mux(2,3,4,5,4); // initialise on construct...
int counter=0;

unsigned char CH1, CH2, CH3, CH4;
unsigned char i=0;
unsigned int delay_time=2500; // delay ms or SPEED
unsigned char clock_tick; // variable for Timer1

void setup() {
Serial.begin(9600);
mux.setup(8,9,10,11,4); // initialise Mux

attachInterrupt(1, zero_crosss_int, RISING);
Timer1.initialize(100); // set a timer of length 100 microseconds for 50Hz or 83 microseconds for 60Hz;
Timer1.attachInterrupt( timerIsr ); // attach the service routine here

}

void timerIsr(){
  clock_tick++;
  
  if (CH1==clock_tick){
    mux.write(0, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    mux.write(0, LOW); // triac Off
  }
  
  if (CH2==clock_tick){
    mux.write(1, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    mux.write(1, LOW); // triac Off
  }
  
  if (CH3==clock_tick){
    mux.write(2, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    mux.write(2, LOW); // triac Off
  }
  
  if (CH4==clock_tick){
    mux.write(3, HIGH); // triac firing
    delayMicroseconds(10); // triac On propogation delay (for 60Hz use 8.33)
    mux.write(3, LOW); // triac Off
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
