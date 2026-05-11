#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K, D;
    cin >> N >> K >> D;

    queue<int> q;  
    vector<int> distance(N+1, -1); 
    vector<int> owner(N+1); 
    vector<pair<int, int>> edges; 
    for(int i = 0; i < K; i++) {
        int value;
        cin >> value;  
        q.push(value);
        distance[value] = 0;
        owner[value] = value;
    }
    vector<vector<int>> adj(N+1); 
    for(int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); 
        adj[v].push_back(u); 

        edges.push_back({u, v}); 
    }
    while(!q.empty()) {
        int city = q.front();
        q.pop();
        for(auto i : adj[city]) {
            if(distance[i] != -1) continue;
             
            owner[i] = owner[city];
            distance[i] = distance[city] + 1; 
            
            q.push(i); 
            
        }
    }
    vector<int> roadsToShutdown;
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        if(owner[u] != owner[v]) { 
            roadsToShutdown.push_back(i+1); 
        }
    }
    cout << roadsToShutdown.size() << endl;
    for(int road : roadsToShutdown) {
        cout << road << " ";
    }
    cout << endl;
}