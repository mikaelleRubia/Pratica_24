#include "../../headerFiles/model/Deslocamento.h"

Deslocamento::Deslocamento(){

}

Deslocamento::Deslocamento(int codigo, string dataAgendada, int numeroParticipantes, string origem, string destino, string meioDeTransporte, string dataChegada, string companhiaTransporte) : Evento(codigo, dataAgendada, numeroParticipantes){
    this->origem = origem;
    this->destino = destino;
    this->meioDeTransporte = meioDeTransporte;
    this->dataChegada = dataChegada;
    this->companhiaTransporte = companhiaTransporte;
}

string Deslocamento::getOrigem(){
    return origem;
}

string Deslocamento::getDestino(){
    return destino;
}

string Deslocamento::getMeioDeTransporte(){
    return meioDeTransporte;
}

string Deslocamento::getDataChegada(){
    return dataChegada;
}

string Deslocamento::getCompanhiaTransporte(){
    return companhiaTransporte;
}

void Deslocamento::detalhar() const {
    cout<<"Um deslocamento saindo de "<<origem<<" na data "<<dataAgendada<<" com destino a "<<destino<<", chegando na data "<<dataChegada<<'.'<<endl;
    cout<<"Servico da "<<companhiaTransporte<<" com meio de tansporte "<<meioDeTransporte<<'.'<<endl;
}