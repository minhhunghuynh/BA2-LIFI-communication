#define LED_PIN 13
#define PERIOD 200  // Durée d'un bit en microsecondes
#define IDLE_PERIOD 200

char* string = "SEND";
int string_length;

byte lc;
byte mc;

void wait_us(unsigned long period_us) {
  unsigned long start_time = micros();
  while (micros() - start_time < period_us) {
    // Boucle d'attente active
  }
}

// Fonction pour calculer le code Hamming(7,4)
byte hamming_7_4(byte nibble) {
  byte d0 = (nibble >>0) & 1; // LSB (Least Significant Bit)
  byte d1 = (nibble >> 1) & 1;
  byte d2 = (nibble >> 2) & 1;
  byte d3 = (nibble >> 3) & 1; // MSB (Most Significant Bit)

  byte p1 = d0 ^ d1 ^ d3; // Parité pour les positions 1, 3, 5, 7
  byte p2 = d0 ^ d2 ^ d3;// Parité pour les positions 2, 3, 6, 7
  byte p4 = d1 ^ d2 ^ d3; // Parité pour les positions 4, 5, 6, 7

  // Construction du mot encodé (ordre : p1, p2, d3, p4, d2, d1, d0)
  return (p1 << 6) | (p2 << 5) | (d3 << 4) | (p4 << 3) | (d2 << 2) | (d1 << 1) | d0;
}

byte addLastBit(byte my_byte, bool msb) {
  if (msb) {
    return my_byte |= 0x80;
  }
  else {
    return my_byte &= 0x7F;
  }
}

void send_byte(byte my_byte) {
  // Diviser l'octet en deux nibbles (4 bits chacun)
  byte low_nibble = my_byte & 0x0F;         // Bits de poids faible
  byte high_nibble = (my_byte >> 4) & 0x0F; // Bits de poids fort

  // Encoder chaque nibble en Hamming(7,4)
  byte encoded_low = hamming_7_4(low_nibble);
  byte encoded_high = hamming_7_4(high_nibble);

  // Envoyer les deux nibbles encodés
  lc = addLastBit(encoded_low, false);
  mc = addLastBit(encoded_high, true);
  send_encoded_byte(lc);
  send_encoded_byte(mc);
}


void send_encoded_byte(byte encoded_byte) {
  // START BIT (indique le début de transmission)
  digitalWrite(LED_PIN, LOW);
  wait_us(PERIOD);

  // Transmission des 8 bits (LSB en premier)
  for (int j = 0; j < 8; j++) {
    digitalWrite(LED_PIN, (encoded_byte & (0x01 << j)) != 0);
    wait_us(PERIOD);
  }
  // STOP BIT (indique la fin de transmission)
  digitalWrite(LED_PIN, HIGH);
  wait_us(PERIOD);

  // IDLE PERIOD (séparation entre les octets)
  wait_us(IDLE_PERIOD);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  string_length = strlen(string);
}
void loop() {
    for (int i = 0; i < string_length; i++) {
    send_byte(string[i]);
  }
}

