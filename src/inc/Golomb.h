#ifndef     SRC_INC_GOLOMB_H
#define     SRC_INC_GOLOMB_H

#include    <iostream>
#include    <string>

#include    "Codec.h"

class Golomb : public Codec
{
public:
    Golomb ();
    ~Golomb ();

    void codificar ();
    void decodificar ();
    std::string status (bool imprime);

private:

};

#endif      // SRC_INC_GOLOMB_H

