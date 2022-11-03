#include <cstdlib>      // EXIT_SUCCESS
#include <iostream>     // cout et cin
#include <iomanip>
#include <limits>       // numeric_limits<streamsize>
#include <ctime>       // calendrier
#include "calendrier.hpp"

using namespace std;

int jourAnnee (int annee) {

    return 1;

}

bool bissextile (int annee){ //Verification si l'année est bissextile !

    bool bissextile = false;

    if (annee % 400 == 0 or (annee % 4 == 0 and annee % 100 != 0)){
        bissextile = true;
    }

    return bissextile;
}
int affichageJours(int nombreJour, int jourDepart){
    const int ESPACE = 3;
    cout << setw(ESPACE) << "L" << setw(ESPACE) << "M" << setw(ESPACE) << "M" << setw(ESPACE) << "J" << setw(ESPACE) << "V" << setw(ESPACE) << "S" << setw(ESPACE) << "D" << endl;
    int jourSemaine = jourDepart;
    int largeur = jourSemaine*ESPACE;
    for(int i = 1 ; i <= nombreJour; ++i){
        cout << setw(largeur) << i;
        if(jourSemaine % 7 == 0){
            jourSemaine = 1;
            cout << endl;
        }
        else{
            jourSemaine++;
        }
        largeur = ESPACE;
    }
    cout << endl << endl;
    return jourSemaine;
}
int affichageMois(int mois, int jourDepart, bool bissextile){
    int finJour;
    if(mois == 2){
        if(bissextile){
            return affichageJours(29, jourDepart);
        }
        else{
            return affichageJours(28, jourDepart);
        }
    }
    else if(mois == 4 || mois == 6 || mois==9 || mois == 11){
        return affichageJours(30, jourDepart);
    }
    else{
        return affichageJours(31, jourDepart);
    }

}

void affichageCalendrier (int anneeUser){

    int mois = 1;
    int jourDepart = jourAnnee(anneeUser);
    bool biss = bissextile(anneeUser);

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
    jourDepart = affichageMois(mois++, jourDepart, biss);
}
