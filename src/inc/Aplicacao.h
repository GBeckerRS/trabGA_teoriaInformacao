#ifndef     SRC_INC_APLICACAO_H
#define     SRC_INC_APLICACAO_H

#include    <iostream>
#include    <stdexcept>
#include    <sstream>

#include    "OpcaoMenu.h"

class Aplicacao
{
private:
    std::string _arqEntrada;
    std::string _arqSaida;
    //Codificador _codificador;
    //Decodificador _decodificador;

    char _modoDeOperacao_atual;
    char _tipoCodificacao_atual;
    int _golombDivisor_atual;
    OpcaoMenu* _opcaoMenu;

    int menu ();
    void parserMenu ();

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

    std::string get_nomeArquivoEntrada ();
    std::string get_nomeArquivoSaida ();
    char get_modoDeOperacao_atual ();
    char get_tipoDeCodificacao_atual ();
    int get_golombDivisor_atual ();


};

#endif      // SRC_INC_APLICACAO_H

