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
int quantidade_cidades_br, quantidade_estradas_br;
vector<vector<int>> grafo_br;

void ler_estradas_br() {
    grafo_br.assign(quantidade_cidades_br + 1, vector<int>());
    for (int i = 0; i < quantidade_estradas_br; i++) {
        int a, b;
        cin >> a >> b;
        grafo_br[a].push_back(b);
        grafo_br[b].push_back(a);
    }
}

vector<int> representantes_componentes_br() {
    vector<char> visitado(quantidade_cidades_br + 1, 0);
    vector<int> representantes;

    for (int inicio = 1; inicio <= quantidade_cidades_br; inicio++) {
        if (visitado[inicio]) continue;
        representantes.push_back(inicio);

        stack<int> pilha;
        pilha.push(inicio);
        visitado[inicio] = 1;

        while (!pilha.empty()) {
            int cidade = pilha.top();
            pilha.pop();
            for (int i = 0; i < (int)grafo_br[cidade].size(); i++) {
                int vizinho = grafo_br[cidade][i];
                if (!visitado[vizinho]) {
                    visitado[vizinho] = 1;
                    pilha.push(vizinho);
                }
            }
        }
    }

    return representantes;
}


// Deixo uma função separado para simplificar casos teste.
void solve(){
    cin >> quantidade_cidades_br >> quantidade_estradas_br;
    ler_estradas_br();
    vector<int> representantes = representantes_componentes_br();

    cout << (int)representantes.size() - 1 << '\n';
    for (int i = 1; i < (int)representantes.size(); i++) {
        cout << representantes[i - 1] << ' ' << representantes[i] << '\n';
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