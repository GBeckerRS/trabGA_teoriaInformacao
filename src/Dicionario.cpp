#include    "inc/Dicionario.h"

// Construtor
Dicionario::Dicionario ()
{
    this->_valor = 0;
    this->adicionaSimbolo (' ');
    this->_conjunto ['!'] = 1;
    this->_conjunto ['\"'] = 2;
    this->_conjunto ['\''] = 3;
    this->_conjunto ['('] = 4;
    this->_conjunto [')'] = 5;
    this->_conjunto ['0'] = 6;
    this->_conjunto ['1'] = 7;
    this->_conjunto ['2'] = 8;
    this->_conjunto ['3'] = 9;
    this->_conjunto ['4'] = 10;
    this->_conjunto ['5'] = 11;
    this->_conjunto ['6'] = 12;
    this->_conjunto ['7'] = 13;
    this->_conjunto ['8'] = 14;
    this->_conjunto ['9'] = 15;
    this->_conjunto [':'] = 16;
    this->_conjunto [';'] = 17;
    this->_conjunto ['.'] = 18;
    this->_conjunto ['?'] = 19;
    this->_conjunto ['A'] = 20;
    this->_conjunto ['B'] = 21;
    this->_conjunto ['C'] = 22;
    this->_conjunto ['D'] = 23;
    this->_conjunto ['E'] = 24;
    this->_conjunto ['F'] = 25;
    this->_conjunto ['G'] = 26;
    this->_conjunto ['H'] = 27;
    this->_conjunto ['I'] = 28;
    this->_conjunto ['J'] = 29;
    this->_conjunto ['K'] = 30;
    this->_conjunto ['L'] = 31;
    this->_conjunto ['M'] = 32;
    this->_conjunto ['N'] = 33;
    this->_conjunto ['O'] = 34;
    this->_conjunto ['P'] = 35;
    this->_conjunto ['Q'] = 36;
    this->_conjunto ['R'] = 37;
    this->_conjunto ['S'] = 38;
    this->_conjunto ['T'] = 39;
    this->_conjunto ['U'] = 40;
    this->_conjunto ['V'] = 41;
    this->_conjunto ['W'] = 42;
    this->_conjunto ['X'] = 43;
    this->_conjunto ['Y'] = 44;
    this->_conjunto ['Z'] = 45;
    this->_conjunto ['a'] = 46;
    this->_conjunto ['b'] = 47;
    this->_conjunto ['c'] = 48;
    this->_conjunto ['d'] = 49;
    this->_conjunto ['e'] = 50;
    this->_conjunto ['f'] = 51;
    this->_conjunto ['g'] = 52;
    this->_conjunto ['h'] = 53;
    this->_conjunto ['i'] = 54;
    this->_conjunto ['j'] = 55;
    this->_conjunto ['k'] = 56;
    this->_conjunto ['l'] = 57;
    this->_conjunto ['m'] = 58;
    this->_conjunto ['n'] = 59;
    this->_conjunto ['o'] = 60;
    this->_conjunto ['p'] = 61;
    this->_conjunto ['q'] = 62;
    this->_conjunto ['r'] = 63;
    this->_conjunto ['s'] = 64;
    this->_conjunto ['t'] = 65;
    this->_conjunto ['u'] = 66;
    this->_conjunto ['v'] = 67;
    this->_conjunto ['w'] = 68;
    this->_conjunto ['x'] = 69;
    this->_conjunto ['y'] = 70;
    this->_conjunto ['z'] = 71;
}

// Construtor
Dicionario::Dicionario (const std::string& amostra)
{
    this->_valor = 0;
    int tamanho = amostra.size ();
    char chave = ' ';

    for (int i = 0; i<tamanho; i++)
    {
        chave = amostra.at (i);
        this->adicionaSimbolo (chave);
    }
}

// Destrutor
Dicionario::~Dicionario ()
{
}

int Dicionario::retornaCodigo (const char& c)
{
    int codigo = this->_conjunto [c];
    return codigo;
}

void Dicionario::adicionaSimbolo (const char& s)
{
    int existeSimbolo = this->_conjunto.count (s);
    if (existeSimbolo == 0)
    {
        this->_conjunto [s] = _valor++;
    }
}

void Dicionario::set_conjunto (const std::map<char,int>& c)
{
    this->_conjunto = c;
}

std::map<char,int> Dicionario::get_conjunto ()
{
    return this->_conjunto;
}

