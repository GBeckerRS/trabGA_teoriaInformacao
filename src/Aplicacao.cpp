#include    "Aplicacao.h"

// Construtor
Aplicacao::Aplicacao ()
{
    this->_opcaoMenu = new OpcaoMenu ();
}

// Destrutor
Aplicacao::~Aplicacao ()
{
    delete this->_opcaoMenu;
}

int Aplicacao::menu ()
{
    int retorno = 0;
    try
    {
    do
    {
        std::cout << "Digite o Modo de Operação (\'C\'odificador ou \'D\'ecodificador)" << std::endl;
        char modoOperacao;
        std::cin >> modoOperacao;
        try
        {
            this->_opcaoMenu->set_ModoDeUso (modoOperacao);
        }
        catch (const std::invalid_argument& ex)
        {
            std::cout << "Erro: " << ex.what () << std::endl;
            retorno = -1;
        }
    } while (retorno < 0);
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Ocorreu um erro não tratado no MENU: " << ex.what () << std::endl;
        std::terminate ();
    }
    return retorno;
}

int Aplicacao::meinKampf ()
{
    std::cout << "Beta teste MENU" << std::endl;
    return this->menu ();
}

// Gets and Sets

void Aplicacao::set_nomeArquivoEntrada (const std::string& n)
{
    this->_arqEntrada = n;
}

void Aplicacao::set_nomeArquivoSaida (const std::string& n)
{
    this->_arqSaida = n;
}

void Aplicacao::set_modoDeOperacao_atual (const char& m)
{
    this->_modoDeOperacao_atual = m;
}

void Aplicacao::set_tipoDeCodificacao_atual (const char& t)
{
    this->_tipoCodificacao_atual = t;
}

void Aplicacao::set_golombDivisor_atual (const int& d)
{
    this->_golombDivisor_atual = d;
}

std::string Aplicacao::get_nomeArquivoEntrada ()
{
    return this->_arqEntrada;
}

std::string Aplicacao::get_nomeArquivoSaida ()
{
    return this->_arqSaida;
}

char Aplicacao::get_modoDeOperacao_atual ()
{
    return this->_modoDeOperacao_atual;
}

char Aplicacao::get_tipoDeCodificacao_atual ()
{
    return this->_tipoCodificacao_atual;
}

int Aplicacao::get_golombDivisor_atual ()
{
    return this->_golombDivisor_atual;
}

