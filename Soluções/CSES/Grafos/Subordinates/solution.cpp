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
int quantidade_funcionarios_sub;
vector<vector<int>> filhos_sub;

void ler_hierarquia_sub() {
    filhos_sub.assign(quantidade_funcionarios_sub + 1, vector<int>());
    for (int funcionario = 2; funcionario <= quantidade_funcionarios_sub; funcionario++) {
        int chefe;
        cin >> chefe;
        filhos_sub[chefe].push_back(funcionario);
    }
}

vector<int> gerar_ordem_dfs_sub() {
    vector<int> ordem;
    ordem.reserve(quantidade_funcionarios_sub);
    stack<int> pilha;
    pilha.push(1);

    while (!pilha.empty()) {
        int atual = pilha.top();
        pilha.pop();
        ordem.push_back(atual);
        for (int i = 0; i < (int)filhos_sub[atual].size(); i++) {
            pilha.push(filhos_sub[atual][i]);
        }
    }

    return ordem;
}

vector<int> calcular_subordinados_sub(const vector<int>& ordem) {
    vector<int> subordinados(quantidade_funcionarios_sub + 1, 0);

    for (int i = quantidade_funcionarios_sub - 1; i >= 0; i--) {
        int atual = ordem[i];
        int total = 0;
        for (int j = 0; j < (int)filhos_sub[atual].size(); j++) {
            int filho = filhos_sub[atual][j];
            total += 1 + subordinados[filho];
        }
        subordinados[atual] = total;
    }

    return subordinados;
}


// Deixo uma função separado para simplificar casos teste.
void solve(){
    cin >> quantidade_funcionarios_sub;
    ler_hierarquia_sub();
    vector<int> ordem = gerar_ordem_dfs_sub();
    vector<int> subordinados = calcular_subordinados_sub(ordem);

    for (int i = 1; i <= quantidade_funcionarios_sub; i++) {
        if (i > 1) cout << ' ';
        cout << subordinados[i];
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