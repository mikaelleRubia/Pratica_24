#include "../../headerFiles/model/Dependente.h"

Dependente::Dependente(){

}

Dependente::Dependente(int codigo, int codigoResponsavel, string nome, string cpf, string dataNascimento){
    this->codigo = codigo;
    this->codigoResponsavel = codigoResponsavel;
    this->nome = nome;
    this->cpf = cpf;
    this->dataNascimento = dataNascimento;
}

int Dependente::getCodigo(){
    return codigo;
}

int Dependente::getCodigoResponsavel(){
    return codigoResponsavel;
}

string Dependente::getNome(){
    return nome;
}

string Dependente::getCpf(){
    return cpf;
}

string Dependente::getDataNascimento(){
    return dataNascimento;
}