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
int quantidade_vertices, quantidade_arestas;
vector<vector<pair<int, int>>> grafo;
vector<ll> distancia;
vector<int> pai;

void ler_arestas_dijkstra() {
    grafo.assign(quantidade_vertices + 1, vector<pair<int, int>>());
    for (int i = 0; i < quantidade_arestas; i++) {
        int origem, destino, peso;
        cin >> origem >> destino >> peso;
        grafo[origem].push_back(make_pair(destino, peso));
        grafo[destino].push_back(make_pair(origem, peso));
    }
}

void executar_dijkstra() {
    ll infinito = (ll)4e18;
    distancia.assign(quantidade_vertices + 1, infinito);
    pai.assign(quantidade_vertices + 1, -1);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> fila_prioridade;
    distancia[1] = 0;
    pai[1] = 1;
    fila_prioridade.push(make_pair(0, 1));

    while (!fila_prioridade.empty()) {
        pair<ll, int> topo = fila_prioridade.top();
        fila_prioridade.pop();

        ll distancia_atual = topo.first;
        int vertice = topo.second;
        if (distancia_atual != distancia[vertice]) continue;

        for (int i = 0; i < (int)grafo[vertice].size(); i++) {
            int vizinho = grafo[vertice][i].first;
            int peso = grafo[vertice][i].second;
            if (distancia[vizinho] > distancia_atual + peso) {
                distancia[vizinho] = distancia_atual + peso;
                pai[vizinho] = vertice;
                fila_prioridade.push(make_pair(distancia[vizinho], vizinho));
            }
        }
    }
}

vector<int> reconstruir_caminho_dijkstra() {
    vector<int> caminho;
    int atual = quantidade_vertices;
    while (atual != pai[atual]) {
        caminho.push_back(atual);
        atual = pai[atual];
    }
    caminho.push_back(1);
    reverse(caminho.begin(), caminho.end());
    return caminho;
}


// Deixo uma função separado para simplificar casos teste.
void solve(){
    cin >> quantidade_vertices >> quantidade_arestas;

    ler_arestas_dijkstra();
    executar_dijkstra();

    if (distancia[quantidade_vertices] == (ll)4e18) {
        cout << -1 << '\n';
        return;
    }

    vector<int> caminho = reconstruir_caminho_dijkstra();
    for (int i = 0; i < (int)caminho.size(); i++) {
        if (i) cout << ' ';
        cout << caminho[i];
    }
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