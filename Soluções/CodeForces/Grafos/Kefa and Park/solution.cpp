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
int quantidade_vertices_kefa, limite_gatos;
vector<int> tem_gato;
vector<vector<int>> arvore_kefa;

void ler_gatos_kefa() {
    tem_gato.assign(quantidade_vertices_kefa + 1, 0);
    for (int i = 1; i <= quantidade_vertices_kefa; i++) cin >> tem_gato[i];
}

void ler_arestas_kefa() {
    arvore_kefa.assign(quantidade_vertices_kefa + 1, vector<int>());
    for (int i = 0; i < quantidade_vertices_kefa - 1; i++) {
        int u, v;
        cin >> u >> v;
        arvore_kefa[u].push_back(v);
        arvore_kefa[v].push_back(u);
    }
}

int contar_restaurantes_kefa() {
    int resposta = 0;
    stack<tuple<int, int, int>> pilha;
    pilha.push(make_tuple(1, 0, tem_gato[1]));

    while (!pilha.empty()) {
        tuple<int, int, int> topo = pilha.top();
        pilha.pop();

        int vertice = get<0>(topo);
        int pai = get<1>(topo);
        int consecutivos = get<2>(topo);

        if (consecutivos > limite_gatos) continue;

        bool eh_folha = (vertice != 1 && (int)arvore_kefa[vertice].size() == 1);
        if (eh_folha) {
            resposta++;
            continue;
        }

        for (int i = 0; i < (int)arvore_kefa[vertice].size(); i++) {
            int vizinho = arvore_kefa[vertice][i];
            if (vizinho == pai) continue;
            int proximos_consecutivos = tem_gato[vizinho] ? consecutivos + 1 : 0;
            pilha.push(make_tuple(vizinho, vertice, proximos_consecutivos));
        }
    }

    return resposta;
}


// Deixo uma função separado para simplificar casos teste.
void solve(){
    cin >> quantidade_vertices_kefa >> limite_gatos;
    ler_gatos_kefa();
    ler_arestas_kefa();
    cout << contar_restaurantes_kefa() << '\n';
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