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

const int mod = 51123987;
// Deve ser alterada conforme o necessário
// Geralmente em problemas que usamos mod, deixamos essa constante salva e alteramos para o mod requisitado

const int inf = 0x3f3f3f3f;
// Pode ser alterado quando formos usar long long, para 0x3f3f3f3f3f3ff3f.
// Deixamos um valor de inf, que geralmente é apenas um inteiro maior do que qualquer outro que iremos usar no nosso programa,
// E é conveniente escolher um tal que 2*inf < MAXINT.
// No geral, eu uso essa repetição de 0x3f pois é um byte repetido e podemos facilmente preencher vetores com memset assim.


// Utilizo esse espaço em branco abaixo para declarar valores globais.
int a[maxn];

void solve() {
    int n;
    string s;
    cin >> n >> s;
    long long ans = 0;
    long long atual_ini = 0, atual_a = 0, atual_b = 0;

    vector<int> d1(n), d2(n);

    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r ? 1 : min(d1[l + r - i], r - i + 1));
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
        d1[i] = k;
        if (i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }

    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r ? 0 : min(d2[l + r - i + 1], r - i + 1));
        while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) k++;
        d2[i] = k;
        if (i + k - 1 > r) {
            l = i - k;
            r = i + k - 1;
        }
    }

    vector<long long> ini(n + 2), da(n + 2), db(n + 2);

    for (int i = 0; i < n; i++) {
        int r = d1[i];

        // adiciona_const(ini, i-r+1, i, 1)
        int l = max(0, i - r + 1);
        int rr = min(n - 1, i);
        if (l <= rr) {
            ini[l]++;
            ini[rr + 1]--;
        }

        l = max(0, i - r + 1);
        rr = min(n - 1, i);
        if (l <= rr) {
            da[l]++;
            da[rr + 1]--;
            db[l] += 1LL * r - i;
            db[rr + 1] -= 1LL * r - i;
        }

        l = max(0, i + 1);
        rr = min(n - 1, i + r - 1);
        if (l <= rr) {
            da[l]--;
            da[rr + 1]++;
            db[l] += 1LL * i + r;
            db[rr + 1] -= 1LL * i + r;
        }
    }

    for (int i = 0; i < n; i++) {
        int r = d2[i];
        if (!r) continue;

        int l = max(0, i - r);
        int rr = min(n - 1, i - 1);
        if (l <= rr) {
            ini[l]++;
            ini[rr + 1]--;
        }

        l = max(0, i - r);
        rr = min(n - 1, i - 1);
        if (l <= rr) {
            da[l]++;
            da[rr + 1]--;
            db[l] += 1LL * r + 1 - i;
            db[rr + 1] -= 1LL * r + 1 - i;
        }

        l = max(0, i);
        rr = min(n - 1, i + r - 1);
        if (l <= rr) {
            da[l]--;
            da[rr + 1]++;
            db[l] += 1LL * i + r;
            db[rr + 1] -= 1LL * i + r;
        }
    }


    for (int i = 0; i < n; i++) {
        atual_ini += ini[i];
        atual_a += da[i];
        atual_b += db[i];

        long long comeco = atual_ini;
        long long cobre = atual_a * i + atual_b;
        long long add = comeco * cobre - comeco * (comeco + 1) / 2;

        ans = (ans + add) % mod;
    }

    cout << (ans + mod) % mod << '\n';
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