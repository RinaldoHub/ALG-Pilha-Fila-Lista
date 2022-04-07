#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <iostream>
using namespace std;

template <class T>
class Fila {
private:
    // array de itens, capacidade, tamanho, posição inicial, etc.
    int capacidade, tam, pos_inicial;
    T * fila;

public:
    Fila(int cap) {
    // inicializar array de items, capacidade, tamanho, posição inicial
        capacidade = cap;
        fila = new T[cap];
        tam = 0;
        pos_inicial = 0;
    }

    ~Fila() {
    // destruir array de itens
    }

    void enfileira(const T & item) {
    // adiciona um item ao final da fila; lança “Fila cheia” caso cheia
        if(tamanho() == capacidade) throw "Fila cheia";

        if(tam == 0){
            fila[pos_inicial] = item;
            tam = tam + 1;
        } else {
            fila[tam] = item;
            tam = tam + 1;
        }
    }

    T desenfileira() {
    // remove um item do inicio da fila; lança “Fila vazia” caso vazia
        if(tamanho() > 0){
            T temp = fila[pos_inicial];
            pos_inicial = pos_inicial + 1;
            tam = tam - 1;
            return temp;
        } else {
            pos_inicial = 0;
            throw "Fila vazia";
        }
    }
	
    int cheia() {
    // retorna 1 se cheia, 0 caso contrário
		if (tamanho() == capacidade){
			return 1;
		} else {
			return 0;
		}
    }

    int vazia() {
    // retorna 1 se vazia, 0 caso contrário
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


#endif // FILA_H_INCLUDED
