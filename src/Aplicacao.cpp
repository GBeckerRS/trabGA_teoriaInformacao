#include    "Aplicacao.h"

// Construtor
Aplicacao::Aplicacao ()
{
    this->_opcaoMenu = new OpcaoMenu ();
    this->_codec = 0;
}

// Destrutor
Aplicacao::~Aplicacao ()
{
    delete this->_opcaoMenu;
    if (this->_codec)
    {
        delete this->_codec;
    }
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
    //this->menu ();
    //this->parserMenu ();

    // Debug
    this->set_nomeArquivoEntrada ("misc/input.txt");
    this->leEntrada ();
    std::string d = this->_entrada.str ();

    Dicionario* dic = new Dicionario ();

/*
    std::stringstream sss;
    char cA = ' ';
    std::vector <char> vec (32,0);
    vec [0] = cA;
    vec [0] = vec[0] >> 8;
*/

    Golomb go (dic,8);
    go.set_input ("casa");
    go.codificar ();
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

void Aplicacao::leEntrada ()
{
    std::string fileName = this->get_nomeArquivoEntrada ();
    try
    {
    std::ifstream file (fileName.c_str ());
    if (file.is_open ())
    {
        this->_entrada << file.rdbuf ();
        file.close ();
        return;
    }
    // Dispara excessao de erro
    }
    catch (std::ifstream::failure& ex)
    {
        std::cout << "Erro: " << ex.what ();
        // Disparar excessão
    }
}

void Aplicacao::escreveSaida ()
{
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

void Aplicacao::set_bufferEntrada (std::string& dados)
{
    //this->_entrada << dados.c_str ();
}

void Aplicacao::set_bufferSaida (std::string& dados)
{
    //this->_saida << dados.c_str ();
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

std::string Aplicacao::get_bufferEntrada ()
{
    return this->_entrada.str ();
}

std::string Aplicacao::get_bufferSaida ()
{
    return this->_saida.str ();
}

