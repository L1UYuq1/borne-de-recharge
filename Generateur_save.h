#ifndef Generateur_save_h
#define Generateur_save_h
#include <lcarte.h>
#include <memoire_borne.h>
#include <donnees_borne.h>
#include "iostream"
#include "string"
#include "iomanip"
#include "mem_sh.h"
#include "Prise.h"

typedef enum _etat{etatA,
					etatB,
					etatC,
					etatD,
					etatE,
					etatF
					} etat;
					

typedef enum _pwm{
                    DC,
                    AC_1K,
                    AC_CL,
                    STOP
                 }  pwm;

class GenerateurSave
{
    private : 
                entrees *io;
                int shmid ;
                Voyants voyants;
                Prise prise;
                Bouton bouton;
                
    
    public : 
                void init_generateur_save();
                void Generateur_save_genererPWM(pwm mode_cmd);
                void Generateur_save_charger();
                void Generateur_save_ouvrir_AC();
                void Generateur_save_fermer_AC ();
                void Generateur_save_deconnecter();
                void Machine_Etats_Finis(etat EtatPresent);
                float Generateur_save_tension();
                
};
#endif// Generateur_save_h
