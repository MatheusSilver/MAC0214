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
int linhas_maze, colunas_maze, quantidade_bloquear_maze;
vector<string> labirinto_maze;

pair<int, pair<int, int>> localizar_inicio_total_maze() {
    int total_livres = 0;
    pair<int, int> inicio = make_pair(-1, -1);
    for (int i = 0; i < linhas_maze; i++) {
        for (int j = 0; j < colunas_maze; j++) {
            if (labirinto_maze[i][j] == '.') {
                total_livres++;
                if (inicio.first == -1) inicio = make_pair(i, j);
            }
        }
    }
    return make_pair(total_livres, inicio);
}

vector<vector<char>> marcar_celulas_que_ficam_maze(int quantidade_manter, pair<int, int> inicio) {
    vector<vector<char>> visitado(linhas_maze, vector<char>(colunas_maze, 0));
    if (inicio.first == -1 || quantidade_manter <= 0) return visitado;

    stack<pair<int, int>> pilha;
    pilha.push(inicio);

    while (!pilha.empty() && quantidade_manter > 0) {
        pair<int, int> topo = pilha.top();
        pilha.pop();

        int linha = topo.first;
        int coluna = topo.second;
        if (visitado[linha][coluna]) continue;

        visitado[linha][coluna] = 1;
        quantidade_manter--;

        if (linha > 0 && labirinto_maze[linha - 1][coluna] == '.' && !visitado[linha - 1][coluna]) pilha.push(make_pair(linha - 1, coluna));
        if (linha + 1 < linhas_maze && labirinto_maze[linha + 1][coluna] == '.' && !visitado[linha + 1][coluna]) pilha.push(make_pair(linha + 1, coluna));
        if (coluna > 0 && labirinto_maze[linha][coluna - 1] == '.' && !visitado[linha][coluna - 1]) pilha.push(make_pair(linha, coluna - 1));
        if (coluna + 1 < colunas_maze && labirinto_maze[linha][coluna + 1] == '.' && !visitado[linha][coluna + 1]) pilha.push(make_pair(linha, coluna + 1));
    }

    return visitado;
}

void transformar_restante_em_parede_maze(const vector<vector<char>>& visitado) {
    for (int i = 0; i < linhas_maze; i++) {
        for (int j = 0; j < colunas_maze; j++) {
            if (labirinto_maze[i][j] == '.' && !visitado[i][j]) labirinto_maze[i][j] = 'X';
        }
    }
}


// Deixo uma função separado para simplificar casos teste.
void solve(){
    cin >> linhas_maze >> colunas_maze >> quantidade_bloquear_maze;
    labirinto_maze.assign(linhas_maze, string());
    for (int i = 0; i < linhas_maze; i++) cin >> labirinto_maze[i];

    pair<int, pair<int, int>> dados = localizar_inicio_total_maze();
    int total_livres = dados.first;
    pair<int, int> inicio = dados.second;

    int quantidade_manter = total_livres - quantidade_bloquear_maze;
    vector<vector<char>> visitado = marcar_celulas_que_ficam_maze(quantidade_manter, inicio);
    transformar_restante_em_parede_maze(visitado);

    for (int i = 0; i < linhas_maze; i++) cout << labirinto_maze[i] << '\n';
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