/**
 * @file monServo.hpp
 * @author Projet Smarties IUT-BM
 * @brief Contient la class de l'objet servomoteur
 * @version 0.1
 * @date 2021-03-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef HEADER_MONSERVO_HPP
#define HEADER_MONSERVO_HPP

#include <arduino.h>
#include <Servo.h>

#include "mycolor.hpp"

class MonServo : public Servo
{

private:

    int m_servoPin = 2;

public:

    MonServo(int servoPin);
    void setEvacuation(Color color);

};


#endif