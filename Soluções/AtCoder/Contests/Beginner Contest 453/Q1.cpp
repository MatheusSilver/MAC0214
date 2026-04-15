#include <bits/stdc++.h>
using namespace std;

// Essa questão foi mais dificil de entender do que de fazer em si.


int main(){
    string S;
    int N, o = 0;
    cin >> N;
    cin >> S;
    int i = 0;
    while (i < S.size() && S[i] == 'o') i++;

    for (; i < S.size(); i++){
        cout << S[i];
    }
}