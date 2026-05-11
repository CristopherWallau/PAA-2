#include <bits/stdc++.h>
using namespace std;

int main() {
    // Otimização para leitura de dados no C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int val_lanche, num_moedas;
    
    // Lê enquanto não for 0 0
    while (cin >> val_lanche >> num_moedas && (val_lanche != 0 || num_moedas != 0)) {
        
        vector<int> moedas(num_moedas);
        for (int i = 0; i < num_moedas; i++) {
            cin >> moedas[i];
        }
        vector<bool> dp(val_lanche + 1, false);
        dp[0] = true; // Base: é sempre possível somar 0
        
        for (int i = 0; i < num_moedas; i++) {
            // Percorre de trás pra frente (para não usar a mesma moeda 2 vezes)
            for (int j = val_lanche; j >= moedas[i]; j--) {
                if (dp[j - moedas[i]]) {
                    dp[j] = true;
                }
            }
        }
        
        // Apenas imprime sim ou nao
        if (dp[val_lanche]) {
            cout << "sim\n";
        } else {
            cout << "nao\n";
        }
    }
    
    return 0;
}