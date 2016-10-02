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
        std::string nomeArquivoEntrada, nomeArquivoSaida;

        switch (estado)
        {
        case 0:
            std::cout << "Digite o Modo de Operação (\'C\'odificador ou \'D\'ecodificador): ";
            std::cin >> modoOperacao;
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
            if (tipoCodificacao == 'G' || tipoCodificacao == 'g')
            {
                std::cout << "Defina o valor do Divisor utilizado no Golomb: ";
                std::cin >> divisorElias;
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

        case 3:
            try
            {
                std::cout << "Escolha o arquivo de entrada: ";
                std::cin.ignore ();
                std::getline (std::cin, nomeArquivoEntrada);
                this->_opcaoMenu->set_NomeArquivoEntrada (nomeArquivoEntrada);
                estado = 4;
            }
            catch (const std::invalid_argument& ex)
            {
                std::cout << "Erro: " << ex.what () << std::endl;
            }
        break;
        case 4:
            try
            {
                std::cout << "Escolha o arquivo de saida: ";
                std::cin.ignore ();
                std::getline (std::cin, nomeArquivoSaida);
                this->_opcaoMenu->set_NomeArquivoSaida (nomeArquivoSaida);
                estado = 5;
            }
            catch (const std::invalid_argument& ex)
            {
                std::cout << "Erro: " << ex.what () << std::endl;
            }
        break;
        };
    } while (estado < 5);
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
    this->menu ();
    this->parserMenu ();
    return 0;
}

void Aplicacao::parserMenu ()
{
    char tipoCodificacao, modoDeUso;
    int divisorG;
    std::string entrada, saida;

    tipoCodificacao = this->_opcaoMenu->get_TipoCodificacao ();
    modoDeUso = this->_opcaoMenu->get_ModoDeUso ();
    divisorG = this->_opcaoMenu->get_DivisorEliasGamma ();
    entrada = this->_opcaoMenu->get_NomeArquivoEntrada ();
    saida = this->_opcaoMenu->get_NomeArquivoSaida ();

    if (tipoCodificacao != ' ')
    {
        this->set_tipoDeCodificacao_atual (tipoCodificacao);
    }

    if (modoDeUso != ' ')
    {
        this->set_modoDeOperacao_atual (modoDeUso);
    }

    if (divisorG > 0)
    {
        this->set_golombDivisor_atual (divisorG);
    }

    if (!entrada.empty ())
    {
        this->set_nomeArquivoEntrada (entrada);
    }

    if (!saida.empty ())
    {
        this->set_nomeArquivoSaida (saida);
    }
}

std::string Aplicacao::imprimeOpcoes (bool imprime=false)
{
    std::stringstream ss;

    ss << "Modo de operação = " << this->get_modoDeOperacao_atual () << std::endl;
    ss << "Tipo de codificacao = " << this->get_tipoDeCodificacao_atual () << std::endl;
    ss << "Divisor Golomb = " << this->get_golombDivisor_atual () << std::endl;
    ss << "Arquivo Entrada = " << this->get_nomeArquivoEntrada () << std::endl;
    ss << "Arquivo Saida = " << this->get_nomeArquivoSaida ();

    if (imprime)
    {
        std::cout << ss.str () << std::endl;
    }
    return ss.str ();
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

