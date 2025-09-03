#include <iostream>
#include <cstdlib>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long count_ssk = 0;

/* Pratica 10 - Forca Bruta ------------------*/
bool subsetSumBF(const vector<int> &array, int K, vector<bool> &subset) {
        // GIVEN
	long total = 1 << array.size(); // 2^N combinacoes totais

	for (long v = 0; v < total; v++) { // para todas as combinacoes
		count_ssk ++;

		int cur_sum = 0;
		for (unsigned i = 0; i < array.size(); i++) { // para todas as posicoes / bits
			subset[i] = v & (1 << i);
			if (subset[i]) cur_sum += array[i];
		}
		if (cur_sum == K) return true;
	}

	return false;
}

/* Pratica 10 - Backtracking ------------------- */
bool SubSetSumBT(const vector<int> &array, int k, vector<bool> &subset, int i) {
    count_ssk++;
    
    if (k == 0) {
        return true;
    }

    if (i < 0 || k < 0) {
        return false;
    }

    if (SubSetSumBT(array, k - array[i], subset, i - 1)) {
        subset[i] = true;
        return true;
    }

    if (SubSetSumBT(array, k, subset, i - 1)) {
        subset[i] = false;
        return true;
    }

    return false;
}

bool subsetSumBT(const vector<int> &array, int k, vector<bool> &subset) {
    subset.assign(array.size(), false);
    return SubSetSumBT(array, k, subset, array.size() - 1);
}

/* Pratica 11 - Greedy ------------------ */
bool subsetSumGreedy(const vector<int> &array, int k, vector<bool> &subset) {
    vector<int> sorted_array = array; 
    sort(sorted_array.begin(), sorted_array.end());
    int sum = 0;
    
    for(int i = sorted_array.size() - 1; i >= 0; --i){
        if((sum + sorted_array[i]) <= k){
            sum += sorted_array[i];
        
            for(int j = 0; j <= array.size() - 1; ++j){
                if(array[j] == sorted_array[i]){
                    subset[j] = true;
                    break;
                }
            }
        }
    }

    return sum == k;
}

/* Pratica 12 - Programacao Dinamica ------------------ */
bool SubSetSumRecMemo(const vector<int> &array, int k, vector<bool> &subset, int i, vector<vector<int>> &memo) {
    count_ssk++;
    
    if (k == 0) return true;
    if (i < 0 || k < 0) return false;

    if (memo[i][k] != -1) return memo[i][k] == 1;

    if (SubSetSumRecMemo(array, k - array[i], subset, i - 1, memo)) {
        subset[i] = true;
        memo[i][k] = 1;
        return true;
    }

    if (SubSetSumRecMemo(array, k, subset, i - 1, memo)) {
        subset[i] = false;
        memo[i][k] = 1;
        return true;
    }

    memo[i][k] = 0;
    return false;
}

bool subsetSumMemo(const vector<int> &array, int k, vector<bool> &subset) {
    vector<vector<int>> memo(array.size(), vector<int>(k + 1, -1));
    return SubSetSumRecMemo(array, k, subset, array.size() - 1, memo);
}

bool subsetSumDP(const vector<int> &array, int k, vector<bool> &subset) {
    // ???
    return false;
}

/* -------------------------------------- */
bool check_sum(const vector<int> &array, int sum, const vector<bool> &subset) {
	int cur_sum = 0;

	for (int i = 0; i < (int)array.size(); i++) {
		if (subset[i]) cur_sum += array[i];
	}

	return (cur_sum == sum);
}

void runSubsetSum(const char *name, bool subsetSum(const vector<int> &, int, vector<bool> &), const vector<int> &array, int sum) {
	using namespace std::chrono;

    count_ssk = 0;

	vector<bool> subset(array.size(), false);

	auto start = high_resolution_clock::now();

	bool found = subsetSum(array, sum, subset);

	auto finish = high_resolution_clock::now();
	long elapsed = duration_cast<nanoseconds>(finish - start).count() / 1000;

	bool valid = found && check_sum(array, sum, subset);

	cout << name << ": " << (found ? ( valid ? "YES " : "ERR " ): " NO ");

	cout << "[time: " << elapsed << "us] ";
	cout << "[count: " << count_ssk << "] ";
	if (found) {
		cout << "[ ";
		for (unsigned i = 0; i < array.size(); i++) {
			if (subset[i])
				cout << array[i] << " ";
		}
		cout << "] ";
	}
	cout << endl;
}

int main() {
	int size = 20;

	vector<int> array(size);

//	srand(333);
	srand(12345);

	for (int i = 0; i < size; i++) {
		cout << (array[i] = 1 + rand() % (size * 5)) << " ";
	}
	cout << endl;

	int value = 0;
	for (int i = 0; i < 20; i++) {
		value += (rand() % (size * 6));
		cout << i << ": Trying " << value << " ..." << endl;

		runSubsetSum("Bruteforce   ", subsetSumBF, array, value);
		runSubsetSum("Backtracking ", subsetSumBT, array, value);
		runSubsetSum("Memoization  ", subsetSumMemo, array, value);
		runSubsetSum("Dynamic Prog.", subsetSumDP, array, value);
		runSubsetSum("Greedy       ", subsetSumGreedy, array, value);
	    cout << "\n" << endl;
	}

	return 0;
}