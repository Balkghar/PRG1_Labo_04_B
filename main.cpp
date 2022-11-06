//---------------------------------------------------------
// Fichier      : main.cpp
// Auteur       : Edwin Häffner & Hugo Germano
// Date         : 02.11.2022

// But          : Programme qui affiche pour une année [1800 – 2100] saisie par l’utilisateur le calendrier complet en
//                tenant compte des années bissextiles.
//
// Remarque     : 
//
// Modifs       :
//
// Compilateur  : gcc (Ubuntu 11.2.0-19ubuntu1) 11.2.0
//---------------------------------------------------------

#include <cstdlib>      // EXIT_SUCCESS
#include <iostream>     // cout et cin
#include "calendrier.hpp" //header pour la déclaration de fonction

using namespace std;

int main() {

   //Déclaration des constantes
   const int    MIN_ANNEE = 1800, MAX_ANNEE = 2100;
   const char   OUI = 'O', NON  = 'N';
   const string DEMANDE_ANNEE   = "Veuillez entrer une année dans l'intervalle entre [" +
                                  to_string(MIN_ANNEE) + "-"+ to_string(MAX_ANNEE) +"]: ";
   const string RECOMMENCER     = "Voulez vous recommencer ? [O/N]: ";

   //Déclaration des années
   int      annee;
   bool continuer;


   //Boucle pour repeter le programme si l'utilisateur le souhaite
   do{
      //saisie de l'utilisateur pour l'année
      annee     = saisie(MAX_ANNEE, MIN_ANNEE, DEMANDE_ANNEE);
      //Appel la fonction qui affiche le calendrier
      affichageCalendrier(annee);
      //saisie si l'utilisateur veut contiuner
      continuer = saisie(OUI,NON,RECOMMENCER);
   }while(continuer);


   return EXIT_SUCCESS; //Retourne un code de succès et quitte le programme
}