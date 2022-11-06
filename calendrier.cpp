//---------------------------------------------------------
// Fichier      : calendrier.cpp
// Auteur       : Edwin Häffner & Hugo Germano
// Date         : 02.11.2022

// But          : Fonction affichant le calendrier d'une année donnée
//
// Remarque     : 
//
// Modifs       :
//
// Compilateur  : gcc (Ubuntu 11.2.0-19ubuntu1) 11.2.0
//---------------------------------------------------------

#include <iostream>         // cout et cin
#include <iomanip>          // setw
#include "calendrier.hpp"   //header pour la déclaration de fonction

using namespace std;

// Nom         premierJourAnnee
// But         Retourne le premier jour de l'année
//             Utilisant l'algorithme de Zeller
// Param       annee : l'année dont on veut le premier jour
// Return      int entre 1 et 7 (Lundi = 1, Mardi = 2, etc.)
// Exception   n/a
// Source : https://www.codespeedy.com/how-to-find-day-from-date-in-cpp/
int premierJourAnnee (int annee) {

    annee -= 1; //On décrémente l'année de 1
    return ((annee + annee/4 - annee/100 + annee/400 ) % 7) + 1; //retourne le premier jour de l'année

}

// Nom         bissextile
// But         Retourne vrai si l'année est bissextile
//
// Param       annee : l'année dont on veut savoir si elle est bissextile
// Return      bool : vrai si l'année est bissextile
// Exception   n/a
bool bissextile (int annee){ //Verification si l'année est bissextile !

    bool bissextile = false; //Initialisation de la variable en false

    if (annee % 400 == 0 or (annee % 4 == 0 and annee % 100 != 0)){ //Verification si l'année est bissextile
        bissextile = true;
    }

    return bissextile; //Retourne si l'année est bissextile ou non
}

// Nom         affichageJours
// But         Affichage de tous les jours d'un mois, avec un jour de départ
//             
// Param       nombreJour  nombre de jour au sein de ce mois
// Param       jourDepart  le jour de la semaine dont le mois commence
// Return      int : Premier jour de semaine de l'année suivante
// Exception   n/a
int affichageJours(int nombreJour, int jourDepart){

    //Espace entre les dates
    const int ESPACE = 3, PREMIER_ESPACE = 2;

    //Affichage des jours de la semaine
    cout << setw(PREMIER_ESPACE) << "L" << setw(ESPACE) << "M" << setw(ESPACE) << "M" << setw(ESPACE) << "J" 
    << setw(ESPACE) << "V" << setw(ESPACE) << "S" << setw(ESPACE) << "D" << endl;
    
    //Déclaration des variables
    int jourSemaine =           jourDepart;
    int largeur     =   jourSemaine*ESPACE;
    //Affiche les date du mois
    for(int i = 1 ; i <= nombreJour; ++i){
        //Si le jour est un Lundi, on enlève un espace pour que ce soit bien aligné
        if (jourSemaine == 1 or i == 1){
            cout << setw(largeur-1) << i;
        } 
        //Autrement, affiche selon la largeur définie
        else {
            cout << setw(largeur)   << i;
        }
        //Si le jour est un Dimanche, on le remet à Lundi
        if(jourSemaine == 7 ){
            jourSemaine = 1;
            cout    << endl;
        }
        //Incrémente le jour de semaine
        else{
            jourSemaine++;
        }
        //Met la largeur à la valeur d'espace
        largeur = ESPACE;
    }
    cout << endl << endl;
    //Retourne le jour de la semaine
    return jourSemaine;
}

// Nom         affichageMois
// But         Affiche le mois appellé
//             
// Param       mois  le mois à afficher
// Param       jourDepart le jour de départ du mois
// Param       bissextile si l'année est bissextile
// Return      le premier de semaine du mois suivant
// Exception   n/a
int affichageMois(int mois, int jourDepart, bool bissextile){

    //Si le mois est février
    if(mois == 2){
        //On vérifie si l'année est bissextile grace à la fonction
        if(bissextile){
            return affichageJours(29, jourDepart);
        }
        else{
            return affichageJours(28, jourDepart);
        }
    }
    //Donne si le mois contient 30 ou 31 jours
    else if(mois == 4 || mois == 6 || mois==9 || mois == 11){
        return affichageJours(30, jourDepart);
    }
    else{
        return affichageJours(31, jourDepart);
    }
}

// Nom         quelMois
// But         retourne le string du mois demandé
//             
// Param       mois  le mois appelé
// Exception   n/a
string quelMois(int mois){
    switch (mois){
            case 1:
                mois = "Janvier "     ;
            case 2:
                mois = "Février "     ;
            case 3:
                mois ="Mars "        ;
            case 4:
                mois = "Avril "       ;
            case 5:
                mois = "Mai "         ;
            case 6:
                mois = "Juin "        ;
            case 7:
                mois = "Juillet "     ;
            case 8:
                mois = "Août "        ;
            case 9:
                mois = "Septembre "   ;
            case 10:
                mois = "Octobre "     ;
            case 11:
                mois = "Novembre "    ;
            case 12:
                return "Décembre "    ;
            default:
                return "Erreur"       ;
        }
}

// Nom         affichageCalendrier
// But         Afficher tous les mois d'une année donnée
//             
// Param       anneeUser  l'année à afficher
// Exception   n/a
void affichageCalendrier (int anneeUser){

    //Déclaration des variables
    int jourDepart = premierJourAnnee(anneeUser);
    bool biss = bissextile(anneeUser);


    //Affichage du calendrier

    string moisString;

    for (int i = 1; i <= 12; i++){

        //Affichage du mois
        moisString = quelMois(i);
        
        cout << moisString << anneeUser << endl;

        //Affiche les jours du mois
        jourDepart = affichageMois(i, jourDepart, biss);

    }
}