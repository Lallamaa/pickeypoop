#include <bits/stdc++.h>
using namespace std;

vector <int> graph[1000];

int main() {
    int n, m, r, ts, td;
    vector <int> tn; //init vector
    scanf("%d", &n); //input the num of city
    while(n--) {
        scanf("%d %d", &m, &r); //input the m (num of road endpoints) & r pairs of endpoints
        int discovered[m]; //init the array of road (city)
        memset(discovered, 0, sizeof(discovered)); //set it all as 0
        for(int i = 0; i < r; i++) {
            scanf("%d %d", &ts, &td); //input each pair of roads, ts (start road), td(end road)
            graph[ts].push_back(td);
            graph[td].push_back(ts); 
        }
        int id = 0, addedRoad = 0, temp;
        while(id < m) {
            if(discovered[id] == 1)
                id++;
            else{
                stack <int> stackRoad;
                stackRoad.push(id); //id
                while(stackRoad.size() > 0) {
                    temp = stackRoad.top(); //0
                    stackRoad.pop(); //clear
                    if(discovered[temp] == 0){
                        discovered[temp]++;
                    }
                    tn = graph[temp];
                    for(int i = 0; i < tn.size(); i++) {
                        if(discovered[tn[i]] == 0){
                            stackRoad.push(tn[i]); //push in the td according to the ts 
                        }
                    }
                }
                addedRoad++;
            }
        }
        printf("%d\n",addedRoad-1); //print out the added road needed
        //clear graph & temporary neighbor
        for(int i = 0; i < 1000; i++) {
            graph[i].clear(); 
            if(i == 0)
                tn.clear();   
        }
    }
    return 0;
}