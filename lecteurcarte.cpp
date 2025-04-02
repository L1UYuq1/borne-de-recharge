#include "iostream"
#include "string"
#include "iomanip"
#include "lecteurcarte.h"

using namespace std;

void LecteurCarte::initialiser()
{
initialisations_ports();
}

void LecteurCarte::lire_carte()
{
cout << "Veuillez insérer votre carte : "<< endl;
attente_insertion_carte();
int num=lecture_numero_carte();
cout << "Numéro de carte  : "<< num <<endl;
}

