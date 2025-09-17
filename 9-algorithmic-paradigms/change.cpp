#include <vector>
#include <iostream>

using namespace std;

class Solution {
  
public:

    int coinChange(const vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        
        if (dp[amount] > amount) {
            return -1;
        }

        return dp[amount];
    }

};

int main() {

    cout << Solution().coinChange({1, 2, 5}, 11) << endl; // res = 3
    cout << Solution().coinChange({1, 6, 7, 9, 11}, 13) << endl; // res = 2
    cout << Solution().coinChange({1, 2, 5, 10}, 16) << endl; // res = 3
    cout << Solution().coinChange({1, 2, 7, 10}, 16) << endl; // res = 3 (greedy = 4)
    cout << Solution().coinChange({1,2,5,7,8,4}, 30) << endl; // res = 4
    cout << Solution().coinChange({83, 186, 408, 419}, 6249) << endl; // res = 20

    return 0;
}