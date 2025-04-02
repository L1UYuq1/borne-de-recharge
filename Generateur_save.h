#ifndef Generateur_save_h
#define Generateur_save_h
#include <lcarte.h>
#include <memoire_borne.h>
#include <donnees_borne.h>

class GenerateurSave
{
void init_generateur_save();
void Generateur_save_genererPWM(pwm mode_cmd);
void Generateur_save_charger();
void Generateur_save_ouvrir_AC();
void Generateur_save_fermer_AC ();
void Generateur_save_deconnecter();
float Generateur_save_tension();
}
#endif// Generateur_save_h
