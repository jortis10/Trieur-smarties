#include "monServo.hpp"

/**
 * @brief Construct a new Mon Servo:: Mon Servo object
 * 
 * @param servoPin 
 */
MonServo::MonServo(int servoPin) : Servo()
{

    m_servoPin = servoPin;

}

/**
 * @brief Met en position le servo pour l'évacuation
 * 
 * @param color 
 */
void MonServo::setEvacuation(Color color){

    int servoPos = map((int)color,0,8,30,150);
    Serial.println(servoPos);
    
    this->write(servoPos);
     
    delay(500);                       

}

