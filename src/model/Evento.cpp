#include "../../headerFiles/model/Evento.h"

Evento::Evento(){

}

Evento::Evento(int codigo, string dataAgendada, int numeroParticipantes){
    this->codigo = codigo;
    this->dataAgendada = dataAgendada;
    this->numeroParticipantes = numeroParticipantes;
}

int Evento::getCodigo(){
    return codigo;
}

string Evento::getDataAgendada(){
    return dataAgendada;
}