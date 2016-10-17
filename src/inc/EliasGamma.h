#ifndef     SRC_INC_ELIASGAMMA_H
#define     SRC_INC_ELIASGAMMA_H

#include    <iostream>
#include    <vector>
#include    <cmath>
#include    <sstream>
#include    <algorithm>

#include    "Dicionario.h"
#include    "Codec.h"

class EliasGamma : public Codec
{
public:
    EliasGamma ();
    ~EliasGamma ();

    void codificar ();
    void decodificar ();
    std::string status (bool imprime);
    void calcula ();

    void set_input (const std::string& input);
    void set_output (const std::string& output);
    void set_N(const unsigned int& n);
    void set_valor (const unsigned int& v);
    void set_dicionario (Dicionario* d);
    void set_caracter (const char& c);

    std::vector<char> get_input ();
    std::vector<char> get_output ();
    unsigned int get_N ();
    unsigned int get_valor ();
    Dicionario* get_dicionario ();
    char get_caracter ();

private:
    std::vector<char> _input;
    std::vector<char> _output;
    unsigned int _N;
    unsigned int _valor;
    Dicionario* _dicionario;
    unsigned char _caracter;
};

#endif      // SRC_INC_ELIASGAMMA_H

