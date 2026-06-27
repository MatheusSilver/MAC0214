// Esse código foi feito pelo Cauê do MaratonUSP e cedido para uso na matéria de MAC0327 
// Contém diversas pré-definições úteis que podem auxiliar na escrita de código para uma série de problemas.

#include <bits/stdc++.h>
//^ biblioteca mais utilizada para programação competitiva
// irá conter todas as principais estruturas já construidas que iremos precisar

using namespace std;
// ^ Usamos para não precisar adicionar o namespace std:: antes das estruturas que utilizarmos

typedef long long ll;
// Um macro que nos permite apenas digitar ll ao invés de long long quando quisermos usar um inteiro 64 bits
// (aumenta a rapized e agilidade do código)

const int maxn = 200005;
// Deve ser alterada conforme o necessário
// Definimos o limite do maior valor de N que iremos encontrar durante o problema.
// Ao declararmos como const, garantimos ao compilador que esse valor não será alterado e ele nos permite
// Criar vetores globais com esse tamanho.

const int mod = 1e9+7;
// Deve ser alterada conforme o necessário
// Geralmente em problemas que usamos mod, deixamos essa constante salva e alteramos para o mod requisitado

const int inf = 0x3f3f3f3f;
// Pode ser alterado quando formos usar long long, para 0x3f3f3f3f3f3ff3f.
// Deixamos um valor de inf, que geralmente é apenas um inteiro maior do que qualquer outro que iremos usar no nosso programa,
// E é conveniente escolher um tal que 2*inf < MAXINT.
// No geral, eu uso essa repetição de 0x3f pois é um byte repetido e podemos facilmente preencher vetores com memset assim.


// Utilizo esse espaço em branco abaixo para declarar valores globais.
int a[maxn];


// Deixo uma função separado para simplificar casos teste.
void solve(){
    vector<vector<char>> dice(16, vector<char>(6));
    for (int j = 0; j < 6; j++) {
        for (int i = 0; i < 16; i++) {
            cin >> dice[i][j];
        }
    }
 
    vector<int> cost = {0, 1, 1, 1, 1, 2};
 
    vector<vector<int>> dp(16, vector<int>(6, INT_MAX));
    for (int j = 0; j < 6; j++) {
        dp[0][j] = cost[j];
    }
 
    for (int i = 1; i < 16; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                if (dice[i][j] < dice[i-1][k]) continue;
                if (dp[i-1][k] == INT_MAX) continue;
                dp[i][j] = min(dp[i][j], dp[i-1][k] + cost[j]);
            }
            if (dice[i][j] == 'Q') dice[i][j] = 'U';
        }
    }
 
    int ans = INT_MAX;
    for (int j = 0; j < 6; j++) {
        ans = min(ans, dp[15][j]);
    }
 
    if (ans == INT_MAX) cout << "impossible" << endl;
    else                cout << ans << endl;
}

int main(){
    // Essa linha serve para receber inputs mais rápido. Geralmente questões com muitos números no input irão dar TLE sem ela.
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    // Caso o problema tenha testes-caso, basta descomentar as linhas abaixo:

    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}