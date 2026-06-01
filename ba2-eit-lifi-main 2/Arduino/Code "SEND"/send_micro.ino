// Définition des constantes
#define LED_PIN 13  // Broche de la LED utilisée pour la transmission
#define PERIOD 200  // Durée d'un bit en microsecondes (0.2 ms) = 1/bitrate ms
#define IDLE_PERIOD 200

char* string = "SEND";  // Message à transmettre
int string_length;      // Longueur de la chaîne

// Fonction pour attendre une durée donnée en microsecondes
void wait_us(unsigned long period_us) {
  unsigned long start_time = micros();  // Enregistre le temps de départ
  while (micros() - start_time < period_us) {
    // Attendre sans rien faire
  }
}
// Fonction pour envoyer un octet via la LED
void send_byte(char my_byte) {
  // START BIT : Signale le début de la trame
  digitalWrite(LED_PIN, LOW); // Allume la LED (état bas pour le start bit)
  wait_us(PERIOD);  // Attente de la durée d'un bit

  // Transmission des bits de données (8 bits)
  for (int j = 0; j < 8; j++) {
    // Vérifie si le bit j est à 1 ou 0 et ajuste la LED en conséquence
    digitalWrite(LED_PIN, (my_byte & (0x01 << j)) != 0);
    wait_us(PERIOD);  // Attente de la durée d'un bit
  }

  // STOP BIT : Signale la fin de la transmission
  digitalWrite(LED_PIN, HIGH);  // Éteint la LED (état haut pour le stop bit)
  wait_us(PERIOD);  // Attente de la durée d'un bit

  //IDLE BIT : Temps d'inactivité entre les octets
  wait_us(IDLE_PERIOD);  // Attente de la période d'inactivité
}


void setup() {
  pinMode(LED_PIN, OUTPUT);  // Configure la broche de la LED comme sortie
  string_length = strlen(string);  // Calcule la longueur de la chaîne à transmettre
  digitalWrite(LED_PIN, HIGH); //Initialise la LED
  delay(100);
  

}

void loop() { 
  // Envoi de chaque caractère de la chaîne
  for (int i = 0; i < string_length; i++) {
    send_byte(string[i]);   // Envoie l'octet correspondant au caractère
  }
} 
