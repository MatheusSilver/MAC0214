class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd(nums.size());

        int mxi = nums[0];
        for (int i = 0; i < nums.size();i++){
            mxi = max(mxi, nums[i]);
            prefixGcd[i] = gcd(nums[i], mxi);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long answer = 0;
        int leftIndex = 0;
        int rightIndex = nums.size()-1;
        while (rightIndex > leftIndex) {
            answer += gcd(prefixGcd[leftIndex++], prefixGcd[rightIndex--]);
        }

        return answer;
    }
};