#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include "le_arquivo.hpp"
#include "adiciona_palavra.hpp"





std::string sorteia_palavra(){
    std::vector<std::string> palavras = le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    return palavras[indice_sorteado];
}

