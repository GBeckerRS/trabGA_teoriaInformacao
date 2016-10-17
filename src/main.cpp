#include    <iostream>

#include    "inc/Aplicacao.h"

int main (int argc, const char * argv[])
{
    int retorno = 0;
    try
    {
        Aplicacao* app = new Aplicacao ();
        retorno = app->inicio ();
        delete app;
    }
    catch (std::exception ex)
    {
        std::cout << "Ocorreu um erro inesperado: " << ex.what () << std::endl;
        std::cout << "A aplicacao será encerrada!" << std::endl;
    }

    return retorno;
}

