#ifndef     SRC_INC_APLICACAO_H
#define     SRC_INC_APLICACAO_H

#include    <iostream>
#include    <stdexcept>
#include    <sstream>
#include    <fstream>

#include    "OpcaoMenu.h"
#include    "Golomb.h"
#include    "Codec.h"
#include    "Dicionario.h"

class Aplicacao
{
private:
    std::string _arqEntrada;
    std::string _arqSaida;
    Codec* _codec;

    char _modoDeOperacao_atual;
    char _tipoCodificacao_atual;
    int _golombDivisor_atual;
    OpcaoMenu* _opcaoMenu;

    // Buffers
    std::stringstream _entrada;
    std::stringstream _saida;

    int menu ();
    void parserMenu ();
    void leEntrada ();
    void escreveSaida ();

public:
    Aplicacao ();
    ~Aplicacao ();

    int meinKampf ();
    std::string imprimeOpcoes (bool imprime);

    void set_nomeArquivoEntrada (const std::string& n);
    void set_nomeArquivoSaida (const std::string& n);
    void set_modoDeOperacao_atual (const char& m);
    void set_tipoDeCodificacao_atual (const char& t);
    void set_golombDivisor_atual (const int& d);
    void set_bufferEntrada (std::string& dados);
    void set_bufferSaida (std::string& dados);

    std::string get_nomeArquivoEntrada ();
    std::string get_nomeArquivoSaida ();
    char get_modoDeOperacao_atual ();
    char get_tipoDeCodificacao_atual ();
    int get_golombDivisor_atual ();
    std::string get_bufferEntrada ();
    std::string get_bufferSaida ();

};

#endif      // SRC_INC_APLICACAO_H

