#include <bits/stdc++.h>
using namespace std;

int BuscaBinaria(vector<int>& A, int i, int j, int x)
{
    if (i > j)
    {
        return -1;
    }
    
    int m = (i + j) / 2;
    
    if (A[m] <= x)
    {
        int r = BuscaBinaria(A, m + 1, j, x);
        if (r != -1)
        {
            return r;
        }
        return m;
    }
    else
    {
        return BuscaBinaria(A, i, m - 1, x);
    }
}

int main()
{
    int tam_a;
    int tam_b;
    int idx;

    vector<int> a;
    
    cin >> tam_a;
    cin >> tam_b;

    int entrada;

    for (int i = 0; i < tam_a; i++)
    {
        cin >> entrada;
        a.push_back(entrada);
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < tam_b; i++)
    {
        cin >> entrada;
        idx = BuscaBinaria(a, 0, a.size() - 1, entrada);
        cout << (idx + 1) << " ";
    }
    
    return 0; 
}