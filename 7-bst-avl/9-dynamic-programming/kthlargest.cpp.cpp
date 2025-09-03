#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &scores, int start, int finish) {
    int pivot = scores[finish];
	int i = start - 1;
	
	for(int j = start; j < finish; j++){
	    if(scores[j] <= pivot){
	        i++;
	        swap(scores[i], scores[j]);
	    }
	}
	swap(scores[i + 1], scores[finish]);
	return i + 1;
}

int quickselect_rec(vector<int> &scores, int start, int finish, int k_index) {
    if (start == finish) {
        return scores[start];
    }

    int pivot_index = partition(scores, start, finish);
    int target = (int)scores.size() - k_index;

    if (pivot_index == target) {
        return scores[pivot_index];
    } else if (pivot_index > target) {
        return quickselect_rec(scores, start, pivot_index - 1, k_index);
    } else {
        return quickselect_rec(scores, pivot_index + 1, finish, k_index);
    }
}

int quickselect(vector<int> &scores, int k) {
    int k_index = scores.size() - k;
    return quickselect_rec(scores, 0, scores.size() - 1, k_index);
}

class KthLargest {
    int k;
    vector<int> scores;
public:
    KthLargest(int k, vector<int>& nums) : k(k), scores(nums.size()) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            scores[i] = nums[i];
        }
    }

    int add(int val) {
        scores.push_back(val);
        return quickselect(scores, scores.size() - k);
    }

    const vector<int> & values() {
        return scores;
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    vector<int> vals = {3, 5, 10, 9, 4};
    KthLargest kthLargest (3, nums);

    for (int v : vals) {
        cout << "Adicionando " << v << ", 3o maior eh " << kthLargest.add(v) << endl;
        for (int x : kthLargest.values()) {
            cout << x << " ";
        }
        cout << endl;
    }
}