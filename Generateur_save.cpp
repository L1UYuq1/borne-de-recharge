#include <donnees_borne.h>
#include <memoire_borne.h>
#include "lecteurcarte.h"
#include "Voyants.h"
#include <lcarte.h>
#include "boutons.h"
#include "Prise.h"
#include "Generateur_save.h"

using namespace std;


//Methodes
//fonction pour gerer la MEF
//void GenerateurSave::Machine_Etats_Finis(); // Fonction prive a Generateur_save

etat EtatPresent = etatA;
//La machine a etats finis
void GenerateurSave::Machine_Etats_Finis(etat EtatPresent)
{
	int fin_charge=1;
	while(fin_charge)
	{
		switch(EtatPresent)
		{
			// A t ten te p r i s e
			case etatA:
			voyants.Voyants_set_charge(ROUGE);
			prise.Prise_deverrouiller_trappe();
			Generateur_save_genererPWM (DC) ;
			if(Generateur_save_tension() == 9)
			{
				EtatPresent=etatB ;
			}
			break;
			// P ri s e b r anchee
			case etatB:
			voyants.Voyants_set_charge(VERT);
			prise.Prise_verrouiller_trappe();
			Generateur_save_genererPWM (AC_1K) ;
			if(bouton.boutons_stop()==1)
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
				if(bouton.boutons_stop()==1||Generateur_save_tension()==9)
				{
					EtatPresent=etatE;
				}
			}
			break ;
			// Charger l a b a t t e r i e
			case etatD: 
			Generateur_save_genererPWM(AC_CL);
			if(Generateur_save_tension()==9||bouton.boutons_stop()==1)
			{
				EtatPresent=etatE;
			}
			break;
			// B a t t e r i e c h a r g e e
			case etatE: 
			voyants.Voyants_set_charge(VERT) ;
			Generateur_save_genererPWM (DC) ;
			if(Generateur_save_tension()==9)
			{
				Generateur_save_ouvrir_AC();
				fin_charge=0;
			}
			break;
			// D e c o n n e c t l e v e h i c u l e
			case etatF:
			prise.Prise_deverrouiller_trappe();
			if(Generateur_save_tension()==12)// s i l a p r i s e e s t d b r a n c h e e
			{
				prise.Prise_deverrouiller_trappe();
				prise.Prise_set_prise(OFF);
				voyants.Voyants_set_disponible(VERT);
				voyants.Voyants_set_charge(OFF) ;
				Generateur_save_genererPWM(STOP);
				fin_charge=0;
			}
			break ;
		}
	}
}

//fonction pour
void GenerateurSave::init_generateur_save()
{
	io=acces_memoire(&shmid);
	if(io==NULL)
	{
		cout<<"erreur pas de mem sh"<<endl;
	}
	Generateur_save_ouvrir_AC ();
}
//Fonction generant un signal STOP, DC, AC1,ACCL
void GenerateurSave::Generateur_save_genererPWM(pwm mode_cmd)
{
	io->gene_pwm=mode_cmd;
}
//fonction pour
void GenerateurSave::Generateur_save_charger()
{
	Machine_Etats_Finis(EtatPresent) ;
}
//fonction pour
float GenerateurSave::Generateur_save_tension()
{
	return io->gene_u;
}
// Ouvrir le contacteur
void GenerateurSave::Generateur_save_ouvrir_AC()
{
	io->contacteur_AC =0 ;
}
//fonction pour Fermer l e c o n t a c t e u r
void GenerateurSave::Generateur_save_fermer_AC()
{
	io->contacteur_AC=1;
}
//Fonction qui permet de reprendre le vehicule
void GenerateurSave::Generateur_save_deconnecter()
{
	Machine_Etats_Finis(etatF) ;
}

