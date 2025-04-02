#include <iostream>
#include "memoire_borne.h"
#include "donnees_borne.h"

#include "lecteurcarte.h"
#include "base_clients.h"
int main()
{

    LecteurCarte lecteurcarte;
    BaseClients baseclients;
    lecteurcarte.initialiser();
    

    while (1)
    {
        lecteurcarte.lire_carte();
        baseclients.base_client_authentifier (11);
        
    }

}
