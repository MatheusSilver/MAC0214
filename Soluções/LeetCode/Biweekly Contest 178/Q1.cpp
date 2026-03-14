class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int> freq;

        for (int i = 0; i < nums.size(); i++) freq[nums[i]]++;

        int index = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0 && freq[nums[i]] == 1) {
                index = i;
                break;
            }
        }
        int answer = index == -1 ? -1 : nums[index];
        return answer;
    }
};©leetcode