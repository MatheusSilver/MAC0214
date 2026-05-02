#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> A(3, vector<int>(7, 0));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            int x; cin >> x;
            A[i][x]++;
        }
    }

    // Não vou negar, estava com preguiça de escrever o coiso de baixo então só confiei no auto complete do copilot k
    int ans =
        A[0][4]*A[1][5]*A[2][6] +
        A[0][4]*A[1][6]*A[2][5] +
        A[0][5]*A[1][4]*A[2][6] +
        A[0][5]*A[1][6]*A[2][4] +
        A[0][6]*A[1][4]*A[2][5] +
        A[0][6]*A[1][5]*A[2][4];

    cout << fixed << setprecision(8) << ans / 216.0;
}