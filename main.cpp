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
#include "calendrier.h" //header pour la déclaration de fonction
#include "saisie.h" //header pour la déclaration de fonction

using namespace std;

int main() {

   //Déclaration des constantes
   const int    MIN_ANNEE = 1800, MAX_ANNEE = 2100;
   const char   OUI = 'O', NON  = 'N';
   const string DEMANDE_ANNEE   = "Veuillez entrer une année dans l'intervalle entre [" +
                                  to_string(MIN_ANNEE) + "-"+ to_string(MAX_ANNEE) +"]: ";
   const string RECOMMENCER     = "Voulez vous recommencer ? [O/N]: ";


   //Boucle pour repeter le programme si l'utilisateur le souhaite
   do{

      const int ANNEE = saisir(MAX_ANNEE, MIN_ANNEE, DEMANDE_ANNEE);

      affichageCalendrier(ANNEE);

   }while(repondOui(OUI,NON,RECOMMENCER));


   return EXIT_SUCCESS; //Retourne un code de succès et quitte le programme
}