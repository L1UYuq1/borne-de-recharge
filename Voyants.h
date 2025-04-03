#ifndef Voyants_h
#define Voyants_h
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mem_sh.h"
#include "donnees_borne.h"
#include "iostream"
#include "string"
#include "iomanip"

typedef enum { OFF, VERT, ROUGE } led;

class Voyants
{
    private : 
            entrees *io;
            int shmid;
    public : 
            void Voyants_initialiser();
            void Voyants_set_charge(led Couleur_charge);
            void Voyants_set_disponible(led Couleur_disponible);
            void Voyants_clignoter_charge(led Couleur_clignoter_charge);
            int Voyants_disponible();
};
#endif// Voyants_h

