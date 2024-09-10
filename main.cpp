#include <iostream>
#include "atm.hpp"
#include <cstdlib>

using namespace std;

int main() {
    
    string nome, senha;
    double saldo, valor;
    bool valido;
    int sistema, erro=0, idade, escolha;
    char sexo, res;
    
    //Faz a verificacao do sistema do usuario para saber qual comando usar na limpagem de tela
    #if defined(_WIN32) || defined(_WIN64)
        sistema=1;
    #elif defined(__APPLE__) || defined(__MACH__)
        sistema=2;
    #elif defined(__linux__)
        sistema=2;
    #elif defined(__unix__) || defined(__unix)
        sistema=2;
    #elif defined(__FreeBSD__)
        sistema=2;
    #else
        sistem=0;
    #endif
    
    //Chama a função que cria o usuario
    criarUsuario(nome, senha, saldo, idade, sexo, valido);
    
    //Chama a funcao que limpa a tela
    OSteste(sistema);
    
    //Chama a função que faz login
    fazerLogin(nome, senha, valido, erro, sexo, idade, res);
    
    //Sistema de repeticao para terminar o programa dependendo da escolha
    while(escolha != 4) {
        
        //Chama a funcao que limpa a tela
        OSteste(sistema);
        
        //Chama a funcao que mostra os dados do usuario
        mostrarDados();
        
        //Chama a funcao que exibe o menu
        exibirMenu(escolha, nome, valor, res, idade, sexo, senha);
    }    
    return 0;
}