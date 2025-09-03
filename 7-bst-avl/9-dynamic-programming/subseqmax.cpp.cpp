#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <vector>
#include <climits>

unsigned long long count_ssm = 0;

using namespace std;

/* Pratica 10 - Forca Bruta -----------------*/
// start e finish: inicio e final sendo testado agora;
// ini e end: onde sao retornados o inicio e final da melhor sequencia
// retorna a soma da maior sequencia
int subseqMaxBF(const vector<int> &array, int & ini, int & end) {
    int max = INT_MIN;
    ini = 0;
    end = 0;
    for(int i = 0; i < array.size(); i++){
        for(int j = i; j < array.size(); j++){
            count_ssm++; 
            int soma = 0;
            for(int k = i; k <= j; k++){
                soma += array[k];
            }
            if(soma > max){
                ini = i;
                end = j;
                max = soma;
            }
        }
    }
    return max;
}

int subseqMaxDCMiddle(const vector<int> &array, int start, int middle, int finish, int &ini, int &end) {
    int sum = 0;
    int left_sum = INT_MIN;
    int left_ini = middle;
    
    for (int i = middle; i >= start; --i) {
        sum += array[i];
        if (sum > left_sum) {
            left_sum = sum;
            left_ini = i;
        }
    }
    
    sum = 0;
    int right_sum = INT_MIN;
    int right_end = middle + 1;

    for (int i = middle + 1; i <= finish; ++i) {
        sum += array[i];
        if (sum > right_sum) {
            right_sum = sum;
            right_end = i;
        }
    }
    
    ini = left_ini;
    end = right_end;
    
    return left_sum + right_sum;
}

int subseqMaxDC_Rec(const vector<int> &array, int start, int finish, int & ini, int & end) {
    int max_sum;
    count_ssm++;
    
    if (start == finish) {
        ini = start;
        end = finish;
        return array[start];
    }

    int mid = (start + finish) / 2;

    int ini_left, end_left;
    int sum_left = subseqMaxDC_Rec(array, start, mid, ini_left, end_left);

    int ini_right, end_right;
    int sum_right = subseqMaxDC_Rec(array, mid + 1, finish, ini_right, end_right);

    int ini_middle, end_middle;
    int sum_middle = subseqMaxDCMiddle(array, start, mid, finish, ini_middle, end_middle);

    if (sum_left >= sum_right && sum_left >= sum_middle) {
        ini = ini_left;
        end = end_left;
        return sum_left;
    } else if (sum_right >= sum_left && sum_right >= sum_middle) {
        ini = ini_right;
        end = end_right;
        return sum_right;
    } else { 
        ini = ini_middle;
        end = end_middle;
        return sum_middle;
    }

    return max_sum;
}

/* Pratica 11 - Dividir e Conquistar ----------------- */
int subseqMaxDC(const vector<int> &array, int & ini, int & end) {
	int len = (int)array.size();
	return subseqMaxDC_Rec(array, 0, len - 1, ini, end);
}

/* Pratica 12 - Rercusiva ----------------- */
int subseqMaxRec(const vector<int> &array, int & ini, int & end) {
	// ???
	return -1;
}

/* Pratica 12 - Memoization ----------------- */
int subseqMaxMemo(const vector<int> &array, int & ini, int & end) {
	// ???
	return -1;
}

/* Pratica 12 - Programacao Dinamica ----------------- */
int subseqMaxPD(const vector<int> &array, int & ini, int & end) {
	int max = INT_MIN;
    int current_max = 0;
    int current_start = 0;

    ini = 0;
    end = 0;

    for (int i = 0; i < array.size(); ++i) {
        count_ssm++;

        if (array[i] > current_max + array[i]) {
            current_max = array[i];
            current_start = i;
        } else current_max += array[i];
        

        if (current_max > max) {
            max = current_max;
            ini = current_start;
            end = i;
        }
    }

    return max;
}

/* -------------------------------------- */
void runSubseqMax(const char * name, int subseqmax(const vector<int> &, int&, int&), const vector<int> & array, bool printSeq) {
	using namespace std::chrono;

	count_ssm = 0;

	int ini = 0, end = 0;

	auto start = high_resolution_clock::now();

	int max = subseqmax(array, ini, end);

	auto finish = high_resolution_clock::now();
	long elapsed = duration_cast<nanoseconds>(finish-start).count() / 1000;

	cout << name << ": " << max << " ";

	cout << "[time: "<< setw(6) << setfill(' ') << elapsed << "us] ";
	cout << "[count: " << setw(6) << setfill(' ') << count_ssm << "] ";

	if (printSeq) {
		cout << "[ ";
		for (int i = ini; i <= end; i++) cout << array[i] << " ";
		cout << "] ";
	}

	cout << endl;
}

int main() {
	bool printSeq = true;
	int size = 20;

	srand(12345);

	vector<int> array(size);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < size; j++) {
			array[j] = (rand() % (3 * size)) - (rand() % (4 * size));
		}

		cout <<"Test " << i << ": ";

		for (auto v : array) cout << v << " ";
		cout << endl;

		runSubseqMax("Bruteforce     ", subseqMaxBF, array, printSeq);
		runSubseqMax("Divide&Conquer ", subseqMaxDC, array, printSeq);
		runSubseqMax("Recursive      ", subseqMaxRec, array, printSeq);
		runSubseqMax("Memoization    ", subseqMaxMemo, array, printSeq);
		runSubseqMax("Dynamic Prog.  ", subseqMaxPD, array, printSeq);
		cout << "\n" << endl;
	}

	return 0;
}