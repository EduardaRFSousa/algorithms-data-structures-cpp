//CONTAMINAÇÃO (Pilha)
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

bool valida(vector<vector<char>> &map, int i, int j){
    int n = map.size(); 
    int m = map[0].size();
    if(i >= 0 && j >= 0 && i < n && j < m && map[i][j] == 'A'){
        return true;
    } else return false;
}

vector<vector<char>> calculoPilha(vector<vector<char>> &map, int i, int j){
    stack <pair<int, int>> pilha;
    map[i][j] = 'A';
    pilha.push({i, j});
    
    do{
        pair<int, int> coord = pilha.top();
        int i = coord.first;
        int j = coord.second;
        
        if(valida(map, i, j)){
            map[i][j] = 'T';
            pilha.pop();
            pilha.push({i, j - 1});
            pilha.push({i + 1, j});
            pilha.push({i, j + 1});
            pilha.push({i - 1, j});
        } else {
            pilha.pop();
        }    
    }while(!pilha.empty());

    return map;
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
    int x = -1;
    int y = -1;
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
                x = i;
                y = j;
                break;
            }
        }    
    }
        
    if(x == -1 || y == -1){
        cout << "Não há um ponto de contaminação na água!";
        exit(1);
    }
    
    calculoPilha(map, x, y);

    for(vector<char> &v : map){
        for(char &c : v){
            cout << c;
        }
        cout << endl;
    }    
    
    return 0;
}