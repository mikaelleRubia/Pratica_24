#ifndef EVENTO_H
#define EVENTO_H

#include <string>
#include <iostream>

using namespace std;

class Evento{
    protected:
        int codigo;
        string dataAgendada;
        int numeroParticipantes;
    public:
        Evento();
        Evento(int, string, int);
        virtual ~Evento() = default;
        virtual void detalhar() const = 0;
        int getCodigo();
        string getDataAgendada();
};

#endif