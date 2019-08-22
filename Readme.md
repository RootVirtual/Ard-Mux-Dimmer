
Código para conectar Arduino a un módulo Dimmer de 4 Canales a través de multiplexor.

Archivo Ard_Mux_Dimmer.ino:

1.- Se inicia con el código que enciende luces a distinta intensidad desde Arduino al módulo Dimmer con 4 canales con bombillas dimmeables a 220v AC.
2.- Se añade código para que haga lo mismo, pero pasando por un multiplexor. El pin 3 de Arduino se conecta directamente con el módulo dimmer.

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

1.- Código original para encender 16 leds de una en una desde Arduino con un multiplexor. Código de ejemplo para el código de Ard_Mux_Dimmer.ino