/**
 * @file main.ino
 * @author Projet Smarties IUT-BM
 * @brief Fichier principal pour le programme Arduino
 * @version 0.1
 * @date 2021-01-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <arduino.h>

#include "mycolor.hpp"
#include "monServo.hpp"
#include "moteur.hpp"

Color currentColor = BLANC;

Moteur moteur(2,3,400);
MonServo servo(9);

void setup() {

  colorSetup();
  servo.attach(9);
  Serial.begin(9600);
}

void loop() {

    currentColor = getColor(20);
    servo.setEvacuation(currentColor);
    moteur.setRotation(Moteur::Dir::CCW,100,1200);
    
    delay(100);

    /*Apprentissage*/

    /*getColor(100);
    delay(1000);*/


}
