class Solution {
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size(), resp = 0;

        vector<int> adj(n);

        for (auto &e : edges) 
            adj[e[0]] |= 1 << e[1], adj[e[1]] |= 1 << e[0];

        for (int m = 1; m < (1 << n); m++){
            int s = 0;
            for (int i = 0; i < n; i++) s += m >> i & 1 ? nums[i] : 0;
            if (s & 1){
                //none
            }else{
                int q = 1 << __builtin_ctz(m);
                int v = q;
    
                while (q) {
                    int u = __builtin_ctz(q);
                    q &= q - 1;
                    int x = adj[u] & m & ~v;
                    v |= x, q |= x;
                }
    
                resp += v == m;
            }

        }
        return resp;
    }
};