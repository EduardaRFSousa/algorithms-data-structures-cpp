#include <iostream>
#include "lista.h"

template <class T>
class KthLargest : public ListaOrdenada<T> {
    int k;

    public:
        explicit KthLargest(int k, vector<T>& nums) : k(k), ListaOrdenada<int>(10000) { 
            for (int val : nums) {
                this->adicionar(val);
            }
        }
        
        int add(int val) {
            this->adicionar(val);
            return (*this)[this->tamanho() - k + 1];
        }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    vector<int> vals = {3, 5, 10, 9, 4};
    KthLargest<int> kthLargest (3, nums);
    
    for (int v : vals) {
        cout << "Adicionando " << v << ", 3o maior eh " << kthLargest.add(v) << endl;
    }
}