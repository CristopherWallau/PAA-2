#include <bits/stdc++.h>
using namespace std;
int subseqdec(vector<int>& a, int n) {
    int somalocal =0;
    int somaglobal =0;
    for (int i = n; i >= 2; i--) {
        if(a[i] >= a[i-1]){
            somalocal++;
        }
        else{
            somalocal = 0;
        }
        somaglobal = max(somaglobal, somalocal);
    }
    return somaglobal+1; // +1 para contar o elemento inicial da subsequência
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    a[0] = 0; // Para facilitar o acesso a partir de 1
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << subseqdec(a, n) << endl;
}