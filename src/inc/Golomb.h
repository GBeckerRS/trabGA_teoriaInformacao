#ifndef     SRC_INC_GOLOMB_H
#define     SRC_INC_GOLOMB_H

#include    <iostream>
#include    <string>
#include    <sstream>
#include    <vector>
#include    <algorithm>
#include    <cmath>
#include    <cstring> // memcpy, memset

#include    "Codec.h"
#include    "Dicionario.h"

class Golomb : public Codec
{
public:
    Golomb (Dicionario* dicionario,int divisor);
    ~Golomb ();

    void codificar ();
    void decodificar ();
    std::string status (bool imprime);
    void reset ();

    void set_input (const std::string& input);
    void set_output (const std::string& output);
    void set_tPrefixo (const int& t);
    void set_tSulfixo (const int& t);
    void set_vSulfixo (const int& v);
    void set_divisor (const int& d);
    void set_dicionario (Dicionario* d);
    void set_bitWalker (int b);
    void set_byteWalker (int b);

    std::vector<char> get_input ();
    std::vector<char> get_output ();
    int get_tPrefixo ();
    int get_tSulfixo ();
    int get_vSulfixo ();
    int get_divisor ();
    Dicionario* get_dicionario ();
    int get_bitWalker ();
    int get_byteWalker ();

private:
    std::vector <char> _input;
    std::vector <char> _output;
    int _tPrefixo;
    int _tSulfixo;
    int _vSulfixo;
    int _divisor;
    Dicionario* _dicionario;
    int _bitWalker;
    int _byteWalker;

    // Metodos privados
    void calcula ();

};

#endif      // SRC_INC_GOLOMB_H

