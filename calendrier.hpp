//---------------------------------------------------------
// Fichier      : calendrier.hpp
// Auteur       : Edwin Häffner & Hugo Germano
// Date         : 02.11.2022

// But          : 
//
// Remarque     : 
//
// Modifs       :
//
// Compilateur  : gcc (Ubuntu 11.2.0-19ubuntu1) 11.2.0
//---------------------------------------------------------
#include <iostream>         //string

#ifndef calendrier

   #define calendrier
   // Le sous programme qui gère tout l'affichage du calendrier
   void affichageCalendrier(int annee);

   //fonction de saisie
   int saisie(int maxInt, int minInt, std::string message);
   bool saisie(char oui, char non, std::string message);

#endif