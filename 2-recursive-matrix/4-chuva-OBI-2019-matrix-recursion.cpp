//Chuva (Recursão): Aqui não mudei pois tava dando muitos erros o uso da função de validação, então só fiz com que a água escorre pra um lado
#include <iostream>
#include <vector>

using namespace std;

bool checa_chuva(const vector<vector<char>> &C, int i, int j) {
    int n = C.size();
    int m = C[0].size();

    return 
    (i > 0 && C[i - 1][j] == 'o') || 
    (j > 0 && i < n - 1 && C[i][j - 1] == 'o' && C[i + 1][j - 1] == '#');
    //j < m - 1 && i < n - 1 && C[i][j + 1] == 'o' && C[i + 1][j + 1] == '#'
}

bool valida(const vector<vector<char>> &C, int i, int j) {
    int n = C.size();
    int m = C[0].size();

    return (i >= 0 && j >= 0 && i < n && j < m && C[i][j] == '.');
}

void chuva(vector<vector<char>> &C, int i, int j) {
    if (C[i][j] == 'o' || checa_chuva(C, i, j)) {
        C[i][j] = 'o';

        if (valida(C, i, j - 1)) chuva(C, i, j - 1);
        if (valida(C, i, j + 1)) chuva(C, i, j + 1);
        if (valida(C, i + 1, j)) chuva(C, i + 1, j);
    }
}

void solucao_recursiva(vector<vector<char>> &C, int x, int y) {
    chuva(C, x, y);
}

int main() {
    int n, m, x, y;
    cin >> n >> m;
    vector<vector<char>> C(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> C[i][j];
            if (C[i][j] == 'o') {
                x = i;
                y = j;
            }
        }
    }

    solucao_recursiva(C, x, y);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << C[i][j];
        }
        cout << endl;
    }

    return 0;
}