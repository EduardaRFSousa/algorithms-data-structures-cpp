#ifndef PRATICA_06_HASHTABLE_H
#define PRATICA_06_HASHTABLE_H

#include <stdexcept>

/* Funcao de espalhamento abstrata */
template <class T>
long hash_function(T v);

/* Tabela de Espalhamento abstrata. */
template<class T_key, class T_value>
class hashtable {
protected:
    int capacity = 0;
    int size = 0;

    // Pega a chave e retorna o indice
    // Chama hash_function() e ajusta para o tamanho da tabela
    long get_idx(T_key key) {
        long hash = hash_function(key);
        // Não aceita hashs negativos!
        if (hash < 0) throw std::runtime_error("Erro no calculo do hash! [Negativo]");
        return hash % capacity;
    }

public:
    explicit hashtable(int cap) : capacity(cap) {
        if (cap <= 0)
            throw std::runtime_error("Capacidade invalida");
    }
    
    // Destrutor da classe
    ~hashtable() = default;

    virtual void insert(T_key key, T_value value) = 0;

    virtual void remove(T_key key) = 0;

    virtual T_value search(T_key key) = 0;

    virtual void show() = 0;

};

#endif
