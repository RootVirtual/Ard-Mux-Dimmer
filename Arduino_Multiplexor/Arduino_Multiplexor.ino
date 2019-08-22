#include <Mux.h>

Mux mux(2,3,4,5,4); // initialise on construct...
int counter=0;

void setup(){
Serial.begin(9600);
mux.setup(8,9,10,11,4); // initialise Mux
}

void loop(){
mux.write(counter, HIGH); //Turn ON the selected LED
delay(50);
mux.write(counter, LOW); //Turn OFF the selected LED

if(counter==3){
Serial.println(counter); //Print results
}
else{
Serial.print(counter);
Serial.print(", ");
}

counter = ++counter & 3; //Add +1 to counter until 15
}
