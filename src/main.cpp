/**
 * @file main.ino
 * @author Projet Smarties IUT-BM
 * @brief Fichier qui contient la routine principal du trieur
 * @version 0.1
 * @date 2021-01-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "mycolor.hpp"
#include "monServo.hpp"
#include "moteur.hpp"

Color currentColor = BLANC;

Moteur moteur(2,3,400);
MonServo servo(9);

/*Initialisation des composants*/
void setup() {

  colorSetup();
  servo.attach(9);
  Serial.begin(9600);
}

/*Routine*/
void loop() {

    /*On lit la couleur courante avec une moyenne de 20 échantillions pour la précision*/
    currentColor = getColor(20);
    /*On positionne l'évacuation*/
    servo.setEvacuation(currentColor);
    /*On effectue la rotation d'un quart de tour*/
    moteur.setRotation(Moteur::Dir::CCW,100,1200);
    
    /*Petite pause pour que le smarties est le temps d'évacuer*/
    delay(100);

    /*Apprentissage : Permet de faire seulement une mesure de 100 échantillions pour parametrer le capteur de couleur*/
    /*getColor(100);
    delay(1000);*/


}
