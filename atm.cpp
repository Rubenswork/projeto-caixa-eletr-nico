#include <iostream>
#include "atm.hpp"
#include <cstdlib>

int sistema;

using namespace std;

Usuario user1;

//Funcao que limpa a tela dependendo do sitema operacional
void OSteste(int systema) {
    if(systema == 1) {
        system("cls");
    } else if(systema == 2) {
        system("clear");
    }
}

//Função para criar o usuario
void criarUsuario(string nome,  string senha, double saldo, int idade, char sexo, bool valido) {
    
    //Recebe o nome do usuario usando a funcao setNome
    cout << "Crie o nome de usuário: ";
    cin >> nome;
    cin.ignore();
    user1.setNome(nome);
    
    //Recebe a idade do usuario
    cout << "Digite a sua idade: ";
    cin >> idade;
    cin.ignore();
    
    //Verifica se a idade é valida
    if(idade < 18 || idade >= 120) {
        char res;
        //Confirma a idade
        cout << "Essa é sua idade real? [S/N] ";
        cin >> res;
        cin.ignore();
        
        //Caso a idade seja invalida o programa termina e se nao for reescreve a idade
        if(res == 'S' || res == 's') {
            //Encerra o programa o programa com exit(0)
            cout << "Idade invalida!" << endl << endl;
            
            cout << "Encerrando programa...";
            exit(0);
        } else {
            //Reescreve a idade real
            cout << "Reescreva sua idade real: ";
            cin >> idade;
            cin.ignore();
        }
    }
    //Recebe a idade do usuario usando setIdade
    user1.setIdade(idade);
    
    //Confirma se o genero é valido e repete enquanto for invalido
    do {
        cout << "Digite seu genero biologico [M/F]: ";
        cin >> sexo;
        cin.ignore();
        
        //Faz a verificacao de genero
        if(sexo == 'M' || sexo == 'F') {
            valido=true;
        } else {
            //Informa queo genero esta incorreto
            cout << "Genero invalido! Tente novamente. ";
            valido=false;
        }
    } while(!valido);
    
    //Recebe o genero usando a funcao setSexo
    user1.setSexo(sexo);
    
    //Recebe a senha do usuario
    cout << "Crie a sua senha: ";
    cin >> senha;
    cin.ignore();
    user1.setSenha(senha);
    
    //Recebe o saldo da conta simulada do usuario
    cout << "Digite seu saldo R$";
    cin >> saldo;
    cin.ignore();
    user1.setSaldo(saldo);
}

//Funcao que faz o login
void fazerLogin(string nome,  string senha, bool valido, int erro, char sexo, int idade, char res) {
    
    cout << "Confirme alguns dados para entrar em sua conta." << endl << endl;
    
    //Confirma se o nome é valido e chama a funcao para resetar o nome
    while(erro < 5 || !valido) {
        cout << "Digite seu nome de usuário: ";
        cin >> nome;
        cin.ignore();
        //Se o nome de usuario for correto continua e se nao for aumenta o numero de erros
        if(nome == user1.getNome()) {
            valido=true;
            OSteste(sistema);
            break;
        } else {
            valido=false;
            cout << "Ops! Nome de usuário não encontrado. Tente novamente." << endl << endl;
            erro++;
        }
        
        //Quando os erros chegam a cinco o programa pergunta se esqueceu dos dados
        if(erro == 5) {
            cout << "Esqueceu o nome de usuário? [S/N]";
            cin >> res;
            if(res == 'S' || res == 's') {
                recuperarUsuario(res, idade, sexo, nome);
            } else {
                //Reseta o sistema de repeticao para recolocar os dados
                OSteste(sistema);
                valido=false;
                erro=0;
            }
        }
        //Limpa a tela
        OSteste(sistema);
    }
    
    
    erro=0;
    
    //Confirma se a senha é valida e chama a funcao para resetar a senha
    while(erro < 5) {
        cout << "Digite sua senha de usuário: ";
        cin >> senha;
        cin.ignore();
        
        //Se a senha for correta continua e se nao for aumenta o numero de erros
        if(senha == user1.getSenha()) {
            valido=true;
            OSteste(sistema);
            break;
        } else {
            valido=false;
            cout << "Ops! Senha de usuário não encontrada. Tente novamente." << endl << endl;
            erro++;
        }
        
        //Quando os erros chegam a cinco o programa pergunta se esqueceu dos dados
        if(erro == 5) {
            cout << "Esqueceu a senha de usuário? [S/N]";
            cin >> res;
            if(res == 'S' || res == 's') {
                recuperarSenha(res, idade, sexo, senha);
            } else {
                //reseta o sistema de repetição para recolocar os dados
                OSteste(sistema);
                valido=false;
                erro=0;
            }
        }
        //Limpa a tela
        OSteste(sistema);
    }
}    

//Funcao que recupera o nome de usuario
void recuperarUsuario(char res, int idade, char sexo, string nome) {
    
    cout << "Digite sua idade para confirmar dados: ";
    cin >> idade;
        
    cout << "Digite seu gênero para confirmar dados:";
    cin >> sexo;
    
    //Limpa a tela
    OSteste(sistema);
    
    //Verifica os dados para resetar
    if(idade == user1.getIdade() && sexo == user1.getSexo()) {
        cout << "Usuário: " << user1.getNome() << endl;
        
        cout << "Deseja mudar o nome? [S/N]";
        cin >> res;
        
        //Se a resposta for s, o usuario reescreve o nome
        if(res == 'S' || res == 's') {
            cout << "Digite seu novo nome: ";
            cin >> nome;
            user1.setNome(nome);
        }
        
        //Limpa a tela
        OSteste(sistema);
            
    } else {
        //Encerra o programa por falta de informaçoes
        OSteste(sistema);
        cout << "Não foi possivel indetifica-lo." << endl;
        cout << "Encerrando...";
        exit(0);
    }
}

//Funcao que recupera a senha do usuario
void recuperarSenha(char res, int idade, char sexo,  string senha) {
    
    cout << "Digite sua idade para confirmar dados: ";
    cin >> idade;
        
    cout << "Digite seu gênero para confirmar dados:";
    cin >> sexo;
    
    //Limpa a tela
    OSteste(sistema);
    
    //Verifica os dados para resetar
    if(idade == user1.getIdade() && sexo == user1.getSexo()) {
        cout << "Senha: " << user1.getSenha() << endl;
        cout << "Deseja mudar a senha? [S/N]";
        cin >> res;
        
        //Se a resposta for s, o usuario reescreve a senha
        if(res == 'S' || res == 's') {
            cout << "Digite sua nova senha: ";
            cin >> senha;
            user1.setSenha(senha);
        }
        //Limpa a tela
        OSteste(sistema);
        
    } else {
        //Encerra o programa por falta de dados
        OSteste(sistema);
        cout << "Não foi possivel indetifica-lo." << endl;
        cout << "Encerrando...";
        exit(0);
    }
    
}

//Mostra os dados do usuario usando o metodo get
void mostrarDados() {
    cout << "Nome: " << user1.getNome() << endl;
    cout << "Senha: " << user1.getSenha() << endl;
    cout << "Saldo R$" << user1.getSaldo() << endl << endl;
}

//Mostra o menu de escolha
void exibirMenu(int escolha, string nome, double valor, char res, int idade, char sexo, string senha) {
    cout << "Escolha uma opção: " << endl << endl;
    
    cout << "[1] Fazer transferência. " << endl;
    cout << "[2] Mudar o nome. " << endl;
    cout << "[3] Mudar a senha. " << endl;
    cout << "[4] Sair. " << endl;
    cin >> escolha;
    
    //Executa as funcoes dependendo da escolha
    switch(escolha) {
        case 1:
            fazerTransferencia(nome, valor, res);
            break;
        case 2:
            recuperarUsuario(res, idade, sexo, nome);
            break;
        case 3:
            recuperarSenha(res, idade, sexo, senha);
            break;
        case 4:
            OSteste(sistema);
            exit(0);
            break;
        default:
            cout << "Opção invalida! Tente novamente!" << endl;
    }
}

//Funcao que faz a transferencia para outras pessoas
void fazerTransferencia(string nome, double valor, char res) {
    res='s';
    while(res == 'S' || res == 's') {
        cout << "Para fazer sua transferência, informe os dados do destinatario: " << endl << endl;
        //Escolhe para quem mandar o valor
        cout << "Escreva o nome do destinatario: ";
        cin >> nome;
        
        //Escolhe o valor
        cout << "Digite valor: ";
        cin >> valor;
        
        //confirma se o saldo é suficiente
        if(valor > user1.getSaldo()) {
            cout << "Saldo insuficiente!" << endl;
            cout << "Deseja fazer outra transferência? [S/N]";
            cin >> res;
        } else {
            cout << "R$" << valor << " foi transferido com sucesso para o destinatario " << nome << endl;
            //Subtrai o valor mandado do saldo do usuario
            user1.setSaldo(user1.getSaldo() - valor);
            cout << "Deseja fazer outratransferência? [S/N]";
            cin >> res;
            
        }
    }
}