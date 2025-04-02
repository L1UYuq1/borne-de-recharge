#include "iostream"
#include "string"
#include "iomanip"
#include "base_clients.h"
#include <donnees_borne.h>
#include <memoire_borne.h>
#include "mem_sh.h"
#include <unistd.h>

using namespace std;

int NumClient;

int BaseClients::base_client_authentifier(int NumCarte)
{
	FILE *fichier;
	int Compare_NumCarte_BaseClient = -1;
	
	fichier=fopen("base_clients.txt","r"); ///on ajoute un fichier txt avec nos num 
	if(fichier==NULL)
	{
		cout << "\n echec!!" << endl;
		exit(1);
	}
	while((fscanf(fichier,"%d", &Compare_NumCarte_BaseClient)!= EOF))
	{
		if(NumCarte==Compare_NumCarte_BaseClient)
		{
			NumClient=NumCarte ; //si il fait partie des num autorisee
			fclose(fichier);
			return 1;  ///autorisation accordee
		}
	}
	fclose(fichier);////autorisation refusee
return 0;
}

int BaseClients::base_client_reprise(int NumCarte)
{
	if(NumCarte==NumClient)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
	
}
