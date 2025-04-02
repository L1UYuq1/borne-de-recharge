#include <memoire_borne.h>
#include <donnees_borne.h>
#include "boutons.h"


using namespace std;


void Bouton::boutons_initialiser()
{
	io=acces_memoire(&shmid);
	if (io==NULL)
	{
		cout<<"erreur pas de mem sh"<<endl;
		
	}
	io->bouton_charge=0;
	io->bouton_stop=0;
}


int Bouton::boutons_charge()
{
	return io->bouton_charge;
}

int Bouton::boutons_stop()
{
	return io->bouton_stop;
}
