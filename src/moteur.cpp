#include "moteur.hpp"

/**
 * @brief Moteur
 * 
 * @param dirPin 
 * @param stepPin 
 * @param stepsPerRevolution 
 */
Moteur::Moteur(int dirPin, int stepPin, int stepsPerRevolution){

    m_dirPin = dirPin;
    m_stepPin = stepPin;
    m_stepsPerRevolution = stepsPerRevolution;

    pinMode(m_stepPin, OUTPUT);
    pinMode(m_dirPin, OUTPUT);
   
}

/**
 * @brief Met en rotation le moteur avec phase acceleration / déccélération
 * 
 * @param direction 
 * @param steps 
 * @param delay 
 */
void Moteur::setRotation(Moteur::Dir direction, int steps, int delay){

    digitalWrite(m_dirPin, (int)direction);

    int j = delay*3;

    /*Acceleration*/
    for (int i = 0; i < steps/8; i++) { 
      
      digitalWrite(m_stepPin, HIGH);
      delayMicroseconds(j);
      digitalWrite(m_stepPin, LOW);
      delayMicroseconds(j);

      j -= (delay*2)/(steps/8);
    }

    /*Vitesse constante*/
    for (int i = 0; i <= (3*steps)/4; i++) {
      
      digitalWrite(m_stepPin, HIGH);
      delayMicroseconds(delay);
      digitalWrite(m_stepPin, LOW);
      delayMicroseconds(delay);
    }

    j = delay;
    
    /*Desceleration*/
    for (int i = 0; i < steps/8; i++) {
      
      digitalWrite(m_stepPin, HIGH);
      delayMicroseconds(j);
      digitalWrite(m_stepPin, LOW);
      delayMicroseconds(j);

      j+= (delay*2)/(steps/8);
    }



}