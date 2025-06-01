#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include "huffman.h"

using namespace std;

struct No {
    char caractere;
    int frequencia;
    No *esq, *dir;

    No(char c, int f) : caractere(c), frequencia(f), esq(nullptr), dir(nullptr) {}
};

struct Comparador {
    bool operator()(No* a, No* b) {
        return a->frequencia > b->frequencia;
    }
};

void construirCodigo(No* raiz, string codigo, unordered_map<char, string> &mapa) {
    if (!raiz) return;
    if (!raiz->esq && !raiz->dir) {
        mapa[raiz->caractere] = codigo;
    }
    construirCodigo(raiz->esq, codigo + "0", mapa);
    construirCodigo(raiz->dir, codigo + "1", mapa);
}

void executarHuffman(const string &texto) {
    unordered_map<char, int> frequencias;
    for (char c : texto) {
        frequencias[c]++;
    }

    priority_queue<No*, vector<No*>, Comparador> fila;

    for (auto &par : frequencias) {
        fila.push(new No(par.first, par.second));
    }

    while (fila.size() > 1) {
        No* esq = fila.top(); fila.pop();
        No* dir = fila.top(); fila.pop();

        No* novo = new No('\0', esq->frequencia + dir->frequencia);
        novo->esq = esq;
        novo->dir = dir;

        fila.push(novo);
    }

    unordered_map<char, string> codigos;
    construirCodigo(fila.top(), "", codigos);

    cout << "\nCodificação Huffman:\n";
    for (auto &par : codigos) {
        cout << "'" << par.first << "' : " << par.second << "\n";
    }

    cout << "\nTexto codificado: ";
    for (char c : texto) {
        cout << codigos[c];
    }
    cout << "\n";
}
