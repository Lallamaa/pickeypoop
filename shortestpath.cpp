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
    int n,m,qq,s,u,v,w;
    edge e,f;
    while (scanf("%d%d%d%d",&n,&m,&qq,&s) && n){
        vector <edge> adjlist[n];
        for (int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            adjlist[u].push_back(edge(v,w));
        }
        // Dijkstra's Algorithm
        vector <int> dist = vector<int>(n+1,INF);
        priority_queue <edge> q;
        q.push(edge(s,0));
        dist[s] = 0;
        while(!q.empty()){
            edge top = q.top(); 
            q.pop();
            int u = top.to;
            for(int i=0;i<adjlist[u].size();i++){
                int v = adjlist[u][i].to;
                if(dist[u] + adjlist[u][i].weight < dist[v]){
                    dist[v] = dist[u] + adjlist[u][i].weight;
                    q.push(edge(v,dist[v]));
                }
            }
        }
        for (int i=0;i<qq;i++){
            scanf("%d",&u);
            if (dist[u] == INF) 
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
