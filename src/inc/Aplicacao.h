#ifndef     SRC_INC_APLICACAO_H
#define     SRC_INC_APLICACAO_H

class Aplicacao
{
private:
    std::string _arqEntrada;
    std::string _arqSaida;
    //Codificador _codificador;
    //Decodificador _decodificador;

    int menu ();

public:
    int start ();

}

#endif      // SRC_INC_APLICACAO_H

