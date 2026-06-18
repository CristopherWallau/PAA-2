#include <bits/stdc++.h>
using namespace std;
struct tower{
    int pos;
    int pow;
};
int dp(vector<tower>& t, int n) {
    vector<int> reach(n + 1, 0); 
    
    vector<int> posicoes(n + 1);
    for (int i = 1; i <= n; i++) {
        posicoes[i] = t[i].pos;
    }
    int max_sobreviventes = 0;

    for (int i = 1; i <= n; i++) {
        int limite_raio = t[i].pos - t[i].pow;

        auto it = lower_bound(posicoes.begin() + 1, posicoes.end(), limite_raio);
        
        int idx = distance(posicoes.begin(), it);

        int sobrevivente_idx = idx - 1;

        if (sobrevivente_idx >= 1) {
            reach[i] = reach[sobrevivente_idx] + 1;
        } else {
            reach[i] = 1;
        }

        max_sobreviventes = max(max_sobreviventes, reach[i]);
    }

    return n - max_sobreviventes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<tower> t(n + 1);
    t[0] = {-1, 0}; 
    for (int i = 1; i <= n; i++) {
        cin >> t[i].pos >> t[i].pow;
    }

    sort(t.begin() + 1, t.end(), [](const tower& a, const tower& b) {
        return a.pos < b.pos;
    });

    int res = dp(t, n);
    cout << res << "\n";

    return 0;
}