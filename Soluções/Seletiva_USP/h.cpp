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
    int n; int m;
    cin >> n >> m;
    vector<int> dist(n+1, INT_MAX);
    vector<int> parent(n+1, INT_MAX);
    vector<vector<int>> adj(n+1, vector<int>());
    pair<int, int> p;
    
    for (int i=0;i<m;i++){
        int u; int v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> s;
    vector<bool> visited(n+1, false);

    s.push(1);
    dist[1] = 1;
    parent[1] = 1;

    int minimum = INT_MAX;

    while (!s.empty()){
        int v = s.front();
        s.pop();

        if (visited[v]) continue;
        visited[v] = true;

        if (parent[v] != v) dist[v] = dist[parent[v]]+1;

        for (int u : adj[v]){
            if (u == parent[v]) continue;
            if (visited[u]){
                if (dist[v] + dist[u] < minimum) p = {u, v};
                minimum = min(minimum, dist[v] + dist[u]);
            } else {
                parent[u] = v;
                s.push(u);
            }
        }
    }

    if (minimum == INT_MAX) cout << "impossible";
    else {
        cout << minimum << endl;

        int u = p.first;
        int v = p.second;

        vector<int> a;

        while (parent[v] != v){
            a.push_back(v);
            v = parent[v];
        }
        a.push_back(1);

        vector<int> b;

        while (parent[u] != u){
            b.push_back(u);
            u = parent[u];
        }

        b.push_back(1);

        for (int i=a.size()-1;i>=0;i--){
            cout << a[i] << " ";
        }

        for (int i=0;i<b.size();i++){
            cout << b[i] << " ";
        }
    }
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