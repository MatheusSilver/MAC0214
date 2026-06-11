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

const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;
const ll BASE1 = 911382323;
const ll BASE2 = 972663749;
// Deve ser alterada conforme o necessário
// Geralmente em problemas que usamos mod, deixamos essa constante salva e alteramos para o mod requisitado

const int inf = 0x3f3f3f3f;
// Pode ser alterado quando formos usar long long, para 0x3f3f3f3f3f3ff3f.
// Deixamos um valor de inf, que geralmente é apenas um inteiro maior do que qualquer outro que iremos usar no nosso programa,
// E é conveniente escolher um tal que 2*inf < MAXINT.
// No geral, eu uso essa repetição de 0x3f pois é um byte repetido e podemos facilmente preencher vetores com memset assim.


// Utilizo esse espaço em branco abaixo para declarar valores globais.
int a[maxn];

struct No {
    ll h1, h2;
    int tam, lazy;

    No(ll h1 = 0, ll h2 = 0, int tam = 0, int lazy = -1) : h1(h1), h2(h2), tam(tam), lazy(lazy) {}
};

vector<ll> pot1, pot2, soma1, soma2;
vector<No> seg;
string s;

pair<ll, ll> hash_repetido(int c, int tam) {
    return {
        1LL * (c + 1) * soma1[tam] % MOD1,
        1LL * (c + 1) * soma2[tam] % MOD2
    };
}

void junta(No& no, const No& esq, const No& dir) {
    no.tam = esq.tam + dir.tam;
    no.h1 = (esq.h1 + dir.h1 * pot1[esq.tam]) % MOD1;
    no.h2 = (esq.h2 + dir.h2 * pot2[esq.tam]) % MOD2;
}

void build(int no, int l, int r) {
    seg[no].lazy = -1;
    seg[no].tam = r - l + 1;

    if (l == r) {
        int v = s[l - 1] - '0' + 1;
        seg[no].h1 = v;
        seg[no].h2 = v;
        return;
    }

    int m = (l + r) / 2;
    build(no * 2, l, m);
    build(no * 2 + 1, m + 1, r);

    junta(seg[no], seg[no * 2], seg[no * 2 + 1]);
}

void aplica(int no, int c) {
    auto [h1, h2] = hash_repetido(c, seg[no].tam);

    seg[no].h1 = h1;
    seg[no].h2 = h2;
    seg[no].lazy = c;
}

void empurra(int no) {
    if (seg[no].lazy == -1) return;

    aplica(no * 2, seg[no].lazy);
    aplica(no * 2 + 1, seg[no].lazy);

    seg[no].lazy = -1;
}

void atualiza(int no, int l, int r, int ql, int qr, int c) {
    if (qr < l || r < ql) return;

    if (ql <= l && r <= qr) {
        aplica(no, c);
        return;
    }

    empurra(no);

    int m = (l + r) / 2;
    atualiza(no * 2, l, m, ql, qr, c);
    atualiza(no * 2 + 1, m + 1, r, ql, qr, c);

    junta(seg[no], seg[no * 2], seg[no * 2 + 1]);
}

No consulta(int no, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return No();

    if (ql <= l && r <= qr)
        return seg[no];

    empurra(no);

    int m = (l + r) / 2;

    No esq = consulta(no * 2, l, m, ql, qr);
    No dir = consulta(no * 2 + 1, m + 1, r, ql, qr);

    if (esq.tam == 0) return dir;
    if (dir.tam == 0) return esq;

    No resp;
    junta(resp, esq, dir);

    return resp;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k >> s;

    pot1.assign(n + 1, 1);
    pot2.assign(n + 1, 1);
    soma1.assign(n + 1, 0);
    soma2.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        pot1[i] = pot1[i - 1] * BASE1 % MOD1;
        pot2[i] = pot2[i - 1] * BASE2 % MOD2;

        soma1[i] = (soma1[i - 1] * BASE1 + 1) % MOD1;
        soma2[i] = (soma2[i - 1] * BASE2 + 1) % MOD2;
    }

    seg.assign(4 * n + 5, No());

    build(1, 1, n);

    int q = m + k;

    while (q--) {
        int tp, l, r, d;
        cin >> tp >> l >> r >> d;

        if (tp == 1) {
            atualiza(1, 1, n, l, r, d);
        } else {
            int tam = r - l + 1 - d;

            if (tam <= 0) {
                cout << "YES\n";
                continue;
            }

            No a = consulta(1, 1, n, l, r - d);
            No b = consulta(1, 1, n, l + d, r);

            cout << (a.h1 == b.h1 && a.h2 == b.h2 ? "YES\n" : "NO\n");
        }
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