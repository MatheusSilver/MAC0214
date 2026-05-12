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
int quantidade_vertices_preguica, niveis_preguica;
vector<vector<int>> arvore_preguica;
vector<vector<int>> ancestral_preguica;
vector<int> profundidade_preguica;

void ler_arestas_preguica() {
    arvore_preguica.assign(quantidade_vertices_preguica + 1, vector<int>());
    for (int i = 0; i < quantidade_vertices_preguica - 1; i++) {
        int u, v;
        cin >> u >> v;
        arvore_preguica[u].push_back(v);
        arvore_preguica[v].push_back(u);
    }
}

void preparar_subidas_preguica() {
    niveis_preguica = 1;
    while ((1 << niveis_preguica) <= quantidade_vertices_preguica) niveis_preguica++;

    ancestral_preguica.assign(niveis_preguica, vector<int>(quantidade_vertices_preguica + 1, 0));
    profundidade_preguica.assign(quantidade_vertices_preguica + 1, 0);

    vector<int> ordem;
    ordem.reserve(quantidade_vertices_preguica);
    ordem.push_back(1);
    ancestral_preguica[0][1] = 1;

    for (int i = 0; i < (int)ordem.size(); i++) {
        int vertice = ordem[i];
        for (int j = 0; j < (int)arvore_preguica[vertice].size(); j++) {
            int vizinho = arvore_preguica[vertice][j];
            if (vizinho == ancestral_preguica[0][vertice]) continue;
            ancestral_preguica[0][vizinho] = vertice;
            profundidade_preguica[vizinho] = profundidade_preguica[vertice] + 1;
            ordem.push_back(vizinho);
        }
    }

    for (int j = 1; j < niveis_preguica; j++) {
        for (int v = 1; v <= quantidade_vertices_preguica; v++) {
            ancestral_preguica[j][v] = ancestral_preguica[j - 1][ancestral_preguica[j - 1][v]];
        }
    }
}

int subir_preguica(int vertice, int passos) {
    for (int j = 0; j < niveis_preguica; j++) {
        if (passos & (1 << j)) vertice = ancestral_preguica[j][vertice];
    }
    return vertice;
}

int lca_preguica(int a, int b) {
    if (profundidade_preguica[a] < profundidade_preguica[b]) swap(a, b);
    a = subir_preguica(a, profundidade_preguica[a] - profundidade_preguica[b]);
    if (a == b) return a;

    for (int j = niveis_preguica - 1; j >= 0; j--) {
        if (ancestral_preguica[j][a] != ancestral_preguica[j][b]) {
            a = ancestral_preguica[j][a];
            b = ancestral_preguica[j][b];
        }
    }
    return ancestral_preguica[0][a];
}

int responder_consulta_preguica(int origem, int destino, int energia) {
    int ancestral_comum = lca_preguica(origem, destino);
    int subir_origem = profundidade_preguica[origem] - profundidade_preguica[ancestral_comum];
    int subir_destino = profundidade_preguica[destino] - profundidade_preguica[ancestral_comum];
    int distancia_total = subir_origem + subir_destino;
    int passos = min(energia, distancia_total);

    if (passos <= subir_origem) return subir_preguica(origem, passos);
    return subir_preguica(destino, distancia_total - passos);
}


// Deixo uma função separado para simplificar casos teste.
void solve(){
    cin >> quantidade_vertices_preguica;
    ler_arestas_preguica();
    preparar_subidas_preguica();

    int quantidade_consultas;
    cin >> quantidade_consultas;
    while (quantidade_consultas--) {
        int origem, destino, energia;
        cin >> origem >> destino >> energia;
        cout << responder_consulta_preguica(origem, destino, energia) << '\n';
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