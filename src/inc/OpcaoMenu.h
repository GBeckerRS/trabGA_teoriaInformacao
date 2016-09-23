#ifndef     SRC_INC_OPCAOMENU_H
#define     SRC_INC_OPCAOMENU_H

#include    <iostream>
#include    <stdexcept> // invalid_argument

class OpcaoMenu
{
private:
    char _tipoCodificacao;  // 'E'lias-Gamma ou 'G'olomb
    char _modoDeUso;    // 'C'odificador ou 'D'ecodificador

    int _divisorEliasGamma;

    std::string _nomeArquivoEntrada;
    std::string _nomeArquivoSaida;

public:
    OpcaoMenu ();
    ~OpcaoMenu ();

    void set_TipoCodificacao (const char& t);
    void set_ModoDeUso (const char& m);
    void set_DivisorEliasGamma (const int& d);
    void set_NomeArquivoEntrada (const std::string& n);
    void set_NomeArquivoSaida (const std::string& n);

    char get_TipoCodificacao ();
    char get_ModoDeUso ();
    int get_DivisorEliasGamma ();
    std::string get_NomeArquivoEntrada ();
    std::string get_NomeArquivoSaida ();

};

#endif      // SRC_INC_OPCAOMENU_H

