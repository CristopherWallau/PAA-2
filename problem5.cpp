#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> adj[n+1];
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    const int INF = 1e9;
    vector<int> distance(n+1, INF);
    vector<bool> processed(n+1, false);
    priority_queue<pair<int,int>> q;

        for (int i = 1; i <= n; i++) distance[i] = INF;

    distance[x] = 0;
    q.push({0,x});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
            if (processed[a]) continue;
        processed[a] = true;
            for (auto u : adj[a]) {
                int b = u.first, w = u.second;
                    if (distance[a]+w < distance[b]) 
                    {
                        distance[b] = distance[a]+w;
                        q.push({-distance[b],b});
                    }
        }
    }
}