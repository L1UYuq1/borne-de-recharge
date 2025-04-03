#ifndef Prise_h
#define Prise_h
#include "donnees_borne.h"
#include "memoire_borne.h"
#include <iostream>
#include "string"
#include "iomanip"


class Prise
{
    public : 
            void prise_initialiser();
            void Prise_verrouiller_trappe();
            void Prise_deverrouiller_trappe();
            void Prise_set_prise(led Couleur);

    private : 
            entrees *io;
            int shmid ;
};
#endif// Prise_h
