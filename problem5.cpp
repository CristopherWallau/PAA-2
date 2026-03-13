    #include <bits/stdc++.h>
    using namespace std;
    int main() {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int,int>>> adj(n+1);
        for (int i = 0; i < m; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }
        const long long INF = 1e16;
        vector<long long> distance(n+1, INF);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q; 
        vector<long long> parent(n+1, -1); 

        distance[1] = 0;
        q.push({0,1});

        while (!q.empty()) {
            long long d= q.top().first; 
            long long a = q.top().second;
            q.pop();
            if(d > distance[a]) continue;
                for (auto u : adj[a]) { 
                    long long b = u.first;
                    long long w = u.second; 
                        if (distance[a]+w < distance[b]) 
                        {
                            distance[b] = distance[a]+w; 
                            parent[b] = a;
                            q.push({distance[b],b}); 
                            
                        }
            }
        }
        if(distance[n] == INF) {
            cout << -1 << "\n"; 
        } else {
            vector<int> path; 
            for (int i = n; i != -1; i = parent[i]) { 
                path.push_back(i); 
            }
            reverse(path.begin(), path.end()); 
            for (int i = 0; i < path.size(); i++) { 
                cout << path[i] << " ";
            }
            cout << "\n";
        }
    }