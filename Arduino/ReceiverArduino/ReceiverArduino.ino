#include <ServoTimer2.h>
#include <VirtualWire.h>

const int led_pin = 6;
const int transmit_pin = 12;
const int receive_pin = 11;
const int transmit_en_pin = 3;

ServoTimer2 servo;
int pos = 0;
int count = 1;

void setup() {
  delay(1000);
  Serial.begin(9600);
  Serial.println("setup");

  // Servo Setup
  servo.attach(9);
  servo.write(0);

  // Set up Virtual Wire pins
  vw_set_tx_pin(transmit_pin);
  vw_set_rx_pin(receive_pin);
  vw_set_ptt_pin(transmit_en_pin);
  
  vw_set_ptt_inverted(true);
  vw_setup(2000);

  // Start Receiver
  vw_rx_start();
}

void loop() {

  // Virtual wire buffer
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  // Message Received
  if (vw_get_message(buf, &buflen)) {

   // If light switch is up
   if (count % 2 == 0) {
    // 0 degrees
    servo.write(750);
    Serial.println("0");
   } else {
    // ~170 degrees
    servo.write(2150);
    Serial.println("1");
   }
   // Switch is up (even) or down (odd)
    count++;
    digitalWrite(led_pin, HIGH);
    digitalWrite(led_pin, LOW);
  }
  
}
