/*
 * ==========================================================
 *  BANCO ENLACE - Versao para ate 5 contas (Desafio 3.5)
 *  INF101 - Programacao de Computadores I - UNIVICOSA
 *  Trabalho - Etapa 1
 *  Aluno: Raphael de Souza Azevedo
 * ==========================================================
 *  PERGUNTA: "Se quisessemos cadastrar ate 5 contas, qual
 *  solucao seria possivel?"
 *
 *  RESPOSTA: usando apenas variaveis individuais (conteudo da
 *  Etapa 1), a unica solucao e criar 5 conjuntos de variaveis:
 *  numeroConta1, numeroConta2, ..., numeroConta5, e assim por
 *  diante para cada campo. Para nao repetir todas as operacoes
 *  5 vezes, o programa:
 *    1) localiza a conta pelo numero (cadeia de if/else);
 *    2) COPIA os dados dela para variaveis de trabalho;
 *    3) executa a operacao nas variaveis de trabalho;
 *    4) COPIA os dados de volta para a conta original.
 *
 *  Funciona, mas o codigo fica longo e repetitivo. Para 100
 *  contas seria inviavel. Essa limitacao e justamente a
 *  motivacao para usar ARRAYS (vetores) e FUNCOES na Etapa 2.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    // ---------- 5 conjuntos de variaveis (um por conta) ----------
    int numeroConta1 = 0, numeroConta2 = 0, numeroConta3 = 0, numeroConta4 = 0, numeroConta5 = 0;
    string nomeCliente1, nomeCliente2, nomeCliente3, nomeCliente4, nomeCliente5;
    string cpf1, cpf2, cpf3, cpf4, cpf5;
    string telefone1, telefone2, telefone3, telefone4, telefone5;
    int tipoConta1 = 0, tipoConta2 = 0, tipoConta3 = 0, tipoConta4 = 0, tipoConta5 = 0;
    double saldo1 = 0, saldo2 = 0, saldo3 = 0, saldo4 = 0, saldo5 = 0;
    bool contaAtiva1 = false, contaAtiva2 = false, contaAtiva3 = false, contaAtiva4 = false, contaAtiva5 = false;
    bool cadastrada1 = false, cadastrada2 = false, cadastrada3 = false, cadastrada4 = false, cadastrada5 = false;

    // ---------- Variaveis de trabalho (conta "selecionada") ----------
    int numeroConta = 0;
    string nomeCliente, cpf, telefone;
    int tipoConta = 0;
    double saldo = 0;
    bool contaAtiva = false;

    int posicao;          // Qual das 5 contas esta selecionada (1 a 5; 0 = nenhuma)
    bool alterou;         // Indica se os dados precisam ser gravados de volta
    int opcao;

    cout << fixed << setprecision(2);

    do {
        cout << "\n********************************\n";
        cout << "**   BANCO ENLACE (5 contas)  **\n";
        cout << "********************************\n";
        cout << "1 - Cadastrar conta\n";
        cout << "2 - Consultar conta\n";
        cout << "3 - Verificar saldo\n";
        cout << "4 - Alterar tipo da conta\n";
        cout << "5 - Ativar/Desativar conta\n";
        cout << "6 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcao = 0;
        }

        posicao = 0;
        alterou = false;

        // ---------- Para as opcoes 2 a 5: localizar a conta pelo numero ----------
        if (opcao >= 2 && opcao <= 5) {
            int numeroBusca;
            cout << "Informe o numero da conta: ";
            cin >> numeroBusca;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                numeroBusca = -1;
            }

            if      (cadastrada1 && numeroConta1 == numeroBusca) posicao = 1;
            else if (cadastrada2 && numeroConta2 == numeroBusca) posicao = 2;
            else if (cadastrada3 && numeroConta3 == numeroBusca) posicao = 3;
            else if (cadastrada4 && numeroConta4 == numeroBusca) posicao = 4;
            else if (cadastrada5 && numeroConta5 == numeroBusca) posicao = 5;

            if (posicao == 0) {
                cout << "Conta nao encontrada.\n";
                continue;   // volta para o menu (a condicao do do-while e testada)
            }

            // Copia os dados da conta encontrada para as variaveis de trabalho
            switch (posicao) {
            case 1: numeroConta = numeroConta1; nomeCliente = nomeCliente1; cpf = cpf1; telefone = telefone1;
                    tipoConta = tipoConta1; saldo = saldo1; contaAtiva = contaAtiva1; break;
            case 2: numeroConta = numeroConta2; nomeCliente = nomeCliente2; cpf = cpf2; telefone = telefone2;
                    tipoConta = tipoConta2; saldo = saldo2; contaAtiva = contaAtiva2; break;
            case 3: numeroConta = numeroConta3; nomeCliente = nomeCliente3; cpf = cpf3; telefone = telefone3;
                    tipoConta = tipoConta3; saldo = saldo3; contaAtiva = contaAtiva3; break;
            case 4: numeroConta = numeroConta4; nomeCliente = nomeCliente4; cpf = cpf4; telefone = telefone4;
                    tipoConta = tipoConta4; saldo = saldo4; contaAtiva = contaAtiva4; break;
            case 5: numeroConta = numeroConta5; nomeCliente = nomeCliente5; cpf = cpf5; telefone = telefone5;
                    tipoConta = tipoConta5; saldo = saldo5; contaAtiva = contaAtiva5; break;
            }
        }

        switch (opcao) {

        case 1: // CADASTRAR CONTA (na primeira posicao livre)
            if      (!cadastrada1) posicao = 1;
            else if (!cadastrada2) posicao = 2;
            else if (!cadastrada3) posicao = 3;
            else if (!cadastrada4) posicao = 4;
            else if (!cadastrada5) posicao = 5;

            if (posicao == 0) {
                cout << "Limite de 5 contas atingido!\n";
                break;
            }

            // Numero > 0 e que ainda nao exista
            do {
                cout << "Numero da conta: ";
                cin >> numeroConta;
                if (cin.fail() || numeroConta <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Erro: o numero da conta deve ser um inteiro maior que zero.\n";
                    numeroConta = 0;
                } else if ((cadastrada1 && numeroConta1 == numeroConta) ||
                           (cadastrada2 && numeroConta2 == numeroConta) ||
                           (cadastrada3 && numeroConta3 == numeroConta) ||
                           (cadastrada4 && numeroConta4 == numeroConta) ||
                           (cadastrada5 && numeroConta5 == numeroConta)) {
                    cout << "Erro: ja existe uma conta com esse numero.\n";
                    numeroConta = 0;
                }
            } while (numeroConta <= 0);

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            do {
                cout << "Nome do titular: ";
                getline(cin, nomeCliente);
                if (nomeCliente.empty()) cout << "Erro: o nome nao pode ficar em branco.\n";
            } while (nomeCliente.empty());

            do {
                cout << "CPF (somente numeros): ";
                getline(cin, cpf);
                if (cpf.length() != 11) cout << "Erro: o CPF deve ter 11 digitos.\n";
            } while (cpf.length() != 11);

            cout << "Telefone: ";
            getline(cin, telefone);

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

            contaAtiva = true;
            alterou = true;
            cout << "\nConta cadastrada com sucesso na posicao " << posicao << " de 5!\n";
            break;

        case 2: // CONSULTAR CONTA
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

        case 3: // VERIFICAR SALDO
            if (!contaAtiva)
                cout << "Operacao negada: a conta esta INATIVA.\n";
            else
                cout << "Saldo da conta " << numeroConta << ": R$ " << saldo << "\n";
            break;

        case 4: // ALTERAR TIPO
            if (!contaAtiva) {
                cout << "Operacao negada: a conta esta INATIVA.\n";
            } else {
                int novoTipo;
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
                alterou = true;
                cout << "Tipo da conta alterado com sucesso!\n";
            }
            break;

        case 5: // ATIVAR / DESATIVAR
            contaAtiva = !contaAtiva;
            alterou = true;
            cout << "A conta agora esta " << (contaAtiva ? "ATIVA" : "INATIVA") << ".\n";
            break;

        case 6:
            cout << "Encerrando o sistema. Ate logo!\n";
            break;

        default:
            cout << "Opcao invalida! Escolha um numero de 1 a 6.\n";
        }

        // ---------- Grava as variaveis de trabalho de volta na conta ----------
        if (alterou) {
            switch (posicao) {
            case 1: numeroConta1 = numeroConta; nomeCliente1 = nomeCliente; cpf1 = cpf; telefone1 = telefone;
                    tipoConta1 = tipoConta; saldo1 = saldo; contaAtiva1 = contaAtiva; cadastrada1 = true; break;
            case 2: numeroConta2 = numeroConta; nomeCliente2 = nomeCliente; cpf2 = cpf; telefone2 = telefone;
                    tipoConta2 = tipoConta; saldo2 = saldo; contaAtiva2 = contaAtiva; cadastrada2 = true; break;
            case 3: numeroConta3 = numeroConta; nomeCliente3 = nomeCliente; cpf3 = cpf; telefone3 = telefone;
                    tipoConta3 = tipoConta; saldo3 = saldo; contaAtiva3 = contaAtiva; cadastrada3 = true; break;
            case 4: numeroConta4 = numeroConta; nomeCliente4 = nomeCliente; cpf4 = cpf; telefone4 = telefone;
                    tipoConta4 = tipoConta; saldo4 = saldo; contaAtiva4 = contaAtiva; cadastrada4 = true; break;
            case 5: numeroConta5 = numeroConta; nomeCliente5 = nomeCliente; cpf5 = cpf; telefone5 = telefone;
                    tipoConta5 = tipoConta; saldo5 = saldo; contaAtiva5 = contaAtiva; cadastrada5 = true; break;
            }
        }

    } while (opcao != 6);

    return 0;
}
