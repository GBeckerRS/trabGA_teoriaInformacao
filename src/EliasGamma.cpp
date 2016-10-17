#include    "inc/EliasGamma.h"

EliasGamma::EliasGamma ()
{
}

EliasGamma::~EliasGamma ()
{
}

void EliasGamma::codificar ()
{
    this->calcula ();
    this->status (true);
}

void EliasGamma::decodificar ()
{
}

std::string EliasGamma::status (bool imprime=false)
{
    std::stringstream ss;
    ss << "Ultimo caracter codificado/decodificado = " << this->get_caracter () << std::endl;
    ss << "Tamanho N = " << this->get_N () << std::endl;
    ss << "Codigo do caracter = " << this->get_valor () << std::endl;

    std::string status = ss.str ();
    if (imprime)
    {
        std::cout << status << std::endl;
    }

    return status;
}

void EliasGamma::calcula ()
{
    char caracter = this->_input.back ();
    int codigo = this->_dicionario->retornaCodigo (caracter);

    this->_N = (log10 ((double)codigo) / log10 ((double)2));
    this->_valor = codigo;

    this->_input.pop_back ();   // Delete an element
}


void EliasGamma::set_input (const std::string& input)
{
    int tam = input.size ();
    this->_input.clear ();
    this->_input.resize (tam);

    std::copy (input.begin (),input.end (),this->_input.begin ());
}

void EliasGamma::set_output (const std::string& output)
{
    int tam = output.size ();
    this->_output.clear ();
    this->_output.resize (tam);

    std::copy (output.begin (),output.end (),this->_output.begin ());
}

void EliasGamma::set_N(const unsigned int& n)
{
    this->_N = n;
}

void EliasGamma::set_valor (const unsigned int& v)
{
    this->_valor = v;
}

void EliasGamma::set_dicionario (Dicionario* d)
{
    this->_dicionario = d;
}

void EliasGamma::set_caracter (const char& c)
{
    this->_caracter = c;
}

std::vector<char> EliasGamma::get_input ()
{
    return this->_input;
}

std::vector<char> EliasGamma::get_output ()
{
    return this->_output;
}

unsigned int EliasGamma::get_N ()
{
    return this->_N;
}

unsigned int EliasGamma::get_valor ()
{
    return this->_valor;
}

Dicionario* EliasGamma::get_dicionario ()
{
    return this->_dicionario;
}

char EliasGamma::get_caracter ()
{
    return this->_caracter;
}

