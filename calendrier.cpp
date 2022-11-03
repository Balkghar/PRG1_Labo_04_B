#include <cstdlib>      // EXIT_SUCCESS
#include <iostream>     // cout et cin
#include <iomanip>
#include <limits>       // numeric_limits<streamsize>
#include <ctime>       // calendrier
#include "calendrier.hpp"

//Source : https://www.codespeedy.com/how-to-find-day-from-date-in-cpp/
int premierJourAnnee (int annee) {


    annee -= 1;
    return ((annee + annee/4 - annee/100 + annee/400 ) % 7) + 1;


}

bool bissextile (int annee){ //Verification si l'année est bissextile !

    bool bissextile = false;

    if (annee % 400 == 0 or (annee % 4 == 0 and annee % 100 != 0)){
        bissextile = true;
    }

    return bissextile;
}

void affichageCalendrier (int anneeUser){
    std::cout << premierJourAnnee(anneeUser) << std::endl;
    bissextile(anneeUser);
}
