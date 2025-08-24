//Contaminação (Recursão): Estrutura mais objetiva, lógica semelhante a da chuva
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool valida(vector<vector<char>> &map, int i, int j){
    int n = map.size(); 
    int m = map[0].size();
    if(i >= 0 && j >= 0 && i < n && j < m && map[i][j] == 'A'){
        return true;
    } else return false;
}

void recursao(vector<vector<char>> &map, int i, int j){
    if(!valida(map, i, j)) return;

    map[i][j] = 'T';

    recursao(map, i - 1, j); // cima
    recursao(map, i + 1, j); // baixo
    recursao(map, i, j - 1); // esquerda
    recursao(map, i, j + 1); // direita
}

vector<vector<char>> entrada(int n, int m){
    vector<vector<char>> map(n,vector<char>(m));
    string linha;
    
    for(int i = 0; i < n; i++){
        cin >> linha;
        for(int j = 0; j < m; j++){
            map[i][j] = linha[j];
        }
    }
    
    return map;
}

int main(){
    int n, m;
    cin >> n >> m;

    if(n <= 0 || n > 50 || m <= 0 || m > 50){
        cout << "Valores inválidos, insira altura e largura maior que 0 e menor que 50." << endl;
        exit(1);
    }
        
    vector<vector <char>> map = entrada(n, m);
    cout << "\n";
        
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 'T'){
                recursao(map, i - 1, j);
                recursao(map, i + 1, j);
                recursao(map, i, j - 1);
                recursao(map, i, j + 1);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << map[i][j];
        }
        cout << endl;
    }    
    
    return 0;
}