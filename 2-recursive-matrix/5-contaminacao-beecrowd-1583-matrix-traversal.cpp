//Contaminação (Varredura): Estrutura mais objetiva, lógica semelhante á da chuva
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool contaminacao(vector<vector<char>> &map, int i, int j){
    if(
        (j != 0 && map[i][j - 1] == 'T') || 
        (j < map[0].size() - 1 && map[i][j + 1] == 'T') || 
        (i != 0 && map [i - 1][j] == 'T') || 
        (i < map.size() - 1 && map [i + 1][j] == 'T')
    ){
        return true;
    } else return false;
}

vector<vector<char>> varredura(vector<vector<char>> &map, int n, int m){
    bool change;
    do{
        change = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(map[i][j] == 'A' && contaminacao(map, i, j)){
                    map[i][j] = 'T';
                    change = true;
                }
            }
        }
    }while(change);
    
    return map;
}

vector<vector<char>> entrada(int n, int m){
    vector<vector<char>> map(n,vector<char>(m));
    string linha;
    
    for(int i = 0; i < n; i++){
        cin >> linha;
        if(linha.length() != m){
            cout << "Quantidade de caracteres diferente de " << n;
            exit(1);
        }
        
        for(int j = 0; j < m; j++){
            map[i][j] = linha[j];
        }
    }
    
    return map;
}

int main(){
    int n = 0;
    int m = 0;
    
    while(true){
        cin >> n >> m;
        if(n <= 0 || n > 50 || m <= 0 || m > 50){
            cout << "Valores inválidos, insira altura e largura maior que 0 e menor que 50.";
        } else {
            break;
        }
    }
    
    vector<vector <char>> map = entrada(n, m);
    cout << "\n";
    varredura(map, n, m);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
    
    return 0;
}