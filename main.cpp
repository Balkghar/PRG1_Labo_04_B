//---------------------------------------------------------
// Fichier      : main.cpp
// Auteur       : Edwin Häffner & Hugo Germano
// Date         : 02.11.2022

// But          : Programme qui affiche pour une année [1800 – 2100] saisie par l’utilisateur le calendrier complet en tenant compte des années bissextiles. 
//
// Remarque     : 
//
// Modifs       :
//
// Compilateur  : gcc (Ubuntu 11.2.0-19ubuntu1) 11.2.0
//---------------------------------------------------------

#include <cstdlib>      // EXIT_SUCCESS
#include <iostream>     // cout et cin
#include <limits>       // numeric_limits<streamsize>
#include "calendrier.hpp" //header pour la déclaration de fonction

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(),'\n')

using namespace std;

int main() {

   //déclaration des constantes
   const int   MIN_ANNEE = 1800, MAX_ANNEE = 2100;

   //déclaration des années
   int annee;
   char continuer;

   do{
      do{
         cout << "Veuillez entrer une année dans l'intervalle entre [" << MIN_ANNEE << "-"<< MAX_ANNEE << "]: ";
         cin >> annee;
         VIDER_BUFFER;

      }while(annee < MIN_ANNEE or annee > MAX_ANNEE);
      
      //appel la fonction qui affiche le calendrier
      affichageCalendrier(annee);
   
      do{
         cout << "Voulez vous recommencer ? [O/N]: ";
         cin >> continuer;
         VIDER_BUFFER;
      }while(continuer != 'O' and continuer != 'N');

   }while(continuer == 'O');


   return EXIT_SUCCESS; //retourne un code de succès
}