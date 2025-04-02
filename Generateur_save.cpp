#include <donnees_borne.h>
#include <memoire_borne.h>
#include "iostream"
#include "string"
#include "iomanip"
#include "lecteur_carte.h"
#include "Voyants.h"
#include <lcarte.h>
#include "boutons.h"
#include "Prise.h"
#include "Generateur_save.h"
#include "mem_sh.h"

using namespace std;

//Attribus
entrees *io;
int shmid ;

//Methodes
//fonction pour gerer la MEF
void Machine_Etats_Finis(); // Fonction prive a Generateur_save
typedef enum _etat{etatA,
					etatB,
					etatC,
					etatD,
					etatE,
					etatF
					} etat;
					
etat EtatPresent = etatA;

//fonction pour
void init_generateur_save()
{
	io=acces_memoire(&shmid);
	if(io==NULL)
	{
		printf("erreur pas de mem sh\n");
	}
	Generateur_save_ouvrir_AC ();
}
//Fonction generant un signal STOP, DC, AC1,ACCL
void Generateur_save_genererPWM(pwm mode_cmd)
{
	io->gene_pwm=mode_cmd;
}
//fonction pour
void Generateur_save_charger()
{
	Machine_Etats_Finis(EtatPresent) ;
}
//fonction pour
float Generateur_save_tension()
{
	return io->gene_u;
}
// Ouvrir le contacteur
void Generateur_save_ouvrir_AC()
{
	io->contacteur_AC =0 ;
}
//fonction pour Fermer l e c o n t a c t e u r
void Generateur_save_fermer_AC()
{
	io->contacteur_AC=1;
}
//Fonction qui permet de reprendre le vehicule
void Generateur_save_deconnecter()
{
	Machine_Etats_Finis(etatF) ;
}
//La machine a etats finis
void Machine_Etats_Finis(etat EtatPresent)
{
	int fin_charge=1;
	while(fin_charge)
	{
		switch(EtatPresent)
		{
			// A t ten te p r i s e
			case etatA:
			Voyants_set_charge(ROUGE);
			Prise_deverrouiller_trappe();
			Generateur_save_genererPWM (DC) ;
			if(Generateur_save_tension() == 9)
			{
				EtatPresent=etatB ;
			}
			break;
			// P ri s e b r anchee
			case etatB:
			Voyants_set_charge(VERT);
			Prise_verrouiller_trappe();
			Generateur_save_genererPWM (AC_1K) ;
			if(boutons_stop()==1)
			{
				EtatPresent=etatE;
			}
			if(Generateur_save_tension()==9)
			{
				EtatPresent=etatC ;
			}
			break;
			// A t ten te S2 v e h i c u l e
			case etatC:
			Generateur_save_fermer_AC();
			if(Generateur_save_tension()==6)
			{
				EtatPresent=etatD;
				if(boutons_stop()==1||Generateur_save_tension()==9)
				{
					EtatPresent=etatE;
				}
			}
			break ;
			// Charger l a b a t t e r i e
			case etatD: 
			Generateur_save_genererPWM(AC_CL);
			if(Generateur_save_tension()==9||boutons_stop()==1)
			{
				EtatPresent=etatE;
			}
			break;
			// B a t t e r i e c h a r g e e
			case etatE: 
			Voyants_set_charge(VERT) ;
			Generateur_save_genererPWM (DC) ;
			if(Generateur_save_tension()==9)
			{
				Generateur_save_ouvrir_AC();
				fin_charge=0;
			}
			break;
			// D e c o n n e c t l e v e h i c u l e
			case etatF:
			Prise_deverrouiller_trappe();
			if(Generateur_save_tension()==12)// s i l a p r i s e e s t d b r a n c h e e
			{
				Prise_deverrouiller_trappe();
				Prise_set_prise(OFF);
				Voyants_set_disponible(VERT);
				Voyants_set_charge(OFF) ;
				Generateur_save_genererPWM(STOP);
				fin_charge=0;
			}
			break ;
		}
	}
}
