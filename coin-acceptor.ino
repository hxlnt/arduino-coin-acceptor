// Arduino coin acceptor code by hxlnt
// Originally created for "Adding a Coin Acceptor to Your Arduino Project" on the Maker Show
// See the entire video tutorial at https://channel9.msdn.com/Shows/themakershow/10
// 
// Read your coin acceptor's specs and instructions first for hookup specifics
// Modifications to this code may be needed
// Coin acceptor model used in this example is JY-923
//
// xoxox



// Constants
const int coinpin = 2;
const int ledpin = 3;
const int targetcents = 100;

// Variables
volatile int cents = 0;
int credits = 0;

// Setup
void setup() {
  
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(coinpin), coinInterrupt, RISING);
  pinMode(ledpin, OUTPUT);
  
}

// Main loop
void loop() {
  
  // If we've hit our target amount of coins, increment our credits and reset the cents counter
  if (cents >= targetcents) {
    credits = credits + 1;
    cents = cents - targetcents;
  }

  // If we haven't reached our target, keep waiting...
  else {
  }

  // Debugging zone
  Serial.print(cents);
  Serial.print(" cents toward current credit and ");
  Serial.print(credits);
  Serial.println(" credit(s) earned so far.");
  delay(1000);

  // Turn off LED
  digitalWrite(ledpin, LOW);

  // Now, write your own cool code here that triggers an event when the player has credits!
  if (credits > 0) {
    // Play music?
    // Spin up a motor?
    // Start a game?
    // It's up to you!
  }
  
}

// Interrupt
void coinInterrupt(){
  
  // Each time a pulse is sent from the coin acceptor, interrupt main loop to add 1 cent and flip on the LED
  cents = cents + 1;
  digitalWrite(ledpin, HIGH);
  
}

