#include "servomoteur.hpp"

/**
 * @brief Servo moteur
 * 
 * @param servoPin pin du servomoteur
 */
Servomoteur::Servomoteur(int servoPin) : Servo()
{

    m_servoPin = servoPin;

}

/**
 * @brief Met en position le servo pour l'évacuation
 * 
 * @param color 
 */
void Servomoteur::setEvacuation(Color color){

    /*On associe une position du servo pour chaque couleurs*/
    int servoPos = map((int)color,0,8,30,150);
    
    this->write(servoPos);
     
    delay(500);                       

}

