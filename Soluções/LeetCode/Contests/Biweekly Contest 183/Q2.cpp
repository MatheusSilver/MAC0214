class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mina = INT_MAX;
        for (int i = 0; i < k; i++){
            for (int j = 0; j < k; j++){

                if (i == j) continue;
                
                int counter = 0;

                for (int x = 0; x < nums.size(); x++){
                    int ans = (x % 2 == 0 ? i : j);
                    int currentNumber = nums[x] % k;

                    counter += min((ans - currentNumber + k) % k, (currentNumber - ans + k) % k);
                }


                // Ok... Achei isso comico, será mais comico ainda se funcionar.
                mina = min(mina, counter);
            }
        }
        return mina;
    }
};