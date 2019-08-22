
unsigned char channel_1 = 7;    // Output to Opto Triac pin, channel 1
unsigned char channel_2 = 6;    // Output to Opto Triac pin, channel 2
unsigned char channel_3 = 5;
unsigned char channel_4 = 4;
unsigned char dimming = 3;      // Dimming level (0-100)
unsigned char i;
unsigned char flag=0;
unsigned char oh=1;

void setup() {
  // put your setup code here, to run once:
  pinMode(channel_1, OUTPUT);// Set AC Load pin as output
  pinMode(channel_2, OUTPUT);// Set AC Load pin as output
  pinMode(channel_3, OUTPUT);
  pinMode(channel_4, OUTPUT);
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
    digitalWrite(channel_1, HIGH);   // triac firing
    delayMicroseconds(10);         // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(channel_1, LOW);    // triac Off
   }else if(flag==1){
    digitalWrite(channel_2, HIGH);   // triac firing
    delayMicroseconds(10);         // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(channel_2, LOW);    // triac Off
   }else if(flag==2){
    digitalWrite(channel_3, HIGH);   // triac firing
    delayMicroseconds(10);         // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(channel_3, LOW);    // triac Off
   }else if(flag==3){
    digitalWrite(channel_4, HIGH);   // triac firing
    delayMicroseconds(10);         // triac On propogation delay (for 60Hz use 8.33)
    digitalWrite(channel_4, LOW);    // triac Off
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
