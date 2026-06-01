/* 
 * Ce projet illustre modifier l'intensité lumineuse du ruban LED (sans utiliser analogWrite).
 * Il utilise aussi la communication série (Serial) pour permettre à l'utilisateur de changer
 * l'intensité lumineuse.
 */


// Définition des pattes utilisées
#define LED_PIN 9

// Définition des constantes utilisées
#define PERIOD_US 1000

// Définition des variables
long nextTimeUs;  // prochain moment où il faut agir sur le ruban LED, en us 
int onTimeUs;     // durée durant laquelle le ruban doit être allumé, en us
int offTimeUs;    // durée durant laquelle le ruban doit être éteint, en us


void setup() {
  // Initialisation de la communication série et envoi des instructions
  Serial.begin(9600);
  Serial.println("\nATTENTION : sélectionnez 'No Line Ending' comme paramètre de fin de ligne");
  Serial.println("Entrez l'intensité désirée, en % : ");
  // Initialisation de la patte commandant le ruban LED et des variables associées
  onTimeUs = 0;
  offTimeUs = PERIOD_US;
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  /* micros() nous donne le temps écoulé en us.
   * On veut que la boucle démarre tout de suite, on initialise donc nextTimeUs à l'instant présent */
  nextTimeUs = micros();
}


void loop() {
  int intensity;

  // Gestion du ruban
  if ( (onTimeUs > 0) && (offTimeUs > 0) ) {  // si on est à 0 ou 100%, on ne doit rien faire
  // Allumage du ruban LED
    while ( nextTimeUs > micros() );      // on attend le moment où il faut allumer le ruban
    digitalWrite(LED_PIN, HIGH);
    nextTimeUs = nextTimeUs + onTimeUs;     // mise à jour du prochain moment
    // Extinction du ruban LED
    while( nextTimeUs > micros() );
    digitalWrite(LED_PIN, LOW);
    nextTimeUs = nextTimeUs + offTimeUs;
  }
  // Gestion de la commuunication série
  if ( Serial.available() ) {         // si on a reçu quelque chose
    intensity = Serial.parseInt();    // on l'interprète comme un entier
    onTimeUs = (1000*intensity)/100;  // on calcule le on time correspondant  
    /* on sature onTimeUs pour rester dans l'intervalle utile (0 -> PERIOD_US)
     * on traite aussi les cas limites (0% et 100%) en excluant 0 et PERIOD_US de l'intervalle utile */ 
    if (onTimeUs <= 0) {
      onTimeUs = 0;
      digitalWrite(LED_PIN, LOW);
    } else if (onTimeUs >= 1000) {
      onTimeUs = 1000;
      digitalWrite(LED_PIN, HIGH);
    }
    offTimeUs = PERIOD_US - onTimeUs;
    // Envoi des résultats du calcul pour debug
    Serial.print("New on time: ");
    Serial.println(onTimeUs);
    Serial.print("New off time: ");
    Serial.println(offTimeUs);
  }
}
