class Solution {
public:
    int MOD = 1E9+7;
    int countArrays(vector<int>& digitSum) {
       vector<vector<int>> arr(50);
        for (int i = 0; i <= 5000; i++){
            int sum = 0, digit = i; 
            while(digit){
                sum += digit % 10;
                digit /= 10;
            }
            arr[sum].push_back(i);
        }
        vector<long long> dp(5001,0);
        if (digitSum[0] >= 50) return 0;
        
        for (int value : arr[digitSum[0]]) dp[value] = 1;
        
        for (int k = 1; k < digitSum.size(); k++){
            int sum = digitSum[k];
            if (sum >= 50) return 0;
            vector<long long> numberDP(5001);
            long long prefixo = 0;
            int j = 0;
            for (int i = 0; i <= 5000; i++){
                prefixo = (prefixo + dp[i])%MOD;
                if (j < arr[sum].size() && arr[sum][j] == i){
                    numberDP[i] = prefixo;
                    j++;
                }
            }
            dp = numberDP;
        }
        int resposta = 0;
        for (long long value : dp) resposta = (resposta + value)%MOD;
        return resposta;
    }
};