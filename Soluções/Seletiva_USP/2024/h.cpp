#include <bits/stdc++.h>
//^ biblioteca mais utilizada para programação competitiva
// irá conter todas as principais estruturas já construidas que iremos precisar

using namespace std;
// ^ Usamos para não precisar adicionar o namespace std:: antes das estruturas que utilizarmos

typedef long long ll;
typedef priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> minheap;
typedef pair<ll, pair<ll, ll>> vertexUnit;
// Um macro que nos permite apenas digitar ll ao invés de long long quando quisermos usar um inteiro 64 bits
// (aumenta a rapized e agilidade do código)

const int maxn = 200005;
// Deve ser alterada conforme o necessário
// Definimos o limite do maior valor de n que iremos encontrar durante o problema.
// Ao declararmos como const, garantimos ao compilador que esse valor não será alterado e ele nos permite
// Criar vetores globais com esse tamanho.

const int mod = 1e9+7;
// Deve ser alterada conforme o necessário
// Geralmente em problemas que usamos mod, deixamos essa constante salva e alteramos para o mod requisitado

const ll inf = 0x3f3f3f3f3f3f3f;
// Pode ser alterado quando formos usar long long, para 0x3f3f3f3f3f3f3f.
// Deixamos um valor de inf, que geralmente é apenas um inteiro maior do que qualquer outro que iremos usar no nosso programa,
// E é conveniente escolher um tal que 2*inf < MAXINT.
// No geral, eu uso essa repetição de 0x3f pois é um byte repetido e podemos facilmente preencher vetores com memset assim.


// Utilizo esse espaço em branco abaixo para declarar valores globais.
ll n, m, t;
vector<pair<ll, ll>> adj[maxn];
vector<vertexUnit> str[maxn];

void djCastro(){
    vector<ll> dist(n + 5, inf); vector<bool> vis(n + 5, false); minheap heap;
    dist[1] = t; heap.emplace(t, 1);
    ll d, u, x, y, v, rt, nd;
    /* Tentativa um pouco melhor de tentar aproximar o djCastro pseudocódigo do Mota. */
    while (!heap.empty()) {
        tie(d, u) = heap.top(); heap.pop();
        if (vis[u]) continue; else if (u == n){ cout << dist[n]; exit(0); } else vis[u] = true;
        for (vertexUnit vp : str[u]) {
            v = vp.first; tie(x, y) = vp.second;
            rt = d % (x + y); nd = d + (rt < x ? 0 : (x + y - rt));
            nd < dist[v] ? (dist[v] = nd, heap.emplace(nd, v)) : void();
        }
    }
}

// Deixo uma função separado para simplificar casos teste.
void solve(){
    cin >> n >> m >> t;
    for (ll i = 1; i <= n; i++) str[i].clear();
    for (ll i = 0; i < m; i++) {
        ll a, b, x, y;  cin >> a >> b >> x >> y;
        str[a].emplace_back(b, make_pair(x, y));
        str[b].emplace_back(a, make_pair(x, y));
    }
    djCastro();
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