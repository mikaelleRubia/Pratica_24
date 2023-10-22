#include "../../headerFiles/model/Cliente.h"

Cliente::Cliente(){

}

Cliente::Cliente(int codigo, string nome, string cpf, string dataNascimento){
    this->codigo = codigo;
    this->nome = nome;
    this->cpf = cpf;
    this->dataNascimento = dataNascimento;
}

int Cliente::getCodigo(){
    return codigo;
}

string Cliente::getNome(){
    return nome;
}

string Cliente::getCpf(){
    return cpf;
}

string Cliente::getDataNascimento(){
    return dataNascimento;
}

void Cliente::adicionaDependente(Dependente &dependente){
    if(dependentes.size() <= 3) dependentes.push_back(dependente);
    else cout<<"Numero limite de dependentes para este cliente atingido!"<<endl;
}