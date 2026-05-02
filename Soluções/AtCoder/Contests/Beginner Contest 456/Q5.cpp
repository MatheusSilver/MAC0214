/* Nota mental: Este código foi desenvolvido seguindo minha ideia padrão de desenvolvimento de softwares normais */
/* Entretanto, a técnica de montar funções para fazerem coisas e depois juntar tudo pode demorar um tempo muito grande de escrita */
/* Tempo que normalmente não temos em competições */
/* Provavelmente este será o código mais limpo e organizado que você verá neste repositório. */

#include <bits/stdc++.h>

using namespace std;

int id_estado(int cidade, int dia, int W){
    return cidade * W + dia;
}

int proximo_dia(int dia, int W){
    return (dia + 1) % W;
}

bool estado_eh_feriado(const vector<string>& feriados, int cidade, int dia){
    return feriados[cidade][dia] == 'o';
}

struct ArestaReversa {
    int destino;
    int proxima;
};

void adicionar_aresta_reversa(int origem, int destino, vector<int>& inicio, vector<ArestaReversa>& arestas){
    ArestaReversa nova;
    nova.destino = destino;
    nova.proxima = inicio[origem];
    inicio[origem] = (int)arestas.size();
    arestas.push_back(nova);
}

bool existe_ciclo_alcancavel(int N, int M, int W, const vector<vector<int>>& adjacencias, const vector<string>& feriados){
    int total_estados = N * W;
    vector<int> inicio_reverso(total_estados, -1);
    vector<ArestaReversa> arestas_reversas;
    arestas_reversas.reserve((N + M) * W * 2);

    vector<int> grau_saida(total_estados, 0);

    for(int cidade=0; cidade<N; ++cidade){
        for(int dia=0; dia<W; ++dia){
            if(!estado_eh_feriado(feriados, cidade, dia)){
                continue;
            }

            int proximo = proximo_dia(dia, W);
            int estado_origem = id_estado(cidade, dia, W);

            if(estado_eh_feriado(feriados, cidade, proximo)){
                int estado_destino = id_estado(cidade, proximo, W);
                adicionar_aresta_reversa(estado_destino, estado_origem, inicio_reverso, arestas_reversas);
                ++grau_saida[estado_origem];
            }

            for(int i=0; i<(int)adjacencias[cidade].size(); ++i){
                int cidade_destino = adjacencias[cidade][i];
                if(estado_eh_feriado(feriados, cidade_destino, proximo)){
                    int estado_destino = id_estado(cidade_destino, proximo, W);
                    adicionar_aresta_reversa(estado_destino, estado_origem, inicio_reverso, arestas_reversas);
                    ++grau_saida[estado_origem];
                }
            }
        }
    }

    queue<int> fila;
    vector<char> removido(total_estados, 0);

    for(int estado=0; estado<total_estados; ++estado){
        if(grau_saida[estado] == 0){
            fila.push(estado);
            removido[estado] = 1;
        }
    }

    while(!fila.empty()){
        int estado_atual = fila.front();
        fila.pop();

        for(int indice = inicio_reverso[estado_atual]; indice != -1; indice = arestas_reversas[indice].proxima){
            int predecessor = arestas_reversas[indice].destino;
            if(removido[predecessor]){
                continue;
            }

            --grau_saida[predecessor];
            if(grau_saida[predecessor] == 0){
                removido[predecessor] = 1;
                fila.push(predecessor);
            }
        }
    }

    for(int cidade=0; cidade<N; ++cidade){
        int estado_inicial = id_estado(cidade, 0, W);
        if(estado_eh_feriado(feriados, cidade, 0) && !removido[estado_inicial]){
            return true;
        }
    }

    return false;
}
void solve(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adjacencias(N);
    for(int i=0; i<M; ++i){
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adjacencias[u].push_back(v);
        adjacencias[v].push_back(u);
    }

    int W;
    cin >> W;

    vector<string> feriados(N);
    for(int i=0; i<N; ++i){
        cin >> feriados[i];
    }

    cout << (existe_ciclo_alcancavel(N, M, W, adjacencias, feriados) ? "Yes" : "No") << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}
