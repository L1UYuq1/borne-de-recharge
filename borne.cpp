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

using namespace std;

int main()
{

    LecteurCarte lecteurcarte;
    Voyants voyants;
    GenerateurSave generateursave;
    Prise prise;
    NewClient newclient;

    lecteurcarte.initialiser();
    voyants.Voyants_initialiser();
    generateursave.init_generateur_save();
    prise.prise_initialiser();


    int answer = 0; 
	int stateAnswer = 0;
	int motDePasse = 0;
	int stateMotDePasse = 0;
	int choixSupAjoue = 99;
	int stateChoixSupAjoue = -99;
	FILE *fichier = NULL;
	do
	{
        cout<<"se connecter en tant que Administrateur ?"<<endl;
        cout<<"\t 1 pour OUI\n \t 0 pour NON "<<endl;
		if(scanf("%d", &answer)!= 1)
		{
            cout<<"erreur saisie"<<endl;
			exit(-1);
		}
			
		if(answer == OUI)
		{
			stateAnswer = VRAI;
			do
			{
                cout<<"entrez mot de passe ou 0 pour abandonner: "<<endl;
				if(scanf("%d",&motDePasse) != 1)
				{
                    cout<<"erreur saisie"<<endl;
					exit(-1);
				}
			
				if(motDePasse == CORRECT)
				{
					stateMotDePasse = VRAI;
					
					do
					{
                        cout<<"Vous voulez ajouter saisir 1 \nOu supprimer saisir 2: "<<endl;
                        cout<<"Ou 0 pour abandonner: "<<endl;
						if(scanf("%d",&choixSupAjoue) != 1)
						{
                            cout<<"erreur saisie"<<endl;
							exit(-1);
						}
						
						if(choixSupAjoue == AJOUE)
						{
							stateChoixSupAjoue = VRAI;
							newclient.New_Client_ajouterNumCarte(fichier);
							return 0;
						}
						else if(choixSupAjoue == SUPP)
						{
							stateChoixSupAjoue = VRAI;
							newclient.New_Client_supprimerNumCarte(fichier);
							return 0;
						}
						else if(choixSupAjoue == ABANDONNER)
						{
							stateChoixSupAjoue = VRAI;
                            cout<<"Goooood Bye"<<endl;
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
                    cout<<"Goooood Bye"<<endl;
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
    	lecteurcarte.lire_carte();
    }

}
