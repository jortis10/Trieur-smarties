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

class Moteur{

private:

    int m_dirPin = 2;
    int m_stepPin = 3;
    int m_stepsPerRevolution = 400;

public:

    enum class Dir{CW = 1, CCW = 0};

    Moteur(int dirPin, int stepPin, int stepsPerRevolution);
    void setRotation(Dir direction, int steps, int delay);

};


#endif