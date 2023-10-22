#include "../../headerFiles/model/Roteiro.h"

Roteiro::Roteiro(){

}

Roteiro::Roteiro(int codigo, string dataAgendada, int numeroParticipantes, string destino, string dataFinal, vector<string> atividades) : Evento(codigo, dataAgendada, numeroParticipantes){
    this->destino = destino;
    this->dataFinal = dataFinal;
    this->atividades = atividades;
}

string Roteiro::getDestino(){
    return destino;
}

string Roteiro::getDataFinal(){
    return dataFinal;
}

vector<string> Roteiro::getAtividades(){
    return atividades;
}

void Roteiro::detalhar() const {
    cout<<"Roteiro para "<<destino<<" partindo em "<<dataAgendada<<" e com previsao de chegada em "<<dataFinal<<'.'<<endl;
    cout<<"A(s) atividade(s) relacionada(s) ao roteiro: "<<endl;
    for(string atividade : atividades){
        cout<<atividade<<endl;
    }
}