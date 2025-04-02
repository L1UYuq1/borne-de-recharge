#include <iostream>
#include "memoire_borne.h"
#include "donnees_borne.h"

#include "lecteurcarte.h"

int main()
{

    LecteurCarte lecteurcarte;
    lecteurcarte.initialiser();

    while (1)
    {
        lecteurcarte.lire_carte();
    }

}
