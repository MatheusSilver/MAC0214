class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> limitedArray;

        int counter = 1;
        limitedArray.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i-1]){
                counter++;
            }else{
                counter = 1;        
            }
            if (counter <= k) limitedArray.push_back(nums[i]);
        }
        return limitedArray;
    }
};