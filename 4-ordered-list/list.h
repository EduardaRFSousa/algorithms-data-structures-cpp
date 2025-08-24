#ifndef FILAS_LISTA_H //Se não estiver definido...
#define FILAS_LISTA_H //...então defina FILAS_LISTA_H agora
/* O fim da condição está no final do código, isso faz
com que o cabeçalho seja anexado ao arquivo apenas uma 
única vez, impedindo erros por duplicação */

#include <vector>
using namespace std;

template <class T>
/*TEMPLATE: Permite que funções sejam declaradas sem variável
definida, trazendo flexibilidade ao código e fazendo com que a 
lista seja capaz de armazenar qualquer tipo (int, string, char, 
etc...), sendo necessário apenas declarar na criação da Lista:
Lista<tipo> lista; */

class Lista {
protected:
    int capacidade;
    int num_itens = 0;
    vector<T> itens;

    /*Uso de &: Faz com que a função retorne uma referência, 
    permitindo acesso ao dado original ao invés de uma cópia */
    T& pega_ref(int idx) {
        if (idx <= 0 || idx > tamanho()) throw runtime_error("Indice invalido");
        return itens[idx - 1];
    }

public:
    explicit Lista(int capacidade)  : itens(capacidade), capacidade(capacidade), num_itens(0) {
        if (capacidade <= 0) throw runtime_error("Capacidade invalida");
        //Já atribui valores(parâmetro passado de capacidade e '0') na declaração do Construtor, ao invés do escopo
    }
    
    //virtual permite que essas funções sejam sobrescritas na herança
    virtual void adicionar(T v) {
        if (num_itens >= capacidade) throw runtime_error("Fila cheia!");
        itens[num_itens] = v;
        num_itens++;
    }

    virtual void inserir(int idx, T v) {
        if (num_itens >= capacidade) throw runtime_error("Fila cheia!");
        pega_ref(idx);
        
        for (int i = num_itens - 1; i >= idx - 1; i--) {
            itens[i + 1] = itens[i];
        }

        itens[idx - 1] = v;
        num_itens++;
    }

    void remover(int idx) {
        pega_ref(idx);
        
        for(int i = idx - 1; i < num_itens - 1; i++){
            itens[i] = itens[i + 1];
        }
        
        itens[num_itens - 1] = T(); //Limpa o último indíce pra não ficar com valor duplicado
        num_itens--;
    }

    //const indica que essa função não vai modificar nenhum atributo da classe
    int tamanho() const {
        return num_itens;
    }

    T pega(int idx) {
        return pega_ref(idx);
    }
    
    /* Sobrecarga do operador []: Aqui o propósito é possibilitar a uma chamada
    da lista como se ela fosse um vetor (ex.: tarefas[1]), dando uma função 
    específica ao uso dos colchetes no código */
    T& operator [] (int idx) {
        return pega_ref(idx);
    }

    virtual int buscar(T valor) {
        for (int i = 0; i < num_itens; i++) {
            if (itens[i] == valor) {
                return i + 1;
            }
        }
        return -1;
    }
};

template <class T>
class ListaOrdenada : public Lista<T> {
//Classe nova que herda de Lista e sobrescreve os métodos necessários
private:
    int buscaBinaria(int inicio, int final, const T& v) const {
        if (inicio > final) return -1;
        int meio = (inicio + final) / 2;
        
        if(this->itens[meio] == v){
            return meio + 1;
        } else if (this->itens[meio] > v){
            return buscaBinaria (inicio, meio - 1, v);
        } else {
            return buscaBinaria (meio + 1, final, v);
        }
    }

public:
    //construtor que chama o construtor da classe-pai (cap passa como parâmetro para capacidade)
    explicit ListaOrdenada(int cap) : Lista<T>(cap) {  }

    void inserir(int idx, T v) override {
        throw runtime_error("Operacao nao suportada!");
    }

    /*this aqui não é obrigatório (já que ListaOrdenada não faz sobrecarga dos nomes dos atributos), 
    apenas é conveniente pra entender que são atributos herdados e não próprios da classe-filha */
    void adicionar(T v) override {
        int i = 0;
        for (i = this->num_itens - 1; i >= 0 && this->itens[i] > v; i--) {
            this->itens[i + 1] = this->itens[i];
        }
        this->itens[i + 1] = v;
        this->num_itens++;
    }

    int buscar (T v) override {
        return buscaBinaria(0, this->num_itens - 1, v);
    }
};

#endif //FILAS_LISTA_H