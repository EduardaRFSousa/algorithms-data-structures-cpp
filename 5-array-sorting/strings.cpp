#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparar(const string &a, const string& b) {
    return a.length() < b.length();
}

vector<vector<string>> groupStrings(vector<string> &strs) {
    vector<vector<string>> res;
    
    sort(strs.begin(), strs.end(), comparar);
    for(const string str : strs){
        if(res.empty() || str.length() != res.back().back().length()){ 
            /*Se escreve res.back().back(). na condição pois captura
            o ÚLTIMO elemento do ÚLTIMO vetor da matriz*/
            res.push_back({str});
        } else {
            res.back().push_back(str);
        }
    }
    
    return res;
}

int main() {
    vector<string> strs = {"Redes", "IFPE", "Algoritmos", "Android",
                           "Complexidade", "IF", "PE", "Recife",
                           "TADS", "2025", "BubbleSort", "Git",
                           "GitHub", "Subversion", "Gradle", "Docker"};

    vector<vector<string>> groups = groupStrings(strs);

    for (const auto &group : groups) {
        for (const auto &str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}