#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
// Estrutura da Fenwick Tree (Binary Indexed Tree)
struct BIT {
    int size;
    vector<int> tree;
    
    BIT(int n) {
        size = n;
        tree.assign(n + 1, 0);
    }
    
    void update(int idx, int val) {
        for (; idx <= size; idx += idx & -idx) {
            tree[idx] += val;
        }
    }
    
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }
};
 
int main() {
    // Otimização de I/O para evitar TLE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> pref(n), suf(n);
    map<int, int> count_pref, count_suf;
    
    // Passo 1: Calcular frequências dos prefixos f(1, i, a_i)
    for (int i = 0; i < n; i++) {
        count_pref[a[i]]++;
        pref[i] = count_pref[a[i]];
    }
    
    // Passo 2: Calcular frequências dos sufixos f(j, n, a_j)
    for (int j = n - 1; j >= 0; j--) {
        count_suf[a[j]]++;
        suf[j] = count_suf[a[j]];
    }
    
    // A maior frequência possível é N
    BIT bit(n);
    long long total_pairs = 0;
    
    // Passo 3: Varrer da direita para a esquerda usando a BIT
    // Como i < j, processamos de trás para frente adicionando os sufixos
    for (int i = n - 1; i >= 0; i--) {
        // Queremos saber quantos elementos já inseridos na BIT são menores que pref[i]
        total_pairs += bit.query(pref[i] - 1);
        
        // Agora inserimos o sufixo atual para os próximos elementos à esquerda usarem
        bit.update(suf[i], 1);
    }
    
    cout << total_pairs << "\n";
    
    return 0;
}