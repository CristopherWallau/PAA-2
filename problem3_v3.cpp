#include <bits/stdc++.h>
using namespace std;
int func(vector<int> &f, int left, int right){
    int result = 0;
    if (left >= right) {
        return 0; // Custo zero para pintar um pedaço de tamanho zero
    }
    int menor_valor = *min_element(f.begin() + left, f.begin() + right); // 2 2 1 2 2 -> 1 
    result = menor_valor; 
    for(int i = left; i < right; i++){
        f[i] = f[i] - menor_valor;
    }
    int new_left = left;
    for(int i = left; i <= right; i++){
    if(i == right || f[i] == 0){
           if(new_left < i){  // Verifica se há um segmento válido para pintar
                result += func(f, new_left, i); // Chama recursivamente para o segmento atual
            }
            new_left = i + 1; // Atualiza o início do próximo segmento
        }
    }
    return min(result, (right-left));
}   
int main(void){
    int n = 0;
    cin >> n;
    int left = 0;
    vector<int> f(n);
    for(int i = 0; i < n; i++){
        cin >> f[i];
    }
    int result = func(f,left,f.size());
    cout << result << endl;
    return 0;
}