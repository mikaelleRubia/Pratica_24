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
    Dependente() : Usuario("", ""), tipoRelacao("") {}
    Dependente(string nome, string cpf, string tipoRelacao) : Usuario(nome, cpf), tipoRelacao(tipoRelacao) {}

    string getTipoRelacao() {return tipoRelacao;}
    void setTipoRelacao(string tipoRelacao) {this->tipoRelacao = tipoRelacao;}
    
};
class Pacote;
class Cliente: public Usuario{
    private:
        vector<Pacote*> pacotes;
        vector<Dependente*> dependentes;
        
    public:
        Cliente() : Usuario("", "") {}
        Cliente(string _nome, string _cpf) : Usuario(_nome, _cpf){}

        vector<Pacote*>& getPacotes(){return pacotes;}

        void setPacotes(const vector<Pacote*>& pacote){
            pacotes = pacote;
        }
        
        int NumeroDependentes() const {
            return dependentes.size();
        }
        void addDependente(Dependente* dependente) {
            dependentes.push_back(dependente);
        }

        vector<Dependente*>& getDependentes() {return dependentes;}

        void venderPacoteCliente(Pacote* pacote);
        static void imprimirPacoteCliente(Cliente* cliente);
        static void add_client_dependente(vector <Cliente> &clientes);
        static void imprimirClientes(vector<Cliente>& clientes);
            

};
class Roteiro {
    private:
        string destino;
        vector<string> pontosTuristicos;

    public:
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

    public:
        Evento(const Roteiro& _roteiro, const Deslocamento& _deslocamento, const Pernoite& _pernoite)
            : roteiro(_roteiro), deslocamento(_deslocamento), pernoite(_pernoite) {}

        const Roteiro& getRoteiro() const {return roteiro;}
        void setRoteiro(const Roteiro& _roteiro) {roteiro = _roteiro;}

        const Deslocamento& getDeslocamento() const {return deslocamento;}
        void setDeslocamento(const Deslocamento& _deslocamento) {deslocamento = _deslocamento;}

        const Pernoite& getPernoite() const {return pernoite; }
        void setPernoite(const Pernoite& _pernoite) {pernoite = _pernoite;}

};

class Pacote{
    private:

        int codigo;
        double preco;
        string descricao;
        vector <Evento>* eventos;
        vector<Cliente*> clientes; 


    public:
        Pacote(int _codigo, double _preco, const string& _descricao)
        : codigo(_codigo), preco(_preco), descricao(_descricao) {}

        int getCodigo() const { return codigo; }
        void setCodigo(int _codigo) { codigo = _codigo; }

        double getPreco() const { return preco; }
        void setPreco(double _preco) { preco = _preco;}

        string getDescricao() const { return descricao; }
        void setDescricao(string _descricao) { descricao = _descricao; }

        const vector<Evento>* getEventos() const { return eventos; }
        void setEventos(vector<Evento>* _eventos) { eventos = _eventos; }        

        vector<Cliente*>* getClientes() { return &clientes; }

        void adicionarCliente(Cliente* cliente) {
            clientes.push_back(cliente);
        }
};

void listarPacotes(vector<Pacote>&);

int main(){
    char resposta;
    vector<Cliente> clientes;
    vector<Pacote> pacotes;
    do{

        Cliente::add_client_dependente(clientes);
        cout << "Deseja adicionar outro cliente e seus dependentes? " << endl;
        cin >> resposta;
    }while(resposta == 's' || resposta == 'S');

    Cliente cliente("Nome do Cliente", "123456789");
    Pacote p(123, 1200.00, "praia");
    Pacote p1(333, 1500.00, "teatro");

    const vector<string> pontos = {"ponto1", "ponto2"};
    Roteiro r1 = Roteiro("Salvador", pontos);
    Roteiro r2 = Roteiro("Belo Horizonte", pontos);
    Deslocamento d1 = Deslocamento("Aviao", 3, "Ilheus");
    Pernoite pe1 = Pernoite("Hotel 1", "endereco 1", 1);
    Evento e1 = Evento(r1, d1, pe1);
    Evento e2 = Evento(r2, d1, pe1);

    vector<Evento>* ev1 = new vector<Evento>();
    ev1->push_back(e1);
    vector<Evento>* ev2 = new vector<Evento>();
    ev2->push_back(e1);
    ev2->push_back(e2);
    p.setEventos(ev1);
    p1.setEventos(ev1);
    p1.setEventos(ev2);
    // Dependente dependente("Nome Dependente", "987654321", "Filho");
    // cliente.addDependente(&dependente);


    clientes[0].venderPacoteCliente(&p);
    clientes[0].venderPacoteCliente(&p1);
    cliente.venderPacoteCliente(&p);
    cliente.venderPacoteCliente(&p1);

    clientes.push_back(cliente);
    pacotes.push_back(p);
    pacotes.push_back(p1);


    Cliente::imprimirClientes(clientes);
    Cliente::imprimirPacoteCliente(&clientes[0]);

    listarPacotes(pacotes);

    return 0;
}

//////////////////////////////////////////////////////////////////////
///////////////////////CLASSE CLIENTE E METODOS///////////////////////
/////////////////////////////////////////////////////////////////////

void Cliente::add_client_dependente(vector <Cliente> &clientes){
    string nome, cpf;
    cout << "Digite o nome do cliente: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Digite o CPF do cliente: ";
    cin >> cpf;

    Cliente cliente(nome, cpf);
    
    int numDependentes;
    cout << "Digite o numero de dependentes: ";
    cin >> numDependentes;

    for (int i = 0; i < numDependentes; ++i) {
        cout << "-----------------------------"<< endl;

        string nomeDependente, cpfDependente, tipoRelacao;
        cout << "Digite o nome do dependente " << i+1 << ": ";
        cin.ignore();
        getline(cin, nomeDependente);
        cout << "Digite o CPF do dependente " << i+1 << ": ";
        cin >> cpfDependente;
        cout << "Digite o tipo de relacao do dependente " << i+1 << ": ";
        cin >> tipoRelacao;

        Dependente* dependente = new Dependente(nomeDependente, cpfDependente, tipoRelacao);
        cliente.addDependente(dependente);
    }
    clientes.push_back(cliente);
}


void Cliente::imprimirClientes(vector<Cliente>& clientes) {
    cout << "-------LISTA CLIENTES---------"<< endl;

    for (Cliente cliente : clientes) {
        cout << "Nome do Cliente: " << cliente.getNome() << endl;
        cout << "CPF do Cliente: " << cliente.getCpf() << endl;

        const vector<Dependente*>& dependentes = cliente.getDependentes();
        if (dependentes.size() > 0) {
            cout << "Dependentes:" << endl;
            for ( Dependente* dependente : dependentes) {
                cout << "   Nome: " << dependente->getNome() << endl;
                cout << "   CPF: " << dependente->getCpf() << endl;
                cout << "   Tipo de Relacao: " << dependente->getTipoRelacao() << endl;
                cout << "------------" << endl;
            }
        } else {
            cout << "O cliente nao possui dependentes." << endl;
        }
        cout << "---------------------------" << endl;
    }
}

void Cliente::imprimirPacoteCliente(Cliente* cliente){
    cout << "-------LISTA CLIENTES E SEUS PACOTES---------"<< endl;

    cout << "Nome do Cliente: " << cliente->getNome() << endl;
    cout << "CPF do Cliente: " << cliente->getCpf() << endl;

    const vector<Pacote*>& pacotes = cliente->getPacotes();
    if (pacotes.size() > 0) {
        for ( Pacote* p: pacotes) {
        cout << "   Nome: " << p->getCodigo() << endl;
        cout << "   CPF: " << p->getDescricao() << endl;
        cout << "------------" << endl;
        }
    }
}

void Cliente::venderPacoteCliente(Pacote* pacote) {
    pacotes.push_back(pacote);
    pacote->adicionarCliente(this);
}

//////////////////////////////////////////////////////////////////////
///////////////////FINAL DA CLASSE CLIENTE E METODOS//////////////////
/////////////////////////////////////////////////////////////////////

void listarPacotes(vector<Pacote> &pacotes){
    cout<<"### LISTA DE PACOTES ###"<<endl;
    for(Pacote pacote : pacotes){
        cout<<"--------------------------"<<endl;
        cout<<"Codigo: "<<pacote.getCodigo()<<endl;
        cout<<"Descricao: "<<pacote.getDescricao()<<endl;
        cout<<"Valor: "<<pacote.getPreco()<<endl;
        cout<<"Eventos cadastrados: "<<endl;
        const vector<Evento>* eventos = pacote.getEventos();
        for(auto i = 0; i < eventos->size(); i++){
            cout<<"\nRoteiro: "<<endl;
            cout<<"Destino: "<<pacote.getEventos()->at(i).getRoteiro().getDestino()<<endl;
            cout<<"Pontos turisticos: "<<endl;
            for(string ponto : pacote.getEventos()->at(i).getRoteiro().getPontosTuristicos()){
                cout<<ponto<<endl;
            }

            cout<<"\nDeslocamento:"<<endl;
            cout<<"Transporte via "<<pacote.getEventos()->at(i).getDeslocamento().getMeioTransporte()<<endl;
            cout<<"Duracao: "<<pacote.getEventos()->at(i).getDeslocamento().getDuracaoHoras()<<endl;
            cout<<"Origem: "<<pacote.getEventos()->at(i).getDeslocamento().getOrigem()<<endl;

            cout<<"\nPernoite:"<<endl;
            cout<<"Hotel: "<<pacote.getEventos()->at(i).getPernoite().getHotel()<<endl;
            cout<<"Localizacao: "<<pacote.getEventos()->at(i).getPernoite().getEndereco()<<endl;
            cout<<"Quantidade de noites: "<<pacote.getEventos()->at(i).getPernoite().getNumeroNoites()<<endl;
        }
    }

    cout<<"--------------------------"<<endl;

}