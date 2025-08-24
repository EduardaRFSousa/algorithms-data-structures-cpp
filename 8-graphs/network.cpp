#include "graph.h"

vector<int> overloaded(Graph capacity, Graph traffic) {
    vector<int> over;
    int size = capacity.size();
    
    vector<int> trafficSum(size, 0);
    vector <int> capacitySum(size, 0);
    
    for(int src = 0; src < size; src++){
        for (int dst : traffic.neighbors(src)){
            int num = traffic.weight(src, dst);
            trafficSum[dst] += num;
        }
    }
    
    for(int src = 0; src < size; src++){
        for (int dst : capacity.neighbors(src)){
            int num = capacity.weight(src, dst);
            capacitySum[src] += num;
        }
    }
    
    for(int src = 0; src < size; src++){
        if(trafficSum[src] > capacitySum[src]){
            over.push_back(src);
        }
    }
    
    return over;
}

int main() {
    // Grafo de capacidade da rede
    Graph capacity(6);
    capacity.edge(0, 1, 10);
    capacity.edge(0, 2, 5);
    capacity.edge(1, 2, 3);
    capacity.edge(1, 3, 3);
    capacity.edge(2, 4, 3);
    capacity.edge(4, 3, 4);
    capacity.edge(3, 5, 12);
    capacity.edge(5, 4, 8);

    // Grafo de trafego atual da rede
    Graph traffic(6);
    traffic.edge(0, 1, 7);
    traffic.edge(0, 2, 2);
    traffic.edge(1, 2, 3);
    traffic.edge(1, 3, 2);
    traffic.edge(2, 4, 3);
    traffic.edge(4, 3, 4);
    traffic.edge(3, 5, 8);
    traffic.edge(5, 4, 8);
    

    auto over = overloaded(capacity, traffic);

    cout << "Sobrecarregados: "; // 1 2 4
    for (int i : over) cout << i << " ";
    cout << endl;

    return 0;
}