#include <stdio.h>
#include <stdlib.h>
#include <donnees_borne.h>
#include <memoire_borne.h>
#include "mem_sh.h"
#include "Timer.h"

using namespace std;

void Timer::Timer_initialiser()
{
	io=acces_memoire(&shmid);
	if (io==NULL)
	{
		cout<<"erreur pas de mem sh"<<endl;
	}
	
}

void Timer::Timer_raz()
{
	io=acces_memoire(&shmid);
	if(io==NULL)
	{
		cout<<"erreur pas de mem sh"<<endl;
	}
	startTimer=io->timer_sec;
}

int Timer::Timer_valeur()
{
	return((io->timer_sec)-(startTimer));
}
