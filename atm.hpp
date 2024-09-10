#ifndef ATM_HPP
#define ATM_HPP

#include <cstdlib>

using namespace std;

//Declaracao de funcoes principais
void OSteste(int systema);

void criarUsuario(string nome, string senha, double saldo, int idade, char sexo, bool valido);

void fazerLogin(string nome, string senha, bool valido, int erro, char sexo, int idade, char res);

void mostrarDados();

void recuperarUsuario(char res, int idade, char sexo, string nome);

void recuperarSenha(char res, int idade, char sexo, string senha);

void exibirMenu(int escolha, string nome, double valor, char res, int idade, char sexo, string senha);

void fazerTransferencia(string nome, double valor, char res);

//Cria a class que manipula e armazenha os dados do usuario
class Usuario {
private:
    string nome;
    string senha;
    double saldo;
    int idade;
    char sexo;
public:
    void setNome(string nome) {
        this->nome=nome;
    }
    
    void setSenha(string senha) {
        this->senha=senha;
    }
    
    void setSaldo(int saldo) {
        this->saldo=saldo;
    }
    
    void setIdade(int idade) {
        this->idade=idade;
    }
    
    void setSexo(char sexo) {
        this->sexo=sexo;
    }
    
    string getNome() {
        return nome;
    }
    
    string getSenha() {
        return senha;
    }
    
    double getSaldo() {
        return saldo;
    }
    
    int getIdade() {
        return idade;
    }
    
    char getSexo() {
        return sexo;
    }
};

#endif //ATM_HPP