// Define motor control pins
const int in1 = 7;
const int in2 = 8;
const int in3 = 9;
const int in4 = 10;

// Define sensor pins
const int SensorLeft = 12;
const int SensorRight = 11;

// Variables to store sensor readings
bool etatCapteurGauche;
bool etatCapteurDroit;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set motor control pins as OUTPUT
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Set sensor pins as INPUT
  pinMode(SensorLeft, INPUT);
  pinMode(SensorRight, INPUT);
}

void loop() {
  // Read sensor values
  etatCapteurGauche = digitalRead(SensorLeft);
  etatCapteurDroit = digitalRead(SensorRight);

  // Check sensor readings and control the robot accordingly
  if (etatCapteurGauche) {
    // Turn left if the left sensor detects an obstacle
    Serial.println("Tourner à gauche");
    turn_left();
  } else if (etatCapteurDroit) {
    // Turn right if the right sensor detects an obstacle
    Serial.println("Tourner à droite");
    turn_right();
  } else {
    // Continue forward if no obstacles are detected
    Serial.println("Continuer tout droit");
    forward();
  }
}

// Function to move the robot forward
void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

// Function to turn the robot left
void turn_left() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

// Function to turn the robot right
void turn_right() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
