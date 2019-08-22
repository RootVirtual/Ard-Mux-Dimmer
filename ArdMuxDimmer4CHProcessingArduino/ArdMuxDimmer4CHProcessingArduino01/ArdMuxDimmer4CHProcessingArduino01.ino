// Conexión de Modulo para 50Hz !!!
//
// Conxión del Dimmer.
//
// Dimmer  Arduino
//   |             |
//  GND           GND
//  VCC           5V
//  SYNC        DIGITAL.3
//  CANAL       DIGITAL.7
//  CANAL       DIGITAL.6
//  CANAL       DIGITAL.5
//  CANAL       DIGITAL.4

#include <Mux.h>
#include <TimerOne.h>    // Librería para interrupción

Mux mux(2,3,4,5,4); // initialise on construct...

unsigned char CH1; // Salida a Canal 1
unsigned char CH2; // Salida a Canal 2
unsigned char CH3; // Salida a Canal 3
unsigned char CH4; // Salida a Canal 4
unsigned char clock_tick; // variable para Timer1
int dato = 0; //Variable que recibe por Serial
int mas[4]; //Array para almacenar el dato para cada dimmer
int indice=0; //Variable para saltar en el array

void setup() {
  Serial.begin(9600); //Velocidad de comunicación

  mux.setup(8,9,10,11,5); // initialise Mux
  
  //Establece el tiempo de interrupción
  attachInterrupt(1, zero_crosss_int, RISING);
  Timer1.initialize(100); // Temporizador de 100 microsegundos para 50Hz o de 83 para 60Hz;
  Timer1.attachInterrupt( timerIsr ); // Establece la interrupción desde la función
  
  CH1=CH2=CH3=CH4=95; // Bombillas en Off al empezar el programa(95 - FULLY OFF ; 5 - FULLY ON)
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

void loop(){
  while(Serial.available()==0){
    //esperar
    
  }
  
  dato = Serial.read();

  if(dato==255){
    indice=0;
    
    if(mas[0]>=0){
      CH1=mas[0];
      CH1=100-CH1;
      if(CH1<5){CH1=5;}
      if(CH1>95){CH1=95;}
    }
    if(mas[1]>=0){
      CH2=mas[1];
      CH2=100-CH2;
      if(CH2<5){CH2=5;}
      if(CH2>95){CH2=95;}
    }
    if(mas[2]>=0){
      CH3=mas[2];
      CH3=100-CH3;
      if(CH3<5){CH3=5;}
      if(CH3>95){CH3=95;}
    }
    if(mas[3]>=0){
      CH4=mas[3];
      CH4=100-CH4;
      if(CH4<5){CH4=5;}
      if(CH4>95){CH4=95;}
    }
    
  }else{

    if(indice<4){
      mas[indice++]=dato;
    }else{
      //Error
    }
  }
  
  

}
