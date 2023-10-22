#ifndef ROTEIRO_H
#define ROTEIRO_H

#include "Evento.h"
#include <vector>

class Roteiro : public Evento{
    private:
        string destino;
        string dataFinal;
        vector<string> atividades;
    public:
        Roteiro();
        Roteiro(int, string, int, string, string, vector<string>);
        string getDestino();
        string getDataFinal();
        vector<string> getAtividades();
        void detalhar() const override;
};

#endif