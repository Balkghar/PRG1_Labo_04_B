//---------------------------------------------------------
// Fichier      : calendrier.cpp
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
#include <iomanip>
#include <limits>       // numeric_limits<streamsize>

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(),'\n')

using namespace std;
int main() {

   //déclaration des constantes
   const int DECIMALES = 2;


   cout << fixed << setprecision(DECIMALES);
   
   cout << "Entrez ENTER pour quitter.";
   VIDER_BUFFER;
   salut a tous les amis;
   return EXIT_SUCCESS; //retourne un code de succès
}
