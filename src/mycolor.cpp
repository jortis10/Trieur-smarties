/**
 * @file mycolor.cpp
 * @author Projet Smarties IUT-BM
 * @brief Permet l'utilisation du capteur de couleur (test)
 * @version 0.1
 * @date 2021-01-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "mycolor.hpp"

char* color[] = {"Blanc", "Orange", "Jaune", "Rouge", "Vert", "bleu","violet","rose","marron", "Erreur"};

/*Ici on entre les valeurs RGB pour calibrer le capteur de couleur, les positions sont celle de char* color[]*/
int learned_colors[3][9] = {{28,32,31,32,29,25,25,27,31},  //R  
                            {33,32,35,29,36,33,31,30,34},  //G
                            {40,36,34,39,37,44,42,41,37}}; //G

int PercentageRed = 0, PercentageGreen = 0, PercentageBlue = 0;
float OutOfRange;

/**
 * @brief Fonction qui initialise les broches du capteur
 * 
 */
void colorSetup(){
  pinMode(PIN_S0, OUTPUT);
  pinMode(PIN_S1, OUTPUT);
  pinMode(PIN_S2, OUTPUT);
  pinMode(PIN_S3, OUTPUT);
  pinMode(PIN_OUT, INPUT);
  pinMode(LED, OUTPUT);
}

/**
 * @brief Fonction qui initialise le capteur de couleur
 * 
 */
void TCS3200_On() {

  digitalWrite(LED,HIGH); 
  digitalWrite(PIN_S0,HIGH);
  digitalWrite(PIN_S1,HIGH);
  delay(5);

}

/**
 * @brief Fonction qui reinitialise le capteur de couleur
 * 
 */
void TCS3200_Off() {

  digitalWrite(LED,LOW);
  digitalWrite(PIN_S0,LOW);
  digitalWrite(PIN_S1,LOW);

}

/**
 * @brief Fonction qui permet de selectionner aucun filtre
 * 
 */
void NoFilter() {

  digitalWrite(PIN_S2,HIGH); // select no filter
  digitalWrite(PIN_S3,LOW);
  delay(5);

}

/**
 * @brief Fonction qui sélectionne le filtre rouge pour la mesure du rouge
 * 
 */
void RedFilter() {

  digitalWrite(PIN_S2,LOW);
  digitalWrite(PIN_S3,LOW);
  delay(5);

}

/**
 * @brief Fonction qui sélectionne le filtre vert pour la mesure du vert
 * 
 */
void GreenFilter() {

  digitalWrite(PIN_S2,HIGH);
  digitalWrite(PIN_S3,HIGH);
  delay(5);

}

/**
 * @brief Fonction qui sélectionne le filtre bleu pour la mesure du bleu
 * 
 */
void BlueFilter() {

  digitalWrite(PIN_S2,LOW);
  digitalWrite(PIN_S3,HIGH);
  delay(5);

}


/**
 * @brief Fontion qui récupère la couleur courante
 * 
 * @param echantillions 
 * @return Color 
 */
Color getColor(byte echantillions) {

  float FrequencyClear, FrequencyRed, FrequencyGreen, FrequencyBlue;
  int colorget;
  Color color = BLANC;

  for (int i = 0 ; i < echantillions ; i++){
    TCS3200_On();
    NoFilter();

    FrequencyClear = float(pulseIn(PIN_OUT,LOW,10000));

    RedFilter();
    FrequencyRed = float(pulseIn(PIN_OUT,LOW,10000));

    GreenFilter();
    FrequencyGreen = float(pulseIn(PIN_OUT,LOW,10000));

    BlueFilter();
    FrequencyBlue = float(pulseIn(PIN_OUT,LOW,10000));

    TCS3200_Off();

    PercentageRed += int((FrequencyClear / FrequencyRed) * 100.0);
    PercentageGreen += int((FrequencyClear / FrequencyGreen) * 100.0);
    PercentageBlue += int((FrequencyClear / FrequencyBlue) * 100.0);

    OutOfRange = 500.0 / FrequencyClear;
  }

  PercentageRed = PercentageRed / echantillions;
  PercentageGreen = PercentageGreen / echantillions;
  PercentageBlue = PercentageBlue / echantillions;

  /*Affichage sur le port série des valeurs RGB*/
  Serial.print("Rouge : ");
  Serial.print(PercentageRed);
  Serial.print(" Vert : ");
  Serial.print(PercentageGreen);
  Serial.print(" Bleu : ");
  Serial.println(PercentageBlue);

  /*On associe une couleur aux valeurs*/
  colorget = classify();

  /*On return la couleur*/
  if (colorget == 0){
    color = BLANC;
    Serial.println("Detecter BLANC");
  }
  else if (colorget == 1){
    color = ORANGE;
    Serial.println("Detecter ORANGE");
  }
  else if (colorget == 2){
    Serial.println("Detecter JAUNE");
    color = JAUNE;
  }
  else if (colorget == 3){
    Serial.println("Detecter ROUGE");
    color = ROUGE;
  }
  else if (colorget == 4){
    Serial.println("Detecter VERT");
    color = VERT;
  }
  else if (colorget == 5){
    Serial.println("Detecter BLEU");
    color = BLEU;
  }
  else if (colorget == 6){
    Serial.println("Detecter VIOLET");
    color = VIOLET;
  }
  else if (colorget == 7){
    Serial.println("Detecter ROSE");
    color = ROSE;
  }
  else if (colorget == 8){
    Serial.println("Detecter MARRON");
    color = MARRON;
  }
  else if (colorget == 9){
    Serial.println("Detecter ERREUR");
    color = BLANC;
  }

  return color;
}

/**
 * @brief Fonction qui associe la couleur la plus "proche" à la couleur en lecture
 * 
 * @return int 
 */
int classify() {

  int i_color;
  int ClosestColor;
  float MaxDiff;
  float MinDiff = 100.0;

  if(OutOfRange < 1.5) ClosestColor = 9; // object out of range

  else {
    for (i_color = 0; i_color < 9; i_color ++) {

      float ED = sqrt(pow((learned_colors[0][i_color] - PercentageRed),2.0) + pow((learned_colors[1][i_color] - PercentageGreen),2.0) + pow((learned_colors[2][i_color] - PercentageBlue),2.0));
      MaxDiff = ED;

      if (MaxDiff < MinDiff) {
        MinDiff = MaxDiff;
        ClosestColor = i_color;
      }
    }
  }

  return ClosestColor;

}
