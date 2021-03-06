#include    "inc/OpcaoMenu.h"

// Construtor
OpcaoMenu::OpcaoMenu ()
{
    this->_tipoCodificacao = ' ';
    this->_modoDeUso = ' ';
    this->_divisorEliasGamma = 0;
    this->_nomeArquivoEntrada = "";
    this->_nomeArquivoSaida = "";
}

OpcaoMenu::OpcaoMenu (const char& t,
                      const char& m,
                      const int& d,
                      const std::string& ne,
                      const std::string& ns)
{
    this->_tipoCodificacao = t;
    this->_modoDeUso = m;
    this->_divisorEliasGamma = d;
    this->_nomeArquivoEntrada = ne;
    this->_nomeArquivoSaida = ns;
}

// Destrutor
OpcaoMenu::~OpcaoMenu ()
{
}

void OpcaoMenu::set_TipoCodificacao (const char& t)
{
    if (t != 'G' && t != 'g' && t != 'E' && t != 'e')
    {
        throw std::invalid_argument ( "Tipo de Codificao invalido." );
    }
    this->_tipoCodificacao = t;
}

void OpcaoMenu::set_ModoDeUso (const char& m)
{
    if (m != 'C' && m != 'c' && m != 'D' && m != 'd')
    {
        throw std::invalid_argument ( "Modo de Uso invalido." );
    }
    this->_modoDeUso = m;
}

void OpcaoMenu::set_DivisorEliasGamma (const int& d)
{
    if (d <= 0)
    {
        throw std::invalid_argument ( "O Divisor deve ser maior que 0." );
    }
    this->_divisorEliasGamma = d;
}

void OpcaoMenu::set_NomeArquivoEntrada (const std::string& n)
{
    if (n.empty ())
    {
        throw std::invalid_argument ( "Nome do Arquivo de entrada invalido." );
    }
    this->_nomeArquivoEntrada = n;
}

void OpcaoMenu::set_NomeArquivoSaida (const std::string& n)
{
    if (n.empty ())
    {
        throw std::invalid_argument ( "Nome do Arquivo de saida invalido." );
    }
    this->_nomeArquivoSaida = n;
}

char OpcaoMenu::get_TipoCodificacao ()
{
    return this->_tipoCodificacao;
}

char OpcaoMenu::get_ModoDeUso ()
{
    return this->_modoDeUso;
}

int OpcaoMenu::get_DivisorEliasGamma ()
{
    return this->_divisorEliasGamma;
}

std::string OpcaoMenu::get_NomeArquivoEntrada ()
{
    return this->_nomeArquivoEntrada;
}

std::string OpcaoMenu::get_NomeArquivoSaida ()
{
    return this->_nomeArquivoSaida;
}

