#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    long long vida = 0;
    long long qtdpot = 0;
    cin >> n;
    priority_queue<long long,vector<long long>,greater<long long>> q;
    for (long long i = 0; i < n; i++) {
            long long x;
            cin >> x;
            q.push(x);
            vida += x;
            if(vida < 0){
                vida = vida - q.top();
                q.pop();
            }
    }
    qtdpot = q.size();
    cout << qtdpot << endl;
    return 0;
}