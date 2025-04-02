#ifndef boutons_h
#define boutons_h
#include "mem_sh.h"
#include <iostream>
#include "string"
#include "iomanip"
#include <unistd.h>

class Bouton
{
	public:
		void boutons_initialiser();
		int  boutons_charge();
		int  boutons_stop();
	private:
		entrees *io;
		int shmid;

};
#endif// boutons_h
