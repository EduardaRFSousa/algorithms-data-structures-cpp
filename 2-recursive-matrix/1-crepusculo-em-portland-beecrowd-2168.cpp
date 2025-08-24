//Crepusculo em Portland: Soma +1 a cada token que esteja iluminado
#include <iostream>
#include <vector>

using namespace std;

vector<char> calculate(vector<vector<int>> &block, int n) {
    vector <char> result = {};
    int i, j;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int count = 0;
            
            if(block[i][j] == 1){
                count++;
            }if (block[i][j + 1] == 1){
                count++;
            }if (block [i + 1][j] == 1){
                count++;
            }if (block [i + 1][j + 1] == 1){
                count++;
            }if(count >= 2){
                result.push_back('s');
            }else{
                result.push_back('u');
            }
        }
    }
    
    return result;
}

int main() {
    int n = 0;
    int count = 0;
    cin >> n;
    vector<vector<int>> block(n + 1, vector<int>(n + 1));
    
    //Entrada de dados atraves de string (facilita a visualizacao da matriz)
    for (int i = 0; i < (n + 1); i++) {
        string linha;
        cin >> linha;
        
        if(linha.length() != (n + 1)){
            cout << "Erro na quantidade de caracteres: Precisa ser " << (n + 1);
            exit(1);
        }
    
        for(int j = 0; j < linha.length(); j++){
            if(linha[j] != '0' && linha[j] != '1'){
                cout << "Erro na insercao de caracteres";
                exit(1);
            } else {
                if(linha[j] == '0'){
                    block[i][j] = 0;
                } else {
                    block[i][j] = 1;
                }
            }
        }
    }
    
    vector<char> result = calculate(block, n);
    
    //Saída de dados
    for (char c : result) {
        cout << c;
        count++;
        if(count % n == 0){
            cout << "\n";
        }
    }
    
    cout << endl;
    return 0;
}