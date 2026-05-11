#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> musicas;

// Matriz 4D para a Programação Dinâmica (Memoization)
// Limites: 105 músicas, e até 55 de capacidade para os 3 cartuchos possíveis
int memo[105][55][55][55];

// Função recursiva com DP
int dp(int idx, int c1, int c2, int c3) {
    // Caso base: acabaram as músicas
    if (idx == n) return 0;
    
    // Se já calculamos essa exata combinação antes, retorna a resposta salva! (Isso evita o TLE)
    if (memo[idx][c1][c2][c3] != -1) return memo[idx][c1][c2][c3];

    // Opção 1: Pular a música atual e não colocar em nenhum cartucho
    int ans = dp(idx + 1, c1, c2, c3);

    // Opção 2: Tentar colocar no Cartucho 1 (se couber)
    if (c1 >= musicas[idx]) {
        ans = max(ans, musicas[idx] + dp(idx + 1, c1 - musicas[idx], c2, c3));
    }
    
    // Opção 3: Tentar colocar no Cartucho 2 (se couber)
    if (c2 >= musicas[idx]) {
        ans = max(ans, musicas[idx] + dp(idx + 1, c1, c2 - musicas[idx], c3));
    }
    
    // Opção 4: Tentar colocar no Cartucho 3 (se couber)
    if (c3 >= musicas[idx]) {
        ans = max(ans, musicas[idx] + dp(idx + 1, c1, c2, c3 - musicas[idx]));
    }
    
    memo[idx][c1][c2][c3] = ans; 
    return ans;                 
}

int main() {
    // Otimização para leitura de dados no C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> k)) return 0;

    musicas.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> musicas[i];
    }

    // Inicializa as capacidades dos cartuchos como 0
    int cap[3] = {0, 0, 0}; 
    for (int i = 0; i < k; i++) {
        cin >> cap[i];
    }

    // Preenche a matriz de memoization com -1 (indicando que nada foi calculado ainda)
    memset(memo, -1, sizeof(memo));

    // Chama a DP passando a capacidade inicial de cada cartucho
    // Se o k for menor que 3, as capacidades dos cartuchos inexistentes continuarão como 0
    cout << dp(0, cap[0], cap[1], cap[2]) << "\n";

    return 0;
}