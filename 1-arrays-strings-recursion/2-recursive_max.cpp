//Recursão que retorna o maior número do vetor
#include <iostream>
#include <vector>

using namespace std;

int Recursao(const vector<int> &arr, int i) {
    if (i == arr.size() - 1) { //Começa a dar ré quando chegar na ÚLTIMA casinha do vetor
        return arr[i];
    }
    
    int maiorNum = Recursao(arr, i + 1);
    /* Vai chamando a si mesma enquanto dá um passo no vetor,
    quando chegar no caso base, todas as chamadas que não foram 
    fechadas vão receber um retorno!
    */

    if (arr[i] > maiorNum) { 
        return arr[i];
    } else {
        return maiorNum;
    }
        
    /* O retorno de todas as recursões é calculado nesse if, 
    onde será retornado ou o algarismo da recursão atual, ou
    o algarismo da recursão anterior (usando o comparador >)
    */
}

int maior(const vector<int> &arr) {
    int i = 0;
    return Recursao(arr, 0);
}

int main() {
    vector<int> arr = {10, 1, 5, 3, 12, 7, 4, 6};
    cout << maior(arr) << endl;
    return 0;
}