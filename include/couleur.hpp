/**
 * @file mycolor.h
 * @author Projet Smarties IUT-BM
 * @brief Contient les déclarations des fonctions pour l'utilisation du capteur de couleur
 * @version 0.1
 * @date 2021-01-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef HEADER_COLOR_H
#define HEADER_COLOR_H

#include <arduino.h>

#define PIN_S0 4
#define PIN_S1 5
#define PIN_S2 6
#define PIN_S3 7
#define PIN_OUT 8
#define LED 10

/**
 * @brief Objet décrivant les différantes couleurs des smarties 
 * 
 */
enum Color{       
  BLANC,
  ROUGE,
  VERT,
  BLEU,
  JAUNE,
  ORANGE,
  VIOLET,
  ROSE,
  MARRON
};


Color getColor(byte echantillions);

void colorSetup();
void capteurOn();
void capteurOff();
void NoFilter();
void RedFilter();
void GreenFilter();
void BlueFilter();
int distance();



#endif