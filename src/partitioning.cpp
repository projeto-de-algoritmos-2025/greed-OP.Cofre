#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "partitioning.h"

using namespace std;

struct Intervalo {
    int inicio;
    int fim;
};

bool compararPorInicio(const Intervalo &a, const Intervalo &b) {
    return a.inicio < b.inicio;
}

void executarPartitioning() {
    int n;
    cout << "Digite o número de caminhões (intervalos de saída): ";
    cin >> n;

    vector<Intervalo> intervalos(n);
    for (int i = 0; i < n; ++i) {
        cout << "Caminhão " << i + 1 << " - início e fim: ";
        cin >> intervalos[i].inicio >> intervalos[i].fim;
    }

    sort(intervalos.begin(), intervalos.end(), compararPorInicio);

    using Pista = pair<int, int>;
    priority_queue<Pista, vector<Pista>, greater<Pista>> fimPistas;

    vector<int> pistaDoIntervalo(n);

    int pistasUsadas = 0;

    for (int i = 0; i < n; ++i) {
        if (!fimPistas.empty() && fimPistas.top().first <= intervalos[i].inicio) {
            int pistaLivre = fimPistas.top().second;
            fimPistas.pop();

            fimPistas.push({intervalos[i].fim, pistaLivre});
            pistaDoIntervalo[i] = pistaLivre;
        } else {
            pistasUsadas++;
            fimPistas.push({intervalos[i].fim, pistasUsadas});
            pistaDoIntervalo[i] = pistasUsadas;
        }
    }

    cout << "\nNúmero mínimo de pistas necessárias: " << pistasUsadas << "\n";

    cout << "Atribuição dos caminhões às pistas:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Caminhão " << i + 1 << ": Pista " << pistaDoIntervalo[i] << "\n";
    }
}
