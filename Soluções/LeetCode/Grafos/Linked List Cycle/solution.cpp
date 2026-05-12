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
int quantidade_nos_linked_list, posicao_ciclo_linked_list;

struct NodeLinkedList {
    int valor;
    NodeLinkedList* proximo;
    NodeLinkedList(int v) : valor(v), proximo(NULL) {}
};

vector<NodeLinkedList*> nos_linked_list;

void ler_nos_linked_list() {
    nos_linked_list.clear();
    nos_linked_list.reserve(max(0, quantidade_nos_linked_list));
    for (int i = 0; i < quantidade_nos_linked_list; i++) {
        int valor;
        cin >> valor;
        nos_linked_list.push_back(new NodeLinkedList(valor));
    }
}

void conectar_lista_linked_list() {
    for (int i = 0; i + 1 < quantidade_nos_linked_list; i++) nos_linked_list[i]->proximo = nos_linked_list[i + 1];
    if (quantidade_nos_linked_list > 0 && posicao_ciclo_linked_list >= 0 && posicao_ciclo_linked_list < quantidade_nos_linked_list) {
        nos_linked_list[quantidade_nos_linked_list - 1]->proximo = nos_linked_list[posicao_ciclo_linked_list];
    }
}

bool possui_ciclo_linked_list() {
    NodeLinkedList* lento = (quantidade_nos_linked_list > 0 ? nos_linked_list[0] : NULL);
    NodeLinkedList* rapido = lento;

    while (rapido != NULL && rapido->proximo != NULL) {
        lento = lento->proximo;
        rapido = rapido->proximo->proximo;
        if (lento == rapido) return true;
    }
    return false;
}


// Deixo uma função separado para simplificar casos teste.
void solve(){
    if (!(cin >> quantidade_nos_linked_list >> posicao_ciclo_linked_list)) return;

    ler_nos_linked_list();
    conectar_lista_linked_list();
    cout << (possui_ciclo_linked_list() ? "true\n" : "false\n");
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