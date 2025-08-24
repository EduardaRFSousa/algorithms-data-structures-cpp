#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> contagem(3, 0);
        
        for(int n : nums){
            contagem[n]++;
        }
        
        int k = 0;
        for(int i = 0; i < contagem.size(); ++i){
            for(int j = 0; j < contagem[i]; ++j){
                nums[k++] = i;
            }
        }
    }
};

int main() {
    vector<int> test1 = {2, 0, 2, 1, 1, 0};
    vector<int> test2 = {2, 0, 1};
    vector<int> test3 = {1, 1, 0, 2, 0, 2, 1, 2, 0, 1, 1, 0, 2, 0, 2};

    Solution().sortColors(test1); for (int v : test1) cout << v << " "; cout << endl;
    Solution().sortColors(test2); for (int v : test2) cout << v << " "; cout << endl;
    Solution().sortColors(test3); for (int v : test3) cout << v << " "; cout << endl;

    return 0;
}