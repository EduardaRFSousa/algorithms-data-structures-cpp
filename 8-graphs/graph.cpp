#include <queue>
#include <set>

#include "graph.h"

// Criacao da aresta src --> dst
void Graph::edge(int src, int dst, int w) {
	if (src < 0) throw std::runtime_error("Src invalido");
	if (dst < 0) throw std::runtime_error("Dst invalido");
    if (w   < 0) throw std::runtime_error("Distancia/peso invalido");
    adj[src].push_back({dst, w});
}

// Grau de saida: src -> dst
int Graph::degree(int src) const {
    if (src < 0 || src >= adj.size()) throw std::runtime_error("Src invalido");
    return adj[src].size();
}

list<int> Graph::neighbors(int src) const {
    if (src < 0 || src >= adj.size()) throw std::runtime_error("Src invalido");
    list<int> result;
    for (auto [dst, w] : adj[src]) {
        result.push_back(dst);
    }
    return result;
}

int Graph::weight(int src, int dst) const {
    if (src < 0 || src >= adj.size()) throw std::runtime_error("Src invalido");
    if (dst < 0 || dst >= adj.size()) throw std::runtime_error("Dst invalido");
    for(auto [d, w] : adj[src]){
        if(d == dst) return w;
    }    
    throw std::runtime_error("Peso não localizado");
}

void Graph::print() {
	for (int i = 0; i < this->size(); i++) {
		int d = this->degree(i);
		cout << i << "(" << d << "): ";
		list<int> nei = this->neighbors(i);
		for (int dst : nei) {
			int w = this->weight(i, dst);
			cout << dst << "[" << w << "]; ";
		}
		cout << endl;
	}
}

bool Graph::isConnected() const {
    vector<int> groups(size());
    for (int i = 0; i < size(); i++) {
        groups[i] = i;
    }

    for (int u = 0; u < size(); u++) {
        for (auto [v, w] : adj[u]) {
            int groupU = groups[u];
            int groupV = groups[v];
            if (groupU != groupV) {
                for (int i = 0; i < size(); i++) {
                    if (groups[i] == groupV) groups[i] = groupU;
                }
            }
        }
    }

    int base = groups[0];
    for (int i = 1; i < size(); i++) {
        if (groups[i] != base) return false;
    }
    return true;
}

// -------- PRAT 09 --------------//

// Busca em profundidade
list<int> Graph::dfs(int src) {
    if (src < 0 || src >= adj.size())
        throw std::runtime_error("Src invalido");

    list<int> result;
    vector<bool> visited(adj.size(), false);

    DFS(src, visited, result);

    return result;
}

// Busca em profundidade
void Graph::DFS(int src, vector<bool> &visited, list<int> &result) {
    visited[src] = true;
    result.push_back(src);
    for (auto[dst, w] : adj[src]){
        if(visited[dst] == false) DFS(dst, visited, result);
    }
}

// Busca em largura
list<int> Graph::bfs(int src) {
    if (src < 0 || src >= adj.size())
        throw std::runtime_error("Src invalido");

    list<int> result;
    vector<bool> visited(adj.size(), false);

    BFS(src, visited, result);

    return result;
}

// Busca em largura
void Graph::BFS(int src, vector<bool> &visited, list<int> &result) {
    queue<int> fila;
    fila.push(src);
    visited[src] = true;
    auto atual = src;
    
    while(!fila.empty()){
        atual = fila.front();
        fila.pop();
        result.push_back(atual);
        
        for(auto[dst, w] : adj[atual]){
            if(visited[dst] == false){
                fila.push(dst);
                visited[dst] = true;
            }
        }
    }
}

bool Graph::has_cycle() const {
    for (int i = 0; i < adj.size(); i++) {
        if (has_cycle(i)) return true;
    }
    return false;
}

bool Graph::has_cycle(int src) const {
    if (src < 0 || src >= adj.size())
        throw std::runtime_error("Src invalido");

    vector<bool> visited(adj.size(), false);

    return has_cycle(src, visited);
}

bool Graph::has_cycle(int src, vector<bool> &visited) const { 
    auto atual = src; 
    if(visited[atual] == true) return true; 
    else { 
        visited[atual] = true; 
        for(auto [dst, w] : adj[atual]){ 
            if(has_cycle(dst, visited)) return true; 
        } 
        visited[atual] = false; 
    }
    return false; 
}

bool Graph::reacheable(int src, int dst) const {
    if (src < 0 || src >= adj.size())
        throw std::runtime_error("Src invalido");

    if (dst < 0 || dst >= adj.size())
        throw std::runtime_error("Dst invalido");

    vector<bool> visited(adj.size(), false);
    queue<int> fila;
    
    fila.push(src);
    visited[src] = true;
    
    while(!fila.empty()){
        int atual = fila.front();
        fila.pop();
        
        for(auto [d, w] : adj[atual]){
            if(d == dst) return true;
            else if(visited[d] == false){
                fila.push(d);
                visited[d] = true;
            }
        }
    }
    
    return false;
}

void Graph::dijkstra(int src, vector<int> &prev, vector<long> &dist) {
    // TODO Desafio
}

list<int> Graph::spf(int src, int dst) {
    if (src < 0 || src >= this->size())
        throw std::runtime_error("Src invalido");

    if (dst < 0 || dst >= this->size())
        throw std::runtime_error("Dst invalido");

	vector<int> prev(adj.size(), -1);     // vertices anteriores
    vector<long> dist(adj.size(), 99999); // distancias acumuladas; 99999 = INF

    dijkstra(src, prev, dist);

    list<int> result;						    // retorno menor caminho

    path(dst, prev, result);				// extrair caminho em result

    return result;
}

void Graph::path(int dst, const vector<int> &prev, list<int> &result) {
    if (dst < 0) return;
    path(prev[dst], prev, result);
    result.push_back(dst);
}