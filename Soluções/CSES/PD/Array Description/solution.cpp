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
    ll n, m;
    cin >> n >> m;

    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<ll> prev(m + 2, 0), cur(m + 2, 0);

    if (v[0] == 0) {
        for (ll x = 1; x <= m; x++) {
            prev[x] = 1;
        }
    } else {
        prev[v[0]] = 1;
    }

    for (ll i = 1; i < n; i++) {
        if (v[i] == 0) {
            for (ll x = 1; x <= m; x++) {
                cur[x] = (prev[x - 1] + prev[x] + prev[x + 1]) % mod;
            }
        } else {
            ll x = v[i];
            cur[x] = (prev[x - 1] + prev[x] + prev[x + 1]) % mod;
        }

        prev.swap(cur);
        fill(cur.begin(), cur.end(), 0);
    }

    ll ans = 0;
    if (v[n - 1] == 0) {
        for (ll x = 1; x <= m; x++) {
            ans = (ans + prev[x]) % mod;
        }
    } else {
        ans = prev[v[n - 1]];
    }

    cout << ans << '\n';
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