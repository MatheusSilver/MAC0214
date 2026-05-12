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
int quantidade_planetas_pk, quantidade_teleportes_pk;
vector<vector<int>> grafo_pk, grafo_reverso_pk;

void ler_arestas_pk() {
    grafo_pk.assign(quantidade_planetas_pk + 1, vector<int>());
    grafo_reverso_pk.assign(quantidade_planetas_pk + 1, vector<int>());
    for (int i = 0; i < quantidade_teleportes_pk; i++) {
        int a, b;
        cin >> a >> b;
        grafo_pk[a].push_back(b);
        grafo_reverso_pk[b].push_back(a);
    }
}

vector<int> calcular_ordem_finalizacao_pk() {
    vector<char> visitado(quantidade_planetas_pk + 1, 0);
    vector<int> ordem;
    ordem.reserve(quantidade_planetas_pk);

    for (int inicio = 1; inicio <= quantidade_planetas_pk; inicio++) {
        if (visitado[inicio]) continue;

        stack<pair<int, int>> pilha;
        pilha.push(make_pair(inicio, 0));
        visitado[inicio] = 1;

        while (!pilha.empty()) {
            int vertice = pilha.top().first;
            int indice = pilha.top().second;

            if (indice < (int)grafo_pk[vertice].size()) {
                int vizinho = grafo_pk[vertice][indice];
                pilha.top().second = indice + 1;
                if (!visitado[vizinho]) {
                    visitado[vizinho] = 1;
                    pilha.push(make_pair(vizinho, 0));
                }
            } else {
                ordem.push_back(vertice);
                pilha.pop();
            }
        }
    }

    return ordem;
}

pair<int, vector<int>> rotular_componentes_pk(const vector<int>& ordem) {
    vector<int> componente(quantidade_planetas_pk + 1, 0);
    int quantidade_componentes = 0;

    for (int i = quantidade_planetas_pk - 1; i >= 0; i--) {
        int inicio = ordem[i];
        if (componente[inicio]) continue;

        quantidade_componentes++;
        stack<int> pilha;
        pilha.push(inicio);
        componente[inicio] = quantidade_componentes;

        while (!pilha.empty()) {
            int vertice = pilha.top();
            pilha.pop();

            for (int j = 0; j < (int)grafo_reverso_pk[vertice].size(); j++) {
                int vizinho = grafo_reverso_pk[vertice][j];
                if (!componente[vizinho]) {
                    componente[vizinho] = quantidade_componentes;
                    pilha.push(vizinho);
                }
            }
        }
    }

    return make_pair(quantidade_componentes, componente);
}


// Deixo uma função separado para simplificar casos teste.
void solve(){
    cin >> quantidade_planetas_pk >> quantidade_teleportes_pk;
    ler_arestas_pk();
    vector<int> ordem = calcular_ordem_finalizacao_pk();
    pair<int, vector<int>> resposta = rotular_componentes_pk(ordem);
    int quantidade_componentes = resposta.first;
    vector<int> componente = resposta.second;

    cout << quantidade_componentes << '\n';
    for (int i = 1; i <= quantidade_planetas_pk; i++) {
        if (i > 1) cout << ' ';
        cout << componente[i];
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