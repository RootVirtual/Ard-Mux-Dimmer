
Encender bombillas simult�neamente a diferentes intensidades.

C�digo para conectar Arduino a un m�dulo Dimmer de 4 Canales a trav�s de multiplexor y encender bombillas, recibiendo datos por Serial
C�digo para pasar datos desde Processing por Serial a Arduino


Carpeta ArdMuxDimmer4CHProcessingArduino


Conexi�n entre:   Arduino - Multiplexor - 4CH de Dimmer


  Arduino	Mux	Dimmer   Mux

     8 -------- S3	 Ch1 ---- Y0

     9 -------- S2	 Ch2 ---- Y1

     10 ------- S1	 Ch3 ---- Y2

     11 ------- S0	 Ch4 ---- Y3

     4 -------- Z

     3------------------Sync

     5v ------- Vcc ---- Vcc

    Gnd ----- Gnd/En --- Gnd



Info de la librer�a Mux.h: https://github.com/mikedotalmond/Arduino-Mux-CD74HC4067




Archivo Arduino_Multiplexor.ino:

1.- C�digo original para encender 16 leds de una en una desde Arduino con un multiplexor. C�digo de ejemplo para el c�digo de Ard_Mux_Dimmer.ino