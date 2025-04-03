#ifndef NEWCLIENT_H
#define NEWCLIENT_H


#define OUI 1
#define NON 0

#define FAUX -1
#define VRAI 1
#define INVALIDE 0

#define CORRECT 10
#define ABANDONNER 0

#define AJOUE 1
#define SUPP 2
#include "iostream"
#include "string"
#include "iomanip"


class NewClient
{
    public : 
        void New_Client_ajouterNumCarte(FILE *fichier);
        void New_Client_supprimerNumCarte(FILE *fichier);
};
#endif
