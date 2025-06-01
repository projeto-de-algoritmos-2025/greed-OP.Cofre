#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>
#include <string>

struct Item {
    std::string nome;
    double peso;
    double valor;
};

struct ResultadoKnapsack {
    std::vector<std::pair<Item, double>> itensSelecionados; // item + fração
    double valorTotal;
};

ResultadoKnapsack executarKnapsack();

#endif
