#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <iostream>
using namespace std;

template <class T>
class Lista {

typedef struct Node {
    int dado;
    Node * prox;
};

private:
    // itens da lista, capacidade e tamanho atual
    int cap, tam;
    Node * pos_inicial;
    Node * pos_final;
    T * lista;

public:

    Lista(int capacidade) {
    // iniciliza��o do array, capacidade e tamanho
    cap = capacidade;
    lista = new T[cap];
    tam = 0;
    pos_inicial = NULL;
    pos_final = NULL;
    }

    ~Lista() {
    //destrui��o do array
        delete[] lista;
    }

    void adiciona (const T & item) {
    // adiciona um item ao final da lista; lan�a �Lista cheia� caso cheia
        if(tamanho() == cap) throw "Lista cheia";

        Node * n = new Node();
        n->dado = item;
        n->prox = NULL;

        if(tam != 0){
            pos_final->prox = n;
            pos_final = n;
        } else {
            pos_inicial = n;
            pos_final = n;
        }

        tam = tam + 1;
    }

    Node * find(int idx) {
        Node * tmp = pos_inicial;
        idx--;
        while (idx != 0){
            tmp = tmp->prox;
            idx--;
        }
        return tmp;
    }

    T pega(int idx) {
    // pega um item pelo indice (come�a em 1);
    // lan�a �Item inv�lido� se posi��o inv�lida
        if(idx > tamanho() || idx <= 0) throw "Item invalido";

        Node * tmp;

        tmp = find(idx);

        return tmp->dado;
    }

    void insere (int idx, const T & item) {
    // insere um item na posi��o indicada (a partir de 1).
    // lan�a �Lista cheia� caso cheia
    // lan�a �Item inv�lido� se posi��o inv�lida
    // desloca itens existentes para a direita
        if(tamanho() == cap) throw "Lista cheia";

        Node * n = new Node();
        n->dado = item;

        if(idx == 1){
            n->prox = pos_inicial;
            pos_inicial = n;
        } else {
            Node * anterior = find(idx - 1);
            n->prox = anterior->prox;
            anterior->prox = n;
        }
        tam = tam + 1;
    }

    T remove(int idx) {
    // remove item de uma posi��o indicada
    // lan�a �Item inv�lido� se posi��o inv�lida
    // desloca itens para a esquerda sobre o item removido
        if(idx > tamanho() || idx <= 0) throw "Item invalido";

        Node * tmp;

        if(idx == 1){
            tmp = pos_inicial;
            pos_inicial = pos_inicial->prox;
            if(pos_final == tmp)
                pos_final = NULL;
        } else {
            Node * anterior = find(idx - 1);
            tmp = anterior->prox;
            anterior->prox = anterior->prox->prox;
            if(pos_final == tmp)
                pos_final = anterior;
        }
        T tmpDados = tmp->dado;
        delete tmp;
        tam = tam - 1;

        return tmpDados;
    }

    void exibe() {
    // exibe os itens da saida padr�o separados por espa�os
        Node * tmp;
        tmp = pos_inicial;
        while(tmp != NULL){
            cout << (T) tmp->dado << endl;
            tmp = tmp->prox;
        }
    }

    int tamanho() {
    // retorna a quantidade de itens atualmente na lista
        return tam;
    }

};



#endif // LISTA_H_INCLUDED
