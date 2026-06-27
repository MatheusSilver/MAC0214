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
vector<ll> X, Y;

ll happy(int i, char w, const string &S) { return S[i] == w ? 0 : -X[i]; }


// Deixo uma função separado para simplificar casos teste.
void solve(){
    int N;
    string S;

    cin >> N;
    cin >> S;

    X.assign(N, 0);
    for (int i = 0; i < N; i++) cin >> X[i];
    
    Y.assign(N - 1, 0);
    for (int i = 0; i < N - 1; i++) cin >> Y[i];
    
    ll sunny = happy(0, 'S', S);
    ll rainy = happy(0, 'R', S);

    for (int i = 1; i < N; i++) {
        ll curSun = happy(i, 'S', S);
        ll curRain = happy(i, 'R', S);

        ll nextSunny = max(sunny + curSun, rainy + Y[i - 1] + curSun);
        ll nextRainy = max(sunny + curRain, rainy + curRain);

        sunny = nextSunny;
        rainy = nextRainy;
    }

    cout << max(sunny, rainy) << '\n';
}

int main(){
    // Essa linha serve para receber inputs mais rápido. Geralmente questões com muitos números no input irão dar TLE sem ela.
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    // Caso o problema tenha testes-caso, basta descomentar as linhas abaixo:

    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}