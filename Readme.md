
C�digo para conectar Arduino a un m�dulo Dimmer de 4 Canales a trav�s de multiplexor.

Archivo Ard_Mux_Dimmer.ino:
1.- Se inicia con el c�digo que enciende luces a distinta intensidad desde Arduino al m�dulo Dimmer con 4 canales con bombillas dimmeables a 220v AC.
2.- Se a�ade c�digo para que haga lo mismo, pero pasando por un multiplexor. El pin 3 de Arduino se conecta directamente con el m�dulo dimmer.

Archivo Arduino_Multiplexor.ino:
1.- C�digo original para encender 16 leds de una en una desde Arduino con un multiplexor. C�digo de ejemplo para el c�digo de Ard_Mux_Dimmer.ino