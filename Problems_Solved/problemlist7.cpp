#include <bits/stdc++.h>
using namespace std;
int main(void){
int val = 0; 
int n = 0;
cin >> n;
vector<int> A(n);
for(int i = 0; i < n; i++){
    cin >> A[i];
}
for (int i =0; i<n; i++){
if (A[i] == A[i-1] || A[i] == A[i+1])
	continue;
  val = A[i];
  break;
}
cout << val << endl;
}
