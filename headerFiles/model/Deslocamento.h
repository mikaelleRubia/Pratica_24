#ifndef DESLOCAMENTO_H
#define DESLOCAMENTO_H

#include "Evento.h"

class Deslocamento : public Evento{
    private:
        string origem;
        string destino;
        string meioDeTransporte;
        string dataChegada;
        string companhiaTransporte;
    public:
        Deslocamento();
        Deslocamento(int, string, int, string, string, string, string, string);
        string getOrigem();
        string getDestino();
        string getMeioDeTransporte();
        string getDataChegada();
        string getCompanhiaTransporte();
        void detalhar() const override;
};

#endif