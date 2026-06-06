// Esse código foi feito pelo Cauê do MaratonUSP e cedido para uso na matéria de MAC0327 
// Contém diversas pré-definições úteis que podem auxiliar na escrita de código para uma série de problemas.

#include <bits/stdc++.h>
//^ biblioteca mais utilizada para programação competitiva
// irá conter todas as principais estruturas já construidas que iremos precisar

using namespace std;
// ^ Usamos para não precisar adicionar o namespace std:: antes das estruturas que utilizarmos

typedef long long ll;
// Um macro que nos permite apenas digitar ll ao invés de long long quando quisermos usar um inteiro 64 bits
// (aumenta a ravetorPrefixoszed e agilidade do código)

const int maxn = 200005;
// Deve ser alterada conforme o necessário
// Definimos o limite do maior valor de N que iremos encontrar durante o problema.
// Ao declararmos como const, garantimos ao comvetorPrefixoslador que esse valor não será alterado e ele nos permite
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

vector<int> prefixo(const vector<int>& v) {
    vector<int> vetorPrefixos(v.size(), 0);
    for (int i = 1, j = 0; i < (int)v.size(); i++) {
        while (j && v[i] != v[j]) j = vetorPrefixos[j - 1];
        if (v[i] == v[j]) j++;
        vetorPrefixos[i] = j;
    }
    return vetorPrefixos;
}


// Deixo uma função separado para simplificar casos teste.
void solve(){
    int n, w;
    cin >> n >> w;
    vector<int> a(n), b(w);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    if (w == 1) {
        cout << n << '\n';
        return;
    }

    vector<int> da, db;
    for (int i = 0; i + 1 < n; i++) da.push_back(a[i + 1] - a[i]);
    for (int i = 0; i + 1 < w; i++) db.push_back(b[i + 1] - b[i]);

    vector<int> vetorPrefixos = prefixo(db);
    int resp = 0;
    for (int i = 0, j = 0; i < (int)da.size(); i++) {
        while (j && da[i] != db[j]) j = vetorPrefixos[j - 1];
        if (da[i] == db[j]) j++;
        if (j == (int)db.size()) {
            resp++;
            j = vetorPrefixos[j - 1];
        }
    }
    cout << resp << '\n';
}

int main(){
    // Essa linha serve para receber inputs mais rávetorPrefixosdo. Geralmente questões com muitos números no input irão dar TLE sem ela.
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    // Caso o problema tenha testes-caso, basta descomentar as linhas abaixo:

    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}