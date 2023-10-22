#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include <iostream>
#include "Dependente.h"

using namespace std;

class Cliente{
    private:
        int codigo;
        string nome;
        string cpf;
        string dataNascimento;
        vector<Dependente> dependentes;
        vector<Pacote> pacotesContratados;
    public:
        Cliente();
        Cliente(int, string, string, string);
        int getCodigo();
        string getNome();
        string getCpf();
        string getDataNascimento();
        void adicionaDependente(Dependente &);
};

#endif