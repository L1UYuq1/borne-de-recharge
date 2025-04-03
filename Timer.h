#ifndef timer_h
#define timer_h
#include <iostream>
class Timer
{
    private : 
            entrees *io;
            int shmid;
            int startTimer;
    public : 
            void Timer_initialiser();
            void Timer_raz();
            int Timer_valeur();
};
#endif // Timer_H
