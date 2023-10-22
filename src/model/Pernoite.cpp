#include "../../headerFiles/model/Pernoite.h"

Pernoite::Pernoite(){

}

Pernoite::Pernoite(int codigo, string dataAgendada, int numeroParticipantes, string local) : Evento(codigo, dataAgendada, numeroParticipantes){
    this->local = local;
}

string Pernoite::getLocal(){
    return local;
}

void Pernoite::detalhar() const {
    cout<<"Um pernoite no(a) "<<local<<endl;
}