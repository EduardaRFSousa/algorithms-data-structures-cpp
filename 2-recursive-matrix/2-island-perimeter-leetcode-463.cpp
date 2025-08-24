//Perimetro da ilha: Cria uma borda imaginária em volta e soma +1 se a TERRA tiver contato com a AGUA
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int perimeter = 0;
		vector<vector<char>> map(m + 2, vector<char>(n + 2, '.'));
		//Cria um mapa novo(map) com bordas e tudo sendo MAR '.'!

        /*A condição abaixo faz com que cada TERRA no mapa original(grid)
        seja posta no mapa com bordas(map), com coordenadas coerentes*/
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					map[i + 1][j + 1] = '#';
					/*É necessário que a operação seja i+1 e j+1 pq 
                    representa as coordenadas do mapa original(grid) + borda*/
				}
			}
		}

		for (int i = 1; i <= m; i++) { //Se a coordenada for TERRA com um MAR estando do seu lado, acrescenta o perimetro
			for (int j = 1; j <= n; j++) {
				if (map[i][j] == '#') {
					if (map[i][j - 1] == '.') {
						perimeter++; //Esquerda
					}
					if (map[i - 1][j] == '.') {
						perimeter++; //Cima
					}

					if (map[i][j + 1] == '.') {
						perimeter++; //Direita
					}
					if (map[i + 1][j] == '.') {
						perimeter++; //Baixo
					}
				}
			}
		}

		return perimeter;
	}
};

int main() {
	vector<vector<int>> grid = {
		{0,1,0,0},
		{1,1,1,0},
		{0,1,0,0},
		{1,1,0,0}
	};

	cout << Solution().islandPerimeter(grid) << endl; //16
	return 0;
}