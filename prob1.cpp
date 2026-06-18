#include <bits/stdc++.h>
using namespace std;
int primeira_ocorrencia(vector<int>& v, int X) {
    int low = 0;
    int high = v.size() - 1;
    int ans = -1; // Guarda a melhor resposta encontrada até agora

    while (low <= high) {
        int mid = low + (high - low) / 2; // Evita overflow de int

        if (v[mid] >= X) {
            if (v[mid] == X) ans = mid; // Achou X! Mas será que não tem outro antes dele?
            high = mid - 1; // Continua procurando na metade esquerda
        } else {
            low = mid + 1;  // v[mid] é menor que X, olha para a direita
        }
    }
    return ans;
}
int last_ocurrence(int first_occurrence, vector<int>& v, int X) {
    if (first_occurrence == -1) return -1; // X não encontrado
    int low = first_occurrence;
    int high = v.size() - 1;
    int ans = -1; // Guarda a melhor resposta encontrada até agora

    while (low <= high) {
        int mid = low + (high - low) / 2; // Evita overflow de int

        if (v[mid] == X) {
            ans = mid; // Achou X! Mas será que não tem outro depois dele?
            low = mid + 1; // Continua procurando na metade direita
        } else {
            high = mid - 1;  // v[mid] é maior que X, olha para a esquerda
        }
    }
    return ans;
}
int main(void){
    int n;
    cin >> n;
    vector<int> v(n+1);
    v[0] = 0; // Inicializa o primeiro elemento como 0
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int X;
    cin >> X;
    int first_occurrence = primeira_ocorrencia(v, X);
    int ans = last_ocurrence(first_occurrence, v, X);
    cout << ans-first_occurrence+1 << endl;    
}