//Reordena um vetor
#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int> &arr, int n) {
    int p, var = 0;
    int size = arr.size();
    vector<int> copy = arr;
    
    for (int i = 0; i < size; i++) {
        p = i + n + size;
        p = p % size;
        var = copy[i];
        arr[p] = var;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    rotate(arr, 3);
    for (auto & v : arr) cout << v << " ";
    
    return 0;
}