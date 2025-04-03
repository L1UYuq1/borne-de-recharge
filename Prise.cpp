#include <donnees_borne.h>
#include <memoire_borne.h>
#include "Prise.h"

using namespace std;

void Prise::prise_initialiser()
{
	io=acces_memoire(&shmid);
	if(io==NULL)
	cout<<"erreur pas de mem sh"<<endl;
	io->led_prise=OFF;
	io->led_trappe=OFF;
}
void Prise::Prise_set_prise(led Couleur)
{
	io->led_prise=Couleur;
}
void Prise::Prise_verrouiller_trappe()
{
	io->led_trappe=OFF;
}
void Prise::Prise_deverrouiller_trappe()
{
	io->led_trappe=VERT;
}

