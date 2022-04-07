#ifndef LISTA_ARRAY_H_INCLUDED
#define LISTA_ARRAY_H_INCLUDED
#include <iostream>
using namespace std;

template <class T>
class Lista {
private:
    // itens da lista, capacidade e tamanho atual
    int cap, tam, pos_inicial, pos_final;
    T * lista;

public:

    Lista(int capacidade) {
    // inicilização do array, capacidade e tamanho
    cap = capacidade + 1; //capacidade + 1 para que os itens comecem na posicao 1
    lista = new T[cap];
    tam = 0;
    pos_inicial = 1;
    pos_final = 1;
    }

    ~Lista() {
    //destruição do array
    }

    void adiciona (const T & item) {
    // adiciona um item ao final da lista; lança “Lista cheia” caso cheia
        if(tamanho() == cap - 1) throw "Lista cheia";

        lista[pos_final] = item;
        pos_final = pos_final + 1;
        tam = tam + 1;

    }

    T pega(int idx) {
    // pega um item pelo indice (começa em 1);
    // lança “Item inválido” se posição inválida
        if(idx > tamanho() || idx <= 0){
            throw "Item invalido";
        } else {
            /*cout << "lista[" << idx << "]: " << lista[idx] << endl;
            cout << "lista[4]: " << lista[4] << endl;*/
            return lista[idx];
        }
    }

    void insere (int idx, const T & item) {
    // insere um item na posição indicada (a partir de 1).
    // lança “Lista cheia” caso cheia
    // lança “Item inválido” se posição inválida
    // desloca itens existentes para a direita
    }

    void remove(int idx) {
    // remove item de uma posição indicada
    // lança “Item inválido” se posição inválida
    // desloca itens para a esquerda sobre o item removido
        int j = 1;
        if(idx > tamanho() || idx <= 0){
            throw "Item invalido";
        } else {
            if(idx == cap){
                lista[idx] = NULL;
                pos_final = pos_final - 1;
                tam = tam - 1;
            } else {
                lista[idx] = lista[idx + 1];/*
                for(int i = 1; i == idx; i++){
                    T temp = lista[idx + i];
                    lista[idx] = temp;
                    lista[idx + i] = NULL;
                }*/
                for(int i = idx; i == idx; i++){
                    j = j + 1;
                    lista[idx + j - 1] = lista[idx + j + 1];
                    pos_final = pos_final - 1;
                    tam = tam - 1;
                cout << "Trocar lista[" << idx + j - 1 << "]: " << lista[idx + j - 1] << " por lista[" << idx + j + 1 << "]: " << lista[idx + j + 1] << endl;
                }/*
                lista[idx] = lista[idx + 1];
                lista[idx + 1] = 0;
                for(int i = 1; lista[idx + i] == NULL; i++){
                    lista[idx + i - 1] = lista[idx + i];
                    pos_final = pos_final - 1;
                    tam = tam - 1;
                }*/
            }
        }
    }

    void exibe() {
    // exibe os itens da saida padrão separados por espaços
    }

    int tamanho() {
    // retorna a quantidade de itens atualmente na lista
        return tam;
    }

};


#endif // LISTA_ARRAY_H_INCLUDED
