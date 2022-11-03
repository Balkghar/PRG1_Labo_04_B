#include <cstdlib>      // EXIT_SUCCESS
#include <iostream>     // cout et cin
#include <iomanip>
#include <limits>       // numeric_limits<streamsize>
#include <ctime>       // calendrier
#include "calendrier.hpp"

int jourAnnee (int annee) {

    return annee;

}

bool bissextile (int annee){ //Verification si l'année est bissextile !

    bool bissextile = false;

    if (annee % 400 == 0 or (annee % 4 == 0 and annee % 100 != 0)){
        bissextile = true;
    }

    return bissextile;
}

void affichageCalendrier (int anneeUser){
    jourAnnee(anneeUser);
    bissextile(anneeUser);
}
