#include <iostream>
#include <sstream>
#include "knapsack.h"
#include "partitioning.h"
#include "huffman.h"

using namespace std;

void mostrarMenu() {
    cout << "\n=== Operação Cofre: Logística da Fortuna ===\n";
    cout << "1. Otimizar carga com Knapsack Fracionário\n";
    cout << "2. Organizar saída dos caminhões com Interval Partitioning\n";
    cout << "3. Comprimir itens escolhidos com Huffman\n";
    cout << "0. Sair\n";
    cout << "Escolha uma opção: ";
}

// Resultado global armazenado para uso posterior
ResultadoKnapsack resultadoGlobal;

int main() {
    int opcao;

    do {
        mostrarMenu();
        cin >> opcao;

        switch (opcao) {
            case 1:
                resultadoGlobal = executarKnapsack();
                break;

            case 2:
                executarPartitioning();
                break;

            case 3: {
                if (resultadoGlobal.itensSelecionados.empty()) {
                    cout << "Você precisa executar o Knapsack primeiro!\n";
                    break;
                }

                stringstream ss;
                for (size_t i = 0; i < resultadoGlobal.itensSelecionados.size(); ++i) {
                    ss << resultadoGlobal.itensSelecionados[i].first.nome;
                    if (i != resultadoGlobal.itensSelecionados.size() - 1) {
                        ss << ",";
                    }
                }

                string texto = ss.str();
                cout << "\nTexto a ser comprimido: " << texto << "\n";
                executarHuffman(texto);
                break;
            }

            case 0:
                cout << "Encerrando a operação. Até mais!\n";
                break;

            default:
                cout << "Opção inválida. Tente novamente.\n";
        }

    } while (opcao != 0);

    return 0;
}
