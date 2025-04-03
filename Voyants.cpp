#include <memoire_borne.h>
#include <donnees_borne.h>
#include "Voyants.h"

using namespace std;

//Methodes 
void Voyants::Voyants_initialiser()
{
	io=acces_memoire(&shmid); 
	if(io==NULL)
	cout<<"erreur pas de mem sh"<<endl;
	io->led_charge=OFF;
	io->led_dispo=VERT;
	io->led_prise=OFF;
	io->led_trappe=OFF;
	io->led_defaut=OFF;
}
//Fonction pour controler la LED charge
void Voyants::Voyants_set_charge(led Couleur_charge)
{
	io->led_charge=Couleur_charge;
}
//Fonction pour controler la LED charge
void Voyants::Voyants_set_disponible(led Couleur_disponible)
{
	io->led_dispo=Couleur_disponible;
}

void Voyants::Voyants_clignoter_charge(led Couleur_clignoter_charge)
{
	int i;
	for(i=1;i<=8;i++)//clignoter la led pendant 8 secondes
	{
		io->led_charge=Couleur_clignoter_charge;
		usleep(500000);//Allumer la led charge pendant 0.5s
		io->led_charge = OFF;
		usleep(500000);// eteindre la led charge pendant 0.5s
	}
}
int Voyants::Voyants_disponible()
{
	if((io->led_dispo)==VERT)
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}
