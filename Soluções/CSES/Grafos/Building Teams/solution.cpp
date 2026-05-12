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
int quantidade_alunos_bt, quantidade_amizades_bt;
vector<vector<int>> grafo_bt;

vector<int> bipartir_bt() {
    vector<int> time(quantidade_alunos_bt + 1, 0);
    queue<int> fila;

    for (int inicio = 1; inicio <= quantidade_alunos_bt; inicio++) {
        if (time[inicio]) continue;
        time[inicio] = 1;
        fila.push(inicio);

        while (!fila.empty()) {
            int aluno = fila.front();
            fila.pop();

            for (int i = 0; i < (int)grafo_bt[aluno].size(); i++) {
                int vizinho = grafo_bt[aluno][i];
                if (!time[vizinho]) {
                    time[vizinho] = 3 - time[aluno];
                    fila.push(vizinho);
                } else if (time[vizinho] == time[aluno]) {
                    return vector<int>();
                }
            }
        }
    }

    return time;
}


// Deixo uma função separado para simplificar casos teste.
void solve(){
    cin >> quantidade_alunos_bt >> quantidade_amizades_bt;

    grafo_bt.assign(quantidade_alunos_bt + 1, vector<int>());
    for (int i = 0; i < quantidade_amizades_bt; i++) {
        int a, b;
        cin >> a >> b;
        grafo_bt[a].push_back(b);
        grafo_bt[b].push_back(a);
    }

    vector<int> time = bipartir_bt();
    if (time.empty()) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for (int i = 1; i <= quantidade_alunos_bt; i++) {
        if (i > 1) cout << ' ';
        cout << time[i];
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