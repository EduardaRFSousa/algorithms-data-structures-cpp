//Cria números binários usando recursão
#include <iostream>
#include <vector>

using namespace std;

void gerar(vector<string> &seqs, int n, string tmp) {
    if (tmp.length() == n) {
        seqs.push_back(tmp);
        return;
    }
    
    gerar(seqs, n, tmp + "0");
    gerar(seqs, n, tmp + "1");
}

vector<string> gerar(int n) {
    vector<string> seqs;
    gerar(seqs, n, string(""));
    return seqs;
}

int main() {
    for (auto &s : gerar(3)) {
        cout << s << endl;
    }
}