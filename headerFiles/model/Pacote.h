#ifndef PACOTE_H
#define PACOTE_H

#include "Cliente.h"
#include "Evento.h"

class Pacote{
    int codigo;
    vector<Cliente> clientes;
    vector<Evento*> evento;
    float custoTotal;
};

#endif