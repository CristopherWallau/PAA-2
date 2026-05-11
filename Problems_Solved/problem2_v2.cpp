#include <bits/stdc++.h>
using namespace std;
int soma(int n, int k){
    int sum = n;
    for(int i=1; i<=n; i++){
        sum = sum + (n/pow(k,i)); 
        if(n/pow(k,i) == 0){
            break;
        }
    }
    return sum;
}
int main(void){
    int n =0,k = 0;
    cin >> n >> k;
    int low = 1;
    int temp = 0;
    int mid = 0;
    int high = n;
    int sum = 0;
    int answer = 0;
    for(int i=0; low <= high; i++){    
        mid = (low + high) / 2;
        sum = soma(mid,k);
        if(sum >= n){
            answer = mid;
            high = mid - 1;
        }
        else if(sum < n){
            low = mid + 1;
        }
    }
    cout << answer << endl;    
    return 0;
}
