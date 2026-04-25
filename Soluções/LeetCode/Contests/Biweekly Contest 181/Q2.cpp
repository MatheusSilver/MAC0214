class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long peak = 0;
        for (int i = 1; i < nums.size(); i++){
            peak = nums[i] > nums[peak] ? i : peak;
        }

        long long upS = 0, downS = 0;
        for (int i = 0; i < peak + 1; i++){
            upS += nums[i];
        }
        for (int i = peak; i < nums.size(); i++){
            downS += nums[i];
        }
        if (upS == downS) return -1;
        
        return upS > downS ? 0 : 1;    
    }
};