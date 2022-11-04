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

#include <iostream>     // cout et cin
#include <iomanip>
#include "calendrier.hpp"

using namespace::std;

// nom         saisie
// but         fonction de saisie
//             la saisie est controllée
// param       MSG_INVITE  message d'invite
// param       MIN         intervalle de saisie, valeur min comprise
// param       MAX         intervalle de saisie, valeur max comprise
// return      valeur saisie
// exception   n/a
//Source : https://www.codespeedy.com/how-to-find-day-from-date-in-cpp/
int premierJourAnnee (int annee) {


    annee -= 1;
    return ((annee + annee/4 - annee/100 + annee/400 ) % 7) + 1;

}

// nom         saisie
// but         fonction de saisie
//             la saisie est controllée
// param       MSG_INVITE  message d'invite
// param       MIN         intervalle de saisie, valeur min comprise
// param       MAX         intervalle de saisie, valeur max comprise
// return      valeur saisie
// exception   n/a
bool bissextile (int annee){ //Verification si l'année est bissextile !

    bool bissextile = false;

    if (annee % 400 == 0 or (annee % 4 == 0 and annee % 100 != 0)){
        bissextile = true;
    }

    return bissextile;
}

// nom         affichageJours
// but         Affichage de tous les jours d'un mois, avec un jour de départ
//             
// param       nombreJour  nombre de jour au sein de ce mois
// param       jourDepart  le jour de la semaine dont le mois commence
// return      premier jour de semaine de l'année suivante
// exception   n/a
int affichageJours(int nombreJour, int jourDepart){

    //espace entre les dates
    const int ESPACE = 3, PREMIER_ESPACE = 2;

    //affichage des jours de la semaine
    cout << setw(PREMIER_ESPACE) << "L" << setw(ESPACE) << "M" << setw(ESPACE) << "M" << setw(ESPACE) << "J" << setw(ESPACE) << "V" << setw(ESPACE) << "S" << setw(ESPACE) << "D" << endl;
    
    // déclaration des variables
    int jourSemaine = jourDepart;
    int largeur = jourSemaine*ESPACE;
    //affiche les date du mois
    for(int i = 1 ; i <= nombreJour; ++i){
        // si jour de semaine lundi, enlève un espace pour que ce soit bien aligné
        if (jourSemaine == 1 or i == 1){
            cout << setw(largeur-1) << i;
        } 
        //autrement, affiche selon la largeur 
        else {
            cout << setw(largeur) << i;
        }
        // si le jour de la semaine est dimanche, le remet à lundi
        if(jourSemaine == 7 ){
            jourSemaine = 1;
            cout << endl;
        }
        //incrémente le jour de semaine
        else{
            jourSemaine++;
        }
        //met la largeur à la valeur d'espace
        largeur = ESPACE;
    }
    cout << endl << endl;
    //return le jour de la semaine
    return jourSemaine;
}

// nom         affichageMois
// but         Affiche le mois appellé
//             
// param       mois  le mois à afficher
// param       jourDepart le jour de départ du mois
// param       bissextile si l'année est bissextile
// return      le premier de semaine du mois suivant
// exception   n/a
int affichageMois(int mois, int jourDepart, bool bissextile){

    //si c'est février
    if(mois == 2){
        //bissextile ou non
        if(bissextile){
            return affichageJours(29, jourDepart);
        }
        else{
            return affichageJours(28, jourDepart);
        }
    }
    //si c'est un mois à 30 jours autrement, 31 jours
    else if(mois == 4 || mois == 6 || mois==9 || mois == 11){
        return affichageJours(30, jourDepart);
    }
    else{
        return affichageJours(31, jourDepart);
    }

}

// nom         affichageCalendrier
// but         Afficher tous les mois d'une année donnée
//             
// param       anneeUser  l'année à afficher
// exception   n/a
void affichageCalendrier (int anneeUser){

    //déclaration des variables
    int mois = 1;
    int jourDepart = premierJourAnnee(anneeUser);
    bool biss = bissextile(anneeUser);

    //affichage de tous les mois de l'année
    cout << "Janvier " << anneeUser << endl;
    jourDepart = affichageMois(mois++, jourDepart, biss);

    cout << "Février " << anneeUser << endl;
    jourDepart = affichageMois(mois++, jourDepart, biss);

    cout << "Mars " << anneeUser << endl;
    jourDepart = affichageMois(mois++, jourDepart, biss);

    cout << "Avril " << anneeUser << endl;
    jourDepart = affichageMois(mois++, jourDepart, biss);

    cout << "Mai " << anneeUser << endl;
    jourDepart = affichageMois(mois++, jourDepart, biss);

    cout << "Juin " << anneeUser << endl;
    jourDepart = affichageMois(mois++, jourDepart, biss);

    cout << "Juillet " << anneeUser << endl;
    jourDepart = affichageMois(mois++, jourDepart, biss);

    cout << "Août " << anneeUser << endl;
    jourDepart = affichageMois(mois++, jourDepart, biss);

    cout << "Septembre " << anneeUser << endl;
    jourDepart = affichageMois(mois++, jourDepart, biss);

    cout << "Octobre " << anneeUser << endl;
    jourDepart = affichageMois(mois++, jourDepart, biss);

    cout << "Novembre " << anneeUser << endl;
    jourDepart = affichageMois(mois++, jourDepart, biss);

    cout << "Décembre " << anneeUser << endl;
    affichageMois(mois, jourDepart, biss);
}