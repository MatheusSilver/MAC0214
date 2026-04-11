#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    int X;
    cin >> T >> X;
    T++;
    vector<int> Ai = vector(T, 0);

    for (int i = 0; i < T; i++){
        cin >> Ai[i];
    }
    int curRead = Ai[0];

    cout << 0 << " " << Ai[0] << endl;
    for (int i = 1; i < T; i++){
        if (abs(Ai[i]-curRead) >= X){
            curRead = Ai[i];
            cout << i << " " << Ai[i] << endl;
        }
    }
}