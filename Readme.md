
Encender bombillas simultáneamente a diferentes intensidades.

Código para conectar Arduino a un módulo Dimmer de 4 Canales a través de multiplexor y encender bombillas, recibiendo datos por Serial
Código para pasar datos desde Processing por Serial a Arduino


Carpeta ArdMuxDimmer4CHProcessingArduino


Conexión entre:   Arduino - Multiplexor - 4CH de Dimmer


  Arduino	Mux	Dimmer   Mux

     8 -------- S3	 Ch1 ---- Y0

     9 -------- S2	 Ch2 ---- Y1

     10 ------- S1	 Ch3 ---- Y2

     11 ------- S0	 Ch4 ---- Y3

     4 -------- Z

     3------------------Sync

     5v ------- Vcc ---- Vcc

    Gnd ----- Gnd/En --- Gnd



Info de la librería Mux.h: https://github.com/mikedotalmond/Arduino-Mux-CD74HC4067




Archivo Arduino_Multiplexor.ino:

1.- Código original para encender 16 leds de una en una desde Arduino con un multiplexor. Código de ejemplo para el código de Ard_Mux_Dimmer.ino