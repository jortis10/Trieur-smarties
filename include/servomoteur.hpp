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

#ifndef HEADER_SERVOMOTEUR_HPP
#define HEADER_SERVOMOTEUR_HPP

#include <Servo.h>
#include "couleur.hpp"

#define PIN_SERVO 9

class Servomoteur : public Servo
{

private:

    int m_servoPin = PIN_SERVO;

public:

    Servomoteur(int servoPin);
    void setEvacuation(Color color);

};


#endif