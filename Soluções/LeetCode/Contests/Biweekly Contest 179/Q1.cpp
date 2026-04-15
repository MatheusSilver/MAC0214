class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int result = nums.size()+1;
        int curSum = 0;
        for (int i = 0; i< nums.size(); i++){
            if (nums[i] == 1){
                for (int j = 0; j<nums.size(); j++){
                     if (nums[j] == 2){
                        curSum = abs(i - j);
                        if (curSum < result){
                            result = curSum;
                        }
                         
                     }   
                }
            }
        }
        if (result == nums.size()+1){
            result = -1;
        }
        return result;
    }
};