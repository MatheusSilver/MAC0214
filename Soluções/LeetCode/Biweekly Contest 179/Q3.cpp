class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        int di[2] = {1,0}, dj[2] = {0, 1};

        vector dp(m, vector<unordered_set<int>>(n));

        dp[0][0].insert(grid[0][0]);

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                for (int k : dp[i][j]) {
                    for (int d = 0; d < 2; d++){
                        // Quatro fors kkkkkkkkk
                        // Ou quatro fours.
                        int ki = i + di[d], kj = j + dj[d];
                        if (ki < m && kj < n){
                            dp[ki][kj].insert(k ^ grid[ki][kj]);
                        }
                    }
                }
            }
        }
        int resposta = 2147483647;
        for (int k : dp[m-1][n-1]) resposta = min(resposta, k);

        return resposta;
    }
};