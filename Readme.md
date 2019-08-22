
Código para conectar Arduino a un módulo Dimmer de 4 Canales a través de multiplexor.

Archivo Ard_Mux_Dimmer.ino:
1.- Se inicia con el código que enciende luces a distinta intensidad desde Arduino al módulo Dimmer con 4 canales con bombillas dimmeables a 220v AC.
2.- Se añade código para que haga lo mismo, pero pasando por un multiplexor. El pin 3 de Arduino se conecta directamente con el módulo dimmer.

Archivo Arduino_Multiplexor.ino:
1.- Código original para encender 16 leds de una en una desde Arduino con un multiplexor. Código de ejemplo para el código de Ard_Mux_Dimmer.ino