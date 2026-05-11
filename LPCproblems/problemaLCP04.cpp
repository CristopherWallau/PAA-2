#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string a, b;

    while (cin >> a >> b) {
        
        int dp[a.size() + 1][b.size() + 1];
        
        for (int i = 0; i <= a.size(); i++){
            for (int j = 0; j <= b.size(); j++){
                if (i == 0) {
                    dp[i][j] = j; // Se 'a' é vazia, preciso de todas as 'j' letras de 'b'
                }
                else if (j == 0) {
                    dp[i][j] = i; // Se 'b' é vazia, preciso de todas as 'i' letras de 'a'
                }
           
                else if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            
                else {
                    // Adicionamos a letra atual de 'a' ou a de 'b', o que tiver menor caminho.
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        
        cout << dp[a.size()][b.size()] << "\n";
    }
    
    return 0;
}