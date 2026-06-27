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
void solve() {
    int n;
    cin >> n;

    vector<array<int, 4>> v;
    v.reserve(n);

    for (int i = 0; i < n; i++) {
        int t, m, c;
        cin >> t >> m >> c;
        v.push_back({t, m, c, i + 1});
    }

    sort(v.begin(), v.end());

    vector<int> ans;
    deque<array<int, 3>> q;

    for (auto [t, m, c, idx] : v) {
        if (c == 0) {
            q.push_back({t, m, idx});
            continue;
        }

        while (!q.empty()) {
            auto [start, dur, cur_idx] = q.front();
            q.pop_front();

            int end = start + dur;
            if (end > t) {
                ans.push_back(cur_idx);
                break;
            }

            if (!q.empty()) {
                q.front()[0] = max(q.front()[0], end);
            }
        }

        q.push_front({t, m, idx});
    }

    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
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