#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "letra_existe.hpp"
#include "imprime_cabecalho.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "nao_acertou.hpp"
#include "nao_enforcou.hpp"
#include "chuta.hpp"
#include "le_arquivo.hpp"
#include "sorteia_palavra.hpp"
#include "adiciona_palavra.hpp"
#include "salva_arquivo.hpp"

using namespace std;

static string palavra_secreta;
static map<char, bool> chutou;
static vector<char> chutes_errados;





int main () {
    imprime_cabecalho();
    palavra_secreta = sorteia_palavra();

    while(nao_acertou(palavra_secreta, chutou) && chutes_errados.size() < 5){
        imprime_erros(chutes_errados);

        imprime_palavra(palavra_secreta, chutou);

         chuta(chutou, chutes_errados, palavra_secreta);
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;
    if(nao_acertou(palavra_secreta, chutou)){
        cout << "Voce perdeu! Tente novamente!" << endl;
    }
        else{
        cout << "Parabens! Voce acertou a palavra secreta!" << endl;


        cout << "Voce deseja adicionar uma nova palavra ao banco de plavras? (S/N) " << endl;
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
            adiciona_palavra();
        }

    
        }
}