#include <bits/stdc++.h>
using namespace std;
int binary_search(int a, vector<pair<int,int>> &q2){
    int left = 0, right = q2.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (q2[mid].first >= a) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left; // Retorna o índice da menor mesa que pode acomodar o visitante
}
int main() {
    int visitors,size,money,tables,table_size;
    int soma=0;
    int total_mesas = 0;
    cin >> visitors;
    priority_queue<pair<pair<int, int>,int>> q; // max-heap para armazenar os visitantes por dinheiro
    vector<pair<int,int>> q2;
    vector<pair<int, int>> resposta; // vetor de adjacências para armazenar as mesas alocadas para cada visitante
    for(int i = 0; i < visitors;i++){
        cin >> size >> money; 
        q.push({{money, size}, i+1});
    }
    cin >> tables;
    for(int i = 0; i < tables; i++){
        cin >> table_size;
        q2.push_back({table_size, i+1});    
    }
    sort(q2.begin(), q2.end()); // ordena as mesas por tamanho
    while(!q.empty() && !q2.empty()) { // enquanto houver visitantes e mesas disponíveis
            int a = q.top().first.second;
            int b = q2.back().first; // pega o visitante mais rico e a menor mesa disponível
            int c = binary_search(a, q2);
            if(c == q2.size()) { // se não houver mesa que possa acomodar o visitante, pula para o próximo visitante
                q.pop();
                continue;
            }
            resposta.push_back({q.top().second, q2[c].second}); // aloca a mesa para o visitante
            soma += q.top().first.first; // acumula o dinheiro do visitante alocado
            total_mesas++; // incrementa o número de mesas alocadas
            q.pop(); // remove o visitante alocado da fila
            q2.erase(q2.begin() + c); // remove a mesa alocada da lista de mesas disponíve
    }
    cout << total_mesas << " " << soma << "\n";
    for(auto u: resposta){ // para cada visitante, imprime as mesas alocadas
        cout << u.first << " " << u.second << "\n";
    }
}