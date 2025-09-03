#include <vector>
#include <iostream>
#include <ranges>

using namespace std;

int max_profit(const vector<int> &costs, const vector<int> &sales) {
    int max = 0;
    int ini = 0;
    int end = 0; 
    for(int i = 0; i < costs.size() - 2; i++){
        for(int j = i + 1; j < costs.size() - 1; j++){
            int soma = 0;
            for(int k = i; k <= j; k++){
                int diff = sales[k] - costs[k];
                soma += diff;
            }
            if(soma > max){
                max = soma;
            }
        }
    }
    return max;
}

int main() {
    vector<int> costs = {10, 22, 15, 20, 18, 16, 14, 12, 10};
    vector<int> sales = {17, 12, 21, 15, 25, 40, 34, 20, 5};

    cout << "Max profit = " << max_profit(costs, sales) << endl; // 60

    return 0;
}