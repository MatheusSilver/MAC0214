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
int linhas_cr, colunas_cr;
vector<string> mapa_cr;

void visitar_componente_cr(int linha_inicial, int coluna_inicial) {
    queue<pair<int, int>> fila;
    fila.push(make_pair(linha_inicial, coluna_inicial));
    mapa_cr[linha_inicial][coluna_inicial] = '#';

    while (!fila.empty()) {
        pair<int, int> topo = fila.front();
        fila.pop();

        int linha = topo.first;
        int coluna = topo.second;

        if (linha > 0 && mapa_cr[linha - 1][coluna] == '.') {
            mapa_cr[linha - 1][coluna] = '#';
            fila.push(make_pair(linha - 1, coluna));
        }
        if (linha + 1 < linhas_cr && mapa_cr[linha + 1][coluna] == '.') {
            mapa_cr[linha + 1][coluna] = '#';
            fila.push(make_pair(linha + 1, coluna));
        }
        if (coluna > 0 && mapa_cr[linha][coluna - 1] == '.') {
            mapa_cr[linha][coluna - 1] = '#';
            fila.push(make_pair(linha, coluna - 1));
        }
        if (coluna + 1 < colunas_cr && mapa_cr[linha][coluna + 1] == '.') {
            mapa_cr[linha][coluna + 1] = '#';
            fila.push(make_pair(linha, coluna + 1));
        }
    }
}


// Deixo uma função separado para simplificar casos teste.
void solve(){
    cin >> linhas_cr >> colunas_cr;
    mapa_cr.assign(linhas_cr, string());
    for (int i = 0; i < linhas_cr; i++) cin >> mapa_cr[i];

    int quantidade_salas = 0;
    for (int i = 0; i < linhas_cr; i++) {
        for (int j = 0; j < colunas_cr; j++) {
            if (mapa_cr[i][j] != '.') continue;
            quantidade_salas++;
            visitar_componente_cr(i, j);
        }
    }

    cout << quantidade_salas << '\n';
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