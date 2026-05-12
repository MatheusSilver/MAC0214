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
int quantidade_nos_mr, quantidade_arestas_mr;
vector<vector<int>> grafo_mr;

void ler_arestas_mr() {
    grafo_mr.assign(quantidade_nos_mr + 1, vector<int>());
    for (int i = 0; i < quantidade_arestas_mr; i++) {
        int a, b;
        cin >> a >> b;
        grafo_mr[a].push_back(b);
        grafo_mr[b].push_back(a);
    }
}

vector<int> bfs_pais_mr() {
    vector<int> pai(quantidade_nos_mr + 1, -1);
    queue<int> fila;
    fila.push(1);
    pai[1] = 1;

    while (!fila.empty()) {
        int vertice = fila.front();
        fila.pop();

        for (int i = 0; i < (int)grafo_mr[vertice].size(); i++) {
            int vizinho = grafo_mr[vertice][i];
            if (pai[vizinho] != -1) continue;
            pai[vizinho] = vertice;
            fila.push(vizinho);
        }
    }

    return pai;
}

vector<int> reconstruir_caminho_mr(const vector<int>& pai) {
    vector<int> caminho;
    int atual = quantidade_nos_mr;
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
    cin >> quantidade_nos_mr >> quantidade_arestas_mr;
    ler_arestas_mr();
    vector<int> pai = bfs_pais_mr();

    if (pai[quantidade_nos_mr] == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> caminho = reconstruir_caminho_mr(pai);
    cout << caminho.size() << '\n';
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