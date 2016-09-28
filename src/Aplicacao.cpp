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
    int estado = 0;
    try
    {
    do
    {
        char modoOperacao, tipoCodificacao;
        int divisorElias = 0;
        switch (estado)
        {
        case 0:
            std::cout << "Digite o Modo de Operação (\'C\'odificador ou \'D\'ecodificador): ";
            std::cin >> modoOperacao;
            std::cout << std::endl;
            try
            {
                this->_opcaoMenu->set_ModoDeUso (modoOperacao);
                estado = 1;
            }
            catch (const std::invalid_argument& ex)
            {
                std::cout << "Erro: " << ex.what () << std::endl;
            }
        break;

        case 1:
            std::cout << "Digite o tipo de codificação (\'G\'olomb ou \'E\'lias-Gamma): ";
            std::cin >> tipoCodificacao;
            std::cout << std::endl;
            try
            {
                this->_opcaoMenu->set_TipoCodificacao (tipoCodificacao);
                estado = 2;
            }
            catch (const std::invalid_argument& ex)
            {
                std::cout << "Erro: " << ex.what () << std::endl;
            }
        break;

        case 2:
            if (tipoCodificacao == 'G')
            {
                std::cout << "Defina o valor do Divisor utilizado no Elias-Gamma: ";
                std::cin >> divisorElias;
                std::cout << std::endl;
                try
                {
                    this->_opcaoMenu->set_DivisorEliasGamma (divisorElias);
                    estado = 3;
                }
                catch (const std::invalid_argument& ex)
                {
                    std::cout << "Erro: " << ex.what () << std::endl;
                }
            }
            else
            {
                estado = 3;
            }
        break;
        };
    } while (estado < 3);
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Ocorreu um erro não tratado no MENU: " << ex.what () << std::endl;
        std::terminate ();
    }
    return 0;
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

