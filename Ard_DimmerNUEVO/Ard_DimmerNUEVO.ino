
#include <Mux.h>
Mux mux(2,3,4,5,4); // initialise on construct...

unsigned char dimming = 3;      // Dimming level (0-100)
unsigned char i;
unsigned char flag=0;
unsigned char oh=1;

void setup() {

  Serial.begin(9600);
  mux.setup(8,9,10,11,5); // initialise Mux
  
  // put your setup code here, to run once:
 
  attachInterrupt(1, zero_crosss_int, RISING);

  // Serial.begin(9600);
}

void zero_crosss_int(){  // function to be fired at the zero crossing to dim the light
  // Firing angle calculation : 1 full 50Hz wave =1/50=20ms 
  // Every zerocrossing : (50Hz)-> 10ms (1/2 Cycle) For 60Hz (1/2 Cycle) => 8.33ms 
  // 10ms=10000us
  
  int dimtime = (100*dimming);    // For 60Hz =>83   
  delayMicroseconds(dimtime);    // Off cycle
  
  if (flag==0){
    mux.write(0, HIGH);   // triac firing
    delayMicroseconds(10);         // triac On propogation delay (for 60Hz use 8.33)
    mux.write(0, LOW);    // triac Off
   }else if(flag==1){
    mux.write(1, HIGH);   // triac firing
    delayMicroseconds(10);         // triac On propogation delay (for 60Hz use 8.33)
    mux.write(1, LOW);    // triac Off
   }else if(flag==2){
    mux.write(2, HIGH);   // triac firing
    delayMicroseconds(10);         // triac On propogation delay (for 60Hz use 8.33)
    mux.write(2, LOW);    // triac Off
   }else if(flag==3){
    mux.write(3, HIGH);   // triac firing
    delayMicroseconds(10);         // triac On propogation delay (for 60Hz use 8.33)
    mux.write(3, LOW);    // triac Off
   }
}

void loop() {
    
          // Serial.println(pulseIn(8, HIGH));
          
         
        
          for (i=85;i>5;i--){
            dimming=i;
            delay(5);
          }
          
          for (i=5;i<85;i++){
            dimming=i;
            delay(5);
          }

          flag=flag+1*oh;
          if((flag>=3)||(flag<=0)){
            oh=oh*-1;   
          }

}
