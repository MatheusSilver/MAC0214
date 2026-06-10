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

void solve() {
    string s;
    cin >> s;

    bool correta = true;
    int pos = -1;

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '=') {
            if (pos != -1) correta = false;
            pos = i;
        }
    }

    if (pos == -1) correta = false;

    __int128 esq = 0, dir = 0;

    if (correta) {
        for (int lado = 0; lado < 2; lado++) {
            string t = (lado == 0 ? s.substr(0, pos) : s.substr(pos + 1));

            if (t.empty()) {
                correta = false;
                break;
            }

            if (t[0] == '+' || t[0] == '-') {
                correta = false;
                break;
            }

            __int128 valor = 0, sinal = 1;

            for (int i = 0; i < (int)t.size();) {
                if ((t[i] == '+' || t[i] == '-') &&
                    (i + 1 == (int)t.size() ||
                     !(t[i + 1] >= '0' && t[i + 1] <= '9'))) {
                    correta = false;
                    break;
                }

                if (t[i] == '+') {
                    sinal = 1;
                    i++;
                    continue;
                }

                if (t[i] == '-') {
                    sinal = -1;
                    i++;
                    continue;
                }

                if (!(t[i] >= '0' && t[i] <= '9')) {
                    correta = false;
                    break;
                }

                if (t[i] == '0' && i + 1 < (int)t.size() &&
                    t[i + 1] >= '0' && t[i + 1] <= '9') {
                    correta = false;
                    break;
                }

                __int128 num = 0;
                int j = i;

                while (j < (int)t.size() && t[j] >= '0' && t[j] <= '9') {
                    num = num * 10 + (t[j] - '0');
                    j++;
                }

                if (j - i > 10) {
                    correta = false;
                    break;
                }

                valor += sinal * num;
                i = j;
            }

            if (!correta) break;

            if (lado == 0) esq = valor;
            else dir = valor;
        }
    }

    if (correta && esq == dir) {
        cout << "Correct\n";
        return;
    }

    int n = s.size();

    for (int i = 0; i < n; i++) {
        if (!(s[i] >= '0' && s[i] <= '9')) continue;

        string resto = s.substr(0, i) + s.substr(i + 1);

        for (int j = 0; j < n; j++) {
            string t = resto.substr(0, j) + s[i] + resto.substr(j);

            bool ok = true;
            int pos2 = -1;

            for (int k = 0; k < (int)t.size(); k++) {
                if (t[k] == '=') {
                    if (pos2 != -1) ok = false;
                    pos2 = k;
                }
            }

            if (pos2 == -1) ok = false;

            __int128 lhs = 0, rhs = 0;

            if (ok) {
                for (int lado = 0; lado < 2; lado++) {
                    string u = (lado == 0 ? t.substr(0, pos2) : t.substr(pos2 + 1));

                    if (u.empty()) {
                        ok = false;
                        break;
                    }

                    if (u[0] == '+' || u[0] == '-') {
                        ok = false;
                        break;
                    }

                    __int128 valor = 0, sinal = 1;

                    for (int p = 0; p < (int)u.size();) {
                        if ((u[p] == '+' || u[p] == '-') &&
                            (p + 1 == (int)u.size() ||
                             !(u[p + 1] >= '0' && u[p + 1] <= '9'))) {
                            ok = false;
                            break;
                        }

                        if (u[p] == '+') {
                            sinal = 1;
                            p++;
                            continue;
                        }

                        if (u[p] == '-') {
                            sinal = -1;
                            p++;
                            continue;
                        }

                        if (!(u[p] >= '0' && u[p] <= '9')) {
                            ok = false;
                            break;
                        }

                        if (u[p] == '0' && p + 1 < (int)u.size() &&
                            u[p + 1] >= '0' && u[p + 1] <= '9') {
                            ok = false;
                            break;
                        }

                        __int128 num = 0;
                        int q = p;

                        while (q < (int)u.size() && u[q] >= '0' && u[q] <= '9') {
                            num = num * 10 + (u[q] - '0');
                            q++;
                        }

                        if (q - p > 10) {
                            ok = false;
                            break;
                        }

                        valor += sinal * num;
                        p = q;
                    }

                    if (!ok) break;

                    if (lado == 0) lhs = valor;
                    else rhs = valor;
                }
            }

            if (ok && lhs == rhs) {
                cout << t << '\n';
                return;
            }
        }
    }

    cout << "Impossible\n";
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