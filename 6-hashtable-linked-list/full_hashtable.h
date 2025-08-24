#ifndef PRATICA_06_FULL_HASHTABLE_H
#define PRATICA_06_FULL_HASHTABLE_H

#include <vector>
#include "hashtable.h"
#include "linkedlist.h"

using namespace std;

/* Tabela de Espalhamento como vector de listas encadeadas.
 * As listas lidam com colisoes  */
template<class T_key, class T_value>
class full_hashtable : public hashtable<T_key, T_value> {
private:
	vector<linkedlist<pair<T_key, T_value>>> table;

	// Valor retornado quando uma busca falha
	T_value not_found;

public:
	explicit full_hashtable(int cap, T_value not_found)
		: hashtable<T_key, T_value>(cap), table(cap), not_found(not_found) {}

	~full_hashtable() = default;

	void insert(T_key key, T_value value) override {
		int idx = this->get_idx(key);

		// Verifica se a chave já existe: se sim, atualiza o valor
		for (auto &par : table[idx]) {
			if (par.first == key) {
				par.second = value;
				return;
			}
		}

		// Se não existe, adiciona um novo par (key, value) no início
		table[idx].add({key, value});
		this->size++;
	}

	void remove(T_key key) override {
		int idx = this->get_idx(key);
		int i = 0;
		for (auto &par : table[idx]) {
			if (par.first == key) {
				table[idx].remove(i);
				this->size--;
				return;
			}
			i++;
		}
		cout << "Chave não encontrada!" << endl;
	}

	T_value search(T_key key) override {
		int idx = this->get_idx(key);
		for (auto &par : table[idx]) {
			if (par.first == key) {
				return par.second;
			}
		}
		return this->not_found;
	}

	void show() override {
		int i = 0;
		for (auto &list : table) {
			cout << i++ << ": ";
			for (auto &[key, value] : list)
				cout << "(" << key << ": " << value << ") ";
			cout << endl;
		}
	}

	virtual T_value operator [] (const T_key &key) {
		return search(key);
	}

private:
	// Dado o indice na tabela, acha o indice na lista associado com a chave
	int search_list(int idx, T_key key) {
		int i = 0;
		for (auto &[k, _] : table[idx]) {
			if (k == key) return i;
			i++;
		}
		return -1;
	}
};

#endif
