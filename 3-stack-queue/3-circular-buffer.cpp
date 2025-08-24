//Média dos últimos números de uma fila (Buffer Circular)
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class fila_media {
private:
    vector<int> itens;
    int tam, // tamanho (numero atual de elementos)
        max, // capacidade (numero max. de elementos)
        head, // indice do valor mais antigo
        tail, // indice do próximo índice a ser completado ou subscrito
        soma;
        
public:
    // construtor receba max(capacidade); inicializa max e o vector itens.
    explicit fila_media(int max) : max(max), itens(max) {
        if(max <= 0){
            throw invalid_argument ("Capacidade máxima do vetor igual ou menor que 0!");
        }
        tam = 0,
        head = 0,
        tail = 0;
        soma = 0;
    }
    
    bool cheia() const {
        return tam == max;
    }
    
    bool vazia() const {
        return tam == 0;
    }
    
    void desenfileira() {
        if(vazia()){
            throw underflow_error ("Fila vazia! Não é possível desenfileirar");
        } else {
            soma -= itens[head];
            head = (head + 1) % max;
            tam--;
        }
    } //remove o elemento na frente da fila
    
    void enfileira(int i) {
        itens[tail] = i;
        if (cheia()) {
            head = (head + 1) % max;
        } else {
            tam++;
        }
        soma += i;
        tail = (tail + 1) % max; //No contexto de max=4, tail vai passar por 1, 2, 3, 0... e assim por diante
    } // adiciona i ao final da fila
    
    int proximo() {
        if(vazia()){
            throw underflow_error("Tentativa de acessar proximo() em buffer vazio.");
        } else return itens[head];
    } // retorna elemento na frente da fila
    
    double media() const {
        return soma/tam;
        
    } // retorna atual media dos elementos
    
    int tamanho() {
        return tam;
    }

};

int main() {
    int arr[] = {10, 2, 3, 5, 6, 10, 7, 9, 2, 6, 3, 13, 6};
    fila_media fila(4);
    for (int i : arr) {
        if (fila.cheia()) fila.desenfileira();
        fila.enfileira(i);
        cout << fila.media() << endl;
    }
    
    // Saida: 10 6 5 5 4 6 7 8 7 6 5 6 7
    return 0;
}