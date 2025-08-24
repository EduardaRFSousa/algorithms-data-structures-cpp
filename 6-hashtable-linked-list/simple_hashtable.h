#ifndef PRATICA_06_SIMPLE_HASHTABLE_H
#define PRATICA_06_SIMPLE_HASHTABLE_H

#include <vector>
#include "hashtable.h"
using namespace std;

/* Tabela de Espalhamento simples com vector. */
template<class T_key, class T_value>
class simple_hashtable : public hashtable<T_key, T_value> {
private:
    vector<pair<T_key, T_value>> table;
    // Usados para representar posicoes vazias na tabela
    T_key no_key;
    T_value no_value;

public:
    explicit simple_hashtable(int cap, T_key no_key, T_value no_value)
    : hashtable<T_key, T_value>(cap),
      no_key(no_key), no_value(no_value),
      table(cap, {no_key, no_value})  // inicializa tabela com tamanho cap, e com valores {no_key, no_value}
            {  }

    ~simple_hashtable() = default;

    void insert(T_key key, T_value value) override {
        int idx = this->get_idx(key);
        table[idx].first = key;
        table[idx].second = value;
    }

    void remove(T_key key) override {
        int idx = this->get_idx(key);
        if (table[idx].first == no_key) {
            cout << "Tentativa de remover chave vazia!" << endl;
        } else {
            table[idx].first = no_key;
            table[idx].second = no_value;
        }
    }

    T_value search(T_key key) override {
        int idx = this->get_idx(key);
        if (table[idx].first == no_key) {
            return no_value;
        } else {
            return table[idx].second;
        }
    }

    void show() override {
        int i = 0;
        for (auto &[k, v]: table) {
            cout << i++ << ": (" << k << ": " << v << ") " << endl;
        }
    }

    T_value operator [] (const T_key &key) {
        return search(key);
    }

};

#endif