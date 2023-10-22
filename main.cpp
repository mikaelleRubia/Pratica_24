#include <iostream>
#include <vector>

using namespace std;


class Usuario{
    private:
        string nome;
        string cpf;

    public:
    Usuario();
        Usuario(string nome, string cpf) {this->nome = nome;this->cpf =cpf;}

        string getCpf(){ return cpf; }
        void setCpf(string cpf) { this->cpf =cpf; }

        string getNome(){ return nome; }
        void setNome(string nome) { this->nome = nome; }

};

class Dependente: public Usuario {
    private:
    string tipoRelacao;  

public:
    Dependente(string nome, string cpf, string tipoRelacao) : Usuario(nome, cpf), tipoRelacao(tipoRelacao) {}

    string getTipoRelacao() {return tipoRelacao;}
    void setTipoRelacao(string tipoRelacao) {this->tipoRelacao = tipoRelacao;}
    
};
class Pacote;
class Cliente: public Usuario{
    private:
        vector<Pacote> pacotes;
        vector<Dependente> dependentes;
        

    public:
        Cliente(string _nome, string _cpf) : Usuario(_nome, _cpf){}
        Cliente(string _nome, string _cpf, Dependente dependente) : Usuario(_nome, _cpf) {
            dependentes.push_back(dependente);
            
        }

        void adicionarDependente(Dependente dependente) {
            dependentes.push_back(dependente);
        } 
};

class Roteiro {
    private:
        string destino;
        vector<string> pontosTuristicos;

    public:
        Roteiro(string _destino, const vector<string>& _pontosTuristicos)
            : destino(_destino), pontosTuristicos(_pontosTuristicos) {}

        string getDestino() const { return destino; }
        vector<string> getPontosTuristicos() const { return pontosTuristicos; }
};

class Deslocamento {
    private:
    string meioTransporte;
    int duracaoHoras;
    string origem;

    public:
    Deslocamento(string _meioTransporte, int _duracaoHoras, string _origem)
        : meioTransporte(_meioTransporte), duracaoHoras(_duracaoHoras), origem(_origem) {}

    string getMeioTransporte() const { return meioTransporte; }
    void setMeioTransporte(string _meioTransporte){ meioTransporte = _meioTransporte;}

    int getDuracaoHoras() const { return duracaoHoras; }
    void setDuracaoHoras(int _duracao){duracaoHoras = _duracao;}

    string getOrigem() const { return origem; }
    void setOrigem(string _origem){ origem = _origem;}
};

class Pernoite {
    private:
        string hotel;
        string endereco;
        int numeroNoites;

    public:
    Pernoite(string _hotel, string _endereco, int _numeroNoites)
        : hotel(_hotel), endereco(_endereco), numeroNoites(_numeroNoites) {}

    string getHotel() const { return hotel; }
    void setHotel(string _hotel) { hotel = _hotel;}

    string getEndereco() const { return endereco; }
    void setEndereco(string _endereco) { endereco = _endereco;}

    int getNumeroNoites() const { return numeroNoites; }
    void setNumeroNoites(int _numeroNoites) {numeroNoites = _numeroNoites;}
};
class Evento{
    private:
        Roteiro roteiro;
        Deslocamento deslocamento;
        Pernoite pernoite;

};

class Pacote{
    private:

        int codigo;
        double preco;
        string descricao;
        Evento* evento;
        vector<Cliente> clientes;


    public:
        Pacote(int _codigo, double _preco, const string& _descricao, Evento* _evento)
        : codigo(_codigo), preco(_preco), descricao(_descricao), evento(_evento) {}

        int getCodigo() const { return codigo; }
        void setCodigo(int _codigo) { codigo = _codigo; }

        double getPreco() const { return preco; }
        void setPreco(double _preco) { preco = _preco;}

        string getDescricao() const { return descricao; }
        void setDescricao(string _descricao) { descricao = _descricao; }

        Evento* getEvento() const { return evento; }
        void setEvento(Evento* _evento) { evento = _evento; }


};

int main(){

    return 0;
}