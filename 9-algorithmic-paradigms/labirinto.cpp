#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool backtracking(vector<vector<char>>& map, int i, int j) {
    if (i < 0 || i >= map.size() || j < 0 || j >= map[0].size() || map[i][j] == '#' || map[i][j] == 'x') return false;
    if (map[i][j] == 'd') return true;
    if (map[i][j] != 'o') map[i][j] = 'x';
    
    
    if (backtracking(map, i - 1, j) ||
        backtracking(map, i, j + 1) ||
        backtracking(map, i + 1, j) ||
        backtracking(map, i, j - 1)) {
        return true;
    }

    if (map[i][j] != 'o') map[i][j] = '.';
    
    return false;
}

void solve(vector<string>& M) {
    int lines = M.size();
    int columns = M[0].size();
    vector<vector<char>> map(lines, vector<char>(columns));
    int x, y;

    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            map[i][j] = M[i][j];
            if (map[i][j] == 'o') {
                x = i;
                y = j;
            }
        }
    }

    if (backtracking(map, x, y)) {
        for (int i = 0; i < lines; ++i) {
            for (int j = 0; j < columns; ++j) {
                M[i][j] = map[i][j];
            }
        }
    } else cout << "Caminho nao encontrado!" << endl;
}

void print(const vector<string>& M) {
    for (const auto& s : M) {
        cout << s << endl;
    }
    cout << endl;
}

int main() {
    vector<string> M1 = {
        ".#...",
        "...##",
        ".#..#",
        "o##.d",
        "#####"
    };

    vector<string> M2 = {
        "#...o",
        "..###",
        ".#...",
        "...#.",
        "###d."
    };

    solve(M1);
    print(M1);
    
    /* saida valida
    .#...
    xxx##
    x#xx#
    o##xd
    #####
    */

    solve(M2);
    print(M2);
    
    /*
    #xxxo
    xx###
    x#xxx
    xxx#x
    ###dx
    */

    return 0;
}