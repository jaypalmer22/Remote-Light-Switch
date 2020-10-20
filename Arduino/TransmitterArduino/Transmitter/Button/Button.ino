
#include <VirtualWire.h>

int RF_TX_PIN = 2;

void setup()
{
 vw_set_tx_pin(RF_TX_PIN); // Setup transmit pin
 vw_setup(2000); // Transmission speed in bits per second.
 pinMode(3, INPUT_PULLUP);
 pinMode(13, OUTPUT); 
}

void loop()
{
 int sensorVal = digitalRead(3);
 // If button pressed, send confirmation, else send zero signal
 if (sensorVal == HIGH) {
   digitalWrite(13, LOW);
   const char *msg = "0";
   vw_send((uint8_t *)msg, strlen(msg)); 
   delay(20);
 } 
 else {
   digitalWrite(13, HIGH);
   const char *msg = "1";
   vw_send((uint8_t *)msg, strlen(msg)); 
   delay(20);
 }
}
