#include <lcarte.h>
#include "lecteurcarte.h"
#include "Voyants.h"
#include "mem_sh.h"
#include "base_clients.h"
#include "boutons.h"
#include "Timer.h"
#include "Generateur_save.h"
#include "Prise.h"
#include "borne.h"
#include "New_Client.h"
int main()
{
/*
    LecteurCarte lecteurcarte;

    lecteur_carte_initialiser();
    Voyants_initialiser();
    init_generateur_save();
    prise_initialiser();
   	Voyants_initialiser();


    int answer = 0; 
	int stateAnswer = 0;
	int motDePasse = 0;
	int stateMotDePasse = 0;
	int choixSupAjoue = 99;
	int stateChoixSupAjoue = -99;
	FILE *fichier = NULL;
	do
	{
		printf("Se connecter en tant que Administrateur ? \n"); 
		printf("\t 1 pour OUI\n \t 0 pour NON \n");
		if(scanf("%d", &answer)!= 1)
		{
			printf("erreur saisie\n");
			exit(-1);
		}
			
		if(answer == OUI)
		{
			stateAnswer = VRAI;
			do
			{
				printf("entrez mot de passe ou 0 pour abandonner: \n");
				if(scanf("%d",&motDePasse) != 1)
				{
					printf("erreur saisie\n");
					exit(-1);
				}
			
				if(motDePasse == CORRECT)
				{
					stateMotDePasse = VRAI;
					
					do
					{
						printf("Vous voulez ajouter saisir 1 \nOu supprimer saisir 2: \n");
						printf("Ou 0 pour abandonner: \n");
						if(scanf("%d",&choixSupAjoue) != 1)
						{
							printf("erreur saisie\n");
							exit(-1);
						}
						
						if(choixSupAjoue == AJOUE)
						{
							stateChoixSupAjoue = VRAI;
							New_Client_ajouterNumCarte(fichier);
							return 0;
						}
						else if(choixSupAjoue == SUPP)
						{
							stateChoixSupAjoue = VRAI;
							New_Client_supprimerNumCarte(fichier);
							return 0;
						}
						else if(choixSupAjoue == ABANDONNER)
						{
							stateChoixSupAjoue = VRAI;
							printf("Goooood Bye\n");
							return 0;
						}
						else
						{
							stateChoixSupAjoue = FAUX;
						}
					
					}while(stateChoixSupAjoue == FAUX);
				}
				else if(motDePasse == ABANDONNER)
				{
					printf("Goooood Bye\n");
					return 0;
				}
				else
				{
					stateMotDePasse = FAUX;
				}
				
			}while(stateMotDePasse == FAUX);
			
		}
		else if(answer == NON)
		{
			stateAnswer = VRAI;
		}
		else
		{
			stateAnswer = INVALIDE;
		}	
	}while(stateAnswer == INVALIDE);
		

    while (1)
   	{
    	lecteur_carte_lireCarte();
    }
*/
}
