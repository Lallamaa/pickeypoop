#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 20000000

struct edge{
    int to, weight;
    edge(){}
    edge(int tto, int wweight){
        to = tto;
        weight = wweight;
    }
    bool operator < (edge e) const {
        return weight > e.weight;
    }
};

int main(){
    int n, m, qq, s, u, v, w;
    //input n(num of nodes) m(num of edges) q(num of queries) s(index of start node)
    while (scanf("%d%d%d%d", &n, &m, &qq, &s) && n) { 
        vector <edge> adjlist[n];
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w); //input edges, u & v with the weight, w
            adjlist[u].push_back(edge(v,w)); //insert the edge, v and weight, w into the vector
        }
        // Dijkstra's Algorithm
        vector <int> dist = vector <int> (n+1, INF); 
        priority_queue <edge> q;
        q.push(edge(s,0)); //push the start node with the weight, w 0
        dist[s] = 0;
        while(!q.empty()) {
            edge top = q.top(); 
            q.pop();
            int u = top.to;
            for(int i = 0; i < adjlist[u].size(); i++) {
                int v = adjlist[u][i].to;
                if(dist[u] + adjlist[u][i].weight < dist[v]) {
                    dist[v] = dist[u] + adjlist[u][i].weight; //add the weight up from edge u to i
                    q.push(edge(v,dist[v]));
                }
            }
        }

        for (int i = 0; i < qq; i++) {
            scanf("%d", &u); //insert the edge
            if (dist[u] == INF)  //no path from starting node
                cout << "Impossible\n";
            else{
                cout << dist[u];
                cout << "\n";
            }  
        }
        cout << "\n";
    }
    return 0;
}
