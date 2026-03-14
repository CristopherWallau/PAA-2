#include <bits/stdc++.h>
using namespace std;
bool visited[205];
vector<int> adj[205];

   void dfs(int s) {  
      if(visited[s]) return;
      visited[s] = true;
      for(int u: adj[s]){
      dfs(u);
      }
   }

int main(void){
      int n, l;
      bool algum_sabe = false;
      int k;
      cin >> n >> l;
      int c = 0;
      for (int i = 1; i <= n; i++) {
         cin >> k;
         if(k>0) algum_sabe = true;
         for(int j=0; j<k;j++){
               int a;
               cin >> a;
               a = a+100; 
               adj[i].push_back(a);
               adj[a].push_back(i);           
         }  
      }
      for(int i=1; i<=n; i++){
         if(!visited[i]){
            dfs(i);
            c++;
         }
      }
      if(!algum_sabe) cout << n << "\n";
      else
      cout <<c-1<< "\n";
   }