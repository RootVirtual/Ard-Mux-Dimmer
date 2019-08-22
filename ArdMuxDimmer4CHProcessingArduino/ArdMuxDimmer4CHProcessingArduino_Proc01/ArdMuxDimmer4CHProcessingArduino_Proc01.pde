
import processing.serial.*;
Serial myPort;

float x, y; // Posición del botón 1
float mx, my;  // Medidas del botón 1
int a1=10;

float x2, y2; // Posición del botón 2
float mx2, my2;  // Medidas del botón 2
int a2=10;

float x3, y3; // Posición del botón 3
float mx3, my3;  // Medidas del botón 3
int a3=10;

float x4, y4; // Posición del botón 4
float mx4, my4;  // Medidas del botón 4
int a4=10;

int b=50;
int count=0;

int PotMin=8;
int PotMax=20;

void setup() {
  size(640, 360);
  String portName = Serial.list()[1];
  myPort = new Serial(this, portName, 9600);
  
  //Variables botón 1
  x = 50;
  y = 277;
  mx = 50;
  my = 20;
  
  //Variables botón 2
  x2 = 150;
  y2 = 277;
  mx2 = 50;
  my2 = 20;
  
  //Variables botón 3
  x3 = 250;
  y3 = 277;
  mx3 = 50;
  my3 = 20;
  
  //Variables botón 4
  x4 = 350;
  y4 = 277;
  mx4 = 50;
  my4 = 20;

  noStroke();
}

void draw() {
  
  background(255); //Fondo
  
  if(count==10){
    b=int(random(-10, 10));
    a1=a1+b;
    if(a1<PotMin){a1=PotMin;}
    if(a1>PotMax){a1=PotMax;}
    b=int(random(-10, PotMin));
    a2=a2+b;
    if(a2<PotMin){a2=PotMin;}
    if(a2>PotMax){a2=PotMax;}
    b=int(random(-10, 10));
    a3=a3+b;
    if(a3<PotMin){a3=PotMin;}
    if(a3>PotMax){a3=PotMax;}
    b=int(random(-10, 10));
    a4=a4+b;
    if(a4<PotMin){a4=PotMin;}
    if(a4>PotMax){a4=PotMax;}
  }
  
  count++;
  if(count>10){
    count=0;
  }
  
  /*
  //Pista de botón 1
  fill(204);
  rect(x+15, 50, 20, 250);
  fill(100);
  rect(x+23, 50, 4, 250);
  
  //Pista de botón 2
  fill(204);
  rect(x2+15, 50, 20, 250);
  fill(100);
  rect(x2+23, 50, 4, 250);
  
  //Pista de botón 3
  fill(204);
  rect(x3+15, 50, 20, 250);
  fill(100);
  rect(x3+23, 50, 4, 250);
  
  //Pista de botón 4
  fill(204);
  rect(x4+15, 50, 20, 250);
  fill(100);
  rect(x4+23, 50, 4, 250);
  
  
  // Si el cursor está sobre la pista, se desplaza manteniendo ratón.
  //De bottón 1
  if(mousePressed && mouseY >= 50+10 && mouseY < 50+250-10 && mouseX >= x && mouseX < x+mx){
    y = mouseY-(my/2);
  }
  //De bottón 2
  if(mousePressed && mouseY >= 50+10 && mouseY < 50+250-10 && mouseX >= x2 && mouseX < x2+mx2){
    y2 = mouseY-(my2/2);
  }
  //De bottón 3
  if(mousePressed && mouseY >= 50+10 && mouseY < 50+250-10 && mouseX >= x3 && mouseX < x3+mx3){
    y3 = mouseY-(my3/2);
  }
  //De bottón 4
  if(mousePressed && mouseY >= 50+10 && mouseY < 50+250-10 && mouseX >= x4 && mouseX < x4+mx4){
    y4 = mouseY-(my4/2);
  }
  
  //Posición y dato de botón 1
  a1=int(map(y,54,276,100,0));
  if(a1>100){a1=100;}
  if(a1<10){a1=0;}
  
  //Posición y dato de botón 2
  a2=int(map(y2,54,276,100,0));
  if(a2>100){a2=100;}
  if(a2<10){a2=0;}
  
  //Posición y dato de botón 3
  a3=int(map(y3,54,276,100,0));
  if(a3>100){a3=100;}
  if(a3<10){a3=0;}
  
  //Posición y dato de botón 4
  a4=int(map(y4,54,276,100,0));
  if(a4>100){a4=100;}
  if(a4<10){a4=0;}
  */
  
  //Enviamos datos
  myPort.write(255); //Dato de control de inicio
  delay(10);
  myPort.write(a1);  //Dato de botón 1
  myPort.write(a2);  //Dato de botón 2
  myPort.write(a3);  //Dato de botón 3
  myPort.write(a4);  //Dato de botón 4
  delay(10);
  
  //Podemos imprimir los datos por consola
  //print(y);
  //print(" - ");
  print(a1);
  print(" - ");
  print(" - ");
  //print(y2);
  //print(" - ");
  print(a2);
  print(" - ");
  print(" - ");
  //print(y3);
  //print(" - ");
  print(a3);
  print(" - ");
  print(" - ");
  //print(y4);
  //print(" - ");
  println(a4);
  
  //Dibujamos los botones:
  fill(0);
  //Botón 1
  rect(x, y, mx, my);
  text("a1", x+18, 315);
  //Botón 2
  rect(x2, y2, mx2, my2);
  text("a2", x2+18, 315);
  //Botón 3
  rect(x3, y3, mx3, my3);
  text("a3", x3+18, 315);
  //Botón 4
  rect(x4, y4, mx4, my4);
  text("a4", x4+18, 315);
  
  //Indicador de cada botón
  fill(255);
  text(a1, x+18, y+15);
  text(a2, x2+18, y2+15);
  text(a3, x3+18, y3+15);
  text(a4, x4+18, y4+15);
  
}
