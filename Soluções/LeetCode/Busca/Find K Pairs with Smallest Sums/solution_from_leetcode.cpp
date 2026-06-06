class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > fila;

        int n = nums1.size();
        int m = nums2.size();

        for (int i = 0; i < min(n, k); i++) {
            fila.push({1LL * nums1[i] + nums2[0], i, 0});
        }

        vector<vector<int>> resposta;

        while (k-- && !fila.empty()) {
            auto [soma, i, j] = fila.top();
            fila.pop();

            resposta.push_back({nums1[i], nums2[j]});

            if (j + 1 < m) {
                fila.push({1LL * nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return resposta;
    }
};