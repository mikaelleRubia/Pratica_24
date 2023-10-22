#ifndef PERNOITE_H
#define PERNOITE_H

#include "Evento.h"

class Pernoite : public Evento{
    private:
        string local;
    public:
        Pernoite();
        Pernoite(int, string, int, string);
        string getLocal();
        void detalhar() const override;

};

#endif