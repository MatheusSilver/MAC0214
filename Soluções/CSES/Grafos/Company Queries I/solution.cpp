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
int quantidade_funcionarios_cq, quantidade_consultas_cq, niveis_cq;
vector<vector<int>> ancestral_cq;

void ler_hierarquia_cq() {
    ancestral_cq.assign(niveis_cq, vector<int>(quantidade_funcionarios_cq + 1, 0));
    for (int funcionario = 2; funcionario <= quantidade_funcionarios_cq; funcionario++) {
        cin >> ancestral_cq[0][funcionario];
    }
}

void montar_tabela_cq() {
    for (int j = 1; j < niveis_cq; j++) {
        for (int funcionario = 1; funcionario <= quantidade_funcionarios_cq; funcionario++) {
            int meio = ancestral_cq[j - 1][funcionario];
            ancestral_cq[j][funcionario] = meio ? ancestral_cq[j - 1][meio] : 0;
        }
    }
}

int subir_k_niveis_cq(int funcionario, int k) {
    for (int j = 0; j < niveis_cq && funcionario; j++) {
        if (k & (1 << j)) funcionario = ancestral_cq[j][funcionario];
    }
    return funcionario;
}


// Deixo uma função separado para simplificar casos teste.
void solve(){
    cin >> quantidade_funcionarios_cq >> quantidade_consultas_cq;
    niveis_cq = 1;
    while ((1 << niveis_cq) <= quantidade_funcionarios_cq) niveis_cq++;

    ler_hierarquia_cq();
    montar_tabela_cq();

    while (quantidade_consultas_cq--) {
        int funcionario, k;
        cin >> funcionario >> k;
        int resposta = subir_k_niveis_cq(funcionario, k);
        cout << (resposta ? resposta : -1) << '\n';
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