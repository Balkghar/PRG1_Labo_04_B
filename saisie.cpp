//---------------------------------------------------------
// Fichier      : saisie.cpp
// Auteur       : Edwin Häffner & Hugo Germano
// Date         : 02.11.2022

// But          : Code pour la saisie d'un utilisateur jusqu'à qu'elle soit correct
//                
//
// Remarque     : 
//
// Modifs       :
//
// Compilateur  : gcc (Ubuntu 11.2.0-19ubuntu1) 11.2.0
//---------------------------------------------------------

#include <iostream>     // cout et cin
#include <limits>       // numeric_limits<streamsize>
#include "calendrier.hpp" //header pour la déclaration de fonction

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(),'\n') //Macro pour vider le buffer

using namespace std;

// Nom         saisie
// But         demande la saisie à l'utilisateur jusqu'à qu'elle soit correct et la retourne
//             
// Param       maxInt  le maximum autorisé
// Param       minInt  le minimum autorisé
// Param       message message d'invitation de saisie
// Exception   n/a
int saisie(int maxInt, int minInt, const string& message){
   int saisie;
   do{
         cout << message;
         cin  >>  saisie;
         VIDER_BUFFER;

   }while(saisie < minInt or saisie > maxInt);
   return saisie;
}

// Nom         saisie
// But         demande de saisie pour l'utilisateur jusqu'à qu'elle soit correct, retourne un booléun selon l'entrée de l'utilisateur
//             
// Param       oui  le char oui
// Param       non  le char non
// Param       message  message d'invitation de saisie
// Exception   n/a
bool saisie(char oui, char non, const string& message){
      char continuer;
      do{
            cout <<   message;
            cin  >> continuer;
            VIDER_BUFFER;
      }while(continuer != oui and continuer != non);

   if(continuer == oui){return true;}else{return false;}
}