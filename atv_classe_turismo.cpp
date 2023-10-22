#include <iostream>
#include <vector>

using namespace std;

class Evento; // Declaração antecipada da classe Evento

class Usuario {
private:
    string nome;
    string cpf;

public:
    Usuario();
    Usuario(string nome, string cpf) { this->nome = nome; this->cpf = cpf; }

    string getCpf() { return cpf; }
    void setCpf(string cpf) { this->cpf = cpf; }

    string getNome() { return nome; }
    void setNome(string nome) { this->nome = nome; }
};

class Dependente : public Usuario {
private:
    string tipoRelacao;

public:
    Dependente(string nome, string cpf, string tipoRelacao) : Usuario(nome, cpf), tipoRelacao(tipoRelacao) {}

    string getTipoRelacao() { return tipoRelacao; }
    void setTipoRelacao(string tipoRelacao) { this->tipoRelacao = tipoRelacao; }
};

class Pacote; // Declaração antecipada da classe Pacote

class Cliente : public Usuario {
private:
    vector<Pacote> pacotes;
    vector<Dependente> dependentes;

public:
    Cliente(string _nome, string _cpf) : Usuario(_nome, _cpf) {}
    Cliente(string _nome, string _cpf, Dependente dependente) : Usuario(_nome, _cpf) {
        dependentes.push_back(dependente);
    }

    const vector<Pacote>& getPacotes() const {
        return pacotes;
    }

    const vector<Dependente>& getDependentes() const {
        return dependentes;
    }

    // Pacote pacote1(01, 250.00," Casa do shows");
    Pacote criarPacote(int _codigo, double _preco, const string& _descricao, vector<Evento> eventos);
};

class Roteiro {
private:
    string destino;
    vector<string> pontosTuristicos;

public:

    Roteiro(string destino) : destino(destino) {}
    Roteiro(string _destino, const vector<string>& _pontosTuristicos)
        : destino(_destino), pontosTuristicos(_pontosTuristicos) {}

    string getDestino() const { return destino; }
    void setDestino(const string& _destino) { destino = _destino; }

    vector<string> getPontosTuristicos() const { return pontosTuristicos; }
    void setPontosTuristicos(const vector<string>& _pontosTuristicos) { pontosTuristicos = _pontosTuristicos; }
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
    void setMeioTransporte(string _meioTransporte) { meioTransporte = _meioTransporte; }

    int getDuracaoHoras() const { return duracaoHoras; }
    void setDuracaoHoras(int _duracao) { duracaoHoras = _duracao; }

    string getOrigem() const { return origem; }
    void setOrigem(string _origem) { origem = _origem; }
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
    void setHotel(string _hotel) { hotel = _hotel; }

    string getEndereco() const { return endereco; }
    void setEndereco(string _endereco) { endereco = _endereco; }

    int getNumeroNoites() const { return numeroNoites; }
    void setNumeroNoites(int _numeroNoites) { numeroNoites = _numeroNoites; }
};

class Evento {
private:
    Roteiro roteiro;
    Deslocamento deslocamento;
    Pernoite pernoite;
    string nome;

public:
    Evento(const Roteiro& _roteiro, const Deslocamento& _deslocamento, const Pernoite& _pernoite, const string& _nome)
        : roteiro(_roteiro), deslocamento(_deslocamento), pernoite(_pernoite), nome(_nome) {}

    const Roteiro& getRoteiro() const { return roteiro; }
    void setRoteiro(const Roteiro& _roteiro) { roteiro = _roteiro; }

    const Deslocamento& getDeslocamento() const { return deslocamento; }
    void setDeslocamento(const Deslocamento& _deslocamento) { deslocamento = _deslocamento; }

    const Pernoite& getPernoite() const { return pernoite; }
    void setPernoite(const Pernoite& _pernoite) { pernoite = _pernoite; }

    const string& getNome() const { return nome; }
    void setNome(const string& _nome) { nome = _nome; }
};

class Pacote {
private:
    int codigo;
    double preco;
    string descricao;
    vector <Evento> eventos;
    vector<Cliente> clientes;

public:
    Pacote(int _codigo, double _preco, const string& _descricao)
        : codigo(_codigo), preco(_preco), descricao(_descricao) {}

    int getCodigo() const { return codigo; }
    void setCodigo(int _codigo) { codigo = _codigo; }

    double getPreco() const { return preco; }
    void setPreco(double _preco) { preco = _preco; }

    string getDescricao() const { return descricao; }
    void setDescricao(string _descricao) { descricao = _descricao; }

    const vector<Evento>& getEventos() const { return eventos; }
    void setEventos(const vector<Evento>& _eventos) { eventos = _eventos; }

    const vector<Cliente>& getClientes() const { return clientes; }
    void setClientes(const vector<Cliente>& _clientes) { clientes = _clientes; }
    void cadastrarEvento(const Evento& evento) {
        eventos.push_back(evento);
    }
};

Pacote Cliente::criarPacote(int _codigo, double _preco, const string& _descricao, vector<Evento> eventos) {
    Pacote pacot(_codigo, _preco, _descricao);
    pacot.setEventos(eventos);
    pacotes.push_back(pacot);
    return pacot;
}

int main() {
    // Criar um cliente
    Cliente cliente1("Danilo", "123.456.789-00");
    Cliente cliente2("Ana", "987.654.321-00");


    // Criar um evento 1
    Roteiro roteiro1("Sao Paulo");
    Deslocamento deslocamento1("Trem", 2, "Sao Paulo");
    Pernoite pernoite1("Hotel", "Endereço do hotel", 3);
    Evento evento1(roteiro1, deslocamento1, pernoite1, "Show de musica");

    // Criar um evento 2
    Roteiro roteiro2("Rio de Janeiro");
    Deslocamento deslocamento2("Aviao", 2, "Rio de Janeiro");
    Pernoite pernoite2("Hotel", "Endereço do hotel", 3);
    Evento evento2(roteiro2, deslocamento2, pernoite2, "Show de danças");

// Criar um pacote  
// Pacote pacote1(1, 250.00, "Casa do shows");
// pacote1.cadastrarEvento(evento1);
// pacote1.cadastrarEvento(evento2);

    // Cadastrar o evento no pacote
    vector<Evento> pacote_de_eventos;
    pacote_de_eventos.push_back(evento1);
    pacote_de_eventos.push_back(evento2);

    // COMPRANDO O PACOTE
    Pacote pacoteCriado = cliente1.criarPacote(1, 250.00, "Casa do shows", pacote_de_eventos);


// imprimindo testando
    vector<Pacote> pacotesContratados =cliente1.getPacotes();
    for (const Pacote& pacote : pacotesContratados) {
        cout << "Codigo do Pacote: " << pacote.getCodigo() << endl;
        cout << "Preco do Pacote: " << pacote.getPreco() << endl;
        cout << "Descricao do Pacote: " << pacote.getDescricao() << endl;
        cout << "Nome do Pacote: " << pacote.getDescricao() << endl;  
        cout << "Nome do Evento: " << pacote.getEventos()[0].getNome() << endl;  
    }
    cout << "Cliente que comprou o pacote: " << cliente1.getNome() << " (CPF: " << cliente1.getCpf() << ")" << endl;
   
    return 0;
}
