#include <bits/stdc++.h>
using namespace std;

bool desigualdade_triangular(vector<vector<long long>> custo,long long a, long long b, long long c){
    return custo[a][b] + custo[b][c] < custo[a][c];
}

int main() {
    int n;
    cin >> n;
    vector<vector<long long>> custo(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) cin >> custo[i][j];

    for (int a = 0; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
            for (int c = b + 1; c < n; c++) {
                if (desigualdade_triangular(custo, a, b, c)) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}