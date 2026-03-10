#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K, D;
    cin >> N >> K >> D;
    vector<int> flag_city[K];
    for(int i = 0; i < K; i++) {
        int value;
        cin >> value;
        if(flag_city[value-1].back == 1) {
            continue;
        }
        flag_city[value-1].push_back(1);
    }
    vector<int> adj[N];
    for(int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
}