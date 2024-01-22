// Define input pins for sensors and motor control pins
const int in1 = 2;
const int in2 = 5;
const int in3 = 6;
const int in4 = 8;

const int SensorLeft = 7;
const int SensorMiddle = 4;
const int SensorRight = 3;

// Variables to store sensor readings
bool etatCapteurGauche;
bool etatCapteurCentre;
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
  pinMode(SensorMiddle, INPUT); 
  pinMode(SensorRight, INPUT); 
} 

void loop() { 
  // Read sensor values
  etatCapteurGauche = digitalRead(SensorLeft); 
  etatCapteurCentre = digitalRead(SensorMiddle); 
  etatCapteurDroit = digitalRead(SensorRight); 
  
  // Check sensor readings and control the robot accordingly
  if(etatCapteurCentre) { 
    if ((etatCapteurGauche) && (!etatCapteurDroit)) { 
      // Turn left if there is black on the left and white on the right
      Serial.println("Tourner à gauche");
      turn_left();
    } 
    else if ((!etatCapteurGauche) && (etatCapteurDroit)) { 
      // Turn right if there is white on the left and black on the right
      Serial.println("Tourner à droite");
      turn_right();
    } 
    else { 
      // Continue forward if the above conditions do not apply
      Serial.println("Continuer tout droit");
      forward();
    } 
  } 
  else { 
    if ((etatCapteurGauche) && (!etatCapteurDroit)) { 
      // Turn left if there is black on the left and white on the right
      Serial.println("Tourner à gauche");
      turn_left();
    }
    else if ((!etatCapteurGauche) && (etatCapteurDroit)) { 
      // Turn right if there is white on the left and black on the right
      Serial.println("Tourner à droite");
      turn_right();
    } 
    else { 
      // Reverse if the above conditions do not apply
      Serial.println("Reculer"); 
      reverse();
    } 
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

// Function to reverse the robot
void reverse() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
