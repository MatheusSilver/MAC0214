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
int linha_inicial, coluna_inicial, linha_final, coluna_final;
int quantidade_segmentos_king;
unordered_set<long long> permitidos_king;

long long codificar_posicao_king(int linha, int coluna) {
    return ((long long)linha << 32) ^ (unsigned int)coluna;
}

void ler_segmentos_king() {
    permitidos_king.clear();
    permitidos_king.reserve(300000);
    for (int i = 0; i < quantidade_segmentos_king; i++) {
        int linha, inicio, fim;
        cin >> linha >> inicio >> fim;
        for (int coluna = inicio; coluna <= fim; coluna++) {
            permitidos_king.insert(codificar_posicao_king(linha, coluna));
        }
    }
}

int bfs_minimo_king() {
    long long origem = codificar_posicao_king(linha_inicial, coluna_inicial);
    long long destino = codificar_posicao_king(linha_final, coluna_final);
    if (origem == destino) return 0;

    queue<pair<int, int>> fila;
    unordered_map<long long, int> distancia;
    distancia.reserve(300000);

    fila.push(make_pair(linha_inicial, coluna_inicial));
    distancia[origem] = 0;
    permitidos_king.erase(origem);

    static const int dl[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static const int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    while (!fila.empty()) {
        pair<int, int> atual = fila.front();
        fila.pop();

        int linha = atual.first;
        int coluna = atual.second;
        int distancia_atual = distancia[codificar_posicao_king(linha, coluna)];

        for (int direcao = 0; direcao < 8; direcao++) {
            int proxima_linha = linha + dl[direcao];
            int proxima_coluna = coluna + dc[direcao];
            long long chave = codificar_posicao_king(proxima_linha, proxima_coluna);
            if (!permitidos_king.count(chave)) continue;

            permitidos_king.erase(chave);
            distancia[chave] = distancia_atual + 1;
            if (chave == destino) return distancia_atual + 1;
            fila.push(make_pair(proxima_linha, proxima_coluna));
        }
    }

    return -1;
}


// Deixo uma função separado para simplificar casos teste.
void solve(){
    cin >> linha_inicial >> coluna_inicial >> linha_final >> coluna_final;
    cin >> quantidade_segmentos_king;
    ler_segmentos_king();
    cout << bfs_minimo_king() << '\n';
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