class Solution {
public:
    int minFlips(string s) {
        vector<int> dp(16, 1e9), ndp(16);
        dp[0] = 0;

        for (char c : s){
            fill(ndp.begin(), ndp.end(), 1e9);

            for (int i = 0; i < 16; i++){
                if (dp[i] >= 1e9) continue;
                for (int bit = 0; bit < 2; bit++){
                    if (bit == 0 && (i & 8) || (bit == 1 && (i & 4))) continue;

                    int j = i | (1 << bit);

                    if (bit != 0) {
                        if (i & 1) j |= 4;
                        if (i & 2) j |= 8;
                    }

                    ndp[j] = min(ndp[j], dp[i] + (bit != c - '0'));
                    
                    
                }
            }
            dp.swap(ndp);
        }
        return *min_element(dp.begin(), dp.end());
    }
};