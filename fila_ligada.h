#ifndef FILA_LIGADA_H_INCLUDED
#define FILA_LIGADA_H_INCLUDED
#include <iostream>
using namespace std;

template <class T>
class Fila {

typedef struct Node {
    int dado;
    Node * prox;
};

private:
    // array de itens, capacidade, tamanho, posição inicial, etc.
    int capacidade, tam;
    Node * pos_inicial;
    Node * pos_final;
    T * fila;

public:
    Fila(int cap) {
    // inicializar array de items, capacidade, tamanho, posição inicial
        capacidade = cap;
        tam = 0;
        pos_inicial = NULL;
        pos_final = NULL;
    }

    ~Fila() {
    // destruir array de itens
        delete[] fila; // desenfileira até Fila ficar vazia
    }

    void enfileira(const T & item) {
    // adiciona um item ao final da fila; lança “Fila cheia” caso cheia
        if(tamanho() == capacidade) throw "Fila cheia";

        Node * n = new Node();
        n->dado = item;
        n->prox = NULL;

        if(pos_inicial == NULL){
            pos_inicial = n;
        } else {
            pos_final->prox = n;
        }
        tam = tam + 1;
        pos_final = n;
    }

    T desenfileira() {
    // remove um item do inicio da fila; lança “Fila vazia” caso vazia
        if (pos_inicial == NULL) throw "Fila vazia";

        Node * tmp = pos_inicial;
        pos_inicial = pos_inicial->prox; //fazer tmp = pos_inicial
        if(pos_inicial == NULL){
            pos_final = NULL;
        }
        tam = tam - 1;
        T tempDados = tmp->dado;
        delete tmp;
        return tempDados;
    }

    int cheia() {
    // retorna 1 se cheia, 0 caso contrário
    //Usar BOOL
		if (tamanho() == capacidade){
			return 1;
		} else {
			return 0;
		}
    }

    int vazia() {
    // retorna 1 se vazia, 0 caso contrário
    //Usar BOOL
		if (tamanho() == 0){
			return 1;
		} else {
			return 0;
		}
    }

    int tamanho() {
    // retorna a quantidade de itens atualmente na fila
        return tam;
    }

};

#endif // FILA_LIGADA_H_INCLUDED
