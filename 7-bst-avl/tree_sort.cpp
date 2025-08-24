#include <iostream>
#include <vector>
#include "avl.h"

using namespace std;

int main() {
    vector<int> nums = {12, 1, 35, 16, 7, 23, 15};

    AVLTree tree;

    for (int v : nums) tree.insert(v);

    vector<int> sorted;

    tree.sort(sorted);

    cout << "Antes: ";
    for (int v : nums) {
        cout << v << " ";
    }
    cout << endl;

    cout << "Depois: ";
    for (int v : sorted) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}