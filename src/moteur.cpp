#include "moteur.hpp"

/**
 * @brief Moteur
 * 
 * @param dirPin Pin de direction
 * @param stepPin Pin de pas
 * @param stepsPerRevolution Nombre de pas pour une révolution du moteur (Dépend du borchage)
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
 * @param direction Direction du moteur CCW (Counter Clock Wise) Ou CW (Clock wise)
 * @param steps Nombre de pas a effectuer
 * @param delay Delay (ajuste la vitesse de rotation) , faire attention lors de la modification
 */
void Moteur::setRotation(Moteur::Dir direction, int steps, int delay){

    digitalWrite(m_dirPin, (int)direction);

    int j = delay*3;

    /*Phase d'accélération 1/8 de la rotation*/
    for (int i = 0; i < steps/8; i++) { 
      
      digitalWrite(m_stepPin, HIGH);
      delayMicroseconds(j);
      digitalWrite(m_stepPin, LOW);
      delayMicroseconds(j);

      j -= (delay*2)/(steps/8);
    }

    /*Vitesse constante 6/8 de la rotation*/
    for (int i = 0; i <= (3*steps)/4; i++) {
      
      digitalWrite(m_stepPin, HIGH);
      delayMicroseconds(delay);
      digitalWrite(m_stepPin, LOW);
      delayMicroseconds(delay);
    }

    j = delay;
    
    /*Phase de déscéleration 1/8 de la rotation*/
    for (int i = 0; i < steps/8; i++) {
      
      digitalWrite(m_stepPin, HIGH);
      delayMicroseconds(j);
      digitalWrite(m_stepPin, LOW);
      delayMicroseconds(j);

      j+= (delay*2)/(steps/8);
    }



}