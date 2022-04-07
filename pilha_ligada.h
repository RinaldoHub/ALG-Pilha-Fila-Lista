#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include <iostream>
using namespace std;

template <class T>
class PilhaLigada{

typedef struct Node {
    int dado;
    Node * prox;
};

private:
// Atributos para array de items, capacidade e topo da pilha
    int cap;
    T * pilha;
    Node * topo;
    int quant;

public:

    PilhaLigada(int capacidade) {
    // instancia array de items, inicializa capacidade e topo
        cap = capacidade;
        topo = NULL;
        quant = 0;
    }

    ~PilhaLigada() {
    // destroy array de items
        delete[] pilha; //desempilha até ficar vazia
    }

    void empilha(T item) {
    // empilha um item no topo da pilha; lança “Estouro da pilha” se cheia
        if(tamanho() >= cap){
            throw "Estouro de Pilha";
        }
        else{
            Node * n = new Node();
            if (topo == NULL){
                n->dado = item;
                topo = n;
                quant = quant + 1;
            } else {
                n->dado = item;
                n->prox = topo;
                topo = n;
                quant = quant + 1;
            }
        }
    }

    T desempilha() {
    // remove um item do topo da pilha; lança “Pilha vazia” se vazia
        if(topo == NULL) throw "Pilha vazia";

        Node * temp;
        temp = topo;
        T tempDado = topo->dado;
        topo = topo->prox;

        delete temp;
        quant = quant - 1;

        return tempDado;
    }

    int tamanho() {
     // retorna o número de elementos na pilha.
        return quant;
    }
};

#endif // PILHA_H_INCLUDED
