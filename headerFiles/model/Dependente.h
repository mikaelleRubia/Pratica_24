#ifndef DEPENDENTE_H
#define DEPENDENTE_H

#include <string>

using namespace std;

class Dependente{
    private:
        int codigo;
        int codigoResponsavel;
        string nome;
        string cpf;
        string dataNascimento;
    public:
        Dependente();
        Dependente(int, int, string, string, string);
        int getCodigo();
        int getCodigoResponsavel();
        string getNome();
        string getCpf();
        string getDataNascimento();
};

#endif