#include <iostream>
#include <vector>
#include <limits>

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
        void adicionarEvento(Evento* evento);
        void listarPacoteComEventos() const;
};

void listarPacotes(vector<Pacote>&);
void exibirMenu() {
    cout << "### Sistema de Agencia de Viagens ###" << endl;
    cout << "1. Cadastrar Evento" << endl;
    cout << "2. Criar Pacote" << endl;
    cout << "3. Criar Cliente" << endl;
    cout << "4. Vender Pacote a Cliente" << endl;
    cout << "5. Consultar Lista de Clientes" << endl;
    cout << "6. Consultar Lista de Pacotes" << endl;
    cout << "7. Consultar Pacotes Contratados por Cliente" << endl;
    cout << "8. Consultar Clientes que Contrataram um Pacote" << endl;
    cout << "9. Sair" << endl;
    cout << "Escolha uma opcao (1-9): ";
}

int main() {
    vector<Cliente> clientes;
    vector<Pacote> pacotes;
    vector<Evento> eventos;

    while (true) {
        exibirMenu();
        int opcao;
        cin >> opcao;

        if (opcao == 1) {
             string destino;
            vector<string> pontosTuristicos;
            string meioTransporte;
            int duracaoHoras;
            string origem;
            string hotel;
            string endereco;
            int numeroNoites;

            cout << "Cadastrar Evento" << endl;
            
            cout << "Digite o destino do roteiro: ";
            cin.ignore();
            getline(cin, destino);

            int numPontosTuristicos;
            cout << "Quantos pontos turísticos deseja cadastrar? ";
            cin >> numPontosTuristicos;
            for (int i = 0; i < numPontosTuristicos; i++) {
                string ponto;
                cout << "Digite o ponto turistico " << i + 1 << ": ";
                cin.ignore();
                getline(cin, ponto);
                pontosTuristicos.push_back(ponto);
            }

            cout << "Digite o meio de transporte: ";
            cin.ignore();
            getline(cin, meioTransporte);
            cout << "Digite a duração em horas: ";
            cin >> duracaoHoras;
            cout << "Digite a origem do deslocamento: ";
            cin.ignore();
            getline(cin, origem);
            cout << "Digite o nome do hotel: ";
            cin.ignore();
            getline(cin, hotel);
            cout << "Digite o endereço do hotel: ";
            cin.ignore();
            getline(cin, endereco);
            cout << "Digite o numero de noites: ";
            cin >> numeroNoites;

            Roteiro roteiro(destino, pontosTuristicos);
            Deslocamento deslocamento(meioTransporte, duracaoHoras, origem);
            Pernoite pernoite(hotel, endereco, numeroNoites);
            Evento evento(roteiro, deslocamento, pernoite);

            eventos.push_back(evento);
            
            cout << "Evento cadastrado com sucesso!" << endl;
        } else if (opcao == 2) {
                int codigo;
                double preco;
                string descricao;

                cout << "Criar Pacote" << endl;

                cout << "Digite o código do pacote: ";
                cin >> codigo;
                cout << "Digite o preço do pacote: ";
                cin >> preco;

                cin.ignore();  // Limpar o buffer de entrada
                cout << "Digite a descrição do pacote: ";
                getline(cin, descricao);

                Pacote pacote(codigo, preco, descricao);

                // Listar os pontos turísticos disponíveis
                cout << "Pontos turisticos disponiveis:" << endl;
                vector<string> pontosTuristicosDisponiveis;
                for (const Evento& evento : eventos) {
                    for (const string& pontoTuristico : evento.getRoteiro().getPontosTuristicos()) {
                        pontosTuristicosDisponiveis.push_back(pontoTuristico);
                    }
                }

                for (size_t i = 0; i < pontosTuristicosDisponiveis.size(); i++) {
                    cout << i+1 << ". " << pontosTuristicosDisponiveis[i] << endl;
                }

                // Solicitar ao usuário a escolha de eventos por ponto turístico
                int numEventos;
                cout << "Quantos eventos deseja adicionar a este pacote? ";
                cin >> numEventos;
                    numEventos = numEventos - 1;
                for (int i = 0; i < numEventos; i++) {
                    cout << "Escolha o evento pelo indice: ";
                    int escolhaEvento;
                    cin >> escolhaEvento;
                    //escolhaEvento = escolhaEvento + 1;
                    if (escolhaEvento >= 0 && escolhaEvento < eventos.size()) {
                        // Adicionar o evento escolhido ao pacote
                        pacote.adicionarEvento(&eventos[escolhaEvento]);
                    } else {
                        cout << "Escolha de evento inválida. Certifique-se de que o índice seja valido." << endl;
                    }
                }

                // Adicionar o pacote criado à lista de pacotes
                pacotes.push_back(pacote);

                cout << "Pacote criado com sucesso!" << endl;


        } else if (opcao == 3) {
            // Opção 3: Criar Cliente
            Cliente::add_client_dependente(clientes);
        } else if (opcao == 4) {
            // Opção 4: Vender Pacote a Cliente
            cout << "Clientes disponíveis para venda de pacotes:" << endl;
            for (size_t i = 0; i < clientes.size(); i++) {
                cout << i << ". " << clientes[i].getNome() << " (" << clientes[i].getCpf() << ")" << endl;
            }

            // Solicitar ao usuário a escolha de um cliente
            int clienteIndex;
            cout << "Escolha o cliente pelo índice: ";
            cin >> clienteIndex;

            if (clienteIndex >= 0 && clienteIndex < clientes.size()) {
                // Listar pacotes disponíveis
                cout << "Pacotes disponíveis para venda:" << endl;
                listarPacotes(pacotes);

                // Solicitar ao usuário a escolha de um pacote
                int pacoteIndex;
                cout << "Escolha o pacote pelo código: ";
                cin >> pacoteIndex;

                if (pacoteIndex >= 0 && pacoteIndex < pacotes.size()) {
                    // Vender o pacote ao cliente
                    clientes[clienteIndex].venderPacoteCliente(&pacotes[pacoteIndex]);
                    cout << "Pacote vendido com sucesso para o cliente." << endl;
                } else {
                    cout << "Pacote não encontrado. Certifique-se de que o código seja válido." << endl;
                }
            } else {
                cout << "Cliente não encontrado. Certifique-se de que o índice seja válido." << endl;
            }
        } else if (opcao == 5) {
            // Opção 5: Consultar Lista de Clientes
            Cliente::imprimirClientes(clientes);
        } else if (opcao == 6) {
           // Opção 6: Consultar Lista de Pacotes
            listarPacotes(pacotes); // Primeiro, liste todos os pacotes disponíveis
            int escolhaPacote;
cout << "Escolha o pacote pelo índice para listar os eventos: ";
cin >> escolhaPacote;

if (cin.fail()) {
    // Se a entrada não for um número válido
    cout << "Entrada inválida. Certifique-se de inserir um número." << endl;
    // Limpar o estado de erro e o buffer de entrada
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
} else if (escolhaPacote >= 0 && escolhaPacote < pacotes.size()) {
    pacotes[escolhaPacote].listarPacoteComEventos();
} else {
    cout << "Pacote não encontrado. Certifique-se de que o índice seja válido." << endl;
}
            //listarPacotes(pacotes);
        } else if (opcao == 7) {
            // Opção 7: Consultar Pacotes Contratados por Cliente
            int escolhaCliente;
            cout << "Escolha o cliente pelo índice ou CPF: ";
            cin >> escolhaCliente;

            if (escolhaCliente >= 0 && escolhaCliente < clientes.size()) {
                // Chame o método para listar os pacotes do cliente escolhido
                Cliente::imprimirPacoteCliente(&clientes[escolhaCliente]);
            } else {
                cout << "Cliente não encontrado. Certifique-se de que o índice ou CPF seja válido." << endl;
            }
        } else if (opcao == 8) {
            // Opção 8: Consultar Clientes que Contrataram um Pacote
            // Implemente a funcionalidade de consultar clientes que contrataram um pacote aqui
        } else if (opcao == 9) {
            // Opção 9: Sair
            cout << "Encerrando o programa. Até mais!" << endl;
            break;
        } else {
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }

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
        // const vector<Evento>* eventos = pacote.getEventos();
        // for(auto i = 0; i < eventos->size(); i++){
        //     cout<<"\nRoteiro: "<<endl;
        //     cout<<"Destino: "<<pacote.getEventos()->at(i).getRoteiro().getDestino()<<endl;
        //     cout<<"Pontos turisticos: "<<endl;
        //     for(string ponto : pacote.getEventos()->at(i).getRoteiro().getPontosTuristicos()){
        //         cout<<ponto<<endl;
        //     }

        //     cout<<"\nDeslocamento:"<<endl;
        //     cout<<"Transporte via "<<pacote.getEventos()->at(i).getDeslocamento().getMeioTransporte()<<endl;
        //     cout<<"Duracao: "<<pacote.getEventos()->at(i).getDeslocamento().getDuracaoHoras()<<endl;
        //     cout<<"Origem: "<<pacote.getEventos()->at(i).getDeslocamento().getOrigem()<<endl;

        //     cout<<"\nPernoite:"<<endl;
        //     cout<<"Hotel: "<<pacote.getEventos()->at(i).getPernoite().getHotel()<<endl;
        //     cout<<"Localizacao: "<<pacote.getEventos()->at(i).getPernoite().getEndereco()<<endl;
        //     cout<<"Quantidade de noites: "<<pacote.getEventos()->at(i).getPernoite().getNumeroNoites()<<endl;
        // }
        
    }

    cout<<"--------------------------"<<endl;

}


void Pacote::adicionarEvento(Evento* evento) {
   if (eventos == nullptr) {
        eventos = new vector<Evento>;
    }
    eventos->push_back(*evento); 
}

void Pacote::listarPacoteComEventos() const {
    cout << "Código do Pacote: " << codigo << endl;
    cout << "Descrição do Pacote: " << descricao << endl;
    cout << "Preço do Pacote: " << preco << endl;
    cout << "Eventos incluídos no Pacote:" << endl;

    if (eventos) {
        for (const Evento& evento : *eventos) {
            cout << "-----------------------------" << endl;
            cout << "Destino: " << evento.getRoteiro().getDestino() << endl;
            cout << "Pontos turísticos:" << endl;
            
            for (const string& pontoTuristico : evento.getRoteiro().getPontosTuristicos()) {
                cout << pontoTuristico << endl;
            }

            cout << "Transporte via " << evento.getDeslocamento().getMeioTransporte() << endl;
            cout << "Duração: " << evento.getDeslocamento().getDuracaoHoras() << " horas" << endl;
            cout << "Origem: " << evento.getDeslocamento().getOrigem() << endl;

            cout << "Hotel: " << evento.getPernoite().getHotel() << endl;
            cout << "Localização: " << evento.getPernoite().getEndereco() << endl;
            cout << "Número de noites: " << evento.getPernoite().getNumeroNoites() << " noites" << endl;
        }
    } else {
        cout << "Nenhum evento cadastrado neste pacote." << endl;
    }
}
