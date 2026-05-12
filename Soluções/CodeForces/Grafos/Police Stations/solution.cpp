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
int quantidade_cidades_ps, quantidade_bases_ps, limite_distancia_ps;
vector<int> bases_ps;
vector<vector<pair<int, int>>> grafo_ps;

void ler_estradas_ps() {
    grafo_ps.assign(quantidade_cidades_ps + 1, vector<pair<int, int>>());
    for (int i = 1; i <= quantidade_cidades_ps - 1; i++) {
        int u, v;
        cin >> u >> v;
        grafo_ps[u].push_back(make_pair(v, i));
        grafo_ps[v].push_back(make_pair(u, i));
    }
}

vector<char> definir_estradas_mantidas_ps() {
    vector<int> distancia(quantidade_cidades_ps + 1, -1);
    vector<char> manter(quantidade_cidades_ps, 0);
    queue<int> fila;

    for (int i = 0; i < (int)bases_ps.size(); i++) {
        int base = bases_ps[i];
        if (distancia[base] != -1) continue;
        distancia[base] = 0;
        fila.push(base);
    }

    while (!fila.empty()) {
        int cidade = fila.front();
        fila.pop();

        if (distancia[cidade] == limite_distancia_ps) continue;

        for (int i = 0; i < (int)grafo_ps[cidade].size(); i++) {
            int vizinho = grafo_ps[cidade][i].first;
            int id_estrada = grafo_ps[cidade][i].second;
            if (distancia[vizinho] != -1) continue;
            distancia[vizinho] = distancia[cidade] + 1;
            manter[id_estrada] = 1;
            fila.push(vizinho);
        }
    }

    return manter;
}

vector<int> listar_estradas_removidas_ps(const vector<char>& manter) {
    vector<int> removidas;
    for (int id = 1; id <= quantidade_cidades_ps - 1; id++) {
        if (!manter[id]) removidas.push_back(id);
    }
    return removidas;
}


// Deixo uma função separado para simplificar casos teste.
void solve(){
    cin >> quantidade_cidades_ps >> quantidade_bases_ps >> limite_distancia_ps;
    bases_ps.assign(quantidade_bases_ps, 0);
    for (int i = 0; i < quantidade_bases_ps; i++) cin >> bases_ps[i];

    ler_estradas_ps();
    vector<char> manter = definir_estradas_mantidas_ps();
    vector<int> removidas = listar_estradas_removidas_ps(manter);

    cout << removidas.size() << '\n';
    for (int i = 0; i < (int)removidas.size(); i++) {
        if (i) cout << ' ';
        cout << removidas[i];
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