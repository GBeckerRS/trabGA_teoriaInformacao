#include    <iostream>

#include    "../inc/OpcaoMenu.h"

int main (int argc, const char * argv[])
{
    try
    {
        OpcaoMenu* op = new OpcaoMenu ();

        std::cout << "Test #1 -> Tipo de Codificacao" << std::endl;
        std::cout << "Atribuindo um caracter invalido: " << std::endl;
        try
        {
            op->set_TipoCodificacao ('B');
        }
        catch (const std::invalid_argument& ex)
        {
            std::cout << "Erro capturado: " << ex.what () << std::endl;
        }
        std::cout << "atribuindo um caracter valido:" << std::endl;
        try
        {
            op->set_TipoCodificacao ('E');
        }
        catch (const std::invalid_argument ex)
        {
            std::cout << "Erro capturado: " << ex.what () << std::endl;
            return -1;
        }
        if (op->get_TipoCodificacao () == 'E')
        {
            std::cout << "Teste OK!" << std::endl;
        }
        else
        {
            std::cout << "Teste NOK!" << std::endl;
        }
        std::cout << "==============================" << std::endl;

        std::cout << "Test #2 -> Modo de Uso" << std::endl;
        std::cout << "Atribuindo um caracter invalido" << std::endl;
        try
        {
            op->set_ModoDeUso ('A');
        }
        catch (const std::invalid_argument& ex)
        {
            std::cout << "Erro capturado: " << ex.what () << std::endl;
        }
        std::cout << "atribuindo um caracter valido:" << std::endl;
        try
        {
            op->set_ModoDeUso ('c');
        }
        catch (const std::invalid_argument& ex)
        {
            std::cout << "Erro capturado: " << ex.what () << std::endl;
            return -1;
        }
        if (op->get_ModoDeUso () == 'c')
        {
            std::cout << "Test OK!" << std::endl;
        }
        else
        {
            std::cout << "Test NOK!" << std::endl;
        }
        std::cout << "==============================" << std::endl;

        std::cout << "Test #3 -> Divisor Elias-Gamma" << std::endl;
        op->set_DivisorEliasGamma (8);
        if (op->get_DivisorEliasGamma () == 8)
        {
            std::cout << "Test OK!" << std::endl;
        }
        else
        {
            std::cout << "Test NOK!" << std::endl;
        }
        std::cout << "==============================" << std::endl;

        std::cout << "Test #4 -> Nome arquivo de entrada" << std::endl;
        op->set_NomeArquivoEntrada ("string de teste");
        if (op->get_NomeArquivoEntrada () == "string de teste")
        {
            std::cout << "Test OK!" << std::endl;
        }
        else
        {
            std::cout << "Test NOK!" << std::endl;
        }
        std::cout << "==============================" << std::endl;

        std::cout << "Test #5 -> Nome arquivo de saida" << std::endl;
        op->set_NomeArquivoSaida ("string de teste");
        if (op->get_NomeArquivoSaida () == "string de teste")
        {
            std::cout << "Test OK!" << std::endl;
        }
        else
        {
            std::cout << "Test NOK!" << std::endl;
        }
        std::cout << "==============================" << std::endl;
    }
    catch (...)
    {
        std::cout << "Erro inesperado!" << std::endl;
    }

    return 0;
}

