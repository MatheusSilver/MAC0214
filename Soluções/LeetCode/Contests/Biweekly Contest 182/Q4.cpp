class Solution {
public:
    
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        if (source == target) return 0;

        
        vector<vector<pair<int, int>>> graph(n);

        int d = 0;

        for (auto& edge : edges){
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
            d = max(d, edge[2]);            
        }

        int e = 0;

        while ( e < d){
            int m = (e + d) / 2;
            vector<int> dist(n, 1e9);
            deque<int> q{source};
            dist[source] = 0;

            while (!q.empty()){
                int  u = q.front();
                q.pop_front();

                for (pair<int,int> edge : graph[u]) {
                    int v = edge.first, w = edge.second;
                    int ndist = dist[u] + (w > m);

                    if (ndist < dist[v] && ndist <= k){
                        dist[v] = ndist;
                        w > m ? q.push_back(v) : q.push_front(v);
                    }
                }
            }

            dist[target] <= k ? d = m : e = m +1;
        }

        vector<int> dist(n, 1e9);
        deque<int> q{source};
        dist[source] = 0;

        while (!q.empty()){
                int  u = q.front();
                q.pop_front();

                for (pair<int,int> edge : graph[u]) {
                    int v = edge.first, w = edge.second;
                    int ndist = dist[u] + (w > e);

                    if (ndist < dist[v] && ndist <= k){
                        dist[v] = ndist;
                        w > e ? q.push_back(v) : q.push_front(v);
                    }
                }
            }

        return dist[target] <= k ? e : -1;
        
    }
};