#ifndef     SRC_INC_CODEC_H
#define     SRC_INC_CODEC_H

#include    <string>

class Codec
{
public:
    virtual void codificar () = 0;
    virtual void decodificar () = 0;
    virtual std::string status (bool imprime) = 0;

};

#endif      // SRC_INC_CODEC_H

