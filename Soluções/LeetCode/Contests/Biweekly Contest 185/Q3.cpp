class Solution {
public:
    vector<vector<int>> graph;
    vector<int> *baseT;
    vector<long long> finish;

    long long dfs(int u){
        if (graph[u].empty()){
            return finish[u] = (*baseT)[u];
        }

        long long mx = LLONG_MAX, my = LLONG_MIN;

        for (int v : graph[u]){
            long long next = dfs(v);
            mx = min(mx, next);
            my = max(my, next);
        }

        finish[u] = 2 * my - mx + (*baseT)[u]; 
        return finish[u];
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        graph.assign(n, {});


        finish.assign(n, 0);

        baseT = &baseTime;

        for (auto &edge : edges){
            graph[edge[0]].push_back(edge[1]);
        }

        return dfs(0);
    }
};