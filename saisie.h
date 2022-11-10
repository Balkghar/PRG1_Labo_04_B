//---------------------------------------------------------
// Fichier      : saisie.h
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

#ifndef saisie

   #define saisie

   int  saisir(int maxInt, int minInt, const std::string& message);
   bool repondOui(char oui, char non, const std::string& message);

#endif