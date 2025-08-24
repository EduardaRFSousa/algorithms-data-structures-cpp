#include <iostream>
#include "graph.h"

using namespace std;

// Para facilitar a exibicao de listas de vertices
ostream & operator <<(ostream &out, const list<int> &l) {
	for (int i : l) out << i << " ";
	return out;
}

int main() {
	Graph graph1(6);		// Connected
	graph1.edge(0, 1, 4);
	graph1.edge(0, 2, 2);
	graph1.edge(1, 2, 5);
	graph1.edge(1, 3, 10);
	graph1.edge(2, 4, 3);
	graph1.edge(4, 3, 4);
	graph1.edge(3, 5, 11);
	graph1.edge(5, 1, 11);

	Graph graph2(9);		// Connected
	graph2.edge(0, 1, 4);
	graph2.edge(0, 7, 8);
	graph2.edge(1, 2, 8);
	graph2.edge(1, 7, 11);
	graph2.edge(2, 3, 7);
	graph2.edge(2, 5, 4);
	graph2.edge(2, 8, 2);
	graph2.edge(3, 4, 9);
	graph2.edge(3, 5, 14);
	graph2.edge(4, 5, 10);
	graph2.edge(5, 6, 2);
	graph2.edge(6, 7, 1);
	graph2.edge(6, 8, 6);
	graph2.edge(7, 8, 7);

	Graph graph3(6);		// Not connected
	graph3.edge(0, 1, 12);
	graph3.edge(0, 2, 2);
	graph3.edge(3, 4, 1);
	graph3.edge(4, 5, 10);

	// Pratica 08
	cout << "Graph1 is connected? " << (graph1.isConnected()?"YES":"NO") << endl; // YES
	graph1.print();
	cout << endl;

	cout << "Graph2 is connected? " << (graph2.isConnected()?"YES":"NO") << endl; // YES
	graph2.print();
	cout << endl;

	cout << "Graph3 is connected? " << (graph3.isConnected()?"YES":"NO") << endl; // NO
	graph3.print();
	cout << endl;

	// Pratica 09
	cout << endl;

	cout << "Graph1: " << endl;
	cout << "DFS(0): " << graph1.dfs(0) << endl; // 0 1 2 4 3 5
	cout << "BFS(0): " << graph1.bfs(0) << endl; // 0 1 2 3 4 5
    cout << "SPF(0, 5): " << graph1.spf(0, 5) << endl; // 0 2 4 3 5
    cout << "Has cycle: " << (graph1.has_cycle()?"yes":"no") << endl; // yes
    cout << "Reachable(0, 5): " << (graph1.reacheable(0, 5)?"yes":"no") << endl; // yes
    cout << "Reachable(5, 0): " << (graph1.reacheable(5, 0)?"yes":"no") << endl; // no
    cout << endl;

	cout << "Graph2: " << endl;
	cout << "DFS(0): " << graph2.dfs(0) << endl; // 0 1 2 3 4 5 6 7 8
	cout << "BFS(0): " << graph2.bfs(0) << endl; // 0 1 7 2 8 3 5 4 6
	cout << "SPF(0, 5): " << graph2.spf(0, 5) << endl; // 0 1 2 5
    cout << "Has cycle: " << (graph2.has_cycle()?"yes":"no") << endl; // no
    cout << "Reachable(0, 5): " << (graph2.reacheable(0, 5)?"yes":"no") << endl; // yes
    cout << "Reachable(5, 0): " << (graph2.reacheable(5, 0)?"yes":"no") << endl; // no
    cout << "Reachable(4, 8): " << (graph2.reacheable(4, 8)?"yes":"no") << endl; // yes
    cout << "Reachable(8, 4): " << (graph2.reacheable(8, 4)?"yes":"no") << endl; // no
    cout << endl;

	cout << "Graph3: " << endl;
	cout << "DFS(0): " << graph3.dfs(0) << endl; // 0 1 2
	cout << "BFS(0): " << graph3.bfs(0) << endl; // 0 1 2
	cout << "SPF(0, 5): " << graph3.spf(0, 5) << endl; // 5 ou vazio
    cout << "Has cycle: " << (graph3.has_cycle()?"yes":"no") << endl; // no
    cout << "Reachable(0, 5): " << (graph3.reacheable(0, 5)?"yes":"no") << endl; // no
    cout << "Reachable(3, 5): " << (graph3.reacheable(3, 5)?"yes":"no") << endl; // yes
    cout << "Reachable(1, 2): " << (graph3.reacheable(1, 2)?"yes":"no") << endl; // no
}