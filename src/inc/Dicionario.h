#ifndef     SRC_INC_DICIONARIO_H
#define     SRC_INC_DICIONARIO_H

#include    <iostream>
#include    <map>

class Dicionario
{
public:
    Dicionario ();
    Dicionario (const std::string& amostra);
    ~Dicionario ();

    void set_conjunto (const std::map<char,int>& c);
    std::map<char,int> get_conjunto ();

    int retornaCodigo (const char& c);
    void adicionaSimbolo (const char& s);

private:
    std::map<char,int> _conjunto;
    int _valor;

};

#endif      // SRC_INC_DICIONARIO_H

