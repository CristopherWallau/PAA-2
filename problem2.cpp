#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K, D;
    cin >> N >> K >> D;
    vector<int> flag_city[N];
    queue<int> q;
    int distance[N];
    bool visited[N];
    for(int i = 0; i < N; i++) {
        int value;
        cin >> value;
        if(flag_city[value-1].back() == 1) {
            continue;
        }
        flag_city[value-1].push_back(1);
    }
    vector<pair<int, int>> adj[N];
    for(int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back({v-1, i+1});
        adj[v-1].push_back({u-1, i+1});
    }
    queue<int> q;
    bool visited[N];
    int distance[N];
    for(int i = 0; i < N-1; i++) {
        q.push(i+1);
        visited[i+1] = false;
    }
    visited[0] = true;
    distance[0] = 0;
    while(!q.empty()) {
        int city = q.front();
        q.pop();
        for(auto i : adj[city-1]) {
            if(!visited[i.first]) {
                visited[i.first] = true;
                distance[i.first] = distance[city-1] + 1;
                q.push(i.first);
            }
        }
    }
    int edges = 0;
    if(distance[0] > D) {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < N; i++) {
        if(flag_city[i].back() == 1) {
            edges = max(edges, distance[i]);
        }
    }
    cout << edges << endl;
}