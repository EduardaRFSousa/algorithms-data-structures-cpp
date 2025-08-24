//Chuva (Varredura): Coloquei validação, mudei algumas funções e fiz com que a água só fosse pra esquerda
#include <iostream>
#include <vector>

using namespace std;

char checa_chuva(const vector<vector<char>> &C, int i, int j, int n, int m) {
    if (
        (i > 0 && C[i - 1][j] == 'o') ||
        (j > 0 && i < n && C[i][j - 1] == 'o' && C[i + 1][j - 1] == '#') // direita
    ) {
        return 'o';
    } else return '.';
}

/*  j < m && i < n && C[i][j + 1] == 'o' && C[i + 1][j + 1] == '#'
    Caso queira mudar a direção pra esquerda
*/

void solucao_iterativa(vector<vector<char>> &C) {
    bool change;
    int n = C.size() - 1;
    int m = C[0].size() - 1;
    
    do {
        change = false;
        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < C[i].size(); j++) {
                if (C[i][j] == '#' || C[i][j] == 'o') continue; //'Continue' pula para o próximo j
                else {
                    C[i][j] = checa_chuva(C, i, j, n, m);
                    if(C[i][j] == 'o'){
                       change = true; 
                    }
                }
            }
        }
    }while (change); 
    /*O loop do-while só prossegue caso algum caractere 
    tenha virado gota, senão, a solução interativa termina*/
}

vector<vector<char>> validacao(){
    int b = 0; //Flag da gota
    int n, m, x, y; //x e y capturam a posição inicial da gota
    string linha;
    
    //Entrada dos parâmetros
    while(true){
        cout << "Escreva o valor de N: ";
        cin >> n;
        cout << "Escreva o valor de M: ";
        cin >> m;
        if((n < 3) || (n > 500) || (m < 3) || (m > 500) || (n % 2 == 0)){
            cout << "\nEntrada inválida de dimensões!\n3 < n < 500 && 3 < m < 500\n(N precisa ser um número ímpar!)\n" << endl;
        } else break;
        
    }
    
    vector<vector<char>> C(n,vector<char>(m));
    
    //Lê por LINHA (string)
    for (int i = 0; i < n; i++){
        string linha; 
        cin >> linha;
    
        // Validação de quantidade de caracteres
        if (linha.length() != m) {
            cout << "Erro na quantidade de caracteres. Deve ter exatamente " << m << " caracteres.\n";
            exit(1);
        }

        //Inserção dos tokens na matriz criada com 3 validações!
        for (int j = 0; j < m; j++){
            char token = linha[j];
            
            if (token == '.') C[i][j] = '.';
            else if (token == '#'){ 
                if(i % 2 == 0 || j == 0 || j == m - 1){
                    cout << "Inserção errada de prateleira! Não devem possuir o caractere '#':\n"
                        << ">> Linhas ímpares;\n>> A primeira coluna;\n>> A última coluna." << endl;
                    exit(1);
                } else C[i][j] = '#';
                
            } else if (token == 'o'){
                if (b == 0 && i == 0) {
                    b = 1;
                    x = i;
                    y = j;
                    C[i][j] = 'o';
                    break;
                } else if (b == 0 && i != 0){
                    cout << "O caractere 'o' só pode estar na primeira linha." << endl;
                    exit(1);
                } else {
                    cout << "Já foi posta uma gota, insira '.' ou '#'." << endl;
                    exit(1);
                }
            }
               
            /*Caso base (nenhum dos caracteres '.', '#' ou 'o'): Aplica mensagem de erro*/
            else {
                cout << "Entrada inválida de token! Use '.', '#' ou 'o'." << endl;
                exit(1);
            }
        }
    }
    
    /*Encerra o código caso não tenha sido inserido nenhuma gota na matriz*/
    if (b == 0) {
        cout << "Erro: não foi inserido nenhum caractere 'o' na primeira linha." << endl;
        exit(1);
    }
    return C;
}

int main() {
    vector<vector<char>> C = validacao();
    solucao_iterativa(C);
    cout << "\n"; //Conveniencia só pra dividir o output
    
    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C[0].size(); j++) {
            cout << C[i][j];
        }
        cout << endl;
    }
    
    cout << endl;
    return 0;
}