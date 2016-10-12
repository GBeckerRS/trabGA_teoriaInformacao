#include    "inc/Golomb.h"

// Construtor
Golomb::Golomb (Dicionario* dicionario, int divisor)
{
    this->_dicionario = dicionario;
    this->_divisor = divisor;
    this->_tPrefixo = 0;
    this->_tSulfixo = 0;
    this->_vSulfixo = 0;
    this->_bitWalker = 0;
    this->_byteWalker = 0;
}

//Destrutor
Golomb::~Golomb ()
{
}

void Golomb::codificar ()
{
    std::cout << "Codificador Golomb" << std::endl;
    if (this->_input.empty ())
    {
        return;
    }
    this->calcula ();
    this->status (true);

    unsigned char dado = this->get_vSulfixo ();
    unsigned char stopBit = 1;
    stopBit = stopBit << this->get_tSulfixo ();

    dado = (dado | stopBit);

    int qtShift = (this->get_tSulfixo () + 1) - this->get_bitWalker ();
    this->set_bitWalker (qtShift);
    dado = dado << qtShift;

    // TODO: Necessario tratar situacao quando o tamanho do byte 
    // estoura, sendo necessario escrever no proximo byte

    // Até aqui, tenho dado + Stop bit no lugar certo

    // Armazenar no lugar certo do buffer de saida 
    // Considerando o shift a direira do tamanho do prefixo

    return;
}

void Golomb::decodificar ()
{
    std::cout << "Decodificador Golomb" << std::endl;
}

std::string Golomb::status (bool imprime=false)
{
    std::stringstream ss;
    ss << "Divisor: " << this->get_divisor () << std::endl;
    ss << "Tamanho do Prefixo: " << this->get_tPrefixo () << std::endl;
    ss << "Tamanho do Sulfixo: " << this->get_tSulfixo ()<< std::endl;
    ss << "Valor do Sulfixo: " << this->get_vSulfixo ();

    std::string out = ss.str ();
    if (imprime)
    {
        std::cout << out << std::endl;;
    }
    return out;
}

void Golomb::calcula ()
{
    int codigo = 0;
    char simbolo = this->_input.back ();
    codigo = this->_dicionario->retornaCodigo (simbolo);

    this->_tPrefixo = codigo / this->_divisor;
    this->_tSulfixo = (log (this->_divisor) / log (2));
    this->_vSulfixo = codigo % this->_divisor;

    this->_input.pop_back ();
}

void Golomb::set_input (const std::string& input)
{
    int tam = input.size ();
    this->_input.clear ();
    this->_input.resize (tam);

    std::copy (input.begin (),input.end (),this->_input.begin ());
}

void Golomb::set_output (const std::string& output)
{
    int tam = output.size ();
    this->_output.clear ();
    this->_output.resize (tam);

    std::copy (output.begin (),output.end (),this->_output.begin ());
}

void Golomb::set_tPrefixo (const int& t)
{
    this->_tPrefixo = t;
}

void Golomb::set_tSulfixo (const int& t)
{
    this->_tSulfixo = t;
}

void Golomb::set_vSulfixo (const int& v)
{
    this->_vSulfixo = v;
}

void Golomb::set_divisor (const int& d)
{
    this->_divisor = d;
}

void Golomb::set_dicionario (Dicionario* d)
{
    this->_dicionario = d;
}

void Golomb::set_bitWalker (int b)
{
    this->_bitWalker = b;
}

void Golomb::set_byteWalker (int b)
{
    this->_byteWalker = b;
}

std::vector<char> Golomb::get_input ()
{
    return this->_input;
}

std::vector<char> Golomb::get_output ()
{
    return this->_output;
}

int Golomb::get_tPrefixo ()
{
    return this->_tPrefixo;
}

int Golomb::get_tSulfixo ()
{
    return this->_tSulfixo;
}

int Golomb::get_vSulfixo ()
{
    return this->_vSulfixo;
}

int Golomb::get_divisor ()
{
    return this->_divisor;
}

Dicionario* Golomb::get_dicionario ()
{
    return this->_dicionario;
}

int Golomb::get_bitWalker ()
{
    return this->_bitWalker;
}

int Golomb::get_byteWalker ()
{
    return this->_byteWalker;
}

