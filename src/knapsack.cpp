#include <iostream>
#include <vector>
#include <algorithm>
#include "knapsack.h"

using namespace std;

bool compararValorPorPeso(const Item &a, const Item &b) {
    return (a.valor / a.peso) > (b.valor / b.peso);
}

ResultadoKnapsack executarKnapsack() {
    int n;
    double capacidade;

    cout << "Digite a capacidade do caminhão: ";
    cin >> capacidade;

    cout << "Digite o número de itens: ";
    cin >> n;

    vector<Item> itens(n);

    for (int i = 0; i < n; ++i) {
        cout << "Item " << i + 1 << " - nome, peso e valor: ";
        cin >> itens[i].nome >> itens[i].peso >> itens[i].valor;
    }

    sort(itens.begin(), itens.end(), compararValorPorPeso);

    double pesoAtual = 0.0;
    double valorTotal = 0.0;
    vector<pair<Item, double>> selecionados;

    for (const auto &item : itens) {
        if (pesoAtual + item.peso <= capacidade) {
            pesoAtual += item.peso;
            valorTotal += item.valor;
            selecionados.push_back({item, 1.0});
        } else {
            double restante = capacidade - pesoAtual;
            double fracao = restante / item.peso;
            valorTotal += item.valor * fracao;
            pesoAtual = capacidade;
            selecionados.push_back({item, fracao});
            break;
        }
    }

    cout << "\nItens selecionados:\n";
    for (auto &[item, frac] : selecionados) {
        cout << "- " << item.nome << " (" << frac * 100 << "%)\n";
    }

    cout << "Valor total: " << valorTotal << "\n";

    return ResultadoKnapsack{selecionados, valorTotal};
}
