/*
 * ==========================================================
 *  BANCO ENLACE - Sistema de Registro e Gestao de Contas
 *  INF101 - Programacao de Computadores I - UNIVICOSA
 *  Trabalho - Etapa 1 (somente variaveis individuais)
 *  Aluno: Raphael de Souza Azevedo
 * ==========================================================
 *  Este programa cadastra e gerencia UMA conta bancaria,
 *  usando apenas variaveis simples, switch e do-while.
 */

#include <iostream>
#include <string>
#include <iomanip>   // setprecision / fixed (formatar o saldo)
#include <limits>    // numeric_limits (limpar o buffer de entrada)

using namespace std;

int main() {
    // ---------- Variaveis obrigatorias ----------
    int numeroConta = 0;        // Numero da conta
    string nomeCliente = "";    // Nome do titular
    string cpf = "";            // CPF do titular
    int tipoConta = 0;          // 1 = Corrente; 2 = Poupanca
    double saldo = 0.0;         // Saldo atual
    bool contaAtiva = false;    // Indica se a conta esta ativa

    // ---------- Variaveis extras (desafio 3.5) ----------
    string telefone = "";           // Telefone de contato do titular
    bool contaCadastrada = false;   // Controla se ja existe uma conta cadastrada

    int opcao;   // Opcao escolhida no menu

    cout << fixed << setprecision(2);   // Saldo sempre com 2 casas decimais

    do {
        // ---------- Menu principal ----------
        cout << "\n********************************\n";
        cout << "**        BANCO ENLACE        **\n";
        cout << "********************************\n";
        cout << "1 - Cadastrar conta\n";
        cout << "2 - Consultar conta\n";
        cout << "3 - Verificar saldo\n";
        cout << "4 - Alterar tipo da conta\n";
        cout << "5 - Ativar/Desativar conta\n";
        cout << "6 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        // Se o usuario digitar letras, o cin entra em estado de erro.
        // Limpamos o erro e descartamos o que foi digitado.
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcao = 0;   // forca cair no "default" do switch
        }

        switch (opcao) {

        // ======================================================
        case 1: // CADASTRAR CONTA
        // ======================================================
            if (contaCadastrada) {
                char resp;
                cout << "Ja existe uma conta cadastrada. Deseja substitui-la? (s/n): ";
                cin >> resp;
                if (resp != 's' && resp != 'S') {
                    cout << "Cadastro cancelado.\n";
                    break;
                }
            }

            // Validacao: numero da conta deve ser maior que zero
            do {
                cout << "Numero da conta: ";
                cin >> numeroConta;
                if (cin.fail() || numeroConta <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Erro: o numero da conta deve ser um inteiro maior que zero.\n";
                    numeroConta = 0;
                }
            } while (numeroConta <= 0);

            // Descarta o "Enter" que ficou no buffer antes de usar getline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Nome pode ter espacos, por isso usamos getline
            do {
                cout << "Nome do titular: ";
                getline(cin, nomeCliente);
                if (nomeCliente.empty())
                    cout << "Erro: o nome nao pode ficar em branco.\n";
            } while (nomeCliente.empty());

            do {
                cout << "CPF (somente numeros): ";
                getline(cin, cpf);
                if (cpf.length() != 11)
                    cout << "Erro: o CPF deve ter 11 digitos.\n";
            } while (cpf.length() != 11);

            cout << "Telefone: ";
            getline(cin, telefone);

            // Validacao: tipo da conta deve ser 1 ou 2
            do {
                cout << "Tipo da conta (1 = Corrente, 2 = Poupanca): ";
                cin >> tipoConta;
                if (cin.fail() || (tipoConta != 1 && tipoConta != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Erro: tipo de conta invalido. Digite 1 ou 2.\n";
                    tipoConta = 0;
                }
            } while (tipoConta != 1 && tipoConta != 2);

            // Validacao: saldo inicial nao pode ser negativo
            do {
                cout << "Saldo inicial: R$ ";
                cin >> saldo;
                if (cin.fail() || saldo < 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Erro: o saldo inicial nao pode ser negativo.\n";
                    saldo = -1;
                }
            } while (saldo < 0);

            contaAtiva = true;        // Toda conta nova comeca ativa
            contaCadastrada = true;
            cout << "\nConta cadastrada com sucesso!\n";
            break;

        // ======================================================
        case 2: // CONSULTAR CONTA
        // ======================================================
            if (!contaCadastrada) {
                cout << "Nenhuma conta cadastrada. Use a opcao 1 primeiro.\n";
                break;
            }
            cout << "\n------ DADOS DA CONTA ------\n";
            cout << "Numero:   " << numeroConta << "\n";
            cout << "Titular:  " << nomeCliente << "\n";
            cout << "CPF:      " << cpf << "\n";
            cout << "Telefone: " << telefone << "\n";
            cout << "Tipo:     " << (tipoConta == 1 ? "Corrente" : "Poupanca") << "\n";
            cout << "Saldo:    R$ " << saldo << "\n";
            cout << "Situacao: " << (contaAtiva ? "Ativa" : "Inativa") << "\n";
            cout << "----------------------------\n";
            break;

        // ======================================================
        case 3: // VERIFICAR SALDO (depende de conta ativa)
        // ======================================================
            if (!contaCadastrada) {
                cout << "Nenhuma conta cadastrada. Use a opcao 1 primeiro.\n";
            } else if (!contaAtiva) {
                cout << "Operacao negada: a conta esta INATIVA.\n";
            } else {
                cout << "Saldo da conta " << numeroConta << ": R$ " << saldo << "\n";
            }
            break;

        // ======================================================
        case 4: // ALTERAR TIPO DA CONTA (depende de conta ativa)
        // ======================================================
            if (!contaCadastrada) {
                cout << "Nenhuma conta cadastrada. Use a opcao 1 primeiro.\n";
            } else if (!contaAtiva) {
                cout << "Operacao negada: a conta esta INATIVA.\n";
            } else {
                int novoTipo;
                cout << "Tipo atual: " << (tipoConta == 1 ? "Corrente" : "Poupanca") << "\n";
                do {
                    cout << "Novo tipo (1 = Corrente, 2 = Poupanca): ";
                    cin >> novoTipo;
                    if (cin.fail() || (novoTipo != 1 && novoTipo != 2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Erro: tipo de conta invalido. Digite 1 ou 2.\n";
                        novoTipo = 0;
                    }
                } while (novoTipo != 1 && novoTipo != 2);
                tipoConta = novoTipo;
                cout << "Tipo da conta alterado com sucesso!\n";
            }
            break;

        // ======================================================
        case 5: // ATIVAR / DESATIVAR CONTA
        // ======================================================
            if (!contaCadastrada) {
                cout << "Nenhuma conta cadastrada. Use a opcao 1 primeiro.\n";
                break;
            }
            contaAtiva = !contaAtiva;   // Inverte a situacao atual
            cout << "A conta agora esta " << (contaAtiva ? "ATIVA" : "INATIVA") << ".\n";
            break;

        // ======================================================
        case 6: // SAIR
        // ======================================================
            cout << "Encerrando o sistema. Ate logo!\n";
            break;

        default:
            cout << "Opcao invalida! Escolha um numero de 1 a 6.\n";
        }

    } while (opcao != 6);   // Menu continua ate escolher Sair

    return 0;
}
