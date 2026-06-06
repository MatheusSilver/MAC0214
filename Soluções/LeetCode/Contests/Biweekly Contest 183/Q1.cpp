class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int counter = 0;
        int last_non_zero = nums.size()-1;
        while (last_non_zero >= 0 && nums[last_non_zero] == 0){
            last_non_zero--;
        }
        if (last_non_zero == 0) return 0;
        for (int i = 0; i < last_non_zero; i++){
            while (last_non_zero >= 0 && nums[last_non_zero] == 0){
            last_non_zero--;
        }
            if (i >= last_non_zero) break;
            if (nums[i] == 0){
                counter++;
                last_non_zero--;
            }
        }

        return counter;
    }
};