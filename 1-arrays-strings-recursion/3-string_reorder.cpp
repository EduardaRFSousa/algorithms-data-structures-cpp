//Ordena os caracteres em ordem alfabética
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string reordenar(string str) {
    vector<char> arr(str.begin(), str.end());
    vector<int> contagem(26, 0);
    int size = arr.size();
    vector<char> result(size);
    char c;
    
    for (int i = 0; i < size; i++){
        c = arr[i];
        if (c >= 'a' && c <= 'z') { 
            contagem[c - 'a']++; 
        }
    }

    for (int i = 0; i < 26; ++i) {
        c = 'a' + i;
        
        //Roda caso for diferente de 0
        for (int j = 0; j < contagem[i]; ++j) {
            result.push_back(c);
        }
    }
    
    string resultado(result.begin(), result.end());
    return resultado;
}

int main() {
    cout << reordenar(string("casa")) << endl;
    cout << reordenar(string("escola")) << endl;
    cout << reordenar(string("ifpe")) << endl;
    cout << reordenar(string("banana")) << endl;
}