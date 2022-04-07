#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include <iostream>
using namespace std;
template <class T>
class PilhaArray {
private:
// Atributos para array de items, capacidade e topo da pilha
    int cap, tam;
    T * pilha;

public:

    PilhaArray(int capacidade) {
    // instancia array de items, inicializa capacidade e topo
        cap = capacidade;
        pilha = new T[capacidade];
        tam = 0;
    }

    ~PilhaArray() {
    // destroy array de items
        delete[] pilha;
    }

    void empilha(T item) {
    // empilha um item no topo da pilha; lança “Estouro da pilha” se cheia
        if(tamanho() >= cap - 1) throw "Estouro de Pilha";

        pilha[tam] = item;
        tam = tam + 1;
    }

    T desempilha() {
    // remove um item do topo da pilha; lança “Pilha vazia” se vazia
        if(tam == 0) throw "Pilha vazia";

        T tmp = pilha[tam - 1];
        pilha[tam] = 0;
        tam = tam - 1;
        return tmp;
    }

    int tamanho() {
     // retorna o número de elementos na pilha.
        return tam;
    }
};

#endif // PILHA_H_INCLUDED
