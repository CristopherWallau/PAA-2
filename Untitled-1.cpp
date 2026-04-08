#include <bits/stdc++.h>
using namespace std;

// Função para encontrar a soma máxima que cruza o ponto médio
int maxCrossingSum(const vector<int>& v, int l, int mid, int r) {
    // 1. Expande do meio para a esquerda
    int sum = 0;
    int left_sum = INT_MIN; // Inicializa com o menor inteiro possível
    for (int i = mid; i >= l; i--) {
        sum += v[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    // 2. Expande do meio para a direita
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = mid + 1; i <= r; i++) {
        sum += v[i];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    // Retorna a soma das duas metades
    return left_sum + right_sum;
}


// Função recursiva de Divisão e Conquista
int maxSubArraySum(const vector<int>& v, int l, int r) {
    // Caso Base: O vetor tem apenas 1 elemento
    if (l == r) {
        return v[l];
    }

    // Encontra o ponto médio para dividir o vetor
    int mid = l + (r - l) / 2;

    // Conquista: Calcula os 3 casos possíveis
    // Caso 1: A soma máxima está totalmente na esquerda
    int max_left = maxSubArraySum(v, l, mid);
    
    // Caso 2: A soma máxima está totalmente na direita
    int max_right = maxSubArraySum(v, mid + 1, r);
    
    // Caso 3: A soma máxima cruza o ponto médio
    int max_cross = maxCrossingSum(v, l, mid, r);

    // Combina: Retorna o maior entre os três cenários
    return max(max(max_left, max_right), max_cross);
}

int main() {
    // Testando o Exemplo 1 do slide
    vector<int> A1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n1 = A1.size();
    int resultado1 = maxSubArraySum(A1, 0, n1 - 1);
    cout << "Exemplo 1: " << resultado1 << endl; // Deve imprimir 6

    // Testando o Exemplo 2 do slide
    vector<int> A2 = {-5, -2, -7, -1};
    int n2 = A2.size();
    int resultado2 = maxSubArraySum(A2, 0, n2 - 1);
    cout << "Exemplo 2: " << resultado2 << endl; // Deve imprimir -1

    return 0;
}