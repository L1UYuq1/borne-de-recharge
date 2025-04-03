#include <lcarte.h>
#include <memoire_borne.h>
#include <donnees_borne.h>
#include "New_Client.h"

using namespace std;

void NewClient::New_Client_ajouterNumCarte(FILE *fichier)
{
	int NumCarte = -99;
	cout<<"Inserez la carte du nouveau client : "<<endl;
	attente_insertion_carte();
	if(carte_inseree())
	{
		NumCarte = lecture_numero_carte();//lire le numero de la carte.
	}
	
	cout<<"Veuillez retirez votre carte svp"<<endl;
	attente_retrait_carte();
	cout<<"Carte retirée"<<endl;	
	
	fichier = fopen("base_clients.txt","a");
	
	if(fichier == NULL)
	{
        cout<<"error fichier"<<endl;
		exit(-1);
	}
	
	fprintf(fichier,"%d\n", NumCarte);
	
	fclose(fichier);
	
	cout<<"Nouveau client ajouté avec succes"<<endl;

}

void NewClient::New_Client_supprimerNumCarte(FILE *fichier)
{
    fichier = fopen("base_clients.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fichier == NULL || temp == NULL) 
    {
        cout<<"Erreur lors de l'ouverture des fichiers."<<endl;
        return;
    }

    int numASupprimer = -99;
    int trouve = 0;

    cout<<"Veuillez inserez la carte du client à supprimer : "<< endl;
	attente_insertion_carte();
	if(carte_inseree())
	{
		numASupprimer = lecture_numero_carte();//lire le numero de la carte.
	}
	
	cout<<"Veuillez retirez votre carte svp"<<endl;
	attente_retrait_carte();
	cout<<"Carte retirée"<<endl;

    int num;

    while (fscanf(fichier, "%d", &num) != EOF) 
    {
        if (num != numASupprimer) 
        {
            fprintf(temp, "%d\n", num);
        } 
        else 
        {
            trouve = 1;
        }
    }

    fclose(fichier);
    fclose(temp);

    remove("base_clients.txt");
    rename("temp.txt", "base_clients.txt");

    if (trouve) 
    {
        cout<<"Numéro supprimé avec ssucès."<<endl;
    } 
    else 
    {
        cout<<"Numéro non trouvé dans le fichier."<<endl;
    }
}

