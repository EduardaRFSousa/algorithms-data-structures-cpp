#include <iostream>
#include "list.h"

using namespace std;

//struct é o tipo escolhido para completar a lista orenada de tarefas
struct tarefa {
    string nome;
    bool feita = false;

    /* SOBRECARGA DE OPERADORES: Aqui se define uma sobrescrita de 
    comportamentos para quando >, < ou == seja usado no código 
    (operadores de comparação), isso permite que as structs tarefas 
    possam ser comparadas entre si através de seus nomes, e mantendo 
    a lista em ordem ALFABÉTICA (Ver adicionar() no lista.h)*/
    bool operator < (const tarefa &t) const { return this->nome < t.nome; }
    bool operator > (const tarefa &t) const { return this->nome > t.nome; }
    bool operator == (const tarefa &t) const { return this->nome == t.nome; }
};

struct compras {
    string nome;
    int qtd;
    float preco;
    bool comprado = false;
    
    bool operator < (const compras &c) const { return this->nome < c.nome; }
    bool operator > (const compras &c) const { return this->nome > c.nome; } 
    bool operator == (const compras &c) const { return this->nome == c.nome; }
};

void mostrarCompra(const compras& c) {
    cout << c.nome << " - qtd: " << c.qtd << ", R$ " << c.preco;
}

int main() {
    int valores[] = {11, 4, 7, 9, 10, 15, 21, 8};
    cout << "Lista Simples: " << endl;

    Lista<int> lista(10);

    for (auto &v : valores) {
        lista.adicionar(v);
    }

    cout << "\nAntes: "; 
    for(int i = 1; i <= lista.tamanho(); i++){
        cout << "\n" << i << ": " << lista[i] << "; ";
    }
    cout << endl;

    lista[5] = 55;
    lista.inserir(2, 22);
    lista.remover(3);
    lista.adicionar(77);
    lista.remover(4);

    cout << "\nDepois: ";
    for(int i = 1; i <= lista.tamanho(); i++){
        cout << "\n" << i << ": " << lista[i] << "; ";
    }
    cout << endl;

    int b[] = {10, 22, 11, 5, 7};
    cout << "\nBuscas: " << endl;
    for (int v : b) {
        cout << "- Buscando " << v << ": " << lista.buscar(v) << endl;
    }

    cout << "\nLista Simples de Compras: " << endl;
    Lista<compras> listaCompras1(5);
    
    compras arr1[] = {{"Arroz", 2, 19.90}, 
                     {"Feijão", 3, 7.50}, 
                     {"Leite", 4, 4.99}, 
                     {"Macarrão", 5, 3.75}, 
                     {"Sabonete", 6, 2.20}};

    for (auto &v : arr1) {
        listaCompras1.adicionar(v);
    }
    
    cout << "\nAntes: "; 
    for(int i = 1; i <= listaCompras1.tamanho(); i++){
        cout << "\n" << i << ": ";
        mostrarCompra(listaCompras1.pega(i));
        cout << "; ";
    }
    cout << endl;
    
    string buscas[] = {"Leite", "Sabonete"};
    vector<int> remocao;
    
    cout << "\nBuscas: " << endl;
    for(string v : buscas){
        cout << "- Buscando " << v << ": ";
        int idx = listaCompras1.buscar({v, 0, 0});
        cout << idx << endl;
        remocao.push_back(idx);
    }
    
    for (int i = remocao.size() - 1; i >= 0; i--) {
        listaCompras1.remover(remocao[i]);
    }

    listaCompras1[1] = {"Café", 1, 14.80};
    listaCompras1.inserir(2, {"Detergente", 3, 2.50});
    listaCompras1.adicionar({"Papel Higiênico", 2, 12.90});
    
    cout << "\nDepois: ";
    for(int i = 1; i <= listaCompras1.tamanho(); i++){
        cout << "\n" << i << ": ";
        mostrarCompra(listaCompras1.pega(i));
        cout << "; ";
    }
    cout << endl;

//-----------------------------------------------------------------------------------------------------------

    cout << "\nLista Ordenada: " << endl;

    ListaOrdenada<int> listaOrd(10);

    for (auto &v : valores) {
        listaOrd.adicionar(v);
    }

    for (int i = 1; i <= listaOrd.tamanho(); i++) {
        cout << "\n" << i << ": " << listaOrd.pega(i) << "; ";
    }
    cout << endl;

    cout << "\nBuscas: " << endl;
    for (int v : b) {
        cout << "- Buscando " << v << ": " << listaOrd.buscar(v) << endl;
    }

    cout << endl << "Lista Ordenada de Tarefas: " << endl;

    ListaOrdenada<tarefa> todo(10);

    tarefa arr2[] = {{"Feira", false},
                     {"Aluguel", false},
                     {"Lixo", false},
                     {"Estudar", false},
                     {"Cinema", false}};

    for (auto &v : arr2) {
        todo.adicionar(v);
    }

    todo[1].feita = true;
    todo[3].feita = true;

    for (int i = 1; i <= todo.tamanho(); i++) {
        cout << i << ": " << todo[i].nome << " [" << (todo[i].feita?"feita":"nao feita") << "]" << endl;
    }

    cout << "\n";

    string str1[] = {"Feira", "Tarefa de casa", "Cinema", "Padaria"};
    for (string &s : str1) {
        // Sintaxe { s, false } cria uma tarefa temporária com nome s, que é usada na busca
        cout << "- Buscando " << s << ": " << todo.buscar({s, false }) << endl;
    }
    
    cout << "\nLista Ordenada de Compras:" << endl;
    ListaOrdenada<compras> listaCompras2(10);
    
    compras arr3[] = {{"Feijão", 3, 7.50}, 
                      {"Sabonete", 6, 2.20},
                      {"Macarrão", 5, 3.75}, 
                      {"Leite", 4, 4.99}, 
                      {"Arroz", 2, 19.90}};

    for (auto &v : arr3) {
        listaCompras2.adicionar(v);
    }
    
    listaCompras2[2].comprado = true;
    listaCompras2[3].comprado = true;
    
    for(int i = 1; i <= listaCompras2.tamanho(); i++){
        cout << i << ": " << listaCompras2[i].nome << " [" << (listaCompras2[i].comprado?"comprado":"nao comprado") << "]" << endl;
    }
    
    cout << "\n";
    
    string str2[] = {"Café", "Leite", "Arroz","Detergente"};
    for(string &s : str2){
        cout << "- Buscando " << s << ": " << listaCompras2.buscar({s, false}) << endl;
    }
    
    return 0;
}