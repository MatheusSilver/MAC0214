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
const int mod = 998244353;
// Deve ser alterada conforme o necessário
// Geralmente em problemas que usamos mod, deixamos essa constante salva e alteramos para o mod requisitado
const int inf = 0x3f3f3f3f;
// Pode ser alterado quando formos usar long long, para 0x3f3f3f3f3f3ff3f.
// Deixamos um valor de inf, que geralmente é apenas um inteiro maior do que qualquer outro que iremos usar no nosso programa,
// E é conveniente escolher um tal que 2*inf < MAXINT.
// No geral, eu uso essa repetição de 0x3f pois é um byte repetido e podemos facilmente preencher vetores com memset assim.
// Utilizo esse espaço em branco abaixo para declarar valores globais.

ll fat[maxn];
ll invFat[maxn];

ll fastExp(ll base, ll exponent){
    ll result = 1;
    base %= mod;
    while(exponent > 0){
        if(exponent & 1) result = result * base % mod;
        base = base * base % mod;
        exponent >>= 1;
    }
    return result;
}

ll binomial(int n, int r){
    if(r < 0 || r > n) return 0;
    return fat[n] * invFat[r] % mod * invFat[n-r] % mod;
}

// Deixo uma função separado para simplificar casos teste.
void solve(){
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> values(n), residue(n), groupKey(n);
    for(int i = 0; i < n; i++){
        cin >> values[i];
        residue[i] = values[i] % k;
        ll complement = (k - residue[i]) % k;
        groupKey[i] = min(residue[i], complement);
    }

    ll answer = 1;
    int i = 0;
    while(i < n){
        int j = i;
        while(j < n && groupKey[j] == groupKey[i]) j++;
        int runSize = j - i;
        ll key = groupKey[i];
        bool selfComplementary = ((2 * residue[i]) % k == 0);

        if(selfComplementary){
            vector<ll> runValues(values.begin() + i, values.begin() + j);
            sort(runValues.begin(), runValues.end());
            ll ways = fat[runSize];
            int repeated = 1;
            for(int p = 1; p < runSize; p++){
                if(runValues[p] == runValues[p-1]){
                    repeated++;
                } else {
                    ways = ways * invFat[repeated] % mod;
                    repeated = 1;
                }
            }
            ways = ways * invFat[repeated] % mod;
            answer = answer * ways % mod;
        } else {
            int countFirst = 0;
            for(int p = i; p < j; p++)
                if(residue[p] == key) countFirst++;
            answer = answer * binomial(runSize, countFirst) % mod;
        }
        i = j;
    }

    cout << answer << "\n";
}

int main(){
    // Essa linha serve para receber inputs mais rápido. Geralmente questões com muitos números no input irão dar TLE sem ela.
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    fat[0] = 1;
    for(int i = 1; i < maxn; i++)
        fat[i] = fat[i-1] * i % mod;

    invFat[maxn-1] = fastExp(fat[maxn-1], mod-2);
    
    for(int i = maxn-1; i > 0; i--)
        invFat[i-1] = invFat[i] * i % mod;
    
    
    // Caso o problema tenha testes-caso, basta descomentar as linhas abaixo:
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}