#include <vector>
#include <iostream>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        return nums;
    }

    vector<int> twoSum_simple(const vector<int>& nums, int target) {
        set<int> res;
        vector<int> result;
        
        for(int num : nums){
            res.insert(num);
        }
        
        for (int firstNum : res) {
            int secondNum = target - firstNum;
            
            if(res.find(secondNum) != res.end() && firstNum != secondNum){
                result.push_back(firstNum);
                result.push_back(secondNum);
                break;
            }
        }
        
        return result;
    }
};

int main() {
    vector<int> nums1 = {2,7,11,15};
    int target1 = 9;
    auto res1 = Solution().twoSum_simple(nums1, target1);
    cout << "Caso 1 (" << target1 << "): ";
    if (res1.empty())
        cout << "impossivel" << endl;
    else {
        cout << res1[0] << " & " << res1[1] << endl; // twoSum_simple()
//        cout << nums1[res1[0]] << " & " << nums1[res1[1]] << endl; // twoSum()
    }

    vector<int> nums2 = {12, 1, 35, 16, 7, 23, 15};
    int target2 = 31;
    auto res2 = Solution().twoSum_simple(nums2, target2);
    cout << "Caso 2 (" << target2 << "): ";
    if (res2.empty())
        cout << "impossivel" << endl;
    else {
        cout << res2[0] << " & " << res2[1] << endl; // twoSum_simple()
//        cout << nums2[res2[0]] << " & " << nums2[res2[1]] << endl; // twoSum()
    }

    vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int target3 = -1;
    auto res3 = Solution().twoSum_simple(nums3, target3);
    cout << "Caso 3 (" << target3 << "): ";
    if (res3.empty())
        cout << "impossivel" << endl;
    else {
        cout << res3[0] << " & " << res3[1] << endl; // twoSum_simple()
//        cout << nums3[res3[0]] << " & " << nums3[res3[1]] << endl; // twoSum()
    }
    return 0;
}