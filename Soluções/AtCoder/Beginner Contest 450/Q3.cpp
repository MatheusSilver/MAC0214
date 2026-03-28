#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<string> s;
vector<vector<bool>> visitado;
const int di[4] = {-1, 1, 0, 0};
const int dj[4] = {0, 0, -1, 1};

inline bool dentro(int i, int j)    { return 0 <= i && i < h && 0 <= j && j < w; }

inline bool aceitavel(int i, int j) { return i == 0 || i == h - 1 || j == 0 || j == w - 1; }

inline bool visitavel(int i, int j) { return s[i][j] == '.' && !visitado[i][j]; }

bool bfs(int si, int sj) {
	queue<pair<int, int>> q;
	q.push({si, sj});
	visitado[si][sj] = true;

	bool adj = aceitavel(si, sj);

	while (!q.empty()) {
		pair<int, int> atual = q.front();
		int ci = atual.first; int cj = atual.second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int cli = ci + di[k];  int clj = cj + dj[k];
			if (dentro(cli, clj) && visitavel(cli, clj)) {
                visitado[cli][clj] = true;
                adj = adj || aceitavel(cli, clj);
                q.push({cli, clj});
			}
		}
	}
	return !adj;
}

int main() {
	cin >> h >> w;
	int resp = 0;
	visitado = vector<vector<bool>>(h, vector<bool>(w, false));
    
    s.resize(h);
    
	for (int i = 0; i < h; i++) cin >> s[i];
	for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) if(visitavel(i, j)) resp += (int)bfs(i, j);

	cout << resp << endl;
}