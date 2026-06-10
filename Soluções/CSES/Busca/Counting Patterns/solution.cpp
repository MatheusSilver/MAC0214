// Esse código foi feito pelo Cauê do MaratonUSP e cedido para uso na matéria de MAC0327 
// Contém diversas pré-definições úteis que podem auxiliar na escrita de código para uma série de problemas.

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

struct Node {
    int prox[26], falha;
    Node() {
        fill(prox, prox + 26, -1);
        falha = 0;
    }
};

void solve() {
    string s;
    int k;
    cin >> s >> k;

    vector<Node> trie(1);
    vector<int> fim(k);

    for (int i = 0; i < k; i++) {
        string p;
        cin >> p;

        int no = 0;
        for (char c : p) {
            int x = c - 'a';

            if (trie[no].prox[x] == -1) {
                trie[no].prox[x] = trie.size();
                trie.push_back(Node());
            }

            no = trie[no].prox[x];
        }

        fim[i] = no;
    }

    queue<int> fila;

    for (int c = 0; c < 26; c++) {
        int v = trie[0].prox[c];

        if (v != -1) {
            fila.push(v);
        } else {
            trie[0].prox[c] = 0;
        }
    }

    vector<int> ordem;
    ordem.push_back(0);

    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();

        ordem.push_back(u);

        for (int c = 0; c < 26; c++) {
            int v = trie[u].prox[c];

            if (v != -1) {
                trie[v].falha = trie[trie[u].falha].prox[c];
                fila.push(v);
            } else {
                trie[u].prox[c] = trie[trie[u].falha].prox[c];
            }
        }
    }

    vector<long long> conta(trie.size());

    int no = 0;

    for (char c : s) {
        no = trie[no].prox[c - 'a'];
        conta[no]++;
    }

    for (int i = (int)ordem.size() - 1; i > 0; i--) {
        conta[trie[ordem[i]].falha] += conta[ordem[i]];
    }

    for (int i = 0; i < k; i++) {
        cout << conta[fim[i]] << '\n';
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