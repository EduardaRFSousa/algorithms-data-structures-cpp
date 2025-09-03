#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float solve(const vector<int> &price, const vector<int> &weight, int k) {
    vector<pair<float, int>> itens;
    
    for (int i = 0; i < price.size(); ++i) {
        float proportion = (float)price[i] / weight[i];
        itens.push_back({
            proportion, 
            weight[i]
        });
    }

    sort(itens.rbegin(), itens.rend());

    float total_value = 0.0;

    for (auto pair : itens) {
        if (k <= 0) {
            break;
        }

        float proportion = pair.first;
        int current_weight = pair.second;

        if (current_weight <= k) {
            total_value += proportion * current_weight;
            k -= current_weight;
        } else {
            total_value += proportion * k;
            k = 0;
        }
    }

    return total_value;
}

int main() {
    vector<int> precos = {100, 10 , 10, 100, 50};
    vector<int> pesos  = {50, 50, 100, 20, 10};
    int K = 100;

    float res = solve(precos, pesos, K);

    cout << res << endl; // 254

    return 0;
}