#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

template<class T>
void bubblesort(vector<T> &array) {
    int n = array.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

template<class T>
void selectionsort(vector<T> &array) {
    int n = array.size();
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[menor]) {
                menor = j;
            }
        }
        swap(array[i], array[menor]);
    }
}

template<class T>
void insertionsort(vector<T> &array) {
    int n = array.size();
    for (int i = 1; i < n; i++) {
        T atual = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > atual) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = atual;
    }
}

//-----------------------------------------------------------------------------------------------------------------------
template<class T>
void merge(vector<T> &array, vector<T> &aux, int start, int mid, int finish) {
	int i = start;
	int j = mid;
	int k = start;
	
	while(i <= mid && j <= finish){
	    if(aux[i] <= aux[j]){
	        array[k] = aux[i];
	        i++;
	    } else {
            array[k] = aux[j];
            j++;
	    }
	    k++;
	}
	
	while(i <= mid){
	    array[k++] = aux[i++];
	}
	
	while(j <= finish){
	    array[k++] = aux[j++];
	}
}

template<class T>
void mergesort(vector<T> &array, vector<T> &aux, int start, int finish) {
	if (start >= finish) return;
	int mid = (start + finish)/2;

	mergesort(aux, array, start, mid);
	mergesort(aux, array, mid + 1, finish);
	merge(array, aux, start, mid + 1, finish);
}

template<class T>
void mergesort(vector<T> &array) {
    vector<T> &aux = array;
	mergesort(array, aux, 0, array.size() - 1);
}

//-----------------------------------------------------------------------------------------------------------------------
template<class T>
int partition(vector<T> &array, int start, int finish) {
	int pivot = array[finish];
	int i = start - 1;
	
	for(int j = start; j < finish; j++){
	    if(array[j] <= pivot){
	        i++;
	        swap(array[i], array[j]);
	    }
	}
	swap(array[i + 1], array[finish]);
	return i + 1;
}

template<class T>
void quicksort(vector<T> &array, int start, int finish) {
	if (finish <= start) return;
	int pivot = partition(array, start, finish);
	quicksort(array, start, pivot - 1);
	quicksort(array, pivot + 1, finish);
}

template<class T>
void quicksort(vector<T> &array) {
	quicksort(array, 0, array.size() - 1);
}

//-----------------------------------------------------------------------------------------------------------------------

template<class T>
int validate(vector<T> &array) {
	for (int i = 0; i < array.size() - 1; i++) {
		if (array[i] > array[i + 1]) return 0;
	}
	return 1;
}

template<class T>
void print(vector<T> &array) {
	for (int i = 0; i < array.size(); i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

template<class T>
void test(vector<T> &array, const char *name, void function(vector<T> &array), bool printFlag) {
    vector<T> copy = array;
    auto start = chrono::high_resolution_clock::now();

    function(copy);

    auto finish = chrono::high_resolution_clock::now();
    long elapsed = chrono::duration_cast<chrono::nanoseconds>(finish - start).count() / 1000;

    int valid = validate(copy);
    cout << name << ": " << (valid ? "ok" : "erro") << " (tempo[us] = " << elapsed << ") ";

    if (printFlag) print(copy);
    else cout << endl;
}