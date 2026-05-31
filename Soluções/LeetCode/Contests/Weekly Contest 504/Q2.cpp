class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> cases(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i != j && items[j][0] % items[i][0] == 0)
                    cases[i]++;
            }
        }

        vector<int> value(n);
        for (int i = 0; i < n; i++) value[i] = items[i][1];
        sort(value.begin(), value.end());

        int mini = INT_MAX;
        for (int i = 0; i < n; i++){
            mini = min(mini, items[i][1]);
        }
        
        vector<int> maxCP(budget+1);
        for (int i = 0; i <= budget; i++){
            maxCP[i] = i / mini;
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++){
            int cost = items[i][1];
            int price = 1+ cases[i];
            for (int c = budget; c >= cost; c--){
                dp[c] = max(dp[c], dp[c-cost] + price);
            }
        }

        int resp = 0;
        for (int i = 0; i <= budget; i++){
            resp = max(resp, dp[i] + maxCP[budget - i]);
        }

        return resp;
        
    }
};