/**
 * @file moteur.hpp
 * @author Projet Smarties IUT-BM
 * @brief Contient la classe de l'objet moteur pas à pas
 * @version 0.1
 * @date 2021-03-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef HEADER_MOTEUR_HPP
#define HEADER_MOTEUR_HPP

#include <arduino.h>

#define STEPSPERREVOLUTION 400
#define PIN_STEP 3
#define PIN_DIR 2

class Moteur{

private:

    int m_dirPin = PIN_DIR;
    int m_stepPin = PIN_STEP;
    int m_stepsPerRevolution = STEPSPERREVOLUTION;

public:

    enum class Dir{CW = 1, CCW = 0};

    Moteur(int dirPin, int stepPin, int stepsPerRevolution);
    void setRotation(Dir direction, int steps, int delay);

};


#endif