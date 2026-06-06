class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        int i = 0;
        long long sol = 0;
        while (i < n){
            if (s[i] == '0'){
                i++;
                continue;
            }

            int l = i;
            while (i < n && s[i] == '1') i++;
            int r = i - 1;

            long long sum = 0;
            long long ma = 100000000000000;

            int st = (l == 0 ? 0 : l - 1);
            for (int j = st; j <= r; j++){
                sum += nums[j];
                ma = min(ma, (long long)nums[j]);
            }

            if (l == 0) sol += sum;
            else sol += sum - ma;
        }

        return sol;
    }
};