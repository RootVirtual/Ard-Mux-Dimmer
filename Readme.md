
C�digo para conectar Arduino a un m�dulo Dimmer de 4 Canales a trav�s de multiplexor.

Archivo Ard_Mux_Dimmer.ino:

1.- Se inicia con el c�digo que enciende luces a distinta intensidad desde Arduino al m�dulo Dimmer con 4 canales con bombillas dimmeables a 220v AC.
2.- Se a�ade c�digo para que haga lo mismo, pero pasando por un multiplexor. El pin 3 de Arduino se conecta directamente con el m�dulo dimmer.

  Arduino	Mux	Dimmer   Mux

     8 -------- S3	 Ch1 ---- Y0

     9 -------- S2	 Ch2 ---- Y1

     10 ------- S1	 Ch3 ---- Y2

     11 ------- S0	 Ch4 ---- Y3

     4 -------- Z

     3------------------Sync

     5v ------- Vcc ---- Vcc

    Gnd ----- Gnd/En --- Gnd




Archivo Arduino_Multiplexor.ino:

1.- C�digo original para encender 16 leds de una en una desde Arduino con un multiplexor. C�digo de ejemplo para el c�digo de Ard_Mux_Dimmer.ino